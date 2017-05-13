#include "uihandler.h"

#include <QDebug>

#include <math.h>


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
        return;
    }

    constraintsPair.xIndex = index;
    constraintsPair.min = min;
    constraintsPair.max = max;

    qDebug() << "index: " << index << ", min: " << min << ", max: " << max;

    _readConstraints.push_back(constraintsPair);
}

void UIHandler::rewriteConstraints()
{
    if (_readConstraints.size() < _N)
    {
        emit notEnoughConstraints();
        _readConstraints.clear();
        return;
    }

    if (_readConstraints.size() > _N)
    {
        emit tooManyConstraints();
    }


    emit constraintsOk();
    _readConstraints.clear();
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
}

void UIHandler::startCalculations()
{
    this->printParmeters();
}


