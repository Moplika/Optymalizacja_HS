#include <iostream>
#include <vector>
#include <algorithm>
#include "HarmonyMemoryRow.h"
#include "HarmonySearch.h"
#include "VariableConstraints.h"
#include "Expression.h"
#include "SimpleExpression.h"
#include "SpecialExpression.h"

using namespace std;

void TestRandomDouble();
void TestMultipleSolutions();

int main()
{
	cout << "Hello world?" << endl;

	/*double testX[] = { 16, 2, 77, 29 };
	vector<double> vTestX(testX, testX + 4);

	HarmonyMemoryRow testRow(vTestX);
	testRow.printRowWithNames();*/

	//TestMultipleSolutions();

	SpecialExpression testExpression;
	testExpression.setFormula("exp(x1+x2)");
	testExpression.setFormula("ln(x1+x2)");
	testExpression.setFormula("log(x1+x2)");
	testExpression.setFormula("sin(x1+x2)");
	testExpression.setFormula("cos(x1+x2)");
	testExpression.setFormula("tan(x1+x2)");
	testExpression.setFormula("tg(x1+x2)");
	testExpression.setFormula("ctan(x1+x2)");
	testExpression.setFormula("ctg(x1+x2)");

	system("PAUSE");
	return 0;
}

double getRandomDouble(double min, double max)
{
	return ((double)rand() / RAND_MAX) * (max - min) + min;
}

// TODO: Przenieœæ do jakiegoœ innego pliku
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

