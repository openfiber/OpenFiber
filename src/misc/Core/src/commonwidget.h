//==============================================================================
// Common widget
//==============================================================================

#ifndef COMMONWIDGET_H
#define COMMONWIDGET_H

//==============================================================================

#include <QtGlobal>

//==============================================================================

#include <QColor>
#include <QString>

//==============================================================================

class QSettings;
class QSize;

//==============================================================================

class CommonWidget
{
public:
    explicit CommonWidget(QWidget *pParent = 0);

    virtual void loadSettings(QSettings *pSettings);
    virtual void saveSettings(QSettings *pSettings) const;

    virtual void retranslateUi();

protected:
    QSize defaultSize(const double &pRatio) const;

    void drawBorder(const bool &pDockedTop, const bool &pDockedLeft,
                    const bool &pDockedBottom, const bool &pDockedRight,
                    const bool &pFloatingTop, const bool &pFloatingLeft,
                    const bool &pFloatingBottom, const bool &pFloatingRight);

private:
    QWidget *mParent;
};

#endif

//==============================================================================
// End of file
//==============================================================================
