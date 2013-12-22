//==============================================================================
// CVODE solver class
//==============================================================================

#ifndef CVODESOLVER_H
#define CVODESOLVER_H

//==============================================================================

#include "coreodesolver.h"

//==============================================================================

#include "nvector/nvector_serial.h"

//==============================================================================

static const QString MaximumStepId          = "MaximumStep";
static const QString MaximumNumberOfStepsId = "MaximumNumberOfSteps";
static const QString RelativeToleranceId    = "RelativeTolerance";
static const QString AbsoluteToleranceId    = "AbsoluteTolerance";

//==============================================================================

// Значения параметров по умолчанию CVODE
// Note #1: максимальный шаг 0 означает, что нет максимального шага как такового
//          и что CVODE можете использовать любой шаг, какой считает нужным ...
// Note #2: По умолчанию максимальное число шагов составляет 500,
//          что должно быть достаточно в большинстве случаев ...

static const double MaximumStepDefaultValue = 0.0;

enum {
    MaximumNumberOfStepsDefaultValue = 500
};

static const double RelativeToleranceDefaultValue = 1.0e-7;
static const double AbsoluteToleranceDefaultValue = 1.0e-7;

//==============================================================================

class CvodeSolverUserData
{
public:
    explicit CvodeSolverUserData(double *pConstants, double *pAlgebraic,
                                 CoreOdeSolver::ComputeRatesFunction pComputeRates);

    double * constants() const;
    double * algebraic() const;

    CoreOdeSolver::ComputeRatesFunction computeRates() const;

private:
    double *mConstants;
    double *mAlgebraic;

    CoreOdeSolver::ComputeRatesFunction mComputeRates;
};

//==============================================================================

class CvodeSolver : public CoreOdeSolver
{
public:
    explicit CvodeSolver();
    ~CvodeSolver();

    virtual void initialize(const double &pVoiStart,
                            const int &pRatesStatesCount, double *pConstants,
                            double *pRates, double *pStates, double *pAlgebraic,
                            ComputeRatesFunction pComputeRates);

    virtual void solve(double &pVoi, const double &pVoiEnd) const;

private:
    void *mSolver;
    N_Vector mStatesVector;
    CvodeSolverUserData *mUserData;

    double mMaximumStep;
    int mMaximumNumberOfSteps;
    double mRelativeTolerance;
    double mAbsoluteTolerance;
};

//==============================================================================

#endif

//==============================================================================
// End of file
//==============================================================================
