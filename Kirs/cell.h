#ifndef CELL_H
#define CELL_H

#include <QVector>
#include "landshaft.h"
#include "traponland.h"
class Cell
{
public:
    Cell();
    ~Cell();

public:
    int addGameObject(GameObject *object);
    int addTrap(TrapOnLand *trap);
    void removeGameObject(int pos, int type);
    void removeGameObject(GameObject *object);

    void setPosition(int x, int y);
    int getVectorSize();
    GameObject* getObjectAt(int pos);
    GameObject* getCurrentObject();
    LivingObject* getLiving(int pos);
    QVector<GameObject* > getObjects();
    QVector<TrapOnLand* > getTraps();
    QVector<LivingObject* > getLivings();

    void setLandshaft(Landshaft* landsh);
    Landshaft* getLandshaft();
    bool canWalkTo();

private:
    QVector<GameObject *> objects;
    QVector<TrapOnLand *> traps;
    QVector<LivingObject *> livings;
    GameObject* currObject;
    Landshaft* land;
    int x, y;
    bool canWalk;
};

#endif // CELL_H
