#pragma once

#include "EquationSigns.h"
#include "SpecialExpression.h"

#include <vector>

class EquationPart
{
public:
	EquationPart();
	EquationPart(std::string formula, MainSign mSign);
	~EquationPart();

	bool setFormula(std::string formula, MainSign mSign);
	std::string getFormula();

	double calculate(std::vector<double> x);

private:
	std::string partFormula;

	double constantMultiplier;	// sta³a, np. z funkcji 4x1 albo 1/5
	bool isExpression;	// true - mamy cokolwiek ze zmienn¹ x, false - tylko sta³a
	MainSign mainSign;	// znak przed ca³oœci¹ (+ albo -)
	std::vector<SpecialExpression> parts; // czêœci równania, przedzielone znakiem * albo /
	std::vector<MultiplicationSign> signs;	// znaki * i /, w kolejnoœci
	
	void setVariablesToZero();

};

