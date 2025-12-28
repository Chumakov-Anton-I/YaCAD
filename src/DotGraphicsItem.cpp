/* DotGraphicsItem implementation */

#include "DotGraphicsItem.h"
#include "HotSpot.h"

#include <QPainter>

DotGraphicsItem::DotGraphicsItem(QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    initItem();
}

DotGraphicsItem::DotGraphicsItem(double x, double y, QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    initItem(x, y);
}

QRectF DotGraphicsItem::boundingRect() const
{
    return QRectF(-m_size/2.0, -m_size/2.0, m_size, m_size);
}

void DotGraphicsItem::paint(QPainter *painter,
                            const QStyleOptionGraphicsItem *option,
                            QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    if (isSelected())
        m_hotSpot->setVisible(true);
    else {
        m_hotSpot->setVisible(false);
        painter->save();
        painter->setPen(Qt::NoPen);
        painter->setBrush(Qt::black);
        painter->drawEllipse(QPointF(), m_size/2.0, m_size/2.0);
        painter->restore();
    }
}

void DotGraphicsItem::initItem(double x, double y, int style)
{
    Q_UNUSED(style)

    setFlags(/*ItemIsMovable |*/ ItemIsSelectable);
    setPos(x, y);
    m_size = 4.0;
    m_hotSpot = new HotSpot(QPointF(), this);
}
