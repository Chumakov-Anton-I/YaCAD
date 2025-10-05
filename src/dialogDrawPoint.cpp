#include "dialogDrawPoint.h"

#include <QFormLayout>
#include <QBoxLayout>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QGraphicsScene>
#include <QLabel>

#include <QDebug>

#include "CustomScene.h"
#include "DotGraphicsItem.h"

DialogDrawPoint::DialogDrawPoint(CustomScene *scene, QWidget *parent)
    : BasePropertyDialog(parent), m_scene(scene)
{
    auto *topLayout = new QVBoxLayout;
    setLayout(topLayout);
    topLayout->addWidget(new QLabel(tr("Draw dot")));

    auto *form = new QFormLayout;
    topLayout->addLayout(form);

    m_Xbox = new QDoubleSpinBox;
    m_Ybox = new QDoubleSpinBox;
    form->addRow("X", m_Xbox);
    form->addRow("Y", m_Ybox);

    double max = std::numeric_limits<double>::max();
    m_Xbox->setRange(-max, max);
    m_Ybox->setRange(-max, max);

    m_scene->clearSelection();  // clear whole selection
    m_scene->setEditingMode(true);  // switch over the scene to editing mode

    m_newItem = new DotGraphicsItem(0, 0);
    m_scene->addItem(m_newItem);
}

DialogDrawPoint::~DialogDrawPoint() {}

bool DialogDrawPoint::eventFilter(QObject *watched, QEvent *event)
{
    Q_UNUSED(watched)
    if (event->type() == QEvent::GraphicsSceneMouseMove)
    {
        auto *mouseEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
        QPointF pos = mouseEvent->scenePos();
        X = pos.x();
        Y = pos.y();
        if (!positionFixed) {
            m_Xbox->setValue(X);
            m_Ybox->setValue(Y);
            m_newItem->setPos(X, Y);
            m_scene->update();  // TODO: this is optimizable
        }
    }
    else if (event->type() == QEvent::GraphicsSceneHoverEnter)
    {
        //
    }
    else if (event->type() == QEvent::GraphicsSceneMousePress)
    {
        // draw dot
        auto *mouseEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
        QPointF p = mouseEvent->buttonDownScenePos(Qt::LeftButton);
        X = p.x();
        Y = p.y();
        positionFixed = true;   // stop mouse tracking in coord edits
        makePoint();
        return true;
    }
    else if (event->type() == QEvent::GraphicsSceneMouseRelease)
        m_scene->update();  // TODO: this is optimizable
    else {
        // there we handle other cases
    }
    return false;   // The event always has to be delivered to the filtered object
}

void DialogDrawPoint::accept()
{
    positionFixed = false;
    makePoint();
}

void DialogDrawPoint::cancel()
{
    m_scene->removeItem(m_newItem);
    m_scene->setEditingMode(false);
    delete m_newItem;
}

bool DialogDrawPoint::makePoint()
{
    m_newItem->setPos(X, Y);    // fix the current item coords
    m_newItem = new DotGraphicsItem(X, Y);  // create a new item...
    m_scene->addItem(m_newItem);            // and add it to the scene
    positionFixed = false;
    return true;    // OK
}
