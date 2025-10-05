#ifndef LINESEGMENTITEM_H
#define LINESEGMENTITEM_H

#include <QGraphicsItem>
#include <QPen>

struct LineSegmentData {
    double X1;
    double Y1;
    double X2;
    double Y2;
    double angle;
    double length;
};

class LineSegmentItem : public QGraphicsItem
{
public:
    enum { Type = UserType + 3 };
    explicit LineSegmentItem(QGraphicsItem *parent = nullptr);
    LineSegmentItem(const LineSegmentData &data, QGraphicsItem *parent = nullptr);
    ~LineSegmentItem() {}

    void setV1(QPointF p);
    void setV2(QPointF p);
    inline void setV1(double x, double y) { setV1(QPointF(x, y)); }
    inline void setV2(double x, double y) { setV2(QPointF(x, y)); }
    void setLength(double length);
    void setAngle(double angle);
    void setEditMode(bool mode) { m_editMode = mode; }

    QPointF getV1() const { return m_V1; }
    QPointF getV2() const { return m_V2; }
    double length() const { return m_length; }
    double angle() const { return m_angle; }
    bool isValid() const { return m_isValid; }

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    LineSegmentData m_data;

    QPen m_pen;
    double m_length;
    QPointF m_V1;   // in absolute CS
    QPointF m_V2;   // in absolute CS
    double m_angle;
    int m_style;

    bool m_isValid = false;
    bool m_editMode = false;

    void updateItem();
    void initItem(QPointF V1, QPointF V2, int style = 0);
    inline void initItem(int style = 0) { initItem(QPointF(), QPointF(), style); }
};

#endif // LINESEGMENTITEM_H
