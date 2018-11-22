#ifndef HERO_H
#define HERO_H

#include <QObject>
#include "gameobject.h"
#include <QBrush>
#include <QImage>

class Hero: public GameObject
{
public:
    explicit Hero();
    ~Hero();

    void setColor(QBrush brush);

    bool changeHealth(int damage, int heal);
    void setMaxHealth(int mHealth);
    int getHealth();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QBrush color;
    QImage image;
    int health, maxHealth;
    int regenPerFrame;
};

#endif // HERO_H
