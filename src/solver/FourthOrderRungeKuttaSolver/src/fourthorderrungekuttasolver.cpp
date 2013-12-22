//==============================================================================
// Fourth-order Runge-Kutta solver class
//==============================================================================

#include "fourthorderrungekuttasolver.h"



//==============================================================================

FourthOrderRungeKuttaSolver::FourthOrderRungeKuttaSolver() :
    mStep(StepDefaultValue),
    mK1(0),
    mK23(0),
    mYk123(0)
{
}

//==============================================================================

FourthOrderRungeKuttaSolver::~FourthOrderRungeKuttaSolver()
{
    // Delete some internal objects

    delete[] mK1;
    delete[] mK23;
    delete[] mYk123;
}

//==============================================================================

void FourthOrderRungeKuttaSolver::initialize(const double &pVoiStart,
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

    delete[] mK1;
    delete[] mK23;
    delete[] mYk123;

    mK1    = new double[pRatesStatesCount];
    mK23   = new double[pRatesStatesCount];
    mYk123 = new double[pRatesStatesCount];
}

//==============================================================================

void FourthOrderRungeKuttaSolver::solve(double &pVoi,
                                        const double &pVoiEnd) const
{
    // k1 = h * f(t_n, Y_n)
    // k2 = h * f(t_n + h / 2, Y_n + k1 / 2)
    // k3 = h * f(t_n + h / 2, Y_n + k2 / 2)
    // k4 = h * f(t_n + h, Y_n + k3)
    // Y_n+1 = Y_n + k1 / 6 + k2 / 3 + k3 / 3 + k4 / 6

    static const double OneOverThree = 1.0/3.0;
    static const double OneOverSix   = 1.0/6.0;

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

        for (int i = 0; i < mRatesStatesCount; ++i) {
            mK1[i]    = mRates[i];
            mYk123[i] = mStates[i]+realHalfStep*mK1[i];
        }

        // Вычисление f(t_n + h / 2, Y_n + k1 / 2)

        mComputeRates(pVoi+realHalfStep, mConstants, mRates, mYk123, mAlgebraic);

        // Вычисление k2 и Yk2

        for (int i = 0; i < mRatesStatesCount; ++i) {
            mK23[i]   = mRates[i];
            mYk123[i] = mStates[i]+realHalfStep*mK23[i];
        }

        // Вычисление f(t_n + h / 2, Y_n + k2 / 2)

        mComputeRates(pVoi+realHalfStep, mConstants, mRates, mYk123, mAlgebraic);

        // Вычисление k3 и Yk3

        for (int i = 0; i < mRatesStatesCount; ++i) {
            mK23[i]   += mRates[i];
            mYk123[i]  = mStates[i]+realStep*mK23[i];
        }

        // Вычисление f(t_n + h, Y_n + k3)

        mComputeRates(pVoi+realStep, mConstants, mRates, mYk123, mAlgebraic);

        // Вычисление k4 и Y_n+1

        for (int i = 0; i < mRatesStatesCount; ++i)
            mStates[i] += realStep*(OneOverSix*(mK1[i]+mRates[i])+OneOverThree*mK23[i]);

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
