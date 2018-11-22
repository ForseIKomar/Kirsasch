#ifndef CELL_H
#define CELL_H

#include <QVector>
#include "gameobject.h"
#include "landshaft.h"
class Cell
{
public:
    Cell();
    ~Cell();

public:
    int addGameObject(GameObject *object);
    GameObject* removeGameObject(int pos);
    void removeGameObject(GameObject *object);

    void setPosition(int x, int y);
    int getVectorSize();
    GameObject* getObjectAt(int pos);
    GameObject* getCurrentObject();

    void setLandshaft(Landshaft* landsh);
    Landshaft* getLandshaft();
    bool canWalkTo();

private:
    QVector<GameObject *> objects;
    GameObject* currObject;
    Landshaft* land;
    int x, y;
    bool canWalk;
};

#endif // CELL_H
