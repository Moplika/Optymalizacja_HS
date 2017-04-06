#include "VariableConstraints.h"


VariableConstraints::VariableConstraints(double _min, double _max)
{
	if (_min >= _max) // TODO: Wyrzuciæ jakiœ error
		return;

	min = _min;
	max = _max;
}


VariableConstraints::~VariableConstraints()
{
}

double VariableConstraints::getMax()
{
	return max;
}

double VariableConstraints::getMin()
{
	return min;
}

void VariableConstraints::setMin(double value)
{
	min = value;
}

void VariableConstraints::setMax(double value)
{
	max = value;
}