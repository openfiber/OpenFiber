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

    // Создание вкладок

    mTabs = new QTabWidget();

    mTabParameters = new ParametersView();

    mTabs->addTab(mTabParameters,"Parameters");

    mTabSimulationView = new SimulationView();

    mTabs->addTab(mTabSimulationView,"Simulation view");

    mTabs->setTabPosition(QTabWidget::East);

    mGui->layout->addWidget(mTabs);
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
