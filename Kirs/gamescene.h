#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QKeyEvent>

#include "gameobject.h"

class GameScene: public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = 0);
    ~GameScene();

    void render(QVector<GameObject *> objects);

    QPoint* getClickPos();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void keyPressEvent(QKeyEvent *event);

    void setLeftPoint(int x, int y);

private:
    QVector<GameObject *> lastVect;
    QPoint* lastClickPos;
    bool hasClicked;
    int leftX, leftY;
};

#endif // GAMESCENE_H
