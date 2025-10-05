#ifndef DIALOGPANEL_H
#define DIALOGPANEL_H

/*!
 * The Sidebar widget
 *
 * This is an area where a property dialog of any tool can be placed.
 * The property dialog has to be a subclass of the BasePropertyDialog class.
*/

#include <QFrame>

class QVBoxLayout;
class QPushButton;
class BasePropertyDialog;

class DialogPanel : public QFrame
{
    Q_OBJECT

public:
    DialogPanel(QWidget *parent = nullptr);

    void setDialog(BasePropertyDialog *dialog);
    void closeDialog();

private:
    BasePropertyDialog *m_activeWidget;
    QVBoxLayout *m_topLayout;
    QFrame *m_headPanel;

    QPushButton *m_btnOK;
    QPushButton *m_btnCancel;
    QPushButton *m_btnHelp;

    const int position = 1;
    bool m_status = false;

private slots:
    void onPushHelp() {}
    void onPushCancel() { closeDialog(); }
    void onPushOK() {}
};

#endif // DIALOGPANEL_H
