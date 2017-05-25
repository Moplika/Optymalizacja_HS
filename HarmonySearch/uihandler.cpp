#include "uihandler.h"
#include "HarmonySearch.h"
#include "HarmonyMemoryRow.h"

#include <QDebug>

#include <math.h>
#include <algorithm>
#include <iostream>

UIHandler::UIHandler(QObject *parent) : QObject(parent)
{

}

void UIHandler::initialize()
{
    HMS = 0;
    HMCR = 0;
    PAR = 0;
    NI = 0;
    doShowIter = false;
    iterationsNb = 0;

    equation = "";

    areAllConstraintsRead = true;
    isEquationCorrect = false;

    // TEMP
    //    _N = 2;
    //    isEquationCorrect = true;
}

int UIHandler::getHMS() const
{
    return HMS;
}

void UIHandler::setHMS(int _HMS)
{
    if (_HMS == 0)
    {
        emit parametersWrong();
        return;
    }
    HMS = _HMS;
}

double UIHandler::getHMCR() const
{
    return HMCR;
}

void UIHandler::setHMCR(double _HMCR)
{
    HMCR = _HMCR;
}

double UIHandler::getPAR() const
{
    return PAR;
}

void UIHandler::setPAR(double _PAR)
{
    PAR = _PAR;
}

int UIHandler::getNI() const
{
    return NI;
}

void UIHandler::setNI(int _NI)
{
    if (_NI == 0)
    {
        emit parametersWrong();
        return;
    }
    NI = _NI;
}

bool UIHandler::doShowIterations() const
{
    return doShowIter;
}

void UIHandler::setShowIterations(bool _doShow)
{
    doShowIter = _doShow;
}

int UIHandler::getIterationNb() const
{
    return iterationsNb;
}

void UIHandler::setIterationNb(int _iterationsNb)
{
    if (_iterationsNb == 0)
    {
        emit parametersWrong();
        return;
    }
    iterationsNb = _iterationsNb;
}

int UIHandler::getN() const
{
    return N;
}

void UIHandler::setN(int _N)
{
    N = _N;
}

std::string UIHandler::getEquation() const
{
    return equation;
}

void UIHandler::setEquation(std::string _equation)
{
    equation = _equation;
}

void UIHandler::setEquation(QString _equation)
{
    equation = _equation.toStdString();

    bool isEquiationOk = harmonySearch.equation.setEquation(equation, N);
    if (!isEquiationOk)
    {
        isEquationCorrect = false;
        emit equationWrong();
        return;
    }

    isEquationCorrect = true;
    emit equationOk();
}

std::vector<VariableConstraints> UIHandler::getConstraints() const
{
    return constraints;
}

void UIHandler::setConstraints(std::vector<VariableConstraints> _constraints)
{
    constraints = _constraints;
}

void UIHandler::readSingleConstraint(int index, double min, double max)
{
    ReadConstraints constraintsPair;

    if ( min >= max || std::isnan(min) || std::isnan(max) )
    {
        emit constraintsWrong();
        areAllConstraintsRead = false;
        return;
    }

    constraintsPair.xIndex = index;
    constraintsPair.min = min;
    constraintsPair.max = max;

    qDebug() << "index: " << index << ", min: " << min << ", max: " << max;

    readConstraints.push_back(constraintsPair);
}

double UIHandler::getMinimum(int index)
{
    VariableConstraints costraint = constraints.at(index-1);
    return costraint.getMin();
}

double UIHandler::getMaximum(int index)
{
    VariableConstraints costraint = constraints.at(index-1);
    return costraint.getMax();
}

void UIHandler::clearReadConstraints()
{
    readConstraints.clear();
    areAllConstraintsRead = true;
}

