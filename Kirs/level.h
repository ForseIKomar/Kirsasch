#ifndef LEVEL_H
#define LEVEL_H

#include <QVector>
#include <QGraphicsSceneMouseEvent>

#include "gamescene.h"
#include "cellsmatrix.h"
#include "player.h"
#include "indicatorscene.h"

class Level
{
public:
    explicit Level();
    ~Level();

    void generateField();

    void AddGameObject(GameObject *object, int x, int y);

    void MoveGameObject(GameObject *object, int to_x, int to_y);
    void MoveGameObject(GameObject *object, QPoint to);

    void RemoveGameObject(GameObject *object);
    void RemoveGameObject(int x, int y, int pos);

    void updateLevel();

    void AddHero();

    void CheckMoving();
    void moveHero();

    GameScene* getGraphics();
    Cell* getCellAt(int x, int y);
    Player* getPlayer();



private:
    CellsMatrix*        field;
    GameScene*          graphics;
    Player*             player;
    IndicatorScene*     indicators;

    QVector<GameObject *> objects;
};

#endif // LEVEL_H
