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

	double constantMultiplier;	// stała, np. z funkcji 4x1 albo 1/5
	MultiplicationSign constantSign;
	bool isExpression;	// true - mamy cokolwiek ze zmienną x, false - tylko stała
	MainSign mainSign;	// znak przed całością (+ albo -)
	std::vector<SpecialExpression> parts; // części równania, przedzielone znakiem * albo /
	std::vector<MultiplicationSign> signs;	// znaki * i /, w kolejności
	
	void setVariablesToZero();
	MultiplicationSign setSign(char sign);
	
	bool splitParts(std::size_t firstNotNumberPosition, std::size_t firstSignPosition);
	bool splitFormula();
	void separateConstant(std::size_t firstNotNumberPosition, std::size_t firstSignPosition, std::size_t &partStartPosition);
	bool createNewExpression(std::string::iterator fragmentStart, std::string::iterator fragmentEnd, MultiplicationSign sign);
	double calculatePart(double first, double second, MultiplicationSign sign);
};

