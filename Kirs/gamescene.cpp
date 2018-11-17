#include "gamescene.h"
#include "dos.h"
#include "main_settings.h"

#include <iostream>
using namespace std;

GameScene::GameScene(QObject *parent): QGraphicsScene(parent){

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

}
