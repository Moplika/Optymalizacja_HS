#include "Expression.h"


Expression::Expression()
{
}

Expression::Expression(std::string formula)
{
    temp = formula;
}

Expression::~Expression()
{
}

double Expression::calculate(std::vector<double> x)
{
	return 0;
}

bool Expression::setFormula(std::string formula)
{
    temp = formula;
	return false;
}
