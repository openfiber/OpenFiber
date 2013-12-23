//==============================================================================
// Main window
//==============================================================================

#include <QDesktopServices>
#include <QCloseEvent>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QSettings>

//==============================================================================

#include "mainwindow.h"
#include "cliutils.h"
#include "settings.h"

//==============================================================================

#include "ui_mainwindow.h"

//==============================================================================

static const QString SystemLocale  = "";
static const QString EnglishLocale = "en";
static const QString RussianLocale  = "ru";

//==============================================================================

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mGui(new Ui::MainWindow)
{

    // Создание объекта параметров приложения

    mSettings = new QSettings(SettingsOrganization, SettingsApplication);

    // Настройка графического интерфейса

    mGui->setupUi(this);

    // Установка роли некоторых из наших пунктов меню

    mGui->actionExit->setMenuRole(QAction::QuitRole);
    mGui->actionAbout->setMenuRole(QAction::AboutRole);

    // Заголовок main window

    setWindowTitle(qApp->applicationName());

    // Подключение status bar

    connect(mGui->actionStatusBar, SIGNAL(triggered(bool)),
            statusBar(), SLOT(setVisible(bool)));

    // Подключение Exit и ResetAll

    connect(mGui->actionExit, SIGNAL(triggered()),
            this, SLOT(close()));
    connect(mGui->actionResetAll, SIGNAL(triggered()),
            this, SLOT(resetAll()));

    // Установливаем ярлыки действий некоторых пунктов меню

#if defined(Q_OS_WIN) || defined(Q_OS_LINUX)
    mGui->actionExit->setShortcuts(QList<QKeySequence>()
                                       << QKeySequence(Qt::ALT|Qt::Key_F4)
                                       << QKeySequence(Qt::CTRL|Qt::Key_Q));
#else
    #error Unsupported platform
#endif

    mGui->actionFullScreen->setShortcut(QKeySequence::FullScreen);

    // Получить параметры пользователя из предыдущей сессии, если таковые имеются

    loadSettings();

    // Инициализация выбраного состояния при полноэкранном режиме

    mGui->actionFullScreen->setChecked(isFullScreen());
}

//==============================================================================

MainWindow::~MainWindow()
{
    // Удаление некоторых внутренних объектов

    delete mSettings;

    // Удаление GUI

    delete mGui;
}

//==============================================================================

void MainWindow::changeEvent(QEvent *pEvent)
{
    QMainWindow::changeEvent(pEvent);

    // Изменения языка

    if (   (pEvent->type() == QEvent::LocaleChange)
        && (mGui->actionSystem->isChecked())) {

        setLocale(SystemLocale);
    }
}

//==============================================================================

void MainWindow::closeEvent(QCloseEvent *pEvent)
{
    // Запускается при закрытии программы

    bool canClose = true;

    // Сохранение параметров пользователя

    if (canClose) {

        saveSettings();

        // Принимает событие

        pEvent->accept();
    } else {

        // Игнорирует событие

        pEvent->ignore();
    }
}

//==============================================================================

void MainWindow::showEvent(QShowEvent *pEvent)
{

    QMainWindow::showEvent(pEvent);

    // Запуск в первый раз

    static bool firstTime = true;

    if (firstTime) {
        firstTime = false;

        mGui->actionStatusBar->setChecked(statusBar()->isVisible());
    }
}

//==============================================================================

void MainWindow::loadSettings()
{
    // Получить и установить язык, который будет использоваться OpenFiber

        setLocale(mSettings->value(SettingsLocale, SystemLocale).toString(), true);

        // Получить геометрию и состояние главного окна

        if (   !restoreGeometry(mSettings->value(SettingsGeometry).toByteArray())
            || !restoreState(mSettings->value(SettingsState).toByteArray())) {

            // Размер по умолчанию и положение главного окна

            double ratio = 1.0/13.0;
            QRect desktopGeometry = qApp->desktop()->availableGeometry();
            int horizSpace = ratio*desktopGeometry.width();
            int vertSpace  = ratio*desktopGeometry.height();

            setGeometry(desktopGeometry.left()+horizSpace,
                        desktopGeometry.top()+vertSpace,
                        desktopGeometry.width()-2*horizSpace,
                        desktopGeometry.height()-2*vertSpace);
        }

        // Получить ли строку состояния

        mGui->statusBar->setVisible(mSettings->value(SettingsStatusBarVisible, true).toBool());
}

