//==============================================================================
// CLI utilities
//==============================================================================

#include "cliutils.h"

//==============================================================================

#include <QChar>
#include <QCoreApplication>
#include <QDate>
#include <QDir>
#include <QFile>
#include <QProcess>
#include <QResource>
#include <QSettings>
#include <QString>
#include <QStringList>

//==============================================================================

#if defined(Q_OS_WIN)
    #include <Windows.h>
#elif defined(Q_OS_LINUX)
    #include <unistd.h>
#endif

//==============================================================================

QString exec(const QString &pProgram, const QStringList &pArgs = QStringList())
{
    // Выполнить и вернуть вывод программы

    QProcess process;

    process.start(pProgram, pArgs);
    process.waitForFinished();

    return process.readAll().trimmed();
}

//==============================================================================

QString osName()
{
#if defined(Q_OS_WIN)
    switch (QSysInfo::WindowsVersion) {
    case QSysInfo::WV_NT:
        return "Microsoft Windows NT";
    case QSysInfo::WV_2000:
        return "Microsoft Windows 2000";
    case QSysInfo::WV_XP:
        return "Microsoft Windows XP";
    case QSysInfo::WV_2003:
        return "Microsoft Windows 2003";
    case QSysInfo::WV_VISTA:
        return "Microsoft Windows Vista";
    case QSysInfo::WV_WINDOWS7:
        return "Microsoft Windows 7";
    case QSysInfo::WV_WINDOWS8:
        return "Microsoft Windows 8";
    default:
        return "Microsoft Windows";
    }
#elif defined(Q_OS_LINUX)
    QString os = exec("uname", QStringList() << "-o");

    if (os.isEmpty())
        // Мы не смогли найти unix name или что-то пошло не так, так что ...

        return "Linux";
    else
        return os+" "+exec("uname", QStringList() << "-r");
#else
    #error Unsupported platform
#endif
}

//==============================================================================

QString shortVersion(QCoreApplication *pApp)
{
    QString res;
    QString appVersion = pApp->applicationVersion();

    if (!appVersion.contains("-"))
        res += "Version ";
    else
        res += "Snapshot ";

    res += appVersion;

    return res;
}

//==============================================================================

QString version(QCoreApplication *pApp)
{
    QString appVersion = pApp->applicationVersion();
    QString bitVersion;

    enum {
        SizeOfPointer = sizeof(void *)
    };

    if (SizeOfPointer == 4)
        bitVersion = "32-bit";
    else if (SizeOfPointer == 8)
        bitVersion = "64-bit";
    else
        // Не определена архитектура, так что ...

        bitVersion = "";

    bool snapshot = appVersion.contains("-");
    QString res = pApp->applicationName()+" ";

    if (snapshot)
        res += "[";

    res += appVersion;

    if (snapshot)
        res += "]";

    if (!bitVersion.isEmpty())
        res += " ("+bitVersion+")";

    return res;
}

//==============================================================================

QString copyright()
{
    return QObject::tr("Copyright")+" 2012-"+QString::number(QDate::currentDate().year());
}

//==============================================================================

QString locale()
{
    // Возвращает текущий язык

    QString res;
    QSettings settings(SettingsOrganization, SettingsApplication);

    settings.beginGroup(SettingsGlobal);
        res = settings.value(SettingsLocale).toString();
    settings.endGroup();

    return res;
}

//==============================================================================

qulonglong totalMemory()
{
    // Получить и вернутьс в байтах общее количество физической памяти

    qulonglong res = 0;

#if defined(Q_OS_WIN)
    MEMORYSTATUSEX memoryStatus;

    memoryStatus.dwLength = sizeof(memoryStatus);

    GlobalMemoryStatusEx(&memoryStatus);

    res = qulonglong(memoryStatus.ullTotalPhys);
#elif defined(Q_OS_LINUX)
    res = qulonglong(sysconf(_SC_PHYS_PAGES))*qulonglong(sysconf(_SC_PAGESIZE));
#else
    #error Unsupported platform
#endif

    return res;
}

//==============================================================================

qulonglong freeMemory()
{
    // Получить и вернуть в байтах доступный объема физической памяти

    qulonglong res = 0;

#if defined(Q_OS_WIN)
    MEMORYSTATUSEX memoryStatus;

    memoryStatus.dwLength = sizeof(memoryStatus);

    GlobalMemoryStatusEx(&memoryStatus);

    res = qulonglong(memoryStatus.ullAvailPhys);
#elif defined(Q_OS_LINUX)
    res = qulonglong(sysconf(_SC_AVPHYS_PAGES))*qulonglong(sysconf(_SC_PAGESIZE));
#else
    #error Unsupported platform
#endif

    return res;
}

//==============================================================================

QByteArray resourceAsByteArray(const QString &pResource)
{
    // Извлечение ресурсы как QByteArray

    QResource resource(pResource);

    if (resource.isValid()) {
        if (resource.isCompressed())
            return qUncompress(resource.data(), resource.size());
        else
            return QByteArray(reinterpret_cast<const char *>(resource.data()),
                              resource.size());
    }
    else {       
        return QByteArray();
    }
}

