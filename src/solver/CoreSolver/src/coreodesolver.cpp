//==============================================================================
// Core ODE solver class
//==============================================================================

#include "coreodesolver.h"

//==============================================================================

CoreOdeSolver::CoreOdeSolver() :
    CoreVoiSolver(),
    mComputeRates(0)
{
}

//==============================================================================

void CoreOdeSolver::initialize(const double &pVoiStart,
                               const int &pRatesStatesCount, double *pConstants,
                               double *pRates, double *pStates,
                               double *pAlgebraic,
                               ComputeRatesFunction pComputeRates)
{
    Q_UNUSED(pVoiStart);

    // Инициализация ODE решателя

    mRatesStatesCount = pRatesStatesCount;

    mConstants = pConstants;
    mRates     = pRates;
    mStates    = pStates;
    mAlgebraic = pAlgebraic;

    mComputeRates = pComputeRates;
}

//==============================================================================
// End of file
//==============================================================================
