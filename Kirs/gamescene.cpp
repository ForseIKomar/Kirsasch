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
    lastVect = m;
}

/*void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
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
}*/

void GameScene::keyPressEvent(QKeyEvent *event){
    cout << "keyPressed: ";
    int dx = 0;
    int dy = 0;
    switch(event->key()){
        case Qt::Key_Right:{ dx = 1; cout << "rigth\n"; break; }
        case Qt::Key_Left:{ dx = -1; cout << "left\n"; break; }
        case Qt::Key_Up:{ dy = -1; cout << "up\n"; break; }
        case Qt::Key_Down:{ dy = 1; cout << "down\n"; break; }
    }
    hasClicked = true;
    lastClickPos->setX(dx);
    lastClickPos->setY(dy);
}

QPoint* GameScene::getClickPos(){
    if (hasClicked){
        hasClicked = false;
        return lastClickPos;
    }
    else
        return NULL;
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
