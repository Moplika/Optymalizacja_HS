#include "VariableConstraints.h"

#include <iostream>

// UWAGA: Nie obsługuje sprawdzania poprawności
VariableConstraints::VariableConstraints(double _min, double _max)
{
   this->setConstraints(_min, _max);
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

bool VariableConstraints::setConstraints(double _min, double _max)
{
    if (_min >= _max)
    {
        std::cerr << "Błąd ograniczeń: minimum większe od maksimum" << std::endl;
        return false;
    }

    min = _min;
    max = _max;

    return true;
}
