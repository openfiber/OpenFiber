//==============================================================================
// Core solver class
//==============================================================================

#include "coresolver.h"

//==============================================================================

CoreSolver::CoreSolver() :
    mProperties(Properties())
{
}

//==============================================================================

void CoreSolver::setProperties(const Properties &pProperties)
{
    // Задание значения свойств, но только если они является допустимыми

    mProperties = pProperties;
}

//==============================================================================

void CoreSolver::emitError(const QString &pErrorMessage)
{
    // Сообщение об ошибке

    QString errorMessage;

    if (pErrorMessage.startsWith("Newton"))
        errorMessage = pErrorMessage;
    else
        errorMessage = pErrorMessage[0].toLower()+pErrorMessage.right(pErrorMessage.size()-1);

    if (!pErrorMessage.right(3).compare("..."))
        emit error(errorMessage.left(errorMessage.size()-3));
    else if (!pErrorMessage.right(1).compare("."))
        emit error(errorMessage.left(errorMessage.size()-1));
    else
        emit error(errorMessage);
}

//==============================================================================
// End of file
//==============================================================================
