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
    AddGameObject(player->getHero(), 0, 0);
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
    cout << "\nStart updating\n";
    CheckMoving();
    moveHero();
    objects.clear();
    objects = field->getAllObjects();
    cout << "Count of redrawed objects: " << objects.size() << endl;
    graphics->render(objects);
    cout << "End of update\n";
}

void Level::generateField(){
    field->generateMatrix(rowCount, colCount);
    field->fillMatrix();
}

void Level::CheckMoving(){
    QPoint* p = graphics->getClickPos();
    if (p != NULL){
        cout << "Coords:" << p->x() << " " << p->y() << endl;
        int x = p->x() + player->getHero()->getCellPos().x();
        int y = p->y() + player->getHero()->getCellPos().y();
        if (!((x < 0) || (x >= rowCount) || (y < 0) || (y >= colCount)) && (field->getCellAt(x, y)->canWalkTo())){
            player->setNextPoint(p->x() + player->getHero()->getCellPos().x(),
                                 p->y() + player->getHero()->getCellPos().y());
        }
        else
            cout << "Not this time\n";
    }
}

void Level::moveHero(){
    bool* t = new bool(false);
    QPoint p = player->getNextMovingPoint(t);
    if (*t){
        cout << "moveHero x = " << p.x() << ", y = " << p.y() << endl;
        MoveGameObject(player->getHero(), p);
    }
    graphics->setLeftPoint(p.x(), p.y());
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
