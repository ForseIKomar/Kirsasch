#ifndef GAMEEVENT_H
#define GAMEEVENT_H

#include "gameobject.h"
#include "livingobject.h"

enum Commands
{
    COMMAND_MOVE,
    COMMAND_ATTACK,
    COMMAND_KILL,
    COMMAND_DELETE
};

class GameEvent
{
public:
    GameEvent();
    ~GameEvent();

    void MoveEvent(LivingObject *send, QPoint move);
    void AttackEvent(LivingObject *send, LivingObject *recv, int dmg);
    void KillEvent(LivingObject *send, LivingObject *recv);
    void DeleteEvent(GameObject *send);

public:
    Commands command;
    LivingObject *sender;
    LivingObject *reciever;
    GameObject  *deletableObject;
    QPoint movingPoint;
    int damage;
};

#endif // GAMEEVENT_H
