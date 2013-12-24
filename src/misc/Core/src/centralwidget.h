//==============================================================================
// Central widget
//==============================================================================

#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

//==============================================================================

#include "commonwidget.h"
#include "parametersview.h"
#include "simulationview.h"

//==============================================================================

#include <QWidget>
#include <QMainWindow>
#include <QTabWidget>

//==============================================================================

namespace Ui {
    class CentralWidget;
}
//==============================================================================

class CentralWidget : public QWidget, public CommonWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QMainWindow *pMainWindow);
    ~CentralWidget();

private:
    Ui::CentralWidget *mGui;

    QTabWidget *mTabs;

    ParametersView *mTabParameters;
    SimulationView *mTabSimulationView;

signals:
    
public slots:
    
};

#endif // CENTRALWIDGET_H

//==============================================================================
// End of file
//==============================================================================
