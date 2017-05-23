#include "HarmonyMemoryRow.h"
#include <iostream>
#include <math.h>

HarmonyMemoryRow::HarmonyMemoryRow(std::vector<double> x, Equation equation)
{
	N = x.size();
	row.reserve(N + 1);

	row = x;
    row.push_back(this->calculateObjectiveFunction(equation));
}

HarmonyMemoryRow::HarmonyMemoryRow()
{
}

HarmonyMemoryRow::HarmonyMemoryRow(const HarmonyMemoryRow &harmonyMemoryRow)
{
    this->row.assign(harmonyMemoryRow.row.begin(), harmonyMemoryRow.row.end());
    this->N = harmonyMemoryRow.N;
}

HarmonyMemoryRow::~HarmonyMemoryRow()
{
}

bool HarmonyMemoryRow::Initialize(unsigned int _N, std::vector<double> _x, Equation equation)
{
	if (_x.size() != _N)
		return false;

	N = _N;
	row.reserve(N + 1);

	row = _x;
    row.push_back(this->calculateObjectiveFunction(equation));

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

double HarmonyMemoryRow::calculateObjectiveFunction(Equation equation)
{
	// TEMP: Tu wpisywać wzór funkcji; x1 = row[0] itp
	//return ((double)rand() / RAND_MAX) * (10 + 10) - 10;
	//double fx = -abs(row[0] + row[1] + row[2]);
//    double fx = pow(row[0], 4) + pow(row[1], 4) - 0.62 * pow(row[0], 2) - 0.62 * pow(row[1], 2);
	//double fx = row[0] * row[0] - 4*row[1];
    std::vector<double> x(row.begin(), row.begin()+N);
    double fx = equation.calculate(x);

	return fx;
}

std::vector<double> HarmonyMemoryRow::getAllX() const
{
    std::vector<double> x(row.begin(), row.begin() + N);
    return x;
}

double HarmonyMemoryRow::getX(unsigned int index) const
{
	if (index <= N)
		return row[index - 1];

	return INT_MIN;
}

double HarmonyMemoryRow::getObjectiveFunction() const
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

bool compareRows(HarmonyMemoryRow &first, HarmonyMemoryRow &second)
{
	return (first.getObjectiveFunction() < second.getObjectiveFunction());
}
