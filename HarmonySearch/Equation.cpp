#include "Equation.h"

#include <iostream>
#include <algorithm>
#include <cctype>

Equation::Equation()
{
	equationFormula = "";
}

// UWAGA: Nie zwraca potwierdzenia, czy wprowadzone równanie jest poprawne
Equation::Equation(std::string formula)
{
	setEquation(formula);
}

Equation::~Equation()
{
}

bool Equation::setEquation(std::string equation)
{
	this->clearVariables();

	equationFormula = equation;
	// Zmiana na same ma³e litery
	std::transform(equationFormula.begin(), equationFormula.end(), equationFormula.begin(), ::tolower);
	
	// Usuniêcie spacji
	std::string::iterator endAfterRemoval = std::remove_if(equationFormula.begin(), equationFormula.end(), std::isspace);
	equationFormula.erase(endAfterRemoval, equationFormula.end());

	return this->splitEquation();
}

MainSign Equation::setSign(char sign)
{
	switch (sign)
	{
	case '+': return MainSign::add;
	case '-': return MainSign::subtract;
	default: return MainSign::nothingMain;
	}
}

std::string Equation::getEquation()
{
	return equationFormula;
}

bool Equation::splitEquation()
{
	int unpairedBracketsNo = 0;
	MainSign sign = MainSign::nothingMain;

	std::string::iterator fragmentStart = equationFormula.begin();
	std::string::iterator fragmentEnd = equationFormula.end();

	// Obs³uga znaku na pocz¹tku równania
	sign = this->setSign(*fragmentStart);
	if (sign != MainSign::nothingMain)
		fragmentStart++;
	else
		sign = MainSign::add; // Jeœli na pocz¹tku nie ma znaku, to przyjmujemy +

	for (std::string::iterator it = fragmentStart; it != equationFormula.end(); it++)
	{
		if (*it == '(')
			unpairedBracketsNo++;
		else if (*it == ')')
			unpairedBracketsNo--;
		if (unpairedBracketsNo < 0)
		{
			std::cerr << "B³¹d: niesparowane nawiasy!" << std::endl;
			return false;
		}

		if (unpairedBracketsNo == 0 && ((*it == '+' || *it == '-')))
		{
			// Ustawienie iteratora do koñca fragmentu na 1 znak przed + lub -
			fragmentEnd = it;
			//--fragmentEnd;

			// Utworzenie fragmentu
			if (!this->createNewFragment(fragmentStart, fragmentEnd, sign))
				return false;
	
			// Rozpoczêcie nowego fragmentu
			sign = this->setSign(*it);

			// Ustawienie iteratora do pocz¹tku nowego fragmentu na 1 znak po + lub -
			fragmentStart = it;
			++fragmentStart;
		}
	}

	// Wstawienie ostatniego fragmentu
	if (unpairedBracketsNo != 0)
	{
		std::cerr << "B³¹d: niesparowane nawiasy!" << std::endl;
		return false;
	}
	
	if (!this->createNewFragment(fragmentStart, equationFormula.end(), sign))
		return false;

	return true;
}

bool Equation::createNewFragment(std::string::iterator fragmentStart, std::string::iterator fragmentEnd, MainSign sign)
{
	std::string fragmentForumula;
	fragmentForumula.assign(fragmentStart, fragmentEnd);

	EquationPart newPart;
	if (!newPart.setFormula(fragmentForumula, sign))
	{
		std::cerr << "B³¹d przy wczytywaniu fragmentu" << std::endl;
		return false;
	}

	equationParts.push_back(newPart);

	return true;
}

double Equation::calculate(std::vector<double> x)
{
	double result = 0;

	for (std::vector<EquationPart>::iterator it = equationParts.begin(); it < equationParts.end(); it++)
	{
		result += it->calculate(x);
	}

	return result;
}

void Equation::clearVariables()
{
	equationFormula = "";
	equationParts.clear();
}