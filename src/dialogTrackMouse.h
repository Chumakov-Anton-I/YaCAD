#ifndef DIALOGTRACKMOUSE_H
#define DIALOGTRACKMOUSE_H

#include <QWidget>

#include "BasePropertyDialog.h"

class QLineEdit;

class DialogTrackMouse : public BasePropertyDialog
{
    Q_OBJECT

public:
    DialogTrackMouse(QWidget *parent = nullptr);
    ~DialogTrackMouse() {}

    bool eventFilter(QObject *watched, QEvent *event);

public slots:
    void accept() {}
    void cancel() {}

private:
    QLineEdit *m_Xedit;
    QLineEdit *m_Yedit;
};

#endif // DIALOGTRACKMOUSE_H
