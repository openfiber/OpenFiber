//==============================================================================
// Core solver class
//==============================================================================

#ifndef CORESOLVER_H
#define CORESOLVER_H

//==============================================================================

#include <QMap>
#include <QVariant>

//==============================================================================

enum {
    SizeOfDouble = sizeof(double),
    SizeOfDoublePointer = sizeof(double *)
};

//==============================================================================

typedef QMap<QString, QVariant> Properties;

//==============================================================================

class CoreSolver : public QObject
{
    Q_OBJECT

public:
    explicit CoreSolver();

    void setProperties(const Properties &pProperties);

    void emitError(const QString &pErrorMessage);

protected:
    Properties mProperties;

Q_SIGNALS:
    void error(const QString &pErrorMessage);
};

//==============================================================================

#endif

//==============================================================================
// End of file
//==============================================================================
