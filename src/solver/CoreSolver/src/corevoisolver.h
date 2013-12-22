//==============================================================================
// Core VOI solver class
//==============================================================================

#ifndef COREVOISOLVER_H
#define COREVOISOLVER_H

//==============================================================================

#include "coresolver.h"

//==============================================================================

class CoreVoiSolver : public CoreSolver
{
public:
    explicit CoreVoiSolver();

    virtual void solve(double &pVoi, const double &pVoiEnd) const = 0;

protected:
    int mRatesStatesCount;

    double *mConstants;
    double *mStates;
    double *mRates;
    double *mAlgebraic;
};

//==============================================================================

#endif

//==============================================================================
// End of file
//==============================================================================
