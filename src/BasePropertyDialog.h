#ifndef BASEPROPERTYDIALOG_H
#define BASEPROPERTYDIALOG_H

/*!
 * An abstract base class for all property dialogs of tools
 */

#include <QWidget>

class BasePropertyDialog : public QWidget
{
public:
    BasePropertyDialog(QWidget *parent) : QWidget(parent) {}
    virtual ~BasePropertyDialog() {}
public slots:
    virtual void accept() = 0;
    virtual void cancel() = 0;
protected:
    double X;
    double Y;
};

#endif // BASEPROPERTYDIALOG_H
