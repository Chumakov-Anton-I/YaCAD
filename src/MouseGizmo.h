#ifndef MOUSEGIZMO_H
#define MOUSEGIZMO_H

#include <QGraphicsItem>
#include <QPen>

//class QPen;

/**
 * @brief
 * The MouseGizmo class draws a small X-cross on the screen,
 * which follows a cursor.
 */
class MouseGizmo : public QGraphicsItem
{
public:
    enum {Type = UserType + 1}; // TODO: define all objects types somewhere
    explicit MouseGizmo();
    ~MouseGizmo() { }

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int type() const { return Type; }
private:
    QPen m_pen;
    const int m_size = 5;   // the half of mouse gizmo's size (w and h)
};

#endif // MOUSEGIZMO_H
