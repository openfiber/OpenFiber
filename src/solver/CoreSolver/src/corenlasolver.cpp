//==============================================================================
// Core NLA solver class
//==============================================================================

#include "corenlasolver.h"
//#include "plugin.h"

//==============================================================================

#include <QSettings>

//==============================================================================

CoreNlaSolver::CoreNlaSolver() :
    mComputeSystem(0),
    mParameters(0),
    mSize(0),
    mUserData(0)
{
}

//==============================================================================

void CoreNlaSolver::initialize(ComputeSystemFunction pComputeSystem,
                               double *pParameters, int pSize, void *pUserData)
{
    // Инициализация

    mComputeSystem = pComputeSystem;

    mParameters = pParameters;
    mSize = pSize;
    mUserData = pUserData;
}

//==============================================================================

static const QString SettingsGlobal = "Global";

//==============================================================================

CoreNlaSolver * nlaSolver(const QString &pRuntime)
{
    // Возвращение NLA решателя

    QSettings settings(SettingsOrganization, SettingsApplication);
    qulonglong res;

    settings.beginGroup(SettingsGlobal);
        res = settings.value(pRuntime, 0).toULongLong();
    settings.endGroup();

    // Возвращение NLA решателя

    return static_cast<CoreNlaSolver *>((void *) res);
}

//==============================================================================

void setNlaSolver(const QString &pRuntime, CoreNlaSolver *pGlobalNlaSolver)
{
    // Отслеживание NLA решателя

    QSettings settings(SettingsOrganization, SettingsApplication);

    settings.beginGroup(SettingsGlobal);
        settings.setValue(pRuntime, QString::number(qulonglong(pGlobalNlaSolver)));
    settings.endGroup();
}

//==============================================================================

void unsetNlaSolver(const QString &pRuntime)
{
    //  NoteStop отслеживание NLA решателя

    QSettings settings(SettingsOrganization, SettingsApplication);

    settings.beginGroup(SettingsGlobal);
        settings.remove(pRuntime);
    settings.endGroup();
}

//==============================================================================
// End of file
//==============================================================================
