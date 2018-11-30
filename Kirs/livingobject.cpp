#include "livingobject.h"

LivingObject::LivingObject(): GameObject()
{
    image = NULL;
    dmg = 0;
    health = 10;
    maxHealth = 10;
    isAlive = true;
    type = LIVING_OBJECT;
}

LivingObject::~LivingObject(){

}

void LivingObject::setImage(QImage *image){
    this->image = image;
}

void LivingObject::setDamage(int damage){
    dmg = damage;
}

int LivingObject::getDmg(){
    return dmg;
}

bool LivingObject::changeHealth(int damage, int heal){
    health -= damage - heal;
    if (health <= 0){
        isAlive = false;
    }
    if (health > maxHealth)
        health = maxHealth;
    return isAlive;
    this->moveBy(0.1, 0);
    this->moveBy(-0.1, 0);
}

void LivingObject::setMaxHealth(int mHealth){
    health = maxHealth = mHealth;
}

int LivingObject::getHealth(){
    return health;
}

void LivingObject::setAliveProperty(bool alive){
    isAlive = alive;
}

bool LivingObject::getAliveProperty(){
    return isAlive;
}
