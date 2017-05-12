#include "uihandler.h"

#include <QDebug>


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

std::string UIHandler::getEquation() const
{
    return _equation;
}

void UIHandler::setEquation(std::string equation)
{
    _equation = equation;
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
