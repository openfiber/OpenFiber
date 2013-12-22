//==============================================================================
// Second-order Runge-Kutta solver class
//==============================================================================

#include "secondorderrungekuttasolver.h"

//==============================================================================

SecondOrderRungeKuttaSolver::SecondOrderRungeKuttaSolver() :
    mStep(StepDefaultValue),
    mYk1(0)
{
}

//==============================================================================

SecondOrderRungeKuttaSolver::~SecondOrderRungeKuttaSolver()
{
    // Удалите некоторых внутренних объектов

    delete[] mYk1;
}

//==============================================================================

void SecondOrderRungeKuttaSolver::initialize(const double &pVoiStart,
                                             const int &pRatesStatesCount,
                                             double *pConstants,
                                             double *pRates, double *pStates,
                                             double *pAlgebraic,
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

    // (Пере-)создание массивос переменных

    delete[] mYk1;

    mYk1 = new double[pRatesStatesCount];
}

//==============================================================================

void SecondOrderRungeKuttaSolver::solve(double &pVoi,
                                        const double &pVoiEnd) const
{
    // k1 = h * f(t_n, Y_n)
    // k2 = h * f(t_n + h / 2, Y_n + k1 / 2)
    // Y_n+1 = Y_n + k2


    double voiStart = pVoi;

    int stepNumber = 0;
    double realStep = mStep;
    double realHalfStep = 0.5*realStep;

    while (pVoi != pVoiEnd) {
        // Проверка, что шаг по времени правильный

        if (pVoi+realStep > pVoiEnd) {
            realStep = pVoiEnd-pVoi;
            realHalfStep = 0.5*realStep;
        }

        // Вычисление f(t_n, Y_n)

        mComputeRates(pVoi, mConstants, mRates, mStates, mAlgebraic);

        // Вычисление k1 и Yk1

        for (int i = 0; i < mRatesStatesCount; ++i)
            mYk1[i] = mStates[i]+realHalfStep*mRates[i];

        // Вычисление  f(t_n + h / 2, Y_n + k1 / 2)

        mComputeRates(pVoi+realHalfStep, mConstants, mRates, mYk1, mAlgebraic);

        // Вычисление  Y_n+1

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
