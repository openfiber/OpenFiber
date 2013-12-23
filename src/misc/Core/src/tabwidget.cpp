//==============================================================================
// Tab widget
//==============================================================================

#include "tabwidget.h"

//==============================================================================

#include <QPainter>
#include <QPaintEvent>

//==============================================================================

TabWidget::TabWidget(QWidget *pParent) :
    QTabWidget(pParent),
    CommonWidget(pParent)
{
}


//==============================================================================
void TabWidget::paintEvent(QPaintEvent *pEvent)
{
    // Показывание логотипа

    if (!count()) {
        // Если нет вклабок показывать логотип

        QPixmap pixmap;

        pixmap.load(":cellmlLogo");

        QPainter paint(this);

        paint.drawPixmap(0.5*(width()-pixmap.width()),
                         0.5*(height()-pixmap.height()),
                         pixmap);

        // Применение события

        pEvent->accept();
    } else {
        // Если есть вкладки

        QTabWidget::paintEvent(pEvent);
    }
}

//==============================================================================
// End of file
//==============================================================================
