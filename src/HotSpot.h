#ifndef HOTSPOT_H
#define HOTSPOT_H

#include <QGraphicsItem>

class HotSpot : public QGraphicsItem
{
public:
    explicit HotSpot(const QPointF &position, QGraphicsItem *parent = nullptr);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const { return QRectF(-m_size/2.0, -m_size/2.0, m_size, m_size); }

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

private:
    double m_size;
    bool m_captured;
};

#endif // HOTSPOT_H
