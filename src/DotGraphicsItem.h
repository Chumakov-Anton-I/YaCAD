#ifndef DOTGRAPHICSITEM_H
#define DOTGRAPHICSITEM_H

#include <QGraphicsItem>

class DotGraphicsItem : public QGraphicsItem
{
public:
    enum {Type = UserType + 2};
    //enum DotStyle { Unknown = -1, DotRound, DotCross, DotXCross, DotRing };
    explicit DotGraphicsItem(QGraphicsItem *parent = nullptr);
    DotGraphicsItem(double x, double y, QGraphicsItem *parent = nullptr);
    virtual ~DotGraphicsItem() {}

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int type() const { return Type; }
    //int style() const { return DotStyle; }

private:
    double m_size;
    int m_style;
    void initItem(double x = 0.0, double y = 0.0, int style = 0);
};

// TODO: add data stream operators >> and <<

#endif // DOTGRAPHICSITEM_H
