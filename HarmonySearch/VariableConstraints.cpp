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

double VariableConstraints::getMax() const
{
	return max;
}

double VariableConstraints::getMin() const
{
	return min;
}


void VariableConstraints::setMax(double value)
{
	max = value;
}