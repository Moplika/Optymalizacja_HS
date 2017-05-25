#include "HarmonySearch.h"

#include <QDebug>

#include <cstdlib>
#include <iostream>
#include <algorithm>

// TODO: Zmienić na wektor czy zostawić jako listę? (Może zrobić jakiś test jak się działanie porównuje)

HarmonySearch::HarmonySearch()
{

}

HarmonySearch::~HarmonySearch()
{
}

bool HarmonySearch::setParameters(std::string equationFormula, unsigned int HMS, double HMCR, double PAR, double _b, unsigned int NI)
{
    bool isEquationOk = equation.setEquation(equationFormula, variableCount);

    if (!isEquationOk)
    {
        return false;
    }

    HMSize = HMS;
    HMConsiderationRate = HMCR;
    PitchAdjustmentRate = PAR;
    b = _b;
    NumberOfImprovisations = NI;

    // TEMP
//    variableCount = 2;

    return true;
}

void HarmonySearch::initializeHM(std::vector<VariableConstraints> &constraints)
{
    harmonyMemory.clear();

	for (unsigned int i = 0; i < HMSize; i++)
	{
		std::vector<double> x;
		std::vector<VariableConstraints>::iterator constrainIt = constraints.begin();

		for (unsigned int j = 0; j < variableCount; j++, constrainIt++)
		{
			x.push_back(this->getRandomDouble(constrainIt->getMin(), constrainIt->getMax()));
		}

        harmonyMemory.push_back(HarmonyMemoryRow(x, equation));
	}

	// Posortowanie pamięci
    harmonyMemory.sort(compareRows);
}

void HarmonySearch::printHM()
{
	int i = 1;
    for (std::list<HarmonyMemoryRow>::iterator it = harmonyMemory.begin(); it != harmonyMemory.end(); it++, i++)
	{
		std::cout << i << ": ";
		it->printRowTable();
	}
}

HarmonyMemoryRow HarmonySearch::search(std::vector<VariableConstraints> &constraints)
{
    this->initializeHM(constraints);

	for (unsigned int i = 0; i < NumberOfImprovisations; i++)
	{
//        HarmonyMemoryRow newSolution(this->createNewSolution(constraints), equation);

//		if (isSolutionBetter(newSolution, harmonyMemory.back()))
//		{
//			harmonyMemory.pop_back();
//			this->insertNewSolution(newSolution);
//		}
        HarmonyMemoryRow newSolution;
        int index;
        this->singleIteration(constraints, newSolution, index);
	}
    return harmonyMemory.front();
}

bool HarmonySearch::isSolutionBetter(HarmonyMemoryRow &solution1, HarmonyMemoryRow &solution2)
{
	return solution1.getObjectiveFunction() < solution2.getObjectiveFunction();
}

int HarmonySearch::insertNewSolution(HarmonyMemoryRow &newSolution)
{
    int position = 0;

    for (std::list<HarmonyMemoryRow>::iterator it = harmonyMemory.begin();
         it != harmonyMemory.end(); it++, position++)
	{
		if (isSolutionBetter(newSolution, *it))
		{
            harmonyMemory.insert(it, newSolution);
            return position;
		}
	}
    harmonyMemory.push_back(newSolution);
    return position;
}

double HarmonySearch::getXFromMemory(unsigned int variableIndex)
{
	int index = this->getRandomInt(0, HMSize - 1); //TODO: Przetestować?

    std::list<HarmonyMemoryRow>::iterator it = harmonyMemory.begin();
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

std::list<HarmonyMemoryRow> HarmonySearch::getHarmonyMemory()
{
    return harmonyMemory;
}

HarmonyMemoryRow HarmonySearch::getOptimalSolution()
{
    return harmonyMemory.front();
}

// Wygenerowane rozwiązanie jest zapisywane w generatedSolution,
// zaś w solutionPosition zapisywany jest index, gdzie zostało wpisane rozwiązanie
// jeśli nie zostało wstawione, to solutionPosition = -1
void HarmonySearch::singleIteration(std::vector<VariableConstraints> &constraints, HarmonyMemoryRow &generatedSolution, int &solutionPosition)
{
    HarmonyMemoryRow newSolution(this->createNewSolution(constraints), equation);

    int position = -1;

    if (isSolutionBetter(newSolution, harmonyMemory.back()))
    {
        harmonyMemory.pop_back();
        position = this->insertNewSolution(newSolution);
    }

    generatedSolution = newSolution;
    solutionPosition = position;
}
