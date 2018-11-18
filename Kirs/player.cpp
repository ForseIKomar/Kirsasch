#include "player.h"

Player::Player()
{
    x = 0;
    y = 0;
    nextX = 0;
    nextY = 0;
    hero = new Hero();
    hero->setColor(Qt::cyan);
}

Player::~Player(){

}
