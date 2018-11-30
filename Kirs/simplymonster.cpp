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
    painter->drawEllipse(5, 10, 45, 50);
    painter->setBrush(Qt::white);
    painter->drawRect(1, 1, 49, 9);
    painter->setBrush(Qt::red);
    painter->drawRect(1, 1, 1 + 48.0 * this->health / this->maxHealth, 9);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
