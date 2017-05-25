#pragma once

#include "HarmonyMemoryRow.h"
#include "VariableConstraints.h"
#include "Equation.h"

#include <list>
#include <string>

class HarmonySearch
{
public:
    HarmonySearch();
    ~HarmonySearch();

    bool setParameters(std::string equationFormula, unsigned int HMS, double HMCR, double PAR, double b, unsigned int NI);
    void initializeHM(std::vector<VariableConstraints> &constraints);

    HarmonyMemoryRow search(std::vector<VariableConstraints> &constraints);
    HarmonyMemoryRow getOptimalSolution();

    void singleIteration(std::vector<VariableConstraints> &constraints, HarmonyMemoryRow &generatedSolution, int &solutionPosition);

    void printHM();
    std::list<HarmonyMemoryRow> getHarmonyMemory();

    Equation equation;

private:
	unsigned int HMSize;						// HM Size - rozmiar pamięci harmonii
	double HMConsiderationRate;					// HM Consideration Rate - prawd. wyboru elementu z HM; [0,1]
	double PitchAdjustmentRate;					// Pitch Adjustment Ratio - współczynnik dostosowania wybranej zmiennej; [0,1]
	double b;									// Zakres zmiany wartości x
	unsigned int NumberOfImprovisations;		// Number of improvisations - dopuszczalna liczba iteracji

	// TEMP? Zmienne i ograniczenia do równania
	unsigned int variableCount;		// Liczba zmiennych w równaniu



    std::list<HarmonyMemoryRow> harmonyMemory;



	double getRandomDouble(double min, double max);
	int getRandomInt(int min, int max);
	double getXFromMemory(unsigned int variableIndex);
	std::vector<double> createNewSolution(std::vector<VariableConstraints> &constraints);
	bool isSolutionBetter(HarmonyMemoryRow &solution1, HarmonyMemoryRow &solution2);
    int insertNewSolution(HarmonyMemoryRow &solution);
};

