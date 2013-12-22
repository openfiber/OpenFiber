//==============================================================================
// KINSOL solver class
//==============================================================================

#include "kinsolsolver.h"

//==============================================================================

#include "kinsol/kinsol.h"
#include "kinsol/kinsol_dense.h"

//==============================================================================

int systemFunction(N_Vector pY, N_Vector pF, void *pUserData)
{
    // Вычисление системной функции

    KinsolSolverUserData *userData = static_cast<KinsolSolverUserData *>(pUserData);

    userData->computeSystem()(N_VGetArrayPointer_Serial(pY),
                              N_VGetArrayPointer_Serial(pF),
                              userData->userData());

    // Если все хорошо...

    return 0;
}

//==============================================================================

void errorHandlerKIN(int pErrorCode, const char *pModule, const char *pFunction,
                  char *pErrorMessage, void *pUserData)
{
    Q_UNUSED(pModule);
    Q_UNUSED(pFunction);

    if (pErrorCode != KIN_WARNING)
        // KINSOL выдал ошибку, поэтому передать его на объект KinsolSolver

        static_cast<KinsolSolver *>(pUserData)->emitError(pErrorMessage);
}

//==============================================================================

KinsolSolverUserData::KinsolSolverUserData(void *pUserData,
                                          CoreNlaSolver::ComputeSystemFunction pComputeSystem) :
    mUserData(pUserData),
    mComputeSystem(pComputeSystem)
{
}

//==============================================================================

void * KinsolSolverUserData::userData() const
{
    // Возвращение пользовательских данных

    return mUserData;
}

//==============================================================================

CoreNlaSolver::ComputeSystemFunction KinsolSolverUserData::computeSystem() const
{
    // Возвращает целевую функцию

    return mComputeSystem;
}

//==============================================================================

KinsolSolver::KinsolSolver() :
    mSolver(0),
    mParametersVector(0),
    mOnesVector(0),
    mUserData(0)
{
}

//==============================================================================

KinsolSolver::~KinsolSolver()
{
    // Удаление некоторых внутренних объектов

    reset();
}

//==============================================================================

void KinsolSolver::reset()
{
    if (!mSolver)
    // Решатель не был инициализирован, так что ...

        return;

    N_VDestroy_Serial(mParametersVector);
    N_VDestroy_Serial(mOnesVector);

    KINFree(&mSolver);

    delete mUserData;
}

//==============================================================================

void KinsolSolver::initialize(ComputeSystemFunction pComputeSystem,
                              double *pParameters, int pSize, void *pUserData)
{
    if (mSolver)
        // Решателя уже инициализирован, поэтому сбросить его ...

        reset();

    // Инициализация ODE решателя

    CoreNlaSolver::initialize(pComputeSystem, pParameters, pSize);

    // Создать вектора

    mParametersVector = N_VMake_Serial(pSize, pParameters);
    mOnesVector = N_VNew_Serial(pSize);

    N_VConst(1.0, mOnesVector);

    // Создать KINSOL решатель

    mSolver = KINCreate();

    // Использование нашего собственного обработчика ошибок

    KINSetErrHandlerFn(mSolver, errorHandlerKIN, this);

    // Иниуиализация KINSOL решателя

    KINInit(mSolver, systemFunction, mParametersVector);

    // Установка некоторых пользовательсикх данных

    mUserData = new KinsolSolverUserData(pUserData, pComputeSystem);

    KINSetUserData(mSolver, mUserData);

    // Установика линейного решателя

    KINDense(mSolver, pSize);
}

//==============================================================================

void KinsolSolver::solve() const
{
    // Решение линейной системы

    KINSol(mSolver, mParametersVector, KIN_LINESEARCH, mOnesVector, mOnesVector);
}

//==============================================================================
// End of file
//==============================================================================
