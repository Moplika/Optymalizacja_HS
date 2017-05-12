#pragma once
#include <vector>
#include <string>

class HarmonyMemoryRow
{
private:
	unsigned int N; // Liczba zmiennych w równaniu

	std::vector<double> row;


public:
	//HarmonyMemoryRow(unsigned int _N);
	HarmonyMemoryRow(std::vector<double> x);
	HarmonyMemoryRow();
	~HarmonyMemoryRow();

	bool Initialize(unsigned int _N, std::vector<double> _x);

	double getX(unsigned int index) const;
	double getObjectiveFunction() const;
    unsigned int getVariableCount() const { return N; }

	bool setX(unsigned int index, double value);
	void setObjectiveFunction(double value);

	void printRowWithNames();
	void printRowTable();

	//bool compare(HarmonyMemoryRow &first, HarmonyMemoryRow &second);

private:
	double calculateObjectiveFunction();

};

bool compareRows(HarmonyMemoryRow &first, HarmonyMemoryRow &second);
