#pragma once

#include "SpecialExpressionType.h"
#include "SimpleExpression.h"

#include <string>
#include <vector>

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
	
	SimpleExpression simpleArgument;

	//bool isArgumentSpecial;
	
	//SpecialExpression specialArgument;
	
	double constantArgument;

	SpecialExpressionType defineExpressionType(std::string expression, double &argument);

	std::string expressionFormula;
};
