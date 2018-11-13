#ifndef HERO_H
#define HERO_H

#include <QObject>
#include "gameobject.h"
#include <QBrush>

class Hero: public GameObject
{
public:
    explicit Hero();
    ~Hero();

    void setColor(QBrush brush);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QBrush color;
};

#endif // HERO_H
