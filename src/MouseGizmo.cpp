#include "MouseGizmo.h"

//#include <QPen>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

MouseGizmo::MouseGizmo()
    : QGraphicsItem(nullptr)
{
    setFlags(ItemIgnoresTransformations);
    setCacheMode(DeviceCoordinateCache);
    setPos(0.0, 0.0);
    m_pen.setColor(Qt::black); //= new QPen(Qt::black, 2);
    m_pen.setWidth(1);
}

QRectF MouseGizmo::boundingRect() const
{
    return QRectF(-m_size, -m_size, 2*m_size, 2*m_size);
}

void MouseGizmo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setPen(m_pen);
    //painter->setBrush(Qt::NoBrush);
    painter->drawLine(-m_size,  m_size, m_size, -m_size);
    painter->drawLine(-m_size, -m_size, m_size,  m_size);
}
