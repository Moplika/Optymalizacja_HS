#include <iostream>
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

	HarmonySearch testSearch(3, 10, 0.45, 0.25, 0.5, 20000);
	testSearch.printHM();

	system("PAUSE");
	return 0;
}