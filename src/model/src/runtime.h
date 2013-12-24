//==============================================================================
// Runtime class
//==============================================================================

#ifndef RUNTIME_H
#define RUNTIME_H

//==============================================================================

#include "test_cell.h"

//==============================================================================

class RunTime
{
public:
    RunTime();

    int constantsCount() const;
    int statesCount() const;
    int ratesCount() const;
    int algebraicCount() const;
    int condVarCount() const;

    Test_Cell *mOdeFunctions;

};

#endif // RUNTIME_H

//==============================================================================
// End of file
//==============================================================================
