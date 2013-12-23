//==============================================================================
// Central widget
//==============================================================================

#include "centralwidget.h"
#include "tabwidget.h"

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

    // Создание и добавление tab widget

    mTabWidget = new TabWidget(this);

    mGui->layout->addWidget(mTabWidget);
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
