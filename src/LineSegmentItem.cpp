#include "LineSegmentItem.h"

#include <QPainter>
#include <cmath>

#include <QDebug>

LineSegmentItem::LineSegmentItem(QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    initItem();
}

LineSegmentItem::LineSegmentItem(const LineSegmentData &data, QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    initItem();
    m_data = data;
}

void LineSegmentItem::setV1(QPointF p)
{
    if (p == m_V2) {
        //m_isValid = false;
        return;
    }
    m_V1 = p;
    updateItem();
}

void LineSegmentItem::setV2(QPointF p)
{
    if (p == m_V1) {
        //m_isValid = false;
        return;
    }
    m_V2 = p;
    updateItem();
}

void LineSegmentItem::setLength(double length)
{
    /*if (length <= 0.0) {
        //m_isValid = false;
        return;
    }
    if (m_isValid) {
        QPointF e = (m_V2 - m_V1) / m_length;
        m_V2 = m_V1 + e * length;
    }
    m_length = length;*/
}

void LineSegmentItem::setAngle(double angle)
{
    /*m_angle = angle;
    if (!m_isValid)
        return;
    // TODO: update V2 position
    */
}

QRectF LineSegmentItem::boundingRect() const
{
    double x = qMin(m_V1.x(), m_V2.x());
    double y = qMin(m_V1.y(), m_V2.y());
    double w = qAbs(m_V1.x() - m_V2.x());
    double h = qAbs(m_V1.y() - m_V2.y());
    return QRectF(x, y, w, h);
}

void LineSegmentItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    if (!m_isValid) return;
    if (isSelected()) {
        m_pen.setColor(Qt::green);
        m_pen.setWidth(2);
    } else if (m_editMode) {
        m_pen.setColor(Qt::black);
        m_pen.setCosmetic(true);
    } else {
        m_pen.setColor(Qt::black);
        m_pen.setWidth(2);
    }
    painter->setPen(m_pen);
    painter->drawLine(QPointF(), mapFromScene(m_V2));
}

void LineSegmentItem::updateItem()
{
    m_length = std::sqrt(std::pow(m_V2.x() - m_V1.x(), 2) + std::pow(m_V2.y() - m_V1.y(), 2));
    if (m_length > 0)
        m_isValid = true;
    // TODO: calculate angle
}

void LineSegmentItem::initItem(QPointF V1, QPointF V2, int style)
{
    m_V1 = V1;
    m_V2 = V2;
    m_length = 0.0;
    m_angle = 0.0;
    m_style = style;
}
