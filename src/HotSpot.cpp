#include "HotSpot.h"

#include <QPainter>
#include <QGraphicsSceneHoverEvent>
#include <QCursor>

HotSpot::HotSpot(const QPointF &position, QGraphicsItem *parent)
    : QGraphicsItem{parent}, m_size{8.0}, m_captured{false}
{
    setPos(position);
    setFlag(ItemIgnoresTransformations);
    setFlag(ItemIsSelectable, false);
    setVisible(false);
    setCursor(Qt::SizeAllCursor);
}

void HotSpot::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::black);
    painter->drawRect(-m_size/2, -m_size/2, m_size, m_size);
    painter->restore();
}

void HotSpot::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event)
    //
}

void HotSpot::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event)
    //
}
