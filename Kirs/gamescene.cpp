#include "gamescene.h"
#include "dos.h"
#include "main_settings.h"

#include <iostream>
using namespace std;

GameScene::GameScene(QObject *parent): QGraphicsScene(parent){
    lastClickPos = new QPoint();
    hasClicked = false;
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
