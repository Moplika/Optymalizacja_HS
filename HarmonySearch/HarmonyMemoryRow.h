#pragma once

#include "Equation.h"

#include <vector>
#include <string>

class HarmonyMemoryRow
{
private:
	unsigned int N; // Liczba zmiennych w równaniu

	std::vector<double> row;


public:
	//HarmonyMemoryRow(unsigned int _N);
    HarmonyMemoryRow(std::vector<double> x, Equation equation);
	HarmonyMemoryRow();
    HarmonyMemoryRow(const HarmonyMemoryRow &harmonyMemoryRow);
	~HarmonyMemoryRow();

    bool Initialize(unsigned int _N, std::vector<double> _x, Equation equation);

	double getX(unsigned int index) const;
    std::vector<double> getAllX() const;
    bool setX(unsigned int index, double value);

    void setObjectiveFunction(double value);
    double getObjectiveFunction() const;

    unsigned int getVariableCount() const { return N; }

	void printRowWithNames();
	void printRowTable();

	//bool compare(HarmonyMemoryRow &first, HarmonyMemoryRow &second);

private:
    double calculateObjectiveFunction(Equation equation);

};

bool compareRows(HarmonyMemoryRow &first, HarmonyMemoryRow &second);
