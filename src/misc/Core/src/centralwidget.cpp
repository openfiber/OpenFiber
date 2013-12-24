//==============================================================================
// Central widget
//==============================================================================

#include "centralwidget.h"

//==============================================================================

#include "ui_centralwidget.h"

//==============================================================================

CentralWidget::CentralWidget(QMainWindow *pMainWindow) :
    QWidget(pMainWindow),
    CommonWidget(pMainWindow),
    mGui(new Ui::CentralWidget)
{
    // Инициализация Gui

    mGui->setupUi(this);

    sim = new SimulationView(this);

    mGui->layout->addWidget(sim);
}

//==============================================================================

CentralWidget::~CentralWidget()
{
    // Удаление GUI

    delete mGui;
}

//==============================================================================
// End of file
//==============================================================================
