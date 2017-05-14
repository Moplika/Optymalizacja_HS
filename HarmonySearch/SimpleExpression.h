#pragma once

#include <string>
#include <vector>

class SimpleExpression
{
public:
	SimpleExpression();
	SimpleExpression(std::string formula);
	~SimpleExpression();

	bool setFormula(std::string formula);
	double calculate(std::vector<double> x);

private:
	std::string temp;
};

