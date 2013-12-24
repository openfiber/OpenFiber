//==============================================================================
// Single cell simulation view
//==============================================================================

#ifndef SIMULATIONVIEW_H
#define SIMULATIONVIEW_H

//==============================================================================

#include "commonwidget.h"
#include "simulationworker.h"

//==============================================================================

#include <QWidget>

//==============================================================================

class QwtPlot;
class QwtPlotCurve;

//==============================================================================

namespace Ui {
class SimulationView;
}

//==============================================================================

class SimulationView : public QWidget, public CommonWidget
{
    Q_OBJECT
    
public:
    explicit SimulationView(QWidget *parent = 0);
    ~SimulationView();

    virtual void retranslateUi();
    
private:
    Ui::SimulationView *mGui;

};

#endif // SIMULATIONVIEW_H


//==============================================================================
// End of file
//==============================================================================