void UIHandler::rewriteConstraints()
{
    constraints.clear();
    areConstraintsSet = false;

    if (!areAllConstraintsRead)
    {
        this->clearReadConstraints();
        return;
    }

    if (readConstraints.size() < N)
    {
        emit notEnoughConstraints();
        this->clearReadConstraints();
        return;
    }

    if (readConstraints.size() > N)
    {
        emit tooManyConstraints();
    }
    else
    {
        emit constraintsOk();
    }

    std::sort(readConstraints.begin(), readConstraints.end(), compareReadConstraints);

    // Sprawdzenie, czy xy są po kolei
    int testX = 1;

    for (std::vector<ReadConstraints>::iterator it = readConstraints.begin();
         it != readConstraints.end(); it++, testX++)
    {
        if ((unsigned int)testX > N)
            break;

        if (testX != it->xIndex)
        {
            emit constraintsWrong();
            this->clearReadConstraints();
            return;
        }
    }

    // Przepisanie na prawdziwe wartości
    for (std::vector<ReadConstraints>::iterator it = readConstraints.begin();
         it != readConstraints.begin() + N; it++)
    {
        VariableConstraints newConstraint(it->min, it->max);
        constraints.push_back(newConstraint);
    }

    areConstraintsSet = true;
    this->clearReadConstraints();
}

void UIHandler::printParmeters()
{
    qDebug() << "Equation: " << equation.c_str();
    qDebug() << "HM Size: " << HMS;
    qDebug() << "HMCR: " << HMCR;
    qDebug() << "PAR: " << PAR;
    qDebug() << "NI: " << NI;

    if (doShowIter)
        qDebug() << "Iterations will be shown";
    else
        qDebug() << "Iterations won't be shown";

    qDebug() << "Every" << iterationsNb << "th iteration will be shown.";

    qDebug() << "Ograniczenia na X:";

    int i = 1;
    for (std::vector<VariableConstraints>::iterator it = constraints.begin();
         it != constraints.end(); it++, i++)
    {
        qDebug() << "X:" << i << "min:" << it->getMin() << "max:" << it->getMax();
    }
}

void UIHandler::clearParameters()
{
    HMS = 0;
    HMCR = 0;
    PAR = 0;
    NI = 0;
    doShowIter = false;
    iterationsNb = 0;
}

void UIHandler::startCalculations()
{
    // DEBUG
    this->printParmeters();

    if (!areParametersOk())
        return;

    emit parametersOk();

    bool hsState = harmonySearch.setParameters(equation, HMS, HMCR, PAR, 0.5, NI);

    if (!hsState)
    {
        return;
    }

    if (!doShowIter)
    {
        this->completeSearch();
    }
    else
    {
        this->searchByIteration();
    }
}

QString UIHandler::fxToString(HarmonyMemoryRow row)
{
    return QString::number(row.getObjectiveFunction(), 'f', 6);
}

QList<QString> UIHandler::xToStringList(HarmonyMemoryRow row)
{
    QList<QString> xList;
    std::vector<double> x = row.getAllX();

    for (std::vector<double>::iterator it = x.begin(); it != x.end(); it++)
    {
        xList.push_back(QString::number(*it, 'f', 6));
    }

    return xList;
}

void UIHandler::completeSearch()
{
    emit calculationsStarted();

    HarmonyMemoryRow result = harmonySearch.search(constraints);
    std::cout << "Result: ";
    result.printRowWithNames();

    QList<QString> xList = this->xToStringList(result);
    QString fx = this->fxToString(result);

    emit calculationsFinished();
    emit showResult(N, fx, xList);
}

void UIHandler::searchByIteration()
{
    emit startShowingIterations();
    globalIteration = 0;

    harmonySearch.initializeHM(constraints);

    HarmonyMemoryRow optimalSolution = harmonySearch.getOptimalSolution();

    QString optimalFx = this->fxToString(optimalSolution);
    QList<QString> optimalX = this->xToStringList(optimalSolution);

    QString currentFx = QString("-");
    QList<QString> currentX;
    for (unsigned int i = 0; i < N; i++)
    {
        currentX.push_back(QString("-"));
    }

    emit showIteration(globalIteration, optimalFx, optimalX, currentFx, currentX, -1);
}

