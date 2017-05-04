#pragma once
#include "Expression.h"
class SimpleExpression :
	public Expression
{
public:
	SimpleExpression();
	SimpleExpression(std::string formula);
	~SimpleExpression();

	void setFormula(std::string formula);
	double calculate(std::vector<double> x);

private:
	std::string temp;
};

