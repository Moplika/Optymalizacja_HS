#include "EquationPart.h"

#include <iostream>

EquationPart::EquationPart()
{
	setVariablesToZero();
}

EquationPart::EquationPart(std::string formula, MainSign mSign)
{
	// UWAGA: Nie sprawdza, czy r�wnanie jest poprawne
	setFormula(formula, mSign);
}

EquationPart::~EquationPart()
{
}

bool EquationPart::setFormula(std::string formula, MainSign mSign)
{
	this->setVariablesToZero();

	partFormula = formula;
	mainSign = mSign;

	return this->splitFormula();
}

std::string EquationPart::getFormula()
{
	return partFormula;
}

void EquationPart::setVariablesToZero()
{
	partFormula = "";
	constantMultiplier = 0;
	constantSign = MultiplicationSign::nothingMulti;
	isExpression = false;
	mainSign = MainSign::nothingMain;
	parts.clear();
	signs.clear();
}

void EquationPart::separateConstant(std::size_t firstNotNumberPosition, std::size_t firstSignPosition, std::size_t &partStartPosition)
{
	if (firstNotNumberPosition != 0)
	{
		constantMultiplier = std::stod(partFormula.substr(0, firstNotNumberPosition));

		if (firstNotNumberPosition == firstSignPosition) // Posta� a*x1
		{
			partStartPosition = firstNotNumberPosition + 1;
			constantSign = this->setSign(partFormula.at(firstSignPosition));
		}
		else // Posta� ax1
		{
			partStartPosition = firstNotNumberPosition;
			constantSign = MultiplicationSign::multiply;
		}
	}
}

bool EquationPart::splitParts(std::size_t firstNotNumberPosition, std::size_t firstSignPosition)
{
	int unpairedBracketsNo = 0;
	MultiplicationSign sign = MultiplicationSign::nothingMulti;
	std::string::iterator fragmentStart = partFormula.begin();
	for (std::size_t i = 0; i < firstNotNumberPosition; i++)
	{
		fragmentStart++;
	}
	if (firstNotNumberPosition == firstSignPosition)
		fragmentStart++;
	std::string::iterator fragmentEnd = partFormula.end();

	for (std::string::iterator it = fragmentStart; it != partFormula.end(); it++)
	{
		if (*it == '(')
			unpairedBracketsNo++;
		else if (*it == ')')
			unpairedBracketsNo--;
		if (unpairedBracketsNo < 0)
		{
			std::cerr << "B��d: niesparowane nawiasy!" << std::endl;
			return false;
		}

		if (unpairedBracketsNo == 0 && ((*it == '*' || *it == '/')))
		{
			// Ustawienie iteratora do ko�ca fragmentu na 1 znak przed * lub /
			fragmentEnd = it;
			//--fragmentEnd;

			if (!this->createNewExpression(fragmentStart, fragmentEnd, sign))
				return false;

			// Rozpocz�cie nowego fragmentu
			sign = this->setSign(*it);

			// Ustawienie iteratora do pocz�tku nowego fragmentu na 1 znak po * lub /
			fragmentStart = it;
			++fragmentStart;
		}
	}

	if (unpairedBracketsNo != 0)
	{
		std::cerr << "B��d: niesparowane nawiasy!" << std::endl;
		return false;
	}

	// Wstawienie ostatniego fragmentu
	if (!this->createNewExpression(fragmentStart, partFormula.end(), sign))
		return false;

	return true;
}

