#include "SpecialExpression.h"

#include <iostream>
#include <cmath>


SpecialExpression::SpecialExpression()
{
	expressionFormula = "";
    simpleArgument = NULL;
}

SpecialExpression::SpecialExpression(std::string string)
{
	expressionFormula = string;
}

SpecialExpression::~SpecialExpression()
{
    if (simpleArgument != NULL)
        delete simpleArgument;
    simpleArgument = NULL;
}

bool SpecialExpression::setFormula(std::string formula)
{
	expressionFormula = formula;

	//TODO: Rewrite -.-

	//return true;

	std::string functionName;
	std::string functionArgument;
	
	// Argument jest w nawiasach
	std::size_t argumentStartPos = formula.find("(");
	if (argumentStartPos != std::string::npos)
	{
		// Znajdź argument funkcji (w nawiasach)
		std::size_t argumentEndPos = formula.find_last_of(")");
		if (argumentEndPos == std::string::npos)
		{
			std::cerr << "Podano błędne równanie - brak zamykającego nawiasu" << std::endl;
			return false;
		}

		functionArgument.append(formula, argumentStartPos + 1, argumentEndPos - argumentStartPos - 1);

		// Znajdź typ funkcji
		if (argumentStartPos != 0) // Funkcja jest na początku - sin, cos, tan, ln, exp itp
		{
			functionName.append(formula, 0, argumentStartPos);
		}
		else if (argumentEndPos != formula.length()) // Funkcja jest na końcu - x^a
		{
			functionName.append(formula, argumentEndPos + 1, formula.length() - argumentEndPos);
		}
		type = this->defineExpressionType(functionName, constantArgument);

		// Logarytm ma podstawę jako pierwszy argument w nawiasie - trzeba ją wyciągnąć
		if (type == SpecialExpressionType::logaritmic)
		{
			std::size_t commaPos = functionArgument.find(",");
			if (commaPos == std::string::npos) // Nie ma podstawy - przyjmij 10
			{
				constantArgument = 10.0;
			}
			else
			{
				constantArgument = std::stod(functionArgument.substr(0, commaPos + 1));
				functionArgument = functionArgument.substr(commaPos + 1);
			}
		}
	}
	else
	{
		// Znajdź pierwszy x:
		std::size_t firstXPos = formula.find('x');

		if (firstXPos == std::string::npos) // Nie ma x?
		{
			std::cerr << "Błąd: w równaniu nie ma x?" << std::endl;
			return false;
		}

		if (firstXPos != 0) // Funkcja na początku
		{
			functionName.append(formula, 0, firstXPos);
			functionArgument.append(formula, firstXPos, formula.length());
		}
		else // Funkcja na końcu: możliwe tylko dla x^a lub x
		{
			std::size_t powerPosition = formula.find("^");
			if (powerPosition == std::string::npos) // Funkcja typu x
			{
				functionName = "";
				functionArgument.append(formula);
			}
			else
			{
				functionName.append(formula, powerPosition, formula.length());
				functionArgument.append(formula, 0, powerPosition);
			}
			
		}

		type = this->defineExpressionType(functionName, constantArgument);
	}
    simpleArgument = new Argument();
    simpleArgument->setFormula(functionArgument);
	
	return true;
}

SpecialExpressionType SpecialExpression::defineExpressionType(std::string expression, double &argument)
{
	argument = 0;

	if (expression == "")
		return SpecialExpressionType::none;
	if (expression == "exp" || expression == "e^")
		return SpecialExpressionType::exponential;
	if (expression == "ln")
		return SpecialExpressionType::naturalLog;
	if (expression == "log")
		return SpecialExpressionType::logaritmic;
	if (expression == "sin")
		return SpecialExpressionType::sinus;
	if (expression == "cos")
		return SpecialExpressionType::cosinus;
	if (expression == "tan" || expression == "tg")
		return SpecialExpressionType::tangens;
	if (expression == "ctan" || expression == "ctg")
		return SpecialExpressionType::cotangens;
	if (expression.front() == '^') // Funkcja x^a
	{
		argument = std::stod(expression.substr(1));
		return SpecialExpressionType::polynomial;
	}
	if (expression.back() == '^') // Funkcja a^x
	{
		argument = std::stod(expression.substr(0, expression.length() - 1));
		return SpecialExpressionType::power;
	}
	
	return SpecialExpressionType::none;
}

double SpecialExpression::calculate(std::vector<double> x)
{
	//return 2.0;

	// TODO: Dodać ograniczenia dla logarytmu i tangensa/cotangensa
    double variable = simpleArgument->calculate(x);

	switch (type)
	{
	case none:
		return variable;
	case polynomial:
		return pow(variable, constantArgument);
	case exponential:
		return exp(variable);
	case logaritmic:
		return log(variable) / log(constantArgument);
	case naturalLog:
		return log(variable);
	case power:
		return pow(constantArgument, variable);
	case sinus:
		return sin(variable);
	case cosinus:
		return cos(variable);
	case tangens:
		return tan(variable);
	case cotangens:
		return 1 / tan(variable);
	default:
		break;
	}

	return 1.0;
}

