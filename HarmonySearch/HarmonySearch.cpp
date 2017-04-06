#include "HarmonySearch.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>

// TODO: Zmieni� na wektor czy zostawi� jako list�? (Mo�e zrobi� jaki� test jak si� dzia�anie por�wnuje)

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
}

HarmonySearch::~HarmonySearch()
{
}

void HarmonySearch::InitializeHM(std::vector<VariableConstraints> &constraints)
{
	for (unsigned int i = 0; i < HMSize; i++)
	{
		std::vector<double> x;
		std::vector<VariableConstraints>::iterator constrainIt = constraints.begin();

		for (unsigned int j = 0; j < variableCount; j++, constrainIt++)
		{
			x.push_back(this->getRandomDouble(constrainIt->getMin(), constrainIt->getMax()));
		}

		HarmonyMemory.push_back(HarmonyMemoryRow(x));
	}

	// Posortowanie pami�ci
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

HarmonyMemoryRow HarmonySearch::Search(std::vector<VariableConstraints> &constraints)
{
	HarmonyMemory.clear();

	this->InitializeHM(constraints);

	for (unsigned int i = 0; i < NumberOfImprovisations; i++)
	{
		HarmonyMemoryRow newSolution(this->createNewSolution(constraints));

		if (isSolutionBetter(newSolution, HarmonyMemory.back()))
		{
			HarmonyMemory.pop_back();
			this->insertNewSolution(newSolution);
		}
	}
	return HarmonyMemory.front();
}

bool HarmonySearch::isSolutionBetter(HarmonyMemoryRow &solution1, HarmonyMemoryRow &solution2)
{
	return solution1.getObjectiveFunction() < solution2.getObjectiveFunction();
}

void HarmonySearch::insertNewSolution(HarmonyMemoryRow &newSolution)
{
	for (std::list<HarmonyMemoryRow>::iterator it = HarmonyMemory.begin(); it != HarmonyMemory.end(); it++)
	{
		if (isSolutionBetter(newSolution, *it))
		{
			HarmonyMemory.insert(it, newSolution);
			return;
		}
	}
	HarmonyMemory.push_back(newSolution);
}

double HarmonySearch::getXFromMemory(unsigned int variableIndex)
{
	int index = this->getRandomInt(0, HMSize - 1); //TODO: Przetestowa�?

	std::list<HarmonyMemoryRow>::iterator it = HarmonyMemory.begin();
	for (int k = 0; k < index; k++)
		it++;

	return it->getX(variableIndex + 1);
}

std::vector<double> HarmonySearch::createNewSolution(std::vector<VariableConstraints> &constraints)
{
	std::vector<double> x;
	std::vector<VariableConstraints>::iterator constrainIt = constraints.begin();

	for (unsigned int j = 0; j < variableCount; j++, constrainIt++)
	{
		double p = this->getRandomDouble(0, 1); // Prawdopodobie�stwo wzi�cia warto�ci z pami�ci
		double value;

		if (p <= HMConsiderationRate) // Wybierz warto�� z pami�ci
		{
			value = this->getXFromMemory(j);

			// Modyfikacja warto�ci
			double p1 = this->getRandomDouble(0, 1); // Prawdopodobie�stwo zmiany warto�ci

			if (p1 <= PitchAdjustmentRate)
			{
				double alpha = b * this->getRandomDouble(-1, 1);
				//value += alpha;
				value = std::min(std::max(constrainIt->getMin(), value + alpha), constrainIt->getMax());
			}
		}
		else // Wygeneruj losow� warto��
		{
			value = this->getRandomDouble(constrainIt->getMin(), constrainIt->getMax());
		}

		x.push_back(value);
	}
	return x;
}

double HarmonySearch::getRandomDouble(double min, double max)
{
	return ((double)rand() / RAND_MAX) * (max - min) + min;
}

int HarmonySearch::getRandomInt(int min, int max)
{
	return rand() % (max - min) + min;
}