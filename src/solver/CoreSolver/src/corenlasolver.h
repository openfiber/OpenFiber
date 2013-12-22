/*******************************************************************************

Licensed to the OpenCOR team under one or more contributor license agreements.
See the NOTICE.txt file distributed with this work for additional information
regarding copyright ownership. The OpenCOR team licenses this file to you under
the Apache License, Version 2.0 (the "License"); you may not use this file
except in compliance with the License. You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License.

*******************************************************************************/

//==============================================================================
// Core NLA solver class
//==============================================================================

#ifndef CORENLASOLVER_H
#define CORENLASOLVER_H

//==============================================================================

#include "coresolver.h"
#include "settings.h"

//==============================================================================

class CoreNlaSolver : public CoreSolver
{
public:
    typedef void (*ComputeSystemFunction)(double *, double *, void *);

    explicit CoreNlaSolver();

    virtual void initialize(ComputeSystemFunction pComputeSystem,
                            double *pParameters, int pSize,
                            void *pUserData = 0);

    virtual void solve() const = 0;

private:
    ComputeSystemFunction mComputeSystem;

    double *mParameters;
    int mSize;
    void *mUserData;
};

//==============================================================================

CoreNlaSolver  * nlaSolver(const QString &pRuntime);

void setNlaSolver(const QString &pRuntime,
                                    CoreNlaSolver *pGlobalNlaSolver);
void unsetNlaSolver(const QString &pRuntime);


//==============================================================================

#endif

//==============================================================================
// End of file
//==============================================================================
