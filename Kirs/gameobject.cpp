#include "gameobject.h"
#include "main_settings.h"

GameObject::GameObject():
    QGraphicsObject()
{
    priority = 0;
    static int nextId = 0;
    id = nextId;
    nextId++;
    this->setZValue(0);
}

GameObject::~GameObject(){

}

void GameObject::setPriority(int prir){
    priority = prir;
    this->setZValue(prir);
}

int GameObject::getPrioriy(){
    return priority;
}

QRectF GameObject::boundingRect() const{
    return QRectF(0, 0, cellWidth, cellHeight);
}

void GameObject::setCellPos(int x, int y){
    setPos(x * cellWidth, y * cellHeight);
    this->x = x;
    this->y = y;
}

QPoint GameObject::getCellPos(){
    return(QPoint(this->x, this->y));
}
