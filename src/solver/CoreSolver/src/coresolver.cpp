//==============================================================================
// Core solver class
//==============================================================================

#include "coresolver.h"

CoreSolver::CoreSolver() :
    mProperties(Properties())
{
}

//==============================================================================

void CoreSolver::setProperty(const QString &pName, const QVariant &pValue)
{
    // Добавить/заменить значение свойств

    if (isValidProperty(pName))
        mProperties.insert(pName, pValue);
}

//==============================================================================

void CoreSolver::emitError(const QString &pErrorMsg)
{
    // Сообщение об ошибке

    emit error(pErrorMsg);
}

//==============================================================================
// End of file
//==============================================================================
