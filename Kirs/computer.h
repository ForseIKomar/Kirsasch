#ifndef COMPUTER_H
#define COMPUTER_H

#include <QVector>
#include <QPoint>
#include "simplymonster.h"
#include "cellsmatrix.h"
#include "eventqueue.h"

class Computer
{
public:
    explicit Computer();
    ~Computer();

    void setField(CellsMatrix* matr);
    void update();
    void isUpdateDone();

    SimplyMonster* getMonster();

private:
    bool moveAction();
    bool attackAction();

private:
    SimplyMonster* monster;
    int x, y;
    int nX, nY;
    int dx, dy;
    CellsMatrix *matrix;
    EventQueue *eQueue;
};

#endif // COMPUTER_H
