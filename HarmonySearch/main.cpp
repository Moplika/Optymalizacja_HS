#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

#include <muParser.h>
#include "uihandler.h"
#include "HarmonyMemoryRow.h"
#include "HarmonySearch.h"
#include "VariableConstraints.h"
#include "Equation.h"

void TestRandomDouble();
void TestMultipleSolutions();
void TestSpecialExpressionParsing();
bool TestEquationPartsParsing();
void TestEquationParsing();
void TestEquation();
void TestParsingLib();
void TestEquationCalculations();
void TestHSCalculations();

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    //    QGuiApplication::setApplicationDisplayName("Harmony Search");

    //    QQmlApplicationEngine engine;
    //    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    //    UIHandler uiHandler;
    //    uiHandler.initialize();
    //    engine.rootContext()->setContextProperty(QString("uiHandler"), &uiHandler);

    std::cout << "Hello world?" << std::endl;

    //    double testX[] = { 16, 2, 77, 29 };
    //    std::vector<double> vTestX(testX, testX + 4);

    //    HarmonyMemoryRow testRow(vTestX);
    //    testRow.printRowWithNames();

//        TestParsingLib();
        TestMultipleSolutions();
    //    TestEquation();
    //    TestEquationCalculations();
//    TestHSCalculations();

    //    return app.exec();
    return 0;
}

double root(double stopien, double argument)
{
    return pow(argument, 1.0/stopien);
}

void TestEquationCalculations()
{
    Equation equation;
    unsigned int N;
    equation.setEquation("x1+x2", N);

    std::vector<double> x;
    x.push_back(1);
    x.push_back(1);

    std::cout << equation.calculate(x) << std::endl;
}

void TestHSCalculations()
{
    HarmonySearch testSearch;
    if (!testSearch.setParameters("x1^4+x2^4-0.62*x1^2-0.62*x2^2", 10, 0.45, 0.10, 0.5, 20000))
        return;

    std::vector<double> x;
    x.push_back(1.5);
    x.push_back(1.3);

    std::cout << testSearch.equation.calculate(x) << std::endl;

    x.at(0) = 1;
    x.at(1) = 1;

    std::cout << testSearch.equation.calculate(x) << std::endl;

    std::vector<VariableConstraints> testConstr;
    HarmonyMemoryRow solution;
    testConstr.push_back(VariableConstraints(0, 1));
    testConstr.push_back(VariableConstraints(0, 1));

    solution = testSearch.Search(testConstr);
    testSearch.printHM();
}

void TestParsingLib() {
    std::vector<double> fVal(2,1);

    //double fVal[] = {1,1};

    try
    {
        mu::Parser parser;
//        std::cout << parser.Eval() << std::endl;

        parser.DefineVar("x1", &(fVal[0]));
        parser.DefineVar("x2", &(fVal[1]));
        parser.DefineFun("root", root);
        parser.SetExpr("root(3,x1)");

        for (std::size_t x = 0; x < 100; x++)
        {
            fVal[0] = x;
            fVal[1] = x+1;
            std::cout << x << ": " << parser.Eval() << std::endl;
        }
    }
    catch (mu::Parser::exception_type &e)
    {
        std::cout << e.GetMsg() << std::endl;
    }
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
    if (!testSearch.setParameters("x1^4+x2^4-0.62*x1^2-0.62*x2^2", 100, 0.45, 0.10, 0.5, 20000))
        return;

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

void TestEquationParsing()
{
    Equation testEquation;
    std::vector<double> x;
    x.assign(10,1.0);
    unsigned int N;

    testEquation.setEquation("+8*(X1+X9) - 3*Sin(X1)", N);
    testEquation.setEquation("+ 8 *(X1+X9) - 3 *Sin(X1) ", N);
    std::cout << testEquation.calculate(x) << std::endl;

    testEquation.setEquation("5*(x2+x3) + 4*sin(x1)", N);
    std::cout << testEquation.calculate(x) << std::endl;
    testEquation.setEquation("-4*(x5+x4) - 5*sin(x1)", N);
    std::cout << testEquation.calculate(x) << std::endl;
    testEquation.setEquation("+8*(x1+x9) - 3*sin(x1)", N);
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

    testBool = testEquation.setEquation("- 0.62*x1^2 - 0.62*x2^2 + 4*sin(x3^2)", N);
    result = testEquation.calculate(testX);

    qDebug() << testBool << result;

}
