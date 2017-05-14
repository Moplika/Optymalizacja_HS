#include "HarmonySearch.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>

// TODO: Zmienić na wektor czy zostawić jako listę? (Może zrobić jakiś test jak się działanie porównuje)

//HarmonySearch::HarmonySearch(unsigned int N, unsigned int _HMS, double _HMCR, double _PAR, double _b, unsigned int _NI)
//{
//	// TODO: Dorobić sprawdzanie, czy wartości parametrów są poprawne

//	// Przepisanie parametrów
//	HMSize = _HMS;
//	HMConsiderationRate = _HMCR;
//	PitchAdjustmentRate = _PAR;
//	b = _b;
//	NumberOfImprovisations = _NI;
//	variableCount = N;
//}

HarmonySearch::HarmonySearch()
{

}

HarmonySearch::~HarmonySearch()
{
}

bool HarmonySearch::setParameters(std::string equationFormula, unsigned int HMS, double HMCR, double PAR, double b, unsigned int NI)
{
    // Odkomentować po napisaniu parsera
//    bool isEquationOk = equation.setEquation(equationFormula, variableCount);

//    if (!isEquationOk)
//    {
//        return false;
//    }

    HMSize = HMS;
    HMConsiderationRate = HMCR;
    PitchAdjustmentRate = PAR;
    b = b;
    NumberOfImprovisations = NI;

    // TEMP
    variableCount = 2;

    return true;
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

	// Posortowanie pamięci
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
	int index = this->getRandomInt(0, HMSize - 1); //TODO: Przetestować?

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
		double p = this->getRandomDouble(0, 1); // Prawdopodobieństwo wzięcia wartości z pamięci
		double value;

		if (p <= HMConsiderationRate) // Wybierz wartość z pamięci
		{
			value = this->getXFromMemory(j);

			// Modyfikacja wartości
			double p1 = this->getRandomDouble(0, 1); // Prawdopodobieństwo zmiany wartości

			if (p1 <= PitchAdjustmentRate)
			{
				double alpha = b * this->getRandomDouble(-1, 1);
				//value += alpha;
				value = std::min(std::max(constrainIt->getMin(), value + alpha), constrainIt->getMax());
			}
		}
		else // Wygeneruj losową wartość
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
