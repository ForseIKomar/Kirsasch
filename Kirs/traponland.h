#ifndef TRAPONLAND_H
#define TRAPONLAND_H

#include <QObject>
#include "gameobject.h"
#include "livingobject.h"

class TrapOnLand: public LivingObject
{
    Q_OBJECT
public:
    explicit TrapOnLand();
    ~TrapOnLand();

    void setImage(QPixmap image);

    void setTrap(int actDamage, bool twoMoreWork, int cOWork = 1);

    int getDamage();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    bool alwaysWork;

};

#endif // TRAPONLAND_H
