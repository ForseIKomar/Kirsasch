#include "cell.h"

Cell::Cell()
{
    x = 0;
    y = 0;
    currObject = NULL;
    land = NULL;
}

Cell::~Cell(){

}

void Cell::setLandshaft(Landshaft *landsh){
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
    objects.push_back(object);
    currObject = NULL;
    return objects.size() - 1;
}

GameObject* Cell::removeGameObject(int pos){
    GameObject* res = NULL;
    if ((pos < objects.size()) && (pos >= 0)){
        res = objects[pos];
        for (int i = pos; i < objects.size() - 1; ++i){
            objects[i] = objects[i + 1];
        }
    }
    objects.pop_back();
    currObject = NULL;
    return res;
}

void Cell::removeGameObject(GameObject *object){
    int pos = -1;
    for (int i = 0; i < objects.size(); ++i){
        if (objects[i] == object)
            pos = i;
    }
    if (pos >= 0)
        removeGameObject(pos);
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
