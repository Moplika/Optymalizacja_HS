#pragma once

#include "SpecialExpression.h"

#include <string>
#include <vector>

class SpecialExpression;

class Argument
{
public:
    Argument();
    Argument(std::string formula);
    ~Argument();

    bool setFormula(std::string formula);
    std::string getFormula() const;

    double calculate(std::vector<double> x);


private:
    std::string formula;

    SpecialExpression *specialExpression;
};

