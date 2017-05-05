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
	return 2.0;
}

bool SimpleExpression::setFormula(std::string formula)
{
	temp = formula;
	return true;
}