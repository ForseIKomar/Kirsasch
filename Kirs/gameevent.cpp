#include "gameevent.h"

GameEvent::GameEvent()
{
    sender = NULL;
    reciever = NULL;
}

GameEvent::~GameEvent(){
    delete sender;
    delete reciever;
}


void GameEvent::MoveEvent(LivingObject *send, QPoint move){
    command = COMMAND_MOVE;
    sender = send;
    movingPoint = move;
}

void GameEvent::AttackEvent(LivingObject *send, LivingObject *recv, int dmg){
    command = COMMAND_ATTACK;
    sender = send;
    reciever = recv;
    damage = dmg;
}

void GameEvent::KillEvent(LivingObject *send, LivingObject *recv){
    command = COMMAND_KILL;
    sender = send;
    reciever = recv;
}

void GameEvent::DeleteEvent(GameObject *send){
    command = COMMAND_DELETE;
    deletableObject = send;
}

