#ifndef DIALOGDRAWLINESEGMENT_H
#define DIALOGDRAWLINESEGMENT_H

#include "BasePropertyDialog.h"

class CustomScene;
class LineSegmentItem;
class QDoubleSpinBox;

class DialogDrawLineSegment : public BasePropertyDialog
{
    Q_OBJECT
public:
    explicit DialogDrawLineSegment(CustomScene *scene, QWidget *parent = nullptr);
    ~DialogDrawLineSegment() {}

    bool eventFilter(QObject *watched, QEvent *event);

public slots:
    void accept();
    void cancel();

private:
    double X1, Y1, X2, Y2;
    QDoubleSpinBox *m_X1box;
    QDoubleSpinBox *m_Y1box;
    QDoubleSpinBox *m_X2box;
    QDoubleSpinBox *m_Y2box;

    CustomScene *m_scene;
    LineSegmentItem *m_newItem;

    bool position1fixed = false;
    bool position2fixed = false;

    bool makeLineSegment();

    void onMousePress(QEvent *event);
    void onMouseMove(QEvent *event);
    void onMouseRelease(QEvent *event);
};

#endif // DIALOGDRAWLINESEGMENT_H