//==============================================================================

void MainWindow::saveSettings() const
{
    // Отслеживание языка, который будет использоваться в OpenFiber

    mSettings->setValue(SettingsLocale, mLocale);

    // Отслеживайте геометрии и состояния главного окна

    mSettings->setValue(SettingsGeometry, saveGeometry());
    mSettings->setValue(SettingsState, saveState());
}
//==============================================================================

QString MainWindow::locale() const
{
    // Возвращает текущий язык

    return !mLocale.compare(SystemLocale)?
               QLocale::system().name().left(2):
               mLocale;
}

//==============================================================================

void MainWindow::setLocale(const QString &pLocale, const bool &pForceSetting)
{

    const QString systemLocale = QLocale::system().name().left(2);

    QString oldLocale = !mLocale.compare(SystemLocale)?systemLocale:mLocale;
    QString newLocale = !pLocale.compare(SystemLocale)?systemLocale:pLocale;

    // Отслеживайте новый язык, в случае необходимости

    if (pLocale.compare(mLocale) || pForceSetting) {
        mLocale = pLocale;

        QSettings settings(SettingsOrganization, SettingsApplication);

        settings.beginGroup(SettingsGlobal);
            settings.setValue(SettingsLocale, locale());
        settings.endGroup();
    }

    // Проверяем, является ли новый языковой стандарт отличным от старого,
    // и если да, то переводим все

    if (oldLocale.compare(newLocale) || pForceSetting) {
        // Указывает язык, который будет использоваться OpenFiber

        qApp->removeTranslator(&mQtTranslator);
        mQtTranslator.load(":qt_"+newLocale);
        qApp->installTranslator(&mQtTranslator);

        qApp->removeTranslator(&mAppTranslator);
        mAppTranslator.load(":app_"+newLocale);
        qApp->installTranslator(&mAppTranslator);

        // Переводим OpenFiber

        mGui->retranslateUi(this);

        setWindowTitle(qApp->applicationName());
    }

   mGui->actionSystem->setChecked(!pLocale.compare(SystemLocale));
   mGui->actionEnglish->setChecked(!pLocale.compare(EnglishLocale));
   mGui->actionRussian->setChecked(!pLocale.compare(RussianLocale));
}

//==============================================================================

void MainWindow::on_actionFullScreen_triggered()
{
    // Переключение в полноэкранный режим

    if (isFullScreen())
        showNormal();
     else
        showFullScreen();
}

//==============================================================================

void MainWindow::on_actionSystem_triggered()
{
    // Выбераем язык системы в качестве языка, используемого OpenFiber

    setLocale(SystemLocale);
}

//==============================================================================

void MainWindow::on_actionEnglish_triggered()
{
    // Выбераем английский язык в качестве языка, используемого OpenFiber

    setLocale(EnglishLocale);
}

//==============================================================================

void MainWindow::on_actionRussian_triggered()
{
    // Выбераем русский язык в качестве языка, используемого OpenFiber

    setLocale(RussianLocale);
}

//==============================================================================

void MainWindow::on_actionHelp_triggered()
{
}

//==============================================================================

static const QString OpenfiberHomePageUrl = "https://github.com/openfiber";

//==============================================================================

void MainWindow::on_actionHomePage_triggered()
{
    // Просмотр домашней страницы OpenFiber

    QDesktopServices::openUrl(QUrl(OpenfiberHomePageUrl));
}

//==============================================================================

void MainWindow::on_actionAbout_triggered()
{

    // Показывает некоторую информацию о OpenFiber

    QMessageBox::about(this, tr("About"),
                        "<h1 align=center><strong>"+version(qApp)+"</strong></h1>"
                      +"<h3 align=center><em>"+osName()+"</em></h3>"
                       +"<p align=center><em>"+copyright()+"</em></p>"
                       +"<a href=\""+QString(OpenfiberHomePageUrl)+"\"><strong>"+qApp->applicationName()+"</strong></a> "+tr("is a cross-platform modelling environment."));
}

//==============================================================================

void MainWindow::resetAll()
{
}

//==============================================================================
// End of file
//==============================================================================
