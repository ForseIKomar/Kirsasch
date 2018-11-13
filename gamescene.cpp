#include "gamescene.h"
#include "dos.h"
#include "main_settings.h"

GameScene::GameScene(QObject *parent): QGraphicsScene(parent){
    matr = new CellsMatrix();
}

GameScene::~GameScene(){

}

void GameScene::generateField(){
    this->clear();
    matr->generateMatrix(rowSize, colSize);
    Hero *hero = new Hero();
    hero->setColor(Qt::red);
    hero->setPriority(5);
    hero->setCellPos(1, 1);
    int pos = matr->addGameObject(hero, 1, 1);
    matr->fillMatrix();
    update();
}

void GameScene::update(){
    for (int i = 0; i < lastVect.size(); ++i){
        this->removeItem(lastVect[i]);
    }
    QVector<GameObject *> m = matr->getAllObjects();
    for (int i = 0; i < m.size(); ++i){
        this->addItem(m[i]);
    }
    lastVect = m;
}

void GameScene::removeGameObject(int x, int y, int pos){
    matr->removeGameObject(x, y, pos);
}

CellsMatrix* GameScene::getMatrix(){
    return matr;
}
