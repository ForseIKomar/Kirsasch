#ifndef LEVEL_H
#define LEVEL_H

#include <QVector>
#include <QGraphicsSceneMouseEvent>

#include "gamescene.h"
#include "cellsmatrix.h"
#include "player.h"
#include "computer.h"
#include "eventqueue.h"

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

    void updateLevel();
    void activateEvent(GameEvent* event);

    void AddHero();
    void checkTraps(LivingObject *object);

    bool CheckMoving();
    void moveHero();

    void render();

    GameScene* getGraphics();
    Cell* getCellAt(int x, int y);
    Player* getPlayer();



private:
    CellsMatrix*        field;
    GameScene*          graphics;
    Player*             player;
    Computer*           enemy, *enemy2;
    EventQueue*         events;
};

#endif // LEVEL_H
