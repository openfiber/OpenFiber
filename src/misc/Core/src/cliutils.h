//==============================================================================
// CLI utilities
//==============================================================================

#ifndef CLIUTILS_H
#define CLIUTILS_H

//==============================================================================

#include "settings.h"

//==============================================================================

#include <QByteArray>

//==============================================================================

class QCoreApplication;

//==============================================================================

static const QString SettingsGlobal          = "Global";
static const QString SettingsLocale          = "Locale";
static const QString SettingsActiveDirectory = "ActiveDirectory";

//==============================================================================

QString osName();

QString shortVersion(QCoreApplication *pApp);
QString version(QCoreApplication *pApp);

QString copyright();

QString locale();

qulonglong totalMemory();
qulonglong freeMemory();

QString sizeAsString(const double &pSize,
                                 const int &pPrecision = 1);

QByteArray resourceAsByteArray(const QString &pResource);
bool  saveResourceAs(const QString &pResource,
                                const QString &pFilename);

void  * globalInstance(const QString &pObjectName,
                                  void *pDefaultGlobalInstance);

void  setActiveDirectory(const QString &pDirName);
QString activeDirectory();

QString nativeCanonicalFileName(const QString &pFileName);

QString formatErrorMessage(const QString &pErrorMessage);

QString nonDiacriticString(const QString &pString);

void doNothing(const int &pMax);

//==============================================================================

#endif

//==============================================================================
// End of file
//==============================================================================
