#include "Argument.h"


Argument::Argument()
{
    specialExpression = NULL;
}

Argument::Argument(std::string string)
{
    formula = string;
    specialExpression = NULL;
}


Argument::~Argument()
{
//    if (specialExpression != NULL)
//        delete specialExpression;
//    specialExpression = NULL;
}

double Argument::calculate(std::vector<double> x)
{
    return 1.0;
}

std::string Argument::getFormula() const
{
    return formula;
}

bool Argument::setFormula(std::string formula)
{
    formula = formula;
	return true;
}
