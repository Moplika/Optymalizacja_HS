#pragma once
#include <vector>
#include <string>

class Expression
{
public:
	Expression();
	Expression(std::string string);
	~Expression();

	virtual double calculate(std::vector<double> x);
	virtual bool setFormula(std::string formula);
};

