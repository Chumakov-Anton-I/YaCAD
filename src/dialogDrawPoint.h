#ifndef DIALOGDRAWPOINT_H
#define DIALOGDRAWPOINT_H

#include <QWidget>
#include "BasePropertyDialog.h"

class QDoubleSpinBox;

class CustomScene;
class DotGraphicsItem;

class DialogDrawPoint : public BasePropertyDialog //QWidget
{
    Q_OBJECT

public:
    DialogDrawPoint(CustomScene *scene, QWidget *parent = nullptr);
    ~DialogDrawPoint();

    bool eventFilter(QObject *watched, QEvent *event);

public slots:
    void accept();
    void cancel();

private:
    QDoubleSpinBox *m_Xbox;
    QDoubleSpinBox *m_Ybox;

    CustomScene *m_scene;
    DotGraphicsItem *m_newItem;

    bool positionFixed = false;

    bool makePoint();
};

#endif // DIALOGDRAWPOINT_H
