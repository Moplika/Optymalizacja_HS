#ifndef UIHANDLER_H
#define UIHANDLER_H

#include <QObject>

#include <string>

class UIHandler : public QObject
{
    Q_OBJECT
public:
    explicit UIHandler(QObject *parent = 0);

    void initialize();
    void printParmeters();

signals:

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

    std::string getEquation() const;
    void setEquation(std::string equation);

private:
    int _HMS;
    double _HMCR;
    double _PAR;
    int _NI;
    bool _doShowIter;
    int _iterationsNb;

    std::string _equation;


};

#endif // UIHANDLER_H
