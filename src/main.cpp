//==============================================================================
// Main
//==============================================================================

#include <QApplication>
#include <QPointer>
#include <QSettings>

//==============================================================================

#include "mainwindow.h"
#include "settings.h"

//==============================================================================

void removeInstances()
{
    // Удаление всей "Глобальной" информации используемой OpenFiber

    QSettings(SettingsOrganization, SettingsApplication).remove("Global");
}

int main(int pArgc, char *pArgv[])
{
    int res;

    QPointer<QApplication> app;
    QPointer<MainWindow> win;

    // Создание приложения

    app = new QApplication(pArgc, pArgv);

    // Удаление всей "Глобальной" информации используемой OpenFiber

    removeInstances();

    // Создание main window

    win = new MainWindow;

    // Отображение main window

    win->show();

    // Выполнение приложения

    res = app->exec();

    // Удаление main window

    delete win;

    // Удаление всей "Глобальной" информации используемой OpenFiber в эту сессию

    removeInstances();

    // Удаление приложения

    delete app;

    // Конец ...

    return res;
}

//==============================================================================
// End of file
//==============================================================================

