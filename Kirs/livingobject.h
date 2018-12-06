#ifndef LIVINGOBJECT_H
#define LIVINGOBJECT_H

#include <QObject>

#include "gameobject.h"

class LivingObject: public GameObject
{
    Q_OBJECT
public:
    explicit LivingObject();
    ~LivingObject();

    void setImage(QImage *image);

    void setDamage(int damage);
    virtual int getDmg();

    bool changeHealth(int damage, int heal = 0);
    void setMaxHealth(int mHealth);
    int getHealth();

    void setAliveProperty(bool alive);
    bool getAliveProperty();


protected:
    QImage *image;
    int dmg;
    int health;
    int maxHealth;

    bool isAlive;

};

#endif // LIVINGOBJECT_H
