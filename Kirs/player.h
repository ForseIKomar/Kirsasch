#ifndef PLAYER_H
#define PLAYER_H

#include <QVector>
#include <QPoint>
#include "hero.h"
#include "eventqueue.h"

class Player
{
public:
    explicit Player();
    ~Player();

    void setNextPoint(int x, int y);
    QPoint getNextMovingPoint(bool *needWalk);
    Hero* getHero();

    void update();

private:
    Hero *hero;
    int x, y;
    int nextX, nextY;
    EventQueue *eQueue;
};

#endif // PLAYER_H
