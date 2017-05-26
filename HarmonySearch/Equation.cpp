#include "Equation.h"

#include <QDebug>

#include <iostream>
#include <algorithm>
#include <cctype>

// Pierwiastek wyższego stopnia dla parsera
double root(double stopien, double argument)
{
    return pow(argument, 1.0/stopien);
}

Equation::Equation()
{
    equationFormula = "";
    variableCount = 0;
}

Equation::~Equation()
{
}

bool Equation::setEquation(std::string equation, unsigned int &N)
{
    this->clearVariables();

    equationFormula = equation;
    // Zmiana na same małe litery
    std::transform(equationFormula.begin(), equationFormula.end(), equationFormula.begin(), ::tolower);

    // Usunięcie spacji
    std::string::iterator endAfterRemoval = std::remove_if(equationFormula.begin(), equationFormula.end(), ::isspace);
    equationFormula.erase(endAfterRemoval, equationFormula.end());

    variableCount = this->countXs();
    N = variableCount;

    return this->parseEquation();
}

std::string Equation::getEquation()
{
    return equationFormula;
}

bool Equation::parseEquation()
{
    fValues.assign(variableCount, 0.0);

    for (int i = 1; i <= variableCount; i++)//, it++ )
    {
        std::string xName = "x" + std::to_string(i);
        parser.DefineVar(xName, &(fValues.at(i-1)));
    }
    parser.DefineFun("root", root);
    parser.SetExpr(equationFormula);

    // Sprawdzenie, czy formuła jest poprawna
    try
    {
        parser.Eval();
    }
    catch (mu::Parser::exception_type &e)
    {
        std::cerr << e.GetMsg() << std::endl;
        return false;
    }

    return true;
}

double Equation::calculate(std::vector<double> x)
{
    double result = 0;

    // Musi tu być, bo inaczej nie liczy poprawnie
    this->parseEquation();

    std::vector<double>::iterator xIt = x.begin();

    for (std::vector<double>::iterator it = fValues.begin(); it != fValues.end();
         it++, xIt++)
    {
        *it = *xIt;
    }

    try
    {
        //        result = pow(x.at(0), 4) + pow(x.at(1), 4) - 0.62 * pow(x.at(0), 2) - 0.62 * pow(x.at(1), 2);
        result = parser.Eval();
    }
    catch (mu::Parser::exception_type &e)
    {
        std::cout << e.GetMsg() << std::endl;
    }

    return result;
}

void Equation::clearVariables()
{
    equationFormula = "";
    variableCount = 0;
    parser.ClearConst();
    parser.ClearVar();
}

int Equation::countXs()
{
    std::string tempFormula = equationFormula;
    int maxX = 0;

    while (!tempFormula.empty())
    {
        std::size_t xPosition = tempFormula.find("x");

        if (xPosition == std::string::npos)
        {
            break;
        }
        tempFormula = tempFormula.substr(xPosition+1);

        std::size_t firstNotNumberPosition = tempFormula.find_first_not_of("0123456789");

        if (firstNotNumberPosition == 0)
        {
            if (tempFormula.at(firstNotNumberPosition) == 'p')
            {
                continue;
            }
            return 0;
        }

        std::string indexStr = tempFormula.substr(0, firstNotNumberPosition);
        int index = std::stoi(indexStr);
        maxX = std::max(maxX, index);
    }

    return maxX;
}