bool UIHandler::compareReadConstraints(ReadConstraints first, ReadConstraints second)
{
    return first.xIndex < second.xIndex;
}

bool UIHandler::areParametersOk()
{
    if (HMS == 0)
        return false;
    if (HMCR == 0)
        return false;
    if (PAR == 0)
        return false;
    if (NI == 0)
        return false;
    if (iterationsNb == 0)
        return false;
    if (!isEquationCorrect)
        return false;
    if (!areConstraintsSet)
    {
        emit notEnoughConstraints();
        return false;
    }

    return true;
}

void UIHandler::printHarmonyMemory()
{
    std::list<HarmonyMemoryRow> HarmonyMemory;
    HarmonyMemory = harmonySearch.getHarmonyMemory();

    QList<QString> rowValues;
    int id = 1;

    for (std::list<HarmonyMemoryRow>::iterator it = HarmonyMemory.begin();
         it != HarmonyMemory.end(); it++, id++)
    {
        rowValues.clear();

        rowValues = this->xToStringList(*it);
        QString fx = this->fxToString(*it);
        rowValues.push_front(fx);

        emit showHarmonyMemoryRow(id, rowValues);
    }

}

void UIHandler::drawSurfaceGraph(double minX1, double maxX1, double minX2, double maxX2)
{
    QList<QString> graphPoint;

    double stepX1 = (maxX1 - minX1) / 50;
    double stepX2 = (maxX2 - minX2) / 50;

    // TEMP
    for (double x1 = minX1; x1 <= maxX1+stepX1; x1 += stepX1)
    {
        for (double x2 = minX2; x2 <= maxX2+stepX2; x2 += stepX2)
        {
            graphPoint.clear();

//            qDebug() << "(" << x1 << ", " << x2 << ")";

            std::vector<double> x;
            x.push_back(x1);
            x.push_back(x2);

            double y = harmonySearch.equation.calculate(x);

            graphPoint.push_back(QString::number(x1));
            graphPoint.push_back(QString::number(x2));
            graphPoint.push_back(QString::number(y));

            emit drawSurfaceGraphPoint(graphPoint);
        }
    }
    emit drawingFinished();
}

void UIHandler::nextIteration()
{
    HarmonyMemoryRow generatedSolution;
    int solutionPosition = -1;

    for (int i = 0; i < iterationsNb; i++)
    {
        globalIteration++;
        if (globalIteration > NI)
        {
            this->showIterationInUI(generatedSolution, solutionPosition, true);
            return;
        }

        harmonySearch.singleIteration(constraints, generatedSolution, solutionPosition);
    }

      this->showIterationInUI(generatedSolution, solutionPosition, false);
}

void UIHandler::finishIterating()
{
    int solutionPosition = 0;
    HarmonyMemoryRow generatedSolution;

    for (; globalIteration < NI; globalIteration++)
    {
        harmonySearch.singleIteration(constraints, generatedSolution, solutionPosition);
    }

    this->showIterationInUI(generatedSolution, solutionPosition, true);
}

void UIHandler::showIterationInUI(HarmonyMemoryRow generatedSolution, int solutionPosition, bool isFinal)
{
    HarmonyMemoryRow optimalSolution = harmonySearch.getOptimalSolution();

    QString optimalFx = this->fxToString(optimalSolution);
    QList<QString> optimalX = this->xToStringList(optimalSolution);

    QString currentFx = this->fxToString(generatedSolution);
    QList<QString> currentX = this->xToStringList(generatedSolution);

    emit showIteration(globalIteration, optimalFx, optimalX, currentFx, currentX, solutionPosition);

    if (isFinal)
    {
        emit showResult(N, optimalFx, optimalX);
    }
}