bool EquationPart::splitFormula()
{
	std::size_t firstXPosition = partFormula.find("x");
	std::size_t firstNotNumberPosition = partFormula.find_first_not_of("0123456789");
	std::size_t firstSignPosition = partFormula.find_first_of("*/");
		
	// Sprawdzenie, czy w r�wnaniu nie ma x - jest tylko sta�a
	if (firstXPosition == std::string::npos)	
	{
		if (firstNotNumberPosition != std::string::npos)	// Ale jest jaki� inny znak, kt�ry nie jest liczb� - b��d
		{
			std::cerr << "Blad: niedozwolone znaki w rownaniu" << std::endl;
			return false;
		}

		isExpression = false;
		constantMultiplier = std::stod(partFormula);
		constantSign = MultiplicationSign::multiply;
		return true;
	}

	isExpression = true;
	std::size_t partStartPosition = 0;

	this->separateConstant(firstNotNumberPosition, firstSignPosition, partStartPosition);

	// Wy��czenie kolejnych kawa�k�w
	//int unpairedBracketsNo = 0;
	//MultiplicationSign sign = MultiplicationSign::nothingMulti;
	//std::string::iterator fragmentStart = partFormula.begin();
	//for (std::size_t i = 0; i < firstNotNumberPosition; i++)
	//{
	//	fragmentStart++;
	//}
	//if (firstNotNumberPosition == firstSignPosition)
	//	fragmentStart++;
	//std::string::iterator fragmentEnd = partFormula.end();

	//for (std::string::iterator it = fragmentStart; it != partFormula.end(); it++)
	//{
	//	if (*it == '(')
	//		unpairedBracketsNo++;
	//	else if (*it == ')')
	//		unpairedBracketsNo--;
	//	if (unpairedBracketsNo < 0)
	//	{
	//		std::cerr << "B��d: niesparowane nawiasy!" << std::endl;
	//		return false;
	//	}

	//	if (unpairedBracketsNo == 0 && ((*it == '*' || *it == '/')))
	//	{
	//		// Ustawienie iteratora do ko�ca fragmentu na 1 znak przed * lub /
	//		fragmentEnd = it;
	//		//--fragmentEnd;

	//		if (!this->createNewExpression(fragmentStart, fragmentEnd, sign))
	//			return false;

	//		// Rozpocz�cie nowego fragmentu
	//		sign = this->setSign(*it);

	//		// Ustawienie iteratora do pocz�tku nowego fragmentu na 1 znak po * lub /
	//		fragmentStart = it;
	//		++fragmentStart;
	//	}
	//}
	if (!this->splitParts(firstNotNumberPosition, firstSignPosition))
		return false;

	//// Wstawienie ostatniego fragmentu
	//if (unpairedBracketsNo != 0)
	//{
	//	std::cerr << "B��d: niesparowane nawiasy!" << std::endl;
	//	return false;
	//}

	//if (!this->createNewExpression(fragmentStart, partFormula.end(), sign))
	//	return false;

	return true;
}

MultiplicationSign EquationPart::setSign(char sign)
{
	switch (sign)
	{
	case '*': return MultiplicationSign::multiply;
	case '/': return MultiplicationSign::divide;
	default: return MultiplicationSign::nothingMulti;
	}
}

bool EquationPart::createNewExpression(std::string::iterator fragmentStart, std::string::iterator fragmentEnd, MultiplicationSign sign)
{
	std::string expressionFormula;
	expressionFormula.assign(fragmentStart, fragmentEnd);

	SpecialExpression newExpression;
	if (!newExpression.setFormula(expressionFormula))
	{
		std::cerr << "B��d przy wczytywaniu funkcji" << std::endl;
		return false;
	}

	parts.push_back(newExpression);
	
	if (sign != MultiplicationSign::nothingMulti)
	{
		signs.push_back(sign);
	}

	return true;
}

double EquationPart::calculate(std::vector<double> x)
{	
	double result;

	if (parts.size() == 0)
	{
		result = 1;
	}
	else if (parts.size() == 1) // Jest tylko jeden element
	{
		result = parts.front().calculate(x);
	}
	else // Wi�cej ni� jeden element
	{
		std::vector<SpecialExpression>::reverse_iterator expressionRit = parts.rbegin();
		result = expressionRit->calculate(x);
		expressionRit++;

		for (std::vector<MultiplicationSign>::reverse_iterator signRit = signs.rbegin();
			signRit != signs.rend(); signRit++, expressionRit++)
		{
			result = this->calculatePart(expressionRit->calculate(x), result, *signRit);
		}
	}
	
	switch (constantSign)
	{
	case MultiplicationSign::multiply: result *= constantMultiplier; break;
	case MultiplicationSign::divide: result = constantMultiplier / result; break;
	default: break;
	}
	
	if (mainSign == MainSign::subtract)
		return -result;
	else
		return result;
}

double EquationPart::calculatePart(double first, double second, MultiplicationSign sign)
{
	switch (sign)
	{
	case MultiplicationSign::multiply: return first * second;
	case MultiplicationSign::divide:
	{
		if (second != 0)
			return first / second;

		std::cerr << "B��d: dzielenie przez zero" << std::endl;
		return INT_MAX;
	}
	case MultiplicationSign::nothingMulti:
		std::cerr << "B��d: brak znaku" << std::endl;
		return INT_MAX;
	default:
		return INT_MAX;
	}

}