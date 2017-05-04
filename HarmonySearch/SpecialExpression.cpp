#pragma warning( disable : 4996 )

#include "SpecialExpression.h"


SpecialExpression::SpecialExpression()
{

}

SpecialExpression::SpecialExpression(std::string string)
{
	temp = string;
}

SpecialExpression::~SpecialExpression()
{
}

void SpecialExpression::setFormula(std::string formula)
{
	temp = formula;

	std::string functionName;
	std::string functionArgument;

	std::size_t splitPos = formula.find("(");
	if (splitPos != std::string::npos)
	{
		// ZnajdŸ nazwê funkcji (cos, sin, exp itp)
		char buffer[20];
		formula.copy(buffer, splitPos, 0);
		functionName.assign(buffer, splitPos);

		type = defineExpressionType(functionName);

		// ZnajdŸ argument funkcji
		std::size_t endPos = formula.find_last_of(")");
		if (endPos == std::string::npos)
		{
			// TODO: Wyrzuciæ jakiœ error
			return;
		}
		//functionArgument.append()

	}

	else
	{
		return; // TODO: Dodaæ obs³ugê sytuacji, gdy nie ma nawiasów
	}


}

SpecialExpressionType SpecialExpression::defineExpressionType(std::string expression)
{
	if (expression == "exp")
		return SpecialExpressionType::exponential;
	if (expression == "ln")
		return SpecialExpressionType::naturalLog;
	if (expression == "log")
		return SpecialExpressionType::logaritmic;
	if (expression == "sin")
		return SpecialExpressionType::sinus;
	if (expression == "cos")
		return SpecialExpressionType::cosinus;
	if (expression == "tan" || expression == "tg")
		return SpecialExpressionType::tangens;
	if (expression == "ctan" || expression == "ctg")
		return SpecialExpressionType::cotangens;

	return SpecialExpressionType::none;
}

double SpecialExpression::calculate(std::vector<double> x)
{
	// TODO: Dodaæ ograniczenia dla logarytmu i tangensa/cotangensa
	double variable = simpleArgument.calculate(x);

	switch (type)
	{
	case none:
		return variable;
	case polynomial:
		return pow(variable, constantArgument);
	case exponential:
		return exp(variable);
	case logaritmic:
		return log(variable) / log(constantArgument);
	case naturalLog:
		return log(variable);
	case power:
		return pow(constantArgument, variable);
	case sinus:
		return sin(variable);
	case cosinus:
		return cos(variable);
	case tangens:
		return tan(variable);
	case cotangens:
		return 1 / tan(variable);
	default:
		break;
	}

	return 1.0;
}