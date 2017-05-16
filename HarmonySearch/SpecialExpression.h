#pragma once

#include "SpecialExpressionType.h"
#include "Argument.h"

#include <string>
#include <vector>

//class Argument;

class SpecialExpression
{
public:
	SpecialExpression();
	SpecialExpression(std::string formula);
	~SpecialExpression();

	double calculate(std::vector<double> x);
	bool setFormula(std::string formula);
private:
	SpecialExpressionType type;
	
    Argument simpleArgument;
	
	double constantArgument;

	SpecialExpressionType defineExpressionType(std::string expression, double &argument);

	std::string expressionFormula;
};
