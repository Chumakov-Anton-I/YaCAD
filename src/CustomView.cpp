#include "CustomView.h"

#include <QPainter>
#include <QWheelEvent>
#include <cmath>

CustomView::CustomView(QWidget *parent)
    : QGraphicsView(parent)
{
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setDragMode(RubberBandDrag);
    setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    setRubberBandSelectionMode(Qt::ContainsItemBoundingRect);
    setCursor(QCursor(Qt::CrossCursor));

    setMouseTracking(true);
}

void CustomView::wheelEvent(QWheelEvent *event)
{
    scaleBy(std::pow(4.0 / 3.0, (-event->angleDelta().y() / 120.0)));
}
