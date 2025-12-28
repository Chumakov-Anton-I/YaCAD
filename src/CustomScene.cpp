#include "CustomScene.h"
#include "MouseGizmo.h"

#include <QGraphicsSceneMouseEvent>

CustomScene::CustomScene(QObject *parent)
    : QGraphicsScene(parent)
{
    initScene();
}

void CustomScene::setEditingMode(bool on)
{
    m_editingMode = on;
    m_gizmo->setVisible(on);  // it's annoying
}

void CustomScene::removeSelected()
{
    QList<QGraphicsItem *> selected = selectedItems();
    for (auto it = selected.begin(); it != selected.end(); ++it) {
        removeItem(*it);
        delete *it;
    }
}

void CustomScene::initScene()
{
    m_gizmo = new MouseGizmo;
    addItem(m_gizmo);
    m_gizmo->setVisible(false);
}

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    m_gizmo->setPos(event->scenePos());
    QGraphicsScene::mouseMoveEvent(event);
}
