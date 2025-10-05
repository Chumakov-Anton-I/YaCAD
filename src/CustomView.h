#ifndef CUSTOMVIEW_H
#define CUSTOMVIEW_H

#include <QGraphicsView>

class CustomView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CustomView(QWidget *parent = nullptr);

public slots:
    void zoomIn() { scaleBy(1.2); }
    void zoomOut() { scaleBy(1.0/1.2); }

protected:
    void wheelEvent(QWheelEvent *event);

private:
    void scaleBy(double factor) { scale(factor, factor); }
};

#endif // CUSTOMVIEW_H
