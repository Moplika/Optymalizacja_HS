#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "uihandler.h"
#include "HarmonyMemoryRow.h"
#include "HarmonySearch.h"
#include "VariableConstraints.h"
#include "Argument.h"
#include "SpecialExpression.h"
#include "EquationPart.h"
#include "Equation.h"

void TestRandomDouble();
void TestMultipleSolutions();
void TestSpecialExpressionParsing();
bool TestEquationPartsParsing();
void TestEquationParsing();
void TestEquation();

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    UIHandler uiHandler;
    uiHandler.initialize();
    engine.rootContext()->setContextProperty(QString("uiHandler"), &uiHandler);

    std::cout << "Hello world?" << std::endl;

//    double testX[] = { 16, 2, 77, 29 };
//    std::vector<double> vTestX(testX, testX + 4);

//    HarmonyMemoryRow testRow(vTestX);
//    testRow.printRowWithNames();

    TestMultipleSolutions();

//    TestSpecialExpressionParsing();

//    TestEquationPartsParsing();

//    TestEquationParsing();

//    TestEquation();

    return app.exec();
//    return 0;
}

double getRandomDouble(double min, double max)
{
    return ((double)rand() / RAND_MAX) * (max - min) + min;
}

void TestRandomDouble()
{
    std::vector<double> testDoubles;
    for (int i = 0; i < 10000; i++)
    {
        double x = getRandomDouble(5, -5);
        testDoubles.push_back(x);
        //cout << x << ", ";
    }
    std::cout << std::endl;

    std::cout << "Minimum: " << *std::min_element(testDoubles.begin(), testDoubles.end()) << std::endl;
    std::cout << "Maximum:" << *std::max_element(testDoubles.begin(), testDoubles.end()) << std::endl;
}

void TestMultipleSolutions()
{
    HarmonySearch testSearch;
    testSearch.setParameters("x1+x2", 100, 0.45, 0.10, 0.5, 20000);

    std::vector<VariableConstraints> testConstr;
    HarmonyMemoryRow solution;

    testConstr.push_back(VariableConstraints(0, 1));
    testConstr.push_back(VariableConstraints(0, 1));
    solution = testSearch.Search(testConstr);
    std::cout << "Solution 1: ";
    solution.printRowWithNames();

    testConstr.clear();

    testConstr.push_back(VariableConstraints(0, 1));
    testConstr.push_back(VariableConstraints(-1, 0));
    solution = testSearch.Search(testConstr);
    std::cout << "Solution 2: ";
    solution.printRowWithNames();

    testConstr.clear();

    testConstr.push_back(VariableConstraints(-1, 0));
    testConstr.push_back(VariableConstraints(0, 1));
    solution = testSearch.Search(testConstr);
    std::cout << "Solution 3: ";
    solution.printRowWithNames();

    testConstr.clear();

    testConstr.push_back(VariableConstraints(-1, 0));
    testConstr.push_back(VariableConstraints(-1, 0));
    solution = testSearch.Search(testConstr);
    std::cout << "Solution 4: ";
    solution.printRowWithNames();
}

void TestSpecialExpressionParsing()
{
    SpecialExpression testExpression;
    testExpression.setFormula("(x1+x2)");
    testExpression.setFormula("(x1(x2+x3))^3");
    testExpression.setFormula("e^(x1+x2)");
    testExpression.setFormula("exp(x1+x2)");
    testExpression.setFormula("log(2,x1+x2)");
    testExpression.setFormula("ln(x1+x2)");
    testExpression.setFormula("4^(x1+x2)");
    testExpression.setFormula("sin(x1+x2)");
    testExpression.setFormula("cos(x1+x2)");
    testExpression.setFormula("tan(x1+x2)");
    testExpression.setFormula("ctan(x1+x2)");
    testExpression.setFormula("tg(x1+x2)");
    testExpression.setFormula("ctg(x1+x2)");
    testExpression.setFormula("sinx1");
    testExpression.setFormula("e^x2");
    testExpression.setFormula("3^x4");
    testExpression.setFormula("x2^3");
}

bool TestEquationPartsParsing()
{
    EquationPart testPart;
    bool testBool;
    std::string testFormula;

    std::vector<double> testX;
    testX.push_back(5.0);

    testFormula = "5";
    testBool = testPart.setFormula(testFormula, add);
    std::cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

    testFormula = "13";
    testBool = testPart.setFormula(testFormula, add);
    std::cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

    testFormula = "s";
    testBool = testPart.setFormula(testFormula, add);
    std::cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

    testFormula = "8x1";
    testBool = testPart.setFormula(testFormula, add);
    std::cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

    testFormula = "7sinx1";
    testBool = testPart.setFormula(testFormula, add);
    std::cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

    testFormula = "6*x1";
    testBool = testPart.setFormula(testFormula, add);
    std::cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

    testFormula = "x4";
    testBool = testPart.setFormula(testFormula, add);
    std::cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

    testFormula = "3*sinx1";
    testBool = testPart.setFormula(testFormula, add);
    std::cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

    testFormula = "x1^3";
    testBool = testPart.setFormula(testFormula, add);
    std::cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

    testFormula = "4x1^3";
    testBool = testPart.setFormula(testFormula, add);
    std::cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

    testFormula = "4x1*sinx2";
    testBool = testPart.setFormula(testFormula, add);
    std::cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

    testFormula = "7*x1*sinx2";
    testBool = testPart.setFormula(testFormula, add);
    std::cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

    testFormula = "7/x1";
    testBool = testPart.setFormula(testFormula, add);
    std::cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

    testFormula = "x2*sinx3";
    testPart.setFormula(testFormula,subtract);
    std::cout << testFormula << ": " << testPart.calculate(testX) << std::endl;

    return testBool;
}

void TestEquationParsing()
{
    Equation testEquation;
    std::vector<double> x;
    unsigned int N;

    testEquation.setEquation("+8(X1+X9) - 3SinX1", N);
    testEquation.setEquation("+ 8 (X1+X9) - 3 SinX1 ", N);
    std::cout << testEquation.calculate(x) << std::endl;

    testEquation.setEquation("5(x2+x3) + 4sinx1", N);
    std::cout << testEquation.calculate(x) << std::endl;
    testEquation.setEquation("-4(x5+x4) - 5sinx1", N);
    std::cout << testEquation.calculate(x) << std::endl;
    testEquation.setEquation("+8(x1+x9) - 3sinx1", N);
    std::cout << testEquation.calculate(x) << std::endl;
}

void TestEquation()
{
    Equation testEquation;
    std::vector<double> testX;
    unsigned int N;

    testX.push_back(1.0);
    testX.push_back(1.0);

    bool testBool;
    double result;

    testBool = testEquation.setEquation("- 0.62x1^2 - 0.62x2^2 + 4sin(x3^2)", N);
    result = testEquation.calculate(testX);

    qDebug() << testBool << result;

}
