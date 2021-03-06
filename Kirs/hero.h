#ifndef HERO_H
#define HERO_H

#include <QObject>
#include "livingobject.h"
#include <QBrush>
#include <QImage>

class Hero: public LivingObject
{
public:
    explicit Hero();
    ~Hero();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // HERO_H
