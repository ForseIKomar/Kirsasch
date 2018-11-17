#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsSceneMouseEvent>

#include "gameobject.h"

class GameScene: public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = 0);
    ~GameScene();

    void render(QVector<GameObject *> objects);

signals:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QVector<GameObject *> lastVect;

};

#endif // GAMESCENE_H
