#include <iostream>
#include <vector>
#include <algorithm>
#include "HarmonyMemoryRow.h"
#include "HarmonySearch.h"


using namespace std;

int main()
{
	cout << "Hello world?" << endl;

	double testX[] = { 16, 2, 77, 29 };
	vector<double> vTestX(testX, testX + 4);

	HarmonyMemoryRow testRow(vTestX);
	testRow.printRowWithNames();

	HarmonySearch testSearch(3, 10, 0.45, 0.10, 0.5, 20000);
	testSearch.Search();
	testSearch.printHM();

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