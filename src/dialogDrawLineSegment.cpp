#include "dialogDrawLineSegment.h"
#include "CustomScene.h"
#include "LineSegmentItem.h"

#include <QBoxLayout>
#include <QFormLayout>
#include <QFrame>
#include <QGraphicsSceneMouseEvent>
#include <QLabel>
#include <QDoubleSpinBox>

DialogDrawLineSegment::DialogDrawLineSegment(CustomScene *scene, QWidget *parent)
    : BasePropertyDialog(parent), m_scene(scene)
{
    auto *topLayout = new QVBoxLayout;
    topLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(topLayout);
    topLayout->addWidget(new QLabel(tr("Draw line segment")));

    auto *form = new QFormLayout;
    topLayout->addLayout(form);

    m_X1box = new QDoubleSpinBox;
    m_Y1box = new QDoubleSpinBox;
    m_X2box = new QDoubleSpinBox;
    m_Y2box = new QDoubleSpinBox;

    form->addRow("X1", m_X1box);
    form->addRow("Y1", m_Y1box);
    /*auto *dash = new QFrame;
    dash->setFrameShape(QFrame::HLine | QFrame::Sunken);
    form->addWidget(dash);*/
    form->addRow("X2", m_X2box);
    form->addRow("Y2", m_Y2box);

    double max = std::numeric_limits<double>::max();
    m_X1box->setRange(-max, max);
    m_Y1box->setRange(-max, max);
    m_X2box->setRange(-max, max);
    m_Y2box->setRange(-max, max);

    m_scene->clearSelection();
    m_scene->setEditingMode(true);

    m_newItem = new LineSegmentItem;
    m_newItem->setEditMode(true);
    m_scene->addItem(m_newItem);
}

bool DialogDrawLineSegment::eventFilter(QObject *watched, QEvent *event)
{
    Q_UNUSED(watched)
    switch (event->type()) {
    case QEvent::GraphicsSceneMouseMove:
        onMouseMove(event);
        return true;
    case QEvent::GraphicsSceneMousePress:
        onMousePress(event);
        return true;
    case QEvent::GraphicsSceneHoverEnter:
        //
        return true;
    default:
        return false;
    }
}

void DialogDrawLineSegment::accept()
{
    position1fixed = false;
    position2fixed = false;
    makeLineSegment();
}

void DialogDrawLineSegment::cancel()
{
    m_scene->removeItem(m_newItem);
    m_scene->setEditingMode(false);
    delete m_newItem;
}

bool DialogDrawLineSegment::makeLineSegment()
{
    m_newItem->setEditMode(false);
    m_scene->update();
    m_newItem = new LineSegmentItem;
    m_newItem->setEditMode(true);
    m_scene->addItem(m_newItem);
    // reset dialog
    position1fixed = false;
    position2fixed = false;
    X1 = 0.0; Y1 = 0.0;
    X2 = 0.0; Y2 = 0.0;
    return true;
}

void DialogDrawLineSegment::onMousePress(QEvent *event)
{
    auto *mevent = static_cast<QGraphicsSceneMouseEvent *>(event);
    QPointF p = mevent->buttonDownScenePos(Qt::LeftButton);
    if (!position1fixed) {
        X1 = p.x();
        Y1 = p.y();
        m_X1box->setValue(X1);
        m_Y1box->setValue(Y1);
        m_newItem->setPos(p);
        position1fixed = true;
    } else {
        X2 = p.x();
        Y2 = p.y();
        m_X2box->setValue(X2);
        m_Y2box->setValue(Y2);
        m_newItem->setV2(p);
        position2fixed = true;
        makeLineSegment();
    }
}

void DialogDrawLineSegment::onMouseMove(QEvent *event)
{
    auto *mevent = static_cast<QGraphicsSceneMouseEvent *>(event);
    if (!position1fixed) {
        QPointF pos1 = mevent->scenePos();
        X1 = pos1.x();
        Y1 = pos1.y();
        m_X1box->setValue(X1);
        m_Y1box->setValue(Y1);
    } else {
        QPointF pos2 = mevent->scenePos();
        X2 = pos2.x();
        Y2 = pos2.y();
        m_X2box->setValue(X2);
        m_Y2box->setValue(Y2);
        m_newItem->setV2(pos2);
        m_scene->update();
    }
}

void DialogDrawLineSegment::onMouseRelease(QEvent *event)
{
    //
}
