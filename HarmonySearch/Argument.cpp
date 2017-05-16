#include "Argument.h"

#include <algorithm>

Argument::Argument()
{
    specialExpression = NULL;
}

Argument::Argument(std::string string)
{
    argumentFormula = string;
    specialExpression = NULL;
}


Argument::~Argument()
{
    if (specialExpression != NULL)
        delete specialExpression;
    specialExpression = NULL;
}

bool Argument::setFormula(std::string formula)
{
	argumentFormula = formula;
	
	if (argumentFormula.at(0) == '-')
	{
        mainSign = MainSign::subtract;
	}
	else
	{
        mainSign = MainSign::add;
	}

	// Policz, ile jest x w równaniu
	std::size_t xNb = std::count(argumentFormula.begin(), argumentFormula.end(), 'x');

	// Wyłączenie stałej

	if (xNb == 0) // W równaniu nie ma x
	{

	}
	else if (xNb == 1)
	{

		return true;
	}

	return true;
}

double Argument::calculate(std::vector<double> x)
{
    return 1.0;
}

std::string Argument::getFormula() const
{
    return argumentFormula;
}


