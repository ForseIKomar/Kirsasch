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
}

GameScene::~GameScene(){

}

void GameScene::render(QVector<GameObject *> objects){
    for (int i = 0; i < lastVect.size(); ++i){
        this->removeItem(lastVect[i]);
    }
    QVector<GameObject *> m = objects;
    for (int i = 0; i < m.size(); ++i){
        this->addItem(m[i]);
    }
    cout << "update: " << m.size() << endl;
    lastVect = m;
}

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    int xx = (int)event->scenePos().x();
    int yy = (int)event->scenePos().y();
    if ((xx >= 0) && (yy >= 0) &&
            (xx < colCount * cellWidth) && (yy < rowCount * cellHeight)){
        xx /= cellWidth;
        yy /= cellHeight;
        lastClickPos->setX(xx);
        lastClickPos->setY(yy);
        cout << endl << "start" << endl;
        cout << "ex = " << event->scenePos().x() << " ey = " << event->scenePos().y() << endl;
        hasClicked = true;
        cout << "x = " << lastClickPos->x() << " y = " << lastClickPos->y() << endl;
    }
    Q_UNUSED(event);
}

void GameScene::keyPressEvent(QKeyEvent *event){
    int dx = 0;
    int dy = 0;
    switch(event->key()){
        case Qt::Key_Right:{ dx = 1; break; }
        case Qt::Key_Left:{ dx = -1; break; }
        case Qt::Key_Up:{ dy = -1; break; }
        case Qt::Key_Down:{ dy = 1; break; }
    }
    if (dx + dy != 0){
        bool p = false;
        if ((lastClickPos->x() + dx >= 0) && (lastClickPos->x() + dx  < colCount)){
            lastClickPos->setX(lastClickPos->x() + dx);
            p = true;
        }

        if ((lastClickPos->y() + dy >= 0) && (lastClickPos->y() + dy < rowCount)){
            lastClickPos->setY(lastClickPos->y() + dy);
            p = true;
        }
        if (p)
            hasClicked = true;
    }
}

QPoint* GameScene::getClickPos(){
    if (hasClicked){
        hasClicked = false;
        return lastClickPos;
    }
    else{
        hasClicked = false;
        return NULL;
    }
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
