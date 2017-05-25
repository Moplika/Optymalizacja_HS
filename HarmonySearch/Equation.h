#pragma once

#include <muParser.h>

#include <string>
#include <vector>

class Equation
{
public:
	Equation();
	~Equation();

    bool setEquation(std::string equation, unsigned int &N);
	std::string getEquation();

	double calculate(std::vector<double> x);

private:
	std::string equationFormula;
    int variableCount;

    mu::Parser parser;
    std::vector<double> fValues;

    bool parseEquation();

    void clearVariables();

	int countXs();
};



