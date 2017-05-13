#include "uihandler.h"

#include <QDebug>

#include <math.h>
#include <algorithm>

UIHandler::UIHandler(QObject *parent) : QObject(parent)
{

}

void UIHandler::initialize()
{
    _HMS = 0;
    _HMCR = 0;
    _PAR = 0;
    _NI = 0;
    _doShowIter = false;
    _iterationsNb = 0;

    _equation = "";

    areAllConstraintsRead = true;
    // TEMP
    _N = 4;
}

int UIHandler::getHMS() const
{
    return _HMS;
}

void UIHandler::setHMS(int HMS)
{
    _HMS = HMS;
}

double UIHandler::getHMCR() const
{
    return _HMCR;
}

void UIHandler::setHMCR(double HMCR)
{
    _HMCR = HMCR;
}

double UIHandler::getPAR() const
{
    return _PAR;
}

void UIHandler::setPAR(double PAR)
{
    _PAR = PAR;
}

int UIHandler::getNI() const
{
    return _NI;
}

void UIHandler::setNI(int NI)
{
    _NI = NI;
}

bool UIHandler::doShowIterations() const
{
    return _doShowIter;
}

void UIHandler::setShowIterations(bool doShow)
{
    _doShowIter = doShow;
}

int UIHandler::getIterationNb() const
{
    return _iterationsNb;
}

void UIHandler::setIterationNb(int iterationsNb)
{
    _iterationsNb = iterationsNb;
}

int UIHandler::getN() const
{
    return _N;
}

void UIHandler::setN(int N)
{
    _N = N;
}

std::string UIHandler::getEquation() const
{
    return _equation;
}

void UIHandler::setEquation(std::string equation)
{
    _equation = equation;
}

std::vector<VariableConstraints> UIHandler::getConstraints() const
{
    return _constraints;
}

void UIHandler::setConstraints(std::vector<VariableConstraints> constraints)
{
    _constraints = constraints;
}

void UIHandler::readSingleConstraint(int index, double min, double max)
{
    readConstraints constraintsPair;

    if ( min >= max || std::isnan(min) || std::isnan(max) )
    {
        emit wrongConstraints();
        areAllConstraintsRead = false;
        return;
    }

    constraintsPair.xIndex = index;
    constraintsPair.min = min;
    constraintsPair.max = max;

    qDebug() << "index: " << index << ", min: " << min << ", max: " << max;

    _readConstraints.push_back(constraintsPair);
}

void UIHandler::clearReadConstraints()
{
    _readConstraints.clear();
    areAllConstraintsRead = true;
}

void UIHandler::rewriteConstraints()
{
    _constraints.clear();
    areConstraintsSet = false;

    if (!areAllConstraintsRead)
    {
        this->clearReadConstraints();
        return;
    }

    if (_readConstraints.size() < _N)
    {
        emit notEnoughConstraints();
        this->clearReadConstraints();
        return;
    }

    if (_readConstraints.size() > _N)
    {
        emit tooManyConstraints();
    }
    else
    {
        emit constraintsOk();
    }

    std::sort(_readConstraints.begin(), _readConstraints.end(), compareReadConstraints);

    // Sprawdzenie, czy xy są po kolei
    int testX = 1;

    for (std::vector<readConstraints>::iterator it = _readConstraints.begin();
         it != _readConstraints.end(); it++, testX++)
    {
        if ((unsigned int)testX > _N)
            break;
        if (testX != it->xIndex)
        {
            emit wrongConstraints();
            this->clearReadConstraints();
            return;
        }
    }

    // Przepisanie na prawdziwe wartości
    for (std::vector<readConstraints>::iterator it = _readConstraints.begin();
         it != _readConstraints.begin() + _N; it++)
    {
        VariableConstraints newConstraint(it->min, it->max);
        _constraints.push_back(newConstraint);
    }

    areConstraintsSet = true;
    this->clearReadConstraints();
}

void UIHandler::printParmeters()
{
    qDebug() << "Equation: " << _equation.c_str();
    qDebug() << "HM Size: " << _HMS;
    qDebug() << "HMCR: " << _HMCR;
    qDebug() << "PAR: " << _PAR;
    qDebug() << "NI: " << _NI;

    if (_doShowIter)
        qDebug() << "Iterations will be shown";
    else
        qDebug() << "Iterations won't be shown";

    qDebug() << "Every" << _iterationsNb << "th iteration will be shown.";

    qDebug() << "Ograniczenia na X:";

    int i = 1;
    for (std::vector<VariableConstraints>::iterator it = _constraints.begin();
         it != _constraints.end(); it++, i++)
    {
        qDebug() << "X:" << i << "min:" << it->getMin() << "max:" << it->getMax();
    }
}

void UIHandler::startCalculations()
{
    this->printParmeters();
}

bool UIHandler::compareReadConstraints(readConstraints first, readConstraints second)
{
    return first.xIndex < second.xIndex;
}
