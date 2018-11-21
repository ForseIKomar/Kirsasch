#include "player.h"

Player::Player()
{
    x = 0;
    y = 0;
    nextX = 0;
    nextY = 0;
    hero = new Hero();
    hero->setColor(Qt::cyan);
    hero->setPriority(10);
}

Player::~Player(){

}

QPoint Player::getNextMovingPoint(){
    if (nextY >= y){
        if (nextX != x){
            if (nextX > x){
                return QPoint(x++, y);
            }
            else
                return QPoint(x--, y);
        }
        if (nextY != y){
            if (nextY > y)
                return QPoint(x, y++);
            else
                return QPoint(x, y--);
        }
    }
    else{
        if (nextY != y){
            if (nextY > y)
                return QPoint(x, y++);
            else
                return QPoint(x, y--);
        }
        if (nextX != x){
            if (nextX > x){
                return QPoint(x++, y);
            }
            else
                return QPoint(x--, y);
        }
    }
    return QPoint(x, y);
}

void Player::setNextPoint(int x, int y){
    nextX = x;
    nextY = y;
}

Hero* Player::getHero(){
    return hero;
}
