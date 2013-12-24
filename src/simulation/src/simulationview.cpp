//==============================================================================
// Single cell simulation view
//==============================================================================

#include "simulationview.h"
#include "toolbarwidget.h"
#include "coreodesolver.h"

//==============================================================================

#include "ui_simulationview.h"

//==============================================================================

#include "qwt_plot.h"
#include "qwt_plot_grid.h"
#include "qwt_plot_curve.h"

//==============================================================================

SimulationView::SimulationView(QWidget *parent) :
    QWidget(parent),
    CommonWidget(parent),
    mGui(new Ui::SimulationView)
{
    // Создание UI

    mGui->setupUi(this);

}

//==============================================================================

SimulationView::~SimulationView()
{
    delete mGui;
}

void SimulationView::retranslateUi()
{
    // Перевод всего виджета

    mGui->retranslateUi(this);
}

//==============================================================================
// End of file
//==============================================================================
