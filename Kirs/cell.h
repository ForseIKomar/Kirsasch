#ifndef CELL_H
#define CELL_H

#include <QVector>
#include "gameobject.h"

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

private:
    QVector<GameObject *> objects;
    GameObject* currObject;
    int x, y;
};

#endif // CELL_H
