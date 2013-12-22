//==============================================================================
// Second-order Runge-Kutta solver class
//==============================================================================

#ifndef SECONDORDERRUNGEKUTTASOLVER_H
#define SECONDORDERRUNGEKUTTASOLVER_H

//==============================================================================

#include "coreodesolver.h"

//==============================================================================

static const QString StepId = "Step";

//==============================================================================

static const double StepDefaultValue = 1.0;

//==============================================================================

class SecondOrderRungeKuttaSolver : public CoreOdeSolver
{
public:
    explicit SecondOrderRungeKuttaSolver();
    ~SecondOrderRungeKuttaSolver();

    virtual void initialize(const double &pVoiStart,
                            const int &pRatesStatesCount, double *pConstants,
                            double *pRates, double *pStates, double *pAlgebraic,
                            ComputeRatesFunction pComputeRates);

    virtual void solve(double &pVoi, const double &pVoiEnd) const;

private:
    double mStep;

    double *mYk1;
};

//==============================================================================

#endif

//==============================================================================
// End of file
//==============================================================================
