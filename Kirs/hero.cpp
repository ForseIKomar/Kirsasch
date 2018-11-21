#include "hero.h"
#include "main_settings.h"

#include <QPainter>

Hero::Hero(): GameObject()
{
    color = Qt::red;
}

Hero::~Hero(){

}

void Hero::setColor(QBrush brush){
    color = brush;
}

void Hero::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(color);
    painter->drawEllipse(0, 0, cellWidth, cellHeight);
    Q_UNUSED(widget);
    Q_UNUSED(option);
}

bool Hero::changeHealth(int damage, int heal){
    health = health - damage + heal + regenPerFrame;
    if (health < 0)
        health = 0;
    if (health > maxHealth)
        health = maxHealth;
    if (health <= 0)
        return true;
    else
        return false;
}

void Hero::setMaxHealth(int mHealth){
    maxHealth = mHealth;
    health = maxHealth;
}

int Hero::getHealth(){
    return health;
}
