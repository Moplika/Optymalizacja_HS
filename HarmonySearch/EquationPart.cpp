#include "EquationPart.h"

#include <iostream>


EquationPart::EquationPart()
{
	setVariablesToZero();
}

EquationPart::EquationPart(std::string formula, MainSign mSign)
{
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

	return true;
}

std::string EquationPart::getFormula()
{
	return partFormula;
}

void EquationPart::setVariablesToZero()
{
	partFormula = "";
	constantMultiplier = 0;
	isExpression = false;
	mainSign = MainSign::nothingMain;
	parts.clear();
	signs.clear();
}

double EquationPart::calculate(std::vector<double> x)
{
	// TODO: Dodaæ obliczanie
	double result = 1.0;

	if (mainSign == MainSign::subtract)
		return -result;
	else
		return result;
}