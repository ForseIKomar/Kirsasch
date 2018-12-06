#include "gamescene.h"
#include "dos.h"
#include "main_settings.h"

#include <iostream>
using namespace std;

GameScene::GameScene(QObject *parent): QGraphicsScene(parent){
    lastClickPos = new QPoint();
    hasClicked = false;
    leftX = 0;
    leftY = 0;
    setSceneRect(0, 0, 12 * cellWidth, 10 * cellHeight);
    readyAttack = false;

    //context menu
    grayScreen = new QGraphicsRectItem();
    grayScreen->setOpacity(0.5);
    grayScreen->setBrush(Qt::black);
    grayScreen->setRect(0, 0, 12 * cellWidth, 10 * cellHeight);
}

GameScene::~GameScene(){

}

void GameScene::openContextMenu(){
    this->addItem(grayScreen);
}

void GameScene::closeContextMenu(){

}

void GameScene::render(QVector<GameObject *> objects){
    for (int i = 0; i < lastVect.size(); ++i){
        this->removeItem(lastVect[i]);
    }
    QVector<GameObject *> m = objects;
    for (int i = 0; i < m.size(); ++i){
        this->addItem(m[i]);
    }
    lastVect = m;
}

void GameScene::keyPressEvent(QKeyEvent *event){
    cout << "keyPressed: ";
    int dx = 0;
    int dy = 0;
    switch(event->key()){
        case Qt::Key_Right:{ dx = 1; cout << "rigth\n"; break; }
        case Qt::Key_Left:{ dx = -1; cout << "left\n"; break; }
        case Qt::Key_Up:{ dy = -1; cout << "up\n"; break; }
        case Qt::Key_Down:{ dy = 1; cout << "down\n"; break; }
        case Qt::Key_1:{ readyAttack = true; cout << "Attack!\n"; break; }
        case Qt::Key_Escape:{
            openContextMenu();
            //emit(OpenMainMenu());
            break;
        }
        default: {readyAttack = false; cout << "Stop!\n"; break; }

    }
    if ((dx != 0) || (dy != 0)){
        hasClicked = true;
        lastClickPos->setX(dx);
        lastClickPos->setY(dy);
    }
    cout << "readyAttack? " << readyAttack << endl;
}

QPoint* GameScene::getClickPos(){
    if (hasClicked){
        hasClicked = false;
        return lastClickPos;
    }
    else
        return NULL;
}

bool GameScene::checkAttack(){
    return readyAttack;
}

void GameScene::setLeftPoint(int x, int y){
    if (leftX + 1 >= x){
        leftX -= leftX + 2 - x;
    }
    else if (leftX + 10 <= x){
        leftX += x - (leftX + 9);
    }
    if (leftY + 1 >= y){
        leftY -= leftY + 2 - y;
    }
    else if (leftY + 8 <= y){
        leftY += y - (leftY + 7);
    }

    setSceneRect(leftX * cellWidth, leftY * cellHeight,
        12 * cellWidth, 10 * cellHeight);
}
