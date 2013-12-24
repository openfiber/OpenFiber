//==============================================================================
// Simulation worker
//==============================================================================

#ifndef SIMULATIONWORKER_H
#define SIMULATIONWORKER_H

#include <QVector>

#include "runtime.h"

class SimulationWorker
{
public:
    SimulationWorker();
    ~SimulationWorker();

    RunTime * runtime;

    typedef QVector<double> Doubles;

    Doubles xData;
    Doubles yData[31];

    void run();
};

#endif // SIMULATIONWORKER_H

//==============================================================================
// End of file
//==============================================================================
