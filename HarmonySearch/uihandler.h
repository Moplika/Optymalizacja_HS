#ifndef UIHANDLER_H
#define UIHANDLER_H

#include "VariableConstraints.h"
#include "HarmonySearch.h"

#include <QObject>
#include <QString>
#include <QVector>
#include <QList>

#include <string>
#include <vector>

class UIHandler : public QObject
{
    Q_OBJECT

    struct ReadConstraints
    {
        int xIndex;
        double min;
        double max;
    };

public:
    explicit UIHandler(QObject *parent = 0);

    void initialize();
    void printParmeters();

signals:
    void constraintsWrong();
    void notEnoughConstraints();
    void tooManyConstraints();
    void constraintsOk();

    void equationOk();
    void equationWrong();

    void calculationResult(QString result);

    void parametersWrong();
    void parametersOk();

    void calculationsStarted();
    void calculationsFinished();
    void showResult(int N, QString fx, QList<QString> x);

    void showIteration(unsigned int iterationNo, QString optimalFx, QList<QString> optimalX,
                       QString currentFx, QList<QString> currentX, int currentSolutionPos);
    void startShowingIterations();

    void showHarmonyMemoryRow(int id, QList<QString> values);

    void drawSurfaceGraphPoint(QList<QString> values);
    void drawingFinished(int x1Pos, int x2Pos);

public slots:
    void clearParameters();
    void startCalculations();

    int getHMS() const;
    void setHMS(int _HMS);

    double getHMCR() const;
    void setHMCR(double _HMCR);

    double getPAR() const;
    void setPAR(double _PAR);

    int getNI() const;
    void setNI(int _NI);

    bool doShowIterations() const;
    void setShowIterations(bool _doShow);

    int getIterationNb() const;
    void setIterationNb(int iterationsNb);

    int getN() const;
    void setN(int _N);

    bool areParametersOk();

    std::string getEquation() const;
    void setEquation(std::string _equation);
    void setEquation(QString _equation);

    std::vector<VariableConstraints> getConstraints() const;
    void setConstraints(std::vector<VariableConstraints> _constraints);
    void readSingleConstraint(int index, double min, double max);
    void rewriteConstraints();
    double getMinimum(int index);
    double getMaximum(int index);

    QList<QString> getOptimalSolution();
    void printHarmonyMemory();
    void drawSurfaceGraph(double minX1, double maxX1, double minX2, double maxX2);

    void nextIteration();
    void finishIterating();

private:
    int HMS;
    double HMCR;
    double PAR;
    int NI;
    bool doShowIter;
    int iterationsNb;
    unsigned int N;

    unsigned int globalIteration;

    std::string equation;
    bool isEquationCorrect;

    HarmonySearch harmonySearch;

    bool areAllConstraintsRead;
    bool areConstraintsSet;
    std::vector<VariableConstraints> constraints;
    std::vector<ReadConstraints> readConstraints;

    void clearReadConstraints();
    static bool compareReadConstraints(ReadConstraints first, ReadConstraints second);

    void completeSearch();
    void searchByIteration();
    void showIterationInUI(HarmonyMemoryRow optimal, int solutionPosition, bool isFinal);

    QString fxToString(HarmonyMemoryRow row);
    QList<QString> xToStringList(HarmonyMemoryRow row);

    void drawAPoint(double x1, double x2);

};


#endif // UIHANDLER_H
