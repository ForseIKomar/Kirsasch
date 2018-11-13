#include "gameobject.h"
#include "main_settings.h"

GameObject::GameObject():
    QGraphicsObject()
{
    priority = 0;
    static int nextId = 0;
    id = nextId;
    nextId++;
}

GameObject::~GameObject(){

}

void GameObject::setPriority(int prir){
    priority = prir;
}

int GameObject::getPrioriy(){
    return priority;
}

QRectF GameObject::boundingRect() const{
    return QRectF(0, 0, cellWidth * 2, cellHeight * 2);
}

void GameObject::setCellPos(int x, int y){
    setPos(x * cellWidth, y * cellHeight);
}
