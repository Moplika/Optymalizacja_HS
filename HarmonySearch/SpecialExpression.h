#pragma once
#include "Expression.h"
#include "SpecialExpressionType.h"
#include "SimpleExpression.h"
class SpecialExpression :
	public Expression
{
public:
	SpecialExpression();
	SpecialExpression(std::string formula);
	~SpecialExpression();

	double calculate(std::vector<double> x);
	void setFormula(std::string formula);

private:
	SpecialExpressionType type;
	
	SimpleExpression simpleArgument;

	//bool isArgumentSpecial;
	
	//SpecialExpression specialArgument;
	
	double constantArgument;

	SpecialExpressionType defineExpressionType(std::string expression);


	std::string temp;
};



