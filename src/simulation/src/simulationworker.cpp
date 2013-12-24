//==============================================================================
// Simulation worker
//==============================================================================

#include "simulationworker.h"

#include <QTime>


SimulationWorker::SimulationWorker()
{
    runtime = new RunTime();
}

SimulationWorker::~SimulationWorker()
{
    delete runtime;
}

void SimulationWorker::run()
{
    int statesCount = runtime->statesCount();

    double voi = 0; // ms
    double voiStep; // ms
    double voiMax; // ms
    double constants[runtime->constantsCount()];
    double rates[runtime->ratesCount()];
    double states[statesCount];
    double algebraic[runtime->algebraicCount()];
    int voiCount = 0;
    int voiOutputCount; // ms

    voiStep = 0.01; // ms
    voiMax = 1000; // ms
    voiOutputCount = 1;

    runtime->mOdeFunctions->initConsts(constants, rates, states);
    runtime->mOdeFunctions->computeRates(voi, constants, rates, states, algebraic);
    runtime->mOdeFunctions->computeVariables(voi, constants, rates, states, algebraic);

    do {
    // Output the current data, if needed

     if(voiCount % voiOutputCount == 0) {
     xData.append(voi);

     for (int i = 0; i < statesCount; ++i)
     yData[i].append(states[i]);
     }

     // Compute the rates and variables

     runtime->mOdeFunctions->computeRates(voi, constants, rates, states, algebraic);
     runtime->mOdeFunctions->computeVariables(voi, constants, rates, states, algebraic);

    //Go to the next voiStep and integrate the states

     voi = ++voiCount*voiStep;

     for (int i = 0; i < statesCount; ++i)
     states[i] += voiStep*rates[i];
    } while (voi < voiMax);

    xData.append(voi);

    for (int i = 0; i < statesCount; ++i)
    yData[i].append(states[i]);
}

//==============================================================================
// End of file
//==============================================================================
