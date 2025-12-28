#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include <QGraphicsScene>

class MouseGizmo;

class CustomScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit CustomScene(QObject *parent = nullptr);
    ~CustomScene() {}

    /// Set/reset the editing mode of the scene
    void setEditingMode(bool on);

public slots:
    void removeSelected();

private:
    MouseGizmo *m_gizmo;
    bool m_editingMode = false;

    void initScene();

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CUSTOMSCENE_H
