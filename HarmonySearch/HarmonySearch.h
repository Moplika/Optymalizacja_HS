#pragma once

#include <list>
#include "HarmonyMemoryRow.h"

class HarmonySearch
{
private:
	unsigned int HMSize;						// HM Size - rozmiar pami�ci harmonii
	double HMConsiderationRate;					// HM Consideration Rate - prawd. wyboru elementu z HM; [0,1]
	double PitchAdjustmentRate;					// Pitch Adjustment Ratio - wsp�czynnik dostosowania wybranej zmiennej; [0,1]
	double b;									// Zakres zmiany warto�ci x
	unsigned int NumberOfImprovisations;		// Number of improvisations - dopuszczalna liczba iteracji

	// TEMP? Zmienne i ograniczenia do r�wnania
	unsigned int variableCount;		// Liczba zmiennych w r�wnaniu


	std::list<HarmonyMemoryRow> HarmonyMemory;


public:
	HarmonySearch(unsigned int N, unsigned int HMS, double HMCR, double PAR, double b, unsigned int NI);
	~HarmonySearch();

	void printHM();

private:
	void InitializeHM();
};

