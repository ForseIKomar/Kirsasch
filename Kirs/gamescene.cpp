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
    setSceneRect(leftX * cellWidth, leftY * cellHeight,
        12 * cellWidth, 12 * cellHeight);
    readyAttack = false;

    //context menu
    grayScreen = new QGraphicsRectItem();
    grayScreen->setOpacity(0.5);
    grayScreen->setBrush(Qt::black);
}

GameScene::~GameScene(){

}

void GameScene::openContextMenu(){
    this->addItem(grayScreen);
}

void GameScene::closeContextMenu(){

}

void GameScene::render(QVector<GameObject *> objects){
    while (this->items().size() > 0){
        this->removeItem(items().at(0));
    }
    QVector<GameObject *> m = objects;
    int x, y;
    QGraphicsPixmapItem *pix = new QGraphicsPixmapItem();
    pix->setPixmap(QPixmap(":/img/s1200.jpg"));
    pix->setPos((leftX - 5) * cellWidth,
                (leftY - 1.5) * cellHeight);
    pix->setZValue(-100);
    this->addItem(pix);
    for (int i = 0; i < m.size(); ++i){
        x = m[i]->getCellPos().x();
        y = m[i]->getCellPos().y();
        if ((x >= leftX - 1) && (x < leftX + 13) &&
                (y >= leftY - 1) && (y < leftY + 11)){
            this->addItem(m[i]);
        }
    }
    this->addRect(5, 13 * cellHeight + 5,
                  13 * cellWidth - 5, 15 * cellHeight - 5);
}

void GameScene::keyPressEvent(QKeyEvent *event){
    cout << "keyPressed: ";
    int dx = 0;
    int dy = 0;
    stopBtn = false;
    readyAttack = false;
    switch(event->key()){
        case Qt::Key_Right:{ dx = 1; cout << "rigth\n"; break; }
        case Qt::Key_Left:{ dx = -1; cout << "left\n"; break; }
        case Qt::Key_Up:{ dy = -1; cout << "up\n"; break; }
        case Qt::Key_Down:{ dy = 1; cout << "down\n"; break; }
        case Qt::Key_S:{ stopBtn = true; cout << "stop\n"; break; }
        case Qt::Key_1:{ readyAttack = true; cout << "Attack!\n"; break; }
        case Qt::Key_Escape:{
            openContextMenu();
            //emit(OpenMainMenu());
            break;
        }
    default: {
        readyAttack = false;
        stopBtn = false;
        cout << "Stop!\n"; break;
    }

    }
    if ((dx != 0) || (dy != 0) || (stopBtn)){
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

bool GameScene::checkStop(){
    return stopBtn;
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
        12 * cellWidth, 12 * cellHeight);
    cout << "Scene rect x and y: " << leftX << " " << leftY << endl;
}
