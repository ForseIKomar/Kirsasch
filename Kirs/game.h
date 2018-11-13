#ifndef GAME_H
#define GAME_H

#include <QVector>

#include "gamescene.h"
#include "cellsmatrix.h"
#include "player.h"

class Game
{
public:
    Game();
    ~Game();

    void AddGameObject(GameObject *object, int x, int y);
    void MoveGameObject(GameObject *object, int from_x, int from_y, int to_x, int to_y);
    void RemoveGameObject(GameObject *object);
    void RemoveGameObject(int x, int y, int pos);



private:
    CellsMatrix*        field;
    GameScene*          graphics;
    Player*             player;

    QVector<GameObject> objects;


};

#endif // GAME_H
