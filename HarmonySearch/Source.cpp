#include <iostream>
#include <vector>
#include <algorithm>

#include "HarmonyMemoryRow.h"
#include "HarmonySearch.h"
#include "VariableConstraints.h"
#include "Expression.h"
#include "SimpleExpression.h"
#include "SpecialExpression.h"
#include "EquationPart.h"
#include "Equation.h"


using namespace std;

void TestRandomDouble();
void TestMultipleSolutions();
void TestSpecialExpressionParsing();
void TestEquationPartsParsing();
void TestEquationParsing();

int main()
{
	cout << "Hello world?" << endl;

	/*double testX[] = { 16, 2, 77, 29 };
	vector<double> vTestX(testX, testX + 4);

	HarmonyMemoryRow testRow(vTestX);
	testRow.printRowWithNames();*/

	//TestMultipleSolutions();

	//TestSpecialExpressionParsing();
	
	TestEquationPartsParsing();

	//TestEquationParsing();
	

	system("PAUSE");
	return 0;
}

double getRandomDouble(double min, double max)
{
	return ((double)rand() / RAND_MAX) * (max - min) + min;
}

void TestRandomDouble()
{
	vector<double> testDoubles;
	for (int i = 0; i < 10000; i++)
	{
		double x = getRandomDouble(5, -5);
		testDoubles.push_back(x);
		//cout << x << ", ";
	}
	cout << endl;

	cout << "Minimum: " << *min_element(testDoubles.begin(), testDoubles.end()) << endl;
	cout << "Maximum:" << *max_element(testDoubles.begin(), testDoubles.end()) << endl;
}

void TestMultipleSolutions()
{
	HarmonySearch testSearch(2, 100, 0.45, 0.10, 0.5, 20000);

	vector<VariableConstraints> testConstr;
	HarmonyMemoryRow solution;

	testConstr.push_back(VariableConstraints(0, 1));
	testConstr.push_back(VariableConstraints(0, 1));
	solution = testSearch.Search(testConstr);
	cout << "Solution 1: ";
	solution.printRowWithNames();

	testConstr.clear();

	testConstr.push_back(VariableConstraints(0, 1));
	testConstr.push_back(VariableConstraints(-1, 0));
	solution = testSearch.Search(testConstr);
	cout << "Solution 2: ";
	solution.printRowWithNames();

	testConstr.clear();

	testConstr.push_back(VariableConstraints(-1, 0));
	testConstr.push_back(VariableConstraints(0, 1));
	solution = testSearch.Search(testConstr);
	cout << "Solution 3: ";
	solution.printRowWithNames();

	testConstr.clear();

	testConstr.push_back(VariableConstraints(-1, 0));
	testConstr.push_back(VariableConstraints(-1, 0));
	solution = testSearch.Search(testConstr);
	cout << "Solution 4: ";
	solution.printRowWithNames();
}

void TestSpecialExpressionParsing()
{
	SpecialExpression testExpression;
	testExpression.setFormula("(x1+x2)");
	testExpression.setFormula("(x1(x2+x3))^3");
	testExpression.setFormula("e^(x1+x2)");
	testExpression.setFormula("exp(x1+x2)");
	testExpression.setFormula("log(2,x1+x2)");
	testExpression.setFormula("ln(x1+x2)");
	testExpression.setFormula("4^(x1+x2)");
	testExpression.setFormula("sin(x1+x2)");
	testExpression.setFormula("cos(x1+x2)");
	testExpression.setFormula("tan(x1+x2)");
	testExpression.setFormula("ctan(x1+x2)");
	testExpression.setFormula("tg(x1+x2)");
	testExpression.setFormula("ctg(x1+x2)");
	testExpression.setFormula("sinx1");
	testExpression.setFormula("e^x2");
	testExpression.setFormula("3^x4");
	testExpression.setFormula("x2^3");
}

void TestEquationPartsParsing()
{
	EquationPart testPart;
	bool testBool;
	std::string testFormula;
	
	std::vector<double> testX;
	testX.push_back(5.0);

	testFormula = "5";
	testBool = testPart.setFormula(testFormula, add);
	cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

	testFormula = "13";
	testBool = testPart.setFormula(testFormula, add);
	cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

	testFormula = "s";
	testBool = testPart.setFormula(testFormula, add);
	cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

	testFormula = "8x1";
	testBool = testPart.setFormula(testFormula, add);
	cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

	testFormula = "7sinx1";
	testBool = testPart.setFormula(testFormula, add);
	cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

	testFormula = "6*x1";
	testBool = testPart.setFormula(testFormula, add);
	cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

	testFormula = "x4";
	testBool = testPart.setFormula(testFormula, add);
	cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

	testFormula = "3*sinx1";
	testBool = testPart.setFormula(testFormula, add);
	cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

	testFormula = "x1^3";
	testBool = testPart.setFormula(testFormula, add);
	cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

	testFormula = "4x1^3";
	testBool = testPart.setFormula(testFormula, add);
	cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

	testFormula = "4x1*sinx2";
	testBool = testPart.setFormula(testFormula, add);
	cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

	testFormula = "7*x1*sinx2";
	testBool = testPart.setFormula(testFormula, add);
	cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

	testFormula = "7/x1";
	testBool = testPart.setFormula(testFormula, add);
	cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

	testFormula = "x2*sinx3";
	testPart.setFormula(testFormula,subtract);
	cout << testFormula << ": " << testPart.calculate(testX) << std::endl;
}

void TestEquationParsing()
{
	Equation testEquation;
	std::vector<double> x;

	testEquation.setEquation("+8(X1+X9) - 3SinX1");
	testEquation.setEquation("+ 8 (X1+X9) - 3 SinX1 ");
	std::cout << testEquation.calculate(x) << std::endl;

	testEquation.setEquation("5(x2+x3) + 4sinx1");
	std::cout << testEquation.calculate(x) << std::endl;
	testEquation.setEquation("-4(x5+x4) - 5sinx1");
	std::cout << testEquation.calculate(x) << std::endl;
	testEquation.setEquation("+8(x1+x9) - 3sinx1");
	std::cout << testEquation.calculate(x) << std::endl;
}
