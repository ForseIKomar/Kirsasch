#ifndef SIMPLYMONSTER_H
#define SIMPLYMONSTER_H

#include <QObject>
#include "livingobject.h"
#include <QBrush>
#include <QImage>

class SimplyMonster: public LivingObject
{
public:
    explicit SimplyMonster();
    ~SimplyMonster();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SIMPLYMONSTER_H
