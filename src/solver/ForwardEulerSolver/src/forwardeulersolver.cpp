//==============================================================================
// Forward Euler solver class
//==============================================================================

#include "forwardeulersolver.h"

//==============================================================================

ForwardEulerSolver::ForwardEulerSolver() :
    mStep(StepDefaultValue)
{
}

//==============================================================================

void ForwardEulerSolver::initialize(const double &pVoiStart,
                                    const int &pRatesStatesCount,
                                    double *pConstants, double *pRates,
                                    double *pStates, double *pAlgebraic,
                                    ComputeRatesFunction pComputeRates)
{
    // Получение свойств решателя

    if (mProperties.contains(StepId)) {
        mStep = mProperties.value(StepId).toDouble();

        if (!mStep) {
            emit error(QObject::tr("the 'step' property value cannot be equal to zero"));

            return;
        }
    } else {
        emit error(QObject::tr("the 'step' property value could not be retrieved"));

        return;
    }

    // Инициализация ODE решателя

    CoreOdeSolver::initialize(pVoiStart, pRatesStatesCount,
                                                   pConstants, pRates, pStates,
                                                   pAlgebraic, pComputeRates);
}

//==============================================================================

void ForwardEulerSolver::solve(double &pVoi, const double &pVoiEnd) const
{
    // Y_n+1 = Y_n + h * f(t_n, Y_n)

    double voiStart = pVoi;

    int stepNumber = 0;
    double realStep = mStep;

    while (pVoi != pVoiEnd) {
        // Проверка, что шаг по времени правильный

        if (pVoi+realStep > pVoiEnd)
            realStep = pVoiEnd-pVoi;

        // Вычисление f(t_n, Y_n)

        mComputeRates(pVoi, mConstants, mRates, mStates, mAlgebraic);

        // Вычмсление Y_n+1

        for (int i = 0; i < mRatesStatesCount; ++i)
            mStates[i] += realStep*mRates[i];

        // Следующий шаг по времени

        if (realStep != mStep)
            pVoi = pVoiEnd;
        else
            pVoi = voiStart+(++stepNumber)*mStep;
    }
}

//==============================================================================
// End of file
//==============================================================================
