#include "simplymonster.h"
#include <QPainter>

SimplyMonster::SimplyMonster()
{
    setWalkProperty(false);
    image = new QImage();
}

SimplyMonster::~SimplyMonster(){

}

void SimplyMonster::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(Qt::green);
    painter->drawEllipse(cellWidth * 0.1, cellWidth * 0.2, cellWidth * 0.9, cellWidth);
    painter->setBrush(Qt::white);
    painter->drawRect(1, 1, cellWidth - 1, cellWidth * 0.2 - 1);
    painter->setBrush(Qt::red);
    painter->drawRect(1, 1, 1 + (cellWidth - 2) * this->health / this->maxHealth, cellWidth * 0.2 - 1);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
