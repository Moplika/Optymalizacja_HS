#pragma once

#include "EquationPart.h"

#include <string>
#include <vector>

class Equation
{
public:
	Equation();
    //Equation(std::string formula);
	~Equation();

    bool setEquation(std::string equation, unsigned int &N);
	std::string getEquation();

	double calculate(std::vector<double> x);

private:
	std::string equationFormula;
	std::vector<EquationPart> equationParts;

	bool splitEquation();

	MainSign setSign(char sign);
	bool createNewFragment(std::string::iterator fragmentStart, std::string::iterator fragmentEnd, MainSign sign);

	void clearVariables();
};

