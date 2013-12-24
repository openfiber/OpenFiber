//==============================================================================
// Runtime class
//==============================================================================

#include "runtime.h"

RunTime::RunTime()
{
    mOdeFunctions = new Test_Cell();
}

int RunTime::constantsCount() const
{
    return 0;
}

int RunTime::statesCount() const
{
}

int RunTime::ratesCount() const
{
}

int RunTime::algebraicCount() const
{
}

int RunTime::condVarCount() const
{
}

//==============================================================================
// End of file
//==============================================================================
