#include "HarmonySearch.h"
#include <cstdlib>
#include <iostream>

// TODO: Zmieniæ na wektor czy zostawiæ jako listê? (Mo¿e zrobiæ jakiœ test jak siê dzia³anie porównuje)

HarmonySearch::HarmonySearch(unsigned int N, unsigned int _HMS, double _HMCR, double _PAR, double _b, unsigned int _NI)
{
	// TODO: Dorobiæ sprawdzanie, czy wartoœci parametrów s¹ poprawne

	// Przepisanie parametrów
	HMSize = _HMS;
	HMConsiderationRate = _HMCR;
	PitchAdjustmentRate = _PAR;
	b = _b;
	NumberOfImprovisations = _NI;
	variableCount = N;

	// Utworzenie pamiêci harmony (HM)
	//this->InitializeHM();
}

HarmonySearch::~HarmonySearch()
{
}

void HarmonySearch::InitializeHM()
{
	for (unsigned int i = 0; i < HMSize; i++)
	{
		std::vector<double> x;
		
		for (unsigned int j = 0; j < variableCount; j++)
		{
			// TODO: Aktualnie wybiera w zakresie 0-1, zrobiæ ¿eby bra³o pod uwagê ograniczenia (z tablicy)
			x.push_back(this->getRandomDouble(0,1));
		}

		HarmonyMemory.push_back(HarmonyMemoryRow(x));
	}

	// Posortowanie pamiêci
	HarmonyMemory.sort(compareRows);
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

void HarmonySearch::Search()
{
	this->InitializeHM();

	for (unsigned int i = 0; i < NumberOfImprovisations; i++)
	{
		std::vector<double> x;

		for (unsigned int j = 0; j < variableCount; j++)
		{
			double p = this->getRandomDouble(0, 1); // Prawdopodobieñstwo wziêcia wartoœci z pamiêci
			double value;


			if (p <= HMConsiderationRate) // Wybierz wartoœæ z pamiêci
			{
				int index = this->getRandomInt(0, HMSize - 1); //TODO: Przetestowaæ?

				std::list<HarmonyMemoryRow>::iterator it = HarmonyMemory.begin();
				for (int k = 0; k < index; k++)
					it++;

				value = it->getX(j+1);

				// Modyfikacja wartoœci
				double p1 = this->getRandomDouble(0, 1); // Prawdopodobieñstwo zmiany wartoœci

				if (p1 <= PitchAdjustmentRate)
				{
					double alpha = b * this->getRandomDouble(-1, 1);
					value += alpha;
				}
			}
			else // Wygeneruj losow¹ wartoœæ
			{
				// TEMP - x ca³kowicie losowe + dodaæ ograniczenia
				value = this->getRandomDouble(0, 1);
			}

			x.push_back(value);
		}

		HarmonyMemoryRow newRow(x);

		// Sprawdzenie, czy rozwi¹zanie jest dobre
		if (newRow.getObjectiveFunction() < HarmonyMemory.back().getObjectiveFunction())
		{
			// Odrzuæ ostatni element
			HarmonyMemory.pop_back();

			// Wstaw now¹ harmoniê w odpowiednie miejsce
			bool wasInserted = false;
			for (std::list<HarmonyMemoryRow>::iterator it = HarmonyMemory.begin(); it != HarmonyMemory.end(); it++)
			{
				if (it->getObjectiveFunction() > newRow.getObjectiveFunction())
				{
					HarmonyMemory.insert(it, newRow);
					wasInserted = true;
					break;
				}
			}
			if (!wasInserted)
			{
				HarmonyMemory.push_back(newRow);
			}
			
		}
	}
}

double HarmonySearch::getRandomDouble(double min, double max)
{
	return ((double)rand() / RAND_MAX) * (max - min) + min;
}

int HarmonySearch::getRandomInt(int min, int max)
{
	return rand() % (max - min) + min;
}