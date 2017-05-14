#include "SimpleExpression.h"


SimpleExpression::SimpleExpression()
{
}

SimpleExpression::SimpleExpression(std::string string)
{
	temp = string;
}


SimpleExpression::~SimpleExpression()
{
}

double SimpleExpression::calculate(std::vector<double> x)
{
    return 1.0;
}

bool SimpleExpression::setFormula(std::string formula)
{
	temp = formula;
	return true;
}