//==============================================================================

bool saveResourceAs(const QString &pResource, const QString &pFilename)
{
    // Сохранение ресурсов

    if (QResource(pResource).isValid()) {
        QFile file(pFilename);

        if (file.open(QIODevice::ReadWrite)) {
            QByteArray resource = resourceAsByteArray(pResource);
            bool res;

            res = file.write(resource) == resource.size();

            file.close();

            if (!res)
                file.remove();

            return res;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

//==============================================================================

void * globalInstance(const QString &pObjectName, void *pDefaultGlobalInstance)
{
    // Извлечение "глобального" экземпляра объекта

    QSettings settings(SettingsOrganization, SettingsApplication);
    qulonglong globalInstance;

    settings.beginGroup(SettingsGlobal);
        globalInstance = settings.value(pObjectName, 0).toULongLong();

        if (!globalInstance) {
            globalInstance = qulonglong(pDefaultGlobalInstance);
            settings.setValue(pObjectName, QString::number(globalInstance));
        }
    settings.endGroup();

    return (void *) globalInstance;
}

//==============================================================================

void setActiveDirectory(const QString &pDirName)
{
    // Отслеживайте активной директории

    QSettings settings(SettingsOrganization, SettingsApplication);

    settings.beginGroup(SettingsGlobal);
        settings.setValue(SettingsActiveDirectory, pDirName);
    settings.endGroup();
}

//==============================================================================

QString activeDirectory()
{
    // Получить и вернуть активно директорию

    QString res;
    QSettings settings(SettingsOrganization, SettingsApplication);

    settings.beginGroup(SettingsGlobal);
        res = settings.value(SettingsActiveDirectory).toString();
    settings.endGroup();

    return res;
}

//==============================================================================

QString nativeCanonicalFileName(const QString &pFileName)
{
    // Возвращение родного имени файла

    QString res = QDir::toNativeSeparators(QFileInfo(pFileName).canonicalFilePath());

    return res.isEmpty()?pFileName:res;
}

//==============================================================================

QString formatErrorMessage(const QString &pErrorMessage)
{
    static const QString DotDotDot = "...";

    if (pErrorMessage.isEmpty())
        return DotDotDot;

    // Формат сообщений об ошибке

    QString errorMessage = pErrorMessage;


    if (    (errorMessage.size() <= 1)
        || ((errorMessage.size() > 1) && !errorMessage[1].isUpper())) {
        errorMessage[0] = errorMessage[0].toLower();
    }

    // Возвращение сообщение об ошибке, лишь убедившись, что ее конец заканчивается
    // "..."

    int subsize = errorMessage.size();

    while (subsize && (errorMessage[subsize-1] == '.'))
        --subsize;

    return errorMessage.left(subsize)+DotDotDot;
}

//==============================================================================

QString nonDiacriticString(const QString &pString)
{
    // Remove and return a non-accentuated version of the given string
    // Note: this code is based on the one that can be found at
    //       http://stackoverflow.com/questions/14009522/how-to-remove-accents-diacritic-marks-from-a-string-in-qt

    static QString diacriticLetters = QString::fromUtf8("ŠŒŽšœžŸ¥µÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖØÙÚÛÜÝßàáâãäåæçèéêëìíîïðñòóôõöøùúûüýÿ");
    static QStringList nonDiacriticLetters = QStringList() << "S" << "OE" << "Z" << "s" << "oe" << "z" << "Y" << "Y" << "u" << "A" << "A" << "A" << "A" << "A" << "A" << "AE" << "C" << "E" << "E" << "E" << "E" << "I" << "I" << "I" << "I" << "D" << "N" << "O" << "O" << "O" << "O" << "O" << "O" << "U" << "U" << "U" << "U" << "Y" << "s" << "a" << "a" << "a" << "a" << "a" << "a" << "ae" << "c" << "e" << "e" << "e" << "e" << "i" << "i" << "i" << "i" << "o" << "n" << "o" << "o" << "o" << "o" << "o" << "o" << "u" << "u" << "u" << "u" << "y" << "y";

    QString res = QString();

    for (int i = 0, iMax = pString.length(); i < iMax; ++i) {
        QChar letter = pString[i];
        int dIndex = diacriticLetters.indexOf(letter);

        res.append((dIndex < 0)?letter:nonDiacriticLetters[dIndex]);
    }

    return res;
}

//==============================================================================

void doNothing(const int &pMax)
{
    // Функция, цель которой просто ничего не делать
    // Note: this function came about because there is no way, on Windows, to
    //       pause a thread for less than a millisecond (in the best of
    //       cases)...

    for (int i = 0; i < pMax; ++i)
#ifdef Q_OS_WIN
        __asm {
            nop
        }
#else
        asm("nop");
#endif
}


//==============================================================================
// End of file
//==============================================================================
