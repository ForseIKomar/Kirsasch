#include "cell.h"

Cell::Cell()
{
    x = 0;
    y = 0;
    currObject = NULL;
}

Cell::~Cell(){

}

void Cell::setPosition(int x, int y){
    this->x = x;
    this->y = y;
}

int Cell::addGameObject(GameObject *object){
    objects.push_back(object);
    if ((currObject == NULL) || (currObject->getPrioriy() < object->getPrioriy()))
        currObject = object;
    for (int i = 0; i < objects.size(); ++i){
        objects[i]->setVisible(false);
    }
    if (currObject != NULL)
        currObject->setVisible(true);
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

    if (objects.size() > 0){
        int numb = 0;
        for (int i = 0; i < objects.size(); ++i){
            objects[i]->setVisible(false);
            if (objects[numb]->getPrioriy() < objects[i]->getPrioriy()){
                numb = i;
            }
        }
        currObject = objects[numb];
        if (currObject != NULL)
            currObject->setVisible(true);
    }
    else
        currObject = NULL;
    return res;
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
