//==============================================================================
// Common widget
//==============================================================================

#include "commonwidget.h"
#include "cliutils.h"

//==============================================================================

#include <QApplication>
#include <QDesktopWidget>
#include <QDockWidget>
#include <QPainter>
#include <QPen>
#include <QSettings>


//==============================================================================

CommonWidget::CommonWidget(QWidget *pParent) :
    mParent(pParent)
{
}

//==============================================================================

QSize CommonWidget::defaultSize(const double &pRatio) const
{
    // По умолчанию размер виджета

    QRect desktopGeometry = qApp->desktop()->availableGeometry();

    return QSize(pRatio*desktopGeometry.width(),
                 pRatio*desktopGeometry.height());
}

//==============================================================================

void CommonWidget::loadSettings(QSettings *pSettings)
{
    Q_UNUSED(pSettings);

    // По умолчанию ничего не делает...
}

//==============================================================================

void CommonWidget::saveSettings(QSettings *pSettings) const
{
    Q_UNUSED(pSettings);

    // По умолчанию ничего не делает...
}

//==============================================================================

void CommonWidget::retranslateUi()
{
    // По умолчанию ничего не делает...
}

//==============================================================================

void CommonWidget::drawBorder(const bool &pDockedTop, const bool &pDockedLeft,
                              const bool &pDockedBottom, const bool &pDockedRight,
                              const bool &pFloatingTop, const bool &pFloatingLeft,
                              const bool &pFloatingBottom, const bool &pFloatingRight)
{
    // Рисование границы виджета
    QDockWidget *dockWidget = dynamic_cast<QDockWidget *>(mParent);
    QWidget *widget = dynamic_cast<QWidget *>(this);

    if (dockWidget && widget) {

        QPainter painter(widget);

        QPen newPen = painter.pen();

        newPen.setColor(Qt::lightGray);

        painter.setPen(newPen);

        bool isDocked = !dockWidget->isFloating();
        QRect border = widget->rect();

        if ((pDockedTop && isDocked) || (pFloatingTop && !isDocked))
            painter.drawLine(border.topLeft(), border.topRight());

        if ((pDockedLeft && isDocked) || (pFloatingLeft && !isDocked))
            painter.drawLine(border.topLeft(), border.bottomLeft());

        if ((pDockedBottom && isDocked) || (pFloatingBottom && !isDocked))
            painter.drawLine(border.bottomLeft(), border.bottomRight());

        if ((pDockedRight && isDocked) || (pFloatingRight && !isDocked))
            painter.drawLine(border.topRight(), border.bottomRight());
    }
}

//==============================================================================
// End of file
//==============================================================================
