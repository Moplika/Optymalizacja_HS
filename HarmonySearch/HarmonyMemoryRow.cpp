#include "HarmonyMemoryRow.h"
#include <iostream>


//HarmonyMemoryRow::HarmonyMemoryRow(unsigned int _N)
//{
//	N = _N;
//	row.reserve(N);
//}
//
HarmonyMemoryRow::HarmonyMemoryRow(std::vector<double> x)
{
	N = x.size();
	row.reserve(N + 1);

	row = x;
	row.push_back(this->calculateObjectiveFunction());
}

HarmonyMemoryRow::HarmonyMemoryRow()
{
}

HarmonyMemoryRow::~HarmonyMemoryRow()
{
}

bool HarmonyMemoryRow::Initialize(unsigned int _N, std::vector<double> _x)
{
	if (_x.size() != _N)
		return false;

	N = _N;
	row.reserve(N + 1);

	row = _x;
	row.push_back(this->calculateObjectiveFunction());

	return true;
}

void HarmonyMemoryRow::printRowWithNames()
{
	//cout << "X1: " << testRow.getX(1) << "; X2: " << testRow.getX(2) << "; X3: " << testRow.getX(3) << "; X4: " << testRow.getX(4) << "; fx: " << testRow.getObjectiveFunction() << endl;
	int i = 1;
	for (std::vector<double>::iterator it = row.begin(); it < row.end() - 1; it++, i++)
	{
		std::cout << "X" << i << ": " << *it << "; ";
	}
	std::cout << "fx: " << row.back() << std::endl;

}

void HarmonyMemoryRow::printRowTable()
{
	for (std::vector<double>::iterator it = row.begin(); it < row.end() - 1; it++)
	{
		std::cout << "| " << *it << " ";
	}
	std::cout << "| " << row.back() << std::endl;
}

double HarmonyMemoryRow::calculateObjectiveFunction()
{
	// TEMP: Tu wpisywaæ wzór funkcji; x1 = row[0] itp
	return 2.0;
}

double HarmonyMemoryRow::getX(unsigned int index)
{
	if (index <= N)
		return row[index - 1];

	return INT_MIN;
}

double HarmonyMemoryRow::getObjectiveFunction()
{
	return row[N];
}

bool HarmonyMemoryRow::setX(unsigned int index, double value)
{
	if (index > N)
		return false;

	row[index - 1] = value;
	return true;
}



void HarmonyMemoryRow::setObjectiveFunction(double value)
{
	row[N] = value;
}