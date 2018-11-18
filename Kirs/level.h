#ifndef LEVEL_H
#define LEVEL_H

#include <QVector>
#include <QGraphicsSceneMouseEvent>

#include "gamescene.h"
#include "cellsmatrix.h"
#include "player.h"

class Level
{
public:
    explicit Level();
    ~Level();

    void generateField();

    void AddGameObject(GameObject *object, int x, int y);

    void MoveGameObject(GameObject *object, int from_x, int from_y, int to_x, int to_y);
    void MoveGameObject(GameObject *object, QPoint from, QPoint to);

    void RemoveGameObject(GameObject *object);
    void RemoveGameObject(int x, int y, int pos);

    void updateScene();

    void AddHero();

    void CheckMoving();





public:
    CellsMatrix*        field;
    GameScene*          graphics;
    Hero*               hero;
    Player*             player;

    QVector<GameObject *> objects;


};

#endif // LEVEL_H
