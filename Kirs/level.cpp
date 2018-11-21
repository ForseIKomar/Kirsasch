#include "level.h"
#include "main_settings.h"

#include <iostream>
using namespace std;

Level::Level()
{

    field = new CellsMatrix();
    graphics = new GameScene();
    player = new Player();
    objects.clear();
    indicators = new IndicatorScene();

}

Level::~Level(){

}

void Level::AddGameObject(GameObject *object, int x, int y){
    field->addGameObject(object, x, y);
}

void Level::AddHero(){
    AddGameObject(player->getHero(), 1, 1);
}

void Level::MoveGameObject(GameObject *object, int to_x, int to_y){
    Cell* c = field->getCellAt(object->getCellPos().x(),
                               object->getCellPos().y());
    c->removeGameObject(object);
    AddGameObject(object, to_x, to_y);
}

void Level::MoveGameObject(GameObject *object, QPoint to){
    MoveGameObject(object, to.x(), to.y());
}

void Level::RemoveGameObject(GameObject *object){
    Cell* c = field->getCellAt(object->getCellPos().x(),
                               object->getCellPos().y());
    c->removeGameObject(object);
}

void Level::RemoveGameObject(int x, int y, int pos){
    field->getCellAt(x, y)->removeGameObject(pos);
}

void Level::updateLevel(){
    CheckMoving();
    moveHero();
    objects.clear();
    objects = field->getAllObjects();

    graphics->render(objects);
}

void Level::generateField(){
    field->generateMatrix(rowCount, colCount);
    field->fillMatrix();
}

void Level::CheckMoving(){
    QPoint* p = graphics->getClickPos();
    if (p != NULL){
        player->setNextPoint(p->x(), p->y());
    }
}

void Level::moveHero(){
    QPoint p = player->getNextMovingPoint();
    MoveGameObject(player->getHero(), p);
    graphics->setLeftPoint(p.x(), p.y());
}

void Level::setSceneRect(int x, int y){
}

GameScene* Level::getGraphics(){
    return graphics;
}

Cell* Level::getCellAt(int x, int y){
    return field->getCellAt(x, y);
}

Player* Level::getPlayer(){
    return player;
}
