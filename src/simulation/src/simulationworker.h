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

    void run();
};

#endif // SIMULATIONWORKER_H
