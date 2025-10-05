/* DrawingWidget implementation */

#include "DrawingWidget.h"
#include "CustomScene.h"
#include "CustomView.h"
#include "DialogPanel.h"
#include "dialogTrackMouse.h"
#include "dialogDrawPoint.h"
#include "dialogDrawLineSegment.h"

#include <QBoxLayout>
#include <QSplitter>
#include <QToolBar>
#include <QAction>
#include <QCursor>
#ifdef ENABLE_HARDWARE_ACCELERATION
# include <QOpenGLWidget>
#endif

DrawingWidget::DrawingWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *topLayout = new QVBoxLayout;
    topLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(topLayout);

    // Big Tool Bar
//    m_ribbon = new RibbonWidget;
//    m_ribbon->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
//    topLayout->addWidget(m_ribbon);
    m_ribbon = new QHBoxLayout;
    topLayout->addLayout(m_ribbon);

    // Splitted workspace
    QSplitter *workPlace = new QSplitter(Qt::Horizontal);
    workPlace->setContentsMargins(0, 0, 0, 0);
    workPlace->setChildrenCollapsible(false);
    topLayout->addWidget(workPlace);

    // SideBar
    m_propertyPane = new DialogPanel;
    m_propertyPane->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    workPlace->addWidget(m_propertyPane);

    // Scene
    m_scene = new CustomScene;//(0, 0, 600, 500);
    m_scene->setSceneRect(-1000.0, -1000.0, 2000.0, 2000.0);

    // Viewport
    m_view = new CustomView;
#ifdef ENABLE_HARDWARE_ACCELERATION
    m_view->setViewport(new QOpenGLWidget);
#endif
    m_view->setScene(m_scene);
    //m_view->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    workPlace->addWidget(m_view);
    workPlace->setStretchFactor(0, 0);  // Sidebar must not resize...
    workPlace->setStretchFactor(1, 1);  // ...when the whole widget is resized

    makeActions();
    makeToolBar();
}

void DrawingWidget::showDialog(BasePropertyDialog *dialog)
{
    m_propertyPane->setDialog(dialog);
    m_scene->installEventFilter(dialog);
}

void DrawingWidget::makeActions()
{
    m_actTrackMouse = new QAction(tr("Track mouse"), this);
    //m_actTrackMouse->setIcon(...);
    connect(m_actTrackMouse, &QAction::triggered, this, &DrawingWidget::trackMouse);

    m_actDrawDot = new QAction(tr("Point"), this);
    //m_actDrawDot->setIcon(...);
    connect(m_actDrawDot, &QAction::triggered, this, &DrawingWidget::drawDot);

    m_actDrawLineSegment = new QAction(tr("Line segment"), this);
    //m_actDrawLineSegment->setIcon(...);
    connect(m_actDrawLineSegment, &QAction::triggered, this, &DrawingWidget::drawLineSegment);
}

void DrawingWidget::makeToolBar()
{
    m_mainToolbar = new QToolBar("Drawing");
    m_ribbon->addWidget(m_mainToolbar);
    m_mainToolbar->addAction(m_actTrackMouse);
    m_mainToolbar->addAction(m_actDrawDot);
    m_mainToolbar->addAction(m_actDrawLineSegment);
}

void DrawingWidget::trackMouse()
{
    DialogTrackMouse *dialog = new DialogTrackMouse(this);
    showDialog(dialog);
}

void DrawingWidget::drawDot()
{
    DialogDrawPoint *dialog = new DialogDrawPoint(m_scene, this);
    showDialog(dialog);    // probably here we should implement the move semantics
}

void DrawingWidget::drawLineSegment()
{
    auto *dialog = new DialogDrawLineSegment(m_scene, this);
    showDialog(dialog);
}
