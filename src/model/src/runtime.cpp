//==============================================================================
// Runtime class
//==============================================================================

#include "runtime.h"

//==============================================================================

RunTime::RunTime()
{
    mOdeFunctions = new Test_Cell();
}

//==============================================================================

int RunTime::constantsCount() const
{
    return 133;
}

//==============================================================================

int RunTime::statesCount() const
{
      return 31;
}

//==============================================================================

int RunTime::ratesCount() const
{
    return 31;
}

//==============================================================================

int RunTime::algebraicCount() const
{
      return 90;
}

//==============================================================================

int RunTime::condVarCount() const
{
      return 31;
}

//==============================================================================
// End of file
//==============================================================================
