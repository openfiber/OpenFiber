//==============================================================================
// Settings
//==============================================================================

#ifndef SETTINGS_H
#define SETTINGS_H

//==============================================================================

#include <QString>
#include <QStringList>

//==============================================================================

static const QString SettingsOrganization            = "IIP";
static const QString SettingsApplication             = "OpenFiber";
static const QString SettingsGlobal                  = "Global";
static const QString SettingsLocale                  = "Locale";
static const QString SettingsActiveDirectory         = "ActiveDirectory";
static const QString SettingsGeometry                = "Geometry";
static const QString SettingsState                   = "State";
static const QString SettingsDockedWidgetsVisible    = "DockedWidgetsVisible";
static const QString SettingsStatusBarVisible        = "StatusBarVisible";

//==============================================================================

class Settings
{
public:
    Settings();
};

#endif // SETTINGS_H

//==============================================================================
// End of file
//==============================================================================
