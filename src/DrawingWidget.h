#ifndef DRAWINGWIDGET_H
#define DRAWINGWIDGET_H

/*
 * This widget provides functionality of a graphical document.
 * It contains the ribbon as the main toolbar, the sidebar as the dialog area
 * and the viewport.
*/

#include <QWidget>

class QToolBar;
class QAction;
class QHBoxLayout;
class DialogPanel;
class BasePropertyDialog;

class CustomScene;
class CustomView;

class DrawingWidget : public QWidget
{
    Q_OBJECT

public:
    DrawingWidget(QWidget *parent = nullptr);

    void showDialog(BasePropertyDialog *dialog);   // show dialog on the sidebar
    //void cancelDialog();    // close and destroy active dialog on the sidebar
private:
    CustomScene *m_scene;
    CustomView  *m_view;
    QHBoxLayout *m_ribbon;
    DialogPanel *m_propertyPane;
    QToolBar *m_mainToolbar;

    QAction *m_actTrackMouse;

    void makeActions();
    void makeToolBar();

private slots:
    void trackMouse();
};

#endif // DRAWINGWIDGET_H
