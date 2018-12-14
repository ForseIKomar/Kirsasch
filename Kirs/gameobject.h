#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>
#include <QGraphicsObject>
#include "main_settings.h"

enum{
    GAME_OBJECT,
    LIVING_OBJECT,
    LANDSHAFT,
    TRAP_OBJECT
};

enum {
    WALL,
    SPIKES,
    GROUND,
    HERO,
    MONSTER
};

class GameObject: public QGraphicsObject
{
public:
    explicit GameObject();
    ~GameObject();

public:
    void setCellPos(int x, int y);
    QPoint getCellPos();

    void setPriority(int prir);
    int getPrioriy();

    void setWalkProperty(bool canWalk);
    bool getWalkProperty();

    int getObjectType();
    int getSecondType();

    void setDefintion(int def);
    int getDefintion();

    int id;

private:
    QRectF boundingRect() const;

protected:
    int type, secType, defintion;
    int x, y;
    int priority;
    bool canWalkThrow;
};

#endif // GAMEOBJECT_H
