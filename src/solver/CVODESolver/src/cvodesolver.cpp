//==============================================================================
// CVODE solver class
//==============================================================================

#include "cvodesolver.h"

//==============================================================================

#include "cvode/cvode.h"
#include "cvode/cvode_dense.h"

//==============================================================================

int rhsFunction(double pVoi, N_Vector pStates, N_Vector pRates, void *pUserData)
{
    // Вычисление функции RHS

    CvodeSolverUserData *userData = static_cast<CvodeSolverUserData *>(pUserData);

    userData->computeRates()(pVoi, userData->constants(),
                             N_VGetArrayPointer_Serial(pRates),
                             N_VGetArrayPointer_Serial(pStates),
                             userData->algebraic());

    // Если все хорошо...

    return 0;
}

//==============================================================================

void errorHandlerCV(int pErrorCode, const char *pModule, const char *pFunction,
                  char *pErrorMessage, void *pUserData)
{
    Q_UNUSED(pModule);
    Q_UNUSED(pFunction);

    if (pErrorCode != CV_WARNING)
        // CVODE выдал ошибку, поэтому передать его на объект CvodeSolver
        reinterpret_cast<CvodeSolver *>(pUserData)->emitError(pErrorMessage);
}

//==============================================================================

CvodeSolverUserData::CvodeSolverUserData(double *pConstants, double *pAlgebraic,
                                         CoreOdeSolver::ComputeRatesFunction pComputeRates) :
    mConstants(pConstants),
    mAlgebraic(pAlgebraic),
    mComputeRates(pComputeRates)
{
}

//==============================================================================

double * CvodeSolverUserData::constants() const
{
    // Возвращает массив констант

    return mConstants;
}

//==============================================================================

double * CvodeSolverUserData::algebraic() const
{
    // Возвращает алгебраический массив

    return mAlgebraic;
}

//==============================================================================

CoreOdeSolver::ComputeRatesFunction CvodeSolverUserData::computeRates() const
{
    // Возвращает целевую функцию

    return mComputeRates;
}

//==============================================================================

CvodeSolver::CvodeSolver() :
    mSolver(0),
    mStatesVector(0),
    mUserData(0),
    mMaximumStep(MaximumStepDefaultValue),
    mMaximumNumberOfSteps(MaximumNumberOfStepsDefaultValue),
    mRelativeTolerance(RelativeToleranceDefaultValue),
    mAbsoluteTolerance(AbsoluteToleranceDefaultValue)
{
}

//==============================================================================

CvodeSolver::~CvodeSolver()
{
    if (!mSolver)
    // Решатель не был инициализирован, так что ...

        return;

    // Удаление некоторых внутренних объектов

    N_VDestroy_Serial(mStatesVector);

    CVodeFree(&mSolver);

    delete mUserData;
}

//==============================================================================

void CvodeSolver::initialize(const double &pVoiStart,
                             const int &pRatesStatesCount, double *pConstants,
                             double *pRates, double *pStates,
                             double *pAlgebraic,
                             ComputeRatesFunction pComputeRates)
{
    if (!mSolver) {
        // Получение свойств решателя CVODE

        if (mProperties.contains(MaximumStepId)) {
            mMaximumStep = mProperties.value(MaximumStepId).toDouble();
        } else {
            emit error(QObject::tr("the 'maximum step' property value could not be retrieved"));

            return;
        }

        if (mProperties.contains(MaximumNumberOfStepsId)) {
            mMaximumNumberOfSteps = mProperties.value(MaximumNumberOfStepsId).toInt();
        } else {
            emit error(QObject::tr("the 'maximum number of steps' property value could not be retrieved"));

            return;
        }

        if (mProperties.contains(RelativeToleranceId)) {
            mRelativeTolerance = mProperties.value(RelativeToleranceId).toDouble();
        } else {
            emit error(QObject::tr("the 'relative tolerance' property value could not be retrieved"));

            return;
        }

        if (mProperties.contains(AbsoluteToleranceId)) {
            mAbsoluteTolerance = mProperties.value(AbsoluteToleranceId).toDouble();
        } else {
            emit error(QObject::tr("the 'absolute tolerance' property value could not be retrieved"));

            return;
        }

        // Инициализация ODE решателя

        CoreOdeSolver::initialize(pVoiStart,
                                           pRatesStatesCount,
                                           pConstants, pRates,
                                           pStates, pAlgebraic,
                                           pComputeRates);

        // Создать вектор состояний

        mStatesVector = N_VMake_Serial(pRatesStatesCount, pStates);

        // Создать CVODE решатель

        mSolver = CVodeCreate(CV_BDF, CV_NEWTON);

        // Использование нашего собственного обработчика ошибок

        CVodeSetErrHandlerFn(mSolver, errorHandlerCV, this);

        // Иниуиализация CVODE решателя

        CVodeInit(mSolver, rhsFunction, pVoiStart, mStatesVector);

        // Установка некоторых пользовательсикх данных

        delete mUserData;   // На всякий случай удаление старых перед инициализацией

        mUserData = new CvodeSolverUserData(pConstants, pAlgebraic,
                                            pComputeRates);

        CVodeSetUserData(mSolver, mUserData);

        // Установика линейного решателя

        CVDense(mSolver, pRatesStatesCount);

        // Установка максимального шага

        CVodeSetMaxStep(mSolver, mMaximumStep);

        // Установка максимального числа шагов

        CVodeSetMaxNumSteps(mSolver, mMaximumNumberOfSteps);

        // Установить относительной и абсолютной погрешности

        CVodeSStolerances(mSolver, mRelativeTolerance, mAbsoluteTolerance);
    } else {
        // Повторная инициализация объекта CVODE

        CVodeReInit(mSolver, pVoiStart, mStatesVector);
    }
}

//==============================================================================

void CvodeSolver::solve(double &pVoi, const double &pVoiEnd) const
{
    // Решение модели

    CVode(mSolver, pVoiEnd, mStatesVector, &pVoi, CV_NORMAL);

    mComputeRates(pVoiEnd, mConstants, mRates,
                  N_VGetArrayPointer_Serial(mStatesVector), mAlgebraic);
}

//==============================================================================
// End of file
//==============================================================================
