#include "computer.h"

#include <iostream>
using namespace std;

Computer::Computer()
{
    monster = new SimplyMonster();
    monster->setPriority(10);
    monster->setMaxHealth(50);
    monster->setWalkProperty(false);
    matrix = NULL;
    x = 0;
    y = 0;
    monster->setCellPos(x, y);
}

Computer::~Computer(){

}

void Computer::setField(CellsMatrix *matr){
    matrix = matr;
    matrix->addGameObject(monster, x, y);
}

void Computer::update(){
    dx = 0;
    dy = 0;
    if (!attackAction())
        moveAction();
}

bool Computer::attackAction(){
    bool t = false;
    int dxx[4] = {1, 0, -1, 0};
    int dyy[4] = {0, -1, 0, 1};
    for (int i = 0; i < 4; ++i){
        if ((x + dxx[i] >= 0) && (x + dxx[i] < colCount) &&
                (y + dyy[i] >= 0) && (y + dyy[i] < rowCount)){
            QVector<LivingObject* > liv = matrix->getCellAt(x + dxx[i], y + dyy[i])->getLivings();
            if ((liv.size() > 0) && (liv[0] != this->monster)){
                t = true;
                GameEvent *event;
                event = new GameEvent();
                event->AttackEvent(this->monster, liv[0], 20);
                eQueue->AddEvent(event);
            }
        }
    }
    return t;
}

bool Computer::moveAction(){
    bool t = false;
    if (monster->getAliveProperty()){
        if ((x + 1 < colCount) && (matrix->getCellAt(x + 1, y)->canWalkTo())){
            dx = 1;
        }
        else if ((y + 1 < rowCount) && (matrix->getCellAt(x, y + 1)->canWalkTo())){
            dy = 1;
        }
        else if ((x > 0) && (matrix->getCellAt(x - 1, y)->canWalkTo())){
            dx = -1;
        }
        else if ((y > 0) && (matrix->getCellAt(x, y--)->canWalkTo())){
            dy = -1;
        }
        if (abs(dx) + abs(dy) > 0){
            t = true;
            cout << "x = " << x << " y = " << y << " ";
            x += dx;
            y += dy;
            cout << "dx = " << dx << " dy = " << dy << endl;
            GameEvent *event = new GameEvent();
            event->MoveEvent(monster, QPoint(x, y));
            eQueue->AddEvent(event);
        }
    }
    return t;
}

void Computer::isUpdateDone(){
    cout << "monster was at " << x - dx << " " << y - dy << " ";
    cout << "monster must be at " << x << " " << y <<
            " and monster at " << monster->getCellPos().x() << " "
         << monster->getCellPos().y() << endl;
    if ((monster->getCellPos().x() == x) && (monster->getCellPos().y() == y)){

    }
    else{
        x = monster->getCellPos().x();
        y = monster->getCellPos().y();
        update();
    }
}

SimplyMonster* Computer::getMonster(){
    return monster;
}
