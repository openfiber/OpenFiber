//==============================================================================
// Core solver class
//==============================================================================

#ifndef CORESOLVER_H
#define CORESOLVER_H

//==============================================================================

#include <QMap>
#include <QVariant>

//==============================================================================

typedef QMap<QString, QVariant> Properties;

//==============================================================================

class CoreSolver : public QObject
{
    Q_OBJECT

public:
    explicit CoreSolver();

    void setProperty(const QString &pName, const QVariant &pValue);

    void emitError(const QString &pErrorMsg);

protected:
    Properties mProperties;

    virtual bool isValidProperty(const QString &pName) const = 0;

Q_SIGNALS:
    void error(const QString &pErrorMsg);
};

#endif

//==============================================================================
// End of file
//==============================================================================
