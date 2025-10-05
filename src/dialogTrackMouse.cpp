#include "dialogTrackMouse.h"
#include "BasePropertyDialog.h"

#include <QFormLayout>
#include <QLineEdit>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>

DialogTrackMouse :: DialogTrackMouse(QWidget *parent)
    : BasePropertyDialog(parent)
{
    QFormLayout *topLayout = new QFormLayout;
    setLayout(topLayout);
    m_Xedit = new QLineEdit;
    m_Yedit = new QLineEdit;
    topLayout->addRow("X", m_Xedit);
    topLayout->addRow("Y", m_Yedit);
}

bool DialogTrackMouse::eventFilter(QObject *watched, QEvent *event)
{
    Q_UNUSED(watched)
    if (event->type() == QEvent::GraphicsSceneMouseMove)
    {
        auto *mouseEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
        QPointF pos = mouseEvent->scenePos();
        X = pos.x();
        Y = pos.y();
        m_Xedit->setText(QString("%1").arg(X, 0, 'g', 6));
        m_Yedit->setText(QString("%1").arg(Y, 0, 'g', 6));
        //return true;
    }
    return false;   // The event always has to go to the filtered object
}
