#ifndef UIHANDLER_H
#define UIHANDLER_H

#include "VariableConstraints.h"

#include <QObject>
#include <QString>

#include <string>
#include <vector>

class UIHandler : public QObject
{
    Q_OBJECT

    struct readConstraints
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
    void wrongConstraints();
    void notEnoughConstraints();
    void tooManyConstraints();
    void constraintsOk();

    void equationOk();
    void equationWrong();

    void calculationStarted();
    void calculationResult(QString result);

public slots:
    void startCalculations();

    int getHMS() const;
    void setHMS(int HMS);

    double getHMCR() const;
    void setHMCR(double HMCR);

    double getPAR() const;
    void setPAR(double PAR);

    int getNI() const;
    void setNI(int NI);

    bool doShowIterations() const;
    void setShowIterations(bool doShow);

    int getIterationNb() const;
    void setIterationNb(int iterationsNb);

    int getN() const;
    void setN(int N);

    std::string getEquation() const;
    void setEquation(std::string equation);
    void setEquation(QString equation);

    std::vector<VariableConstraints> getConstraints() const;
    void setConstraints(std::vector<VariableConstraints> constraints);
    void readSingleConstraint(int index, double min, double max);
    void rewriteConstraints();

private:
    int _HMS;
    double _HMCR;
    double _PAR;
    int _NI;
    bool _doShowIter;
    int _iterationsNb;
    unsigned int _N;

    std::string _equation;

    bool areAllConstraintsRead;
    bool areConstraintsSet;
    std::vector<VariableConstraints> _constraints;
    std::vector<readConstraints> _readConstraints;

    void clearReadConstraints();

    static bool compareReadConstraints(readConstraints first, readConstraints second);

};


#endif // UIHANDLER_H