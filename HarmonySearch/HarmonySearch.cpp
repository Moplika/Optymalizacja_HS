#include "HarmonySearch.h"
#include <cstdlib>
#include <iostream>


HarmonySearch::HarmonySearch(unsigned int N, unsigned int _HMS, double _HMCR, double _PAR, double _b, unsigned int _NI)
{
	// TODO: Dorobi� sprawdzanie, czy warto�ci parametr�w s� poprawne

	// Przepisanie parametr�w
	HMSize = _HMS;
	HMConsiderationRate = _HMCR;
	PitchAdjustmentRate = _PAR;
	b = _b;
	NumberOfImprovisations = _NI;
	variableCount = N;

	// Utworzenie pami�ci harmony (HM)
	this->InitializeHM();
}


HarmonySearch::~HarmonySearch()
{
}

void HarmonySearch::InitializeHM()
{
	for (unsigned int i = 0; i < HMSize; i++)
	{
		std::vector<double> x;

		for (int j = 0; j < variableCount; j++)
		{
			// TODO: Aktualnie wybiera w zakresie 0-RAND_MAX, zrobi� �eby bra�o pod uwag� ograniczenia (z tablicy)
			x.push_back(rand());
		}

		HarmonyMemory.push_back(HarmonyMemoryRow(x));
	}
}

void HarmonySearch::printHM()
{
	int i = 1;
	for (std::list<HarmonyMemoryRow>::iterator it = HarmonyMemory.begin(); it != HarmonyMemory.end(); it++, i++)
	{
		std::cout << i << ": ";
		it->printRowTable();
	}
}