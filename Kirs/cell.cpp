#include "cell.h"
#include <iostream>
using namespace std;

Cell::Cell()
{
    x = 0;
    y = 0;
    currObject = NULL;
    land = NULL;
    canWalk = true;
}

Cell::~Cell(){

}

void Cell::setLandshaft(Landshaft *landsh){
    if (!landsh->getWalkProperty()){
        canWalk = false;
    }
    land = landsh;
}

Landshaft* Cell::getLandshaft(){
    return land;
}

void Cell::setPosition(int x, int y){
    this->x = x;
    this->y = y;
}

int Cell::addGameObject(GameObject *object){
    if (!object->getWalkProperty()){
        canWalk = false;
    }
    if (object->getObjectType() == GAME_OBJECT){
        objects.push_back(object);
    }
    else if (object->getObjectType() == LIVING_OBJECT){
        livings.push_back(static_cast<LivingObject *>(object));
    }
    currObject = NULL;
    return objects.size() - 1;
}

int Cell::addTrap(TrapOnLand *trap){
    if (!trap->getWalkProperty()){
        canWalk = false;
    }
    traps.push_back(trap);
    currObject = NULL;
    return traps.size() - 1;
}

void Cell::removeGameObject(int pos, int type){
    if (type == GAME_OBJECT){
        GameObject* res = NULL;
        if ((pos < objects.size()) && (pos >= 0)){
            res = objects[pos];
            for (int i = pos; i < objects.size() - 1; ++i){
                objects[i] = objects[i + 1];
            }
        }

        if (!res->getWalkProperty()){
            canWalk = true;
        }

        objects.pop_back();
        currObject = NULL;
    }
    if (type == LIVING_OBJECT){
        LivingObject* res = NULL;
        if ((pos < livings.size()) && (pos >= 0)){
            res = livings[pos];
            for (int i = pos; i < livings.size() - 1; ++i){
                livings[i] = livings[i + 1];
            }
        }

        if (!res->getWalkProperty()){
            canWalk = true;
        }

        livings.pop_back();
        currObject = NULL;
    }
}

void Cell::removeGameObject(GameObject *object){
    int pos = -1;
    if (object->getObjectType() == GAME_OBJECT){
        for (int i = 0; i < objects.size(); ++i){
            if (objects[i]->id == object->id)
                pos = i;
        }
    }
    else {
        for (int i = 0; i < livings.size(); ++i)
            if (livings[i]->id == object->id)
                pos = i;
    }
    if (pos >= 0)
        removeGameObject(pos, object->getObjectType());
}

int Cell::getVectorSize(){
    return objects.size();
}

GameObject* Cell::getObjectAt(int pos){
    if ((pos < objects.size()) && (pos >= 0))
        return objects[pos];
    else
        return NULL;
}

GameObject* Cell::getCurrentObject(){
    GameObject* n = NULL;
    if (currObject == NULL){
        if (objects.size() > 0){
            n = objects[0];
            for (int i = 1; i < objects.size(); ++i){
                if (n->getPrioriy() < objects[i]->getPrioriy())
                    n = objects[i];
            }
        }
        currObject = n;
    }
    return currObject;
}

QVector<GameObject* > Cell::getObjects(){
    QVector<GameObject* > t = objects;
    for (int i = 0; i < traps.size(); ++i){
        t.push_back(traps[i]);
    }
    for (int i = 0; i < livings.size(); ++i){
        t.push_back(livings[i]);
    }
    return t;
}

QVector<TrapOnLand* > Cell::getTraps(){
    return traps;
}

bool Cell::canWalkTo(){
    return canWalk;
}

QVector<LivingObject* > Cell::getLivings(){
    return livings;
}

LivingObject* Cell::getLiving(int pos){
    return livings[pos];
}
