#ifndef TEST_CELL_H
#define TEST_CELL_H

#include <math.h>

class Test_Cell
{
public:
    Test_Cell();

    void initConsts(double* CONSTANTS, double* RATES, double *STATES);
    void computeRates(double VOI, double* CONSTANTS, double* RATES, double* STATES, double* ALGEBRAIC);
    void computeVariables(double VOI, double* CONSTANTS, double* RATES, double* STATES, double* ALGEBRAIC);
};

#endif // TEST_CELL_H
