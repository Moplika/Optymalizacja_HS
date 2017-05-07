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

	double constantMultiplier;	// sta�a, np. z funkcji 4x1 albo 1/5
	bool isExpression;	// true - mamy cokolwiek ze zmienn� x, false - tylko sta�a
	MainSign mainSign;	// znak przed ca�o�ci� (+ albo -)
	std::vector<SpecialExpression> parts; // cz�ci r�wnania, przedzielone znakiem * albo /
	std::vector<MultiplicationSign> signs;	// znaki * i /, w kolejno�ci
	
	void setVariablesToZero();

};

