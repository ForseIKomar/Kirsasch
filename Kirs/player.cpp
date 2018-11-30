#include "player.h"

Player::Player()
{
    x = 0;
    y = 0;
    nextX = 0;
    nextY = 0;
    hero = new Hero();
    hero->setPriority(10);
    hero->setMaxHealth(100);
    eQueue = new EventQueue();
}

Player::~Player(){

}

QPoint Player::getNextMovingPoint(bool *needWalk){
    *needWalk = true;
    return QPoint(nextX, nextY);
}

void Player::setNextPoint(int x, int y){
    nextX = x;
    nextY = y;
}

Hero* Player::getHero(){
    return hero;
}

void Player::update(){
    if (hero->getAliveProperty()){
        GameEvent *event = new GameEvent();
        event->MoveEvent(hero, QPoint(nextX, nextY));
        eQueue->AddEvent(event);
    }
}
