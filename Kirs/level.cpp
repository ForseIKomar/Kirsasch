#include "level.h"
#include "main_settings.h"

Level::Level()
{

    field = new CellsMatrix();
    graphics = new GameScene();
    player = new Player();
    objects.clear();
}

Level::~Level(){

}

void Level::AddGameObject(GameObject *object, int x, int y){
    field->addGameObject(object, x, y);
}

void Level::AddHero(){

    hero = new Hero();
    hero->setColor(Qt::yellow);
    hero->setCellPos(1, 1);
    hero->setPriority(10);
    AddGameObject(hero, 1, 1);
}

void Level::MoveGameObject(GameObject *object, int from_x, int from_y, int to_x, int to_y){
    Cell* c = field->getCellAt(from_x, from_y);
    c->removeGameObject(object);
    AddGameObject(object, to_x, to_y);
}

void Level::MoveGameObject(GameObject *object, QPoint from, QPoint to){
    MoveGameObject(object, from.x(), from.y(), to.x(), to.y());
}

void Level::RemoveGameObject(GameObject *object){
    Cell* c = field->getCellAt(object->getCellPos().x(),
                               object->getCellPos().y());
    c->removeGameObject(object);
}

void Level::RemoveGameObject(int x, int y, int pos){
    field->getCellAt(x, y)->removeGameObject(pos);
}

void Level::updateScene(){
    objects.clear();
    objects = field->getAllObjects();
    graphics->render(objects);
}

void Level::generateField(){
    field->generateMatrix(rowCount, colCount);
    field->fillMatrix();
}

void Level::MoveHeroSlot(QGraphicsSceneMouseEvent *event){
    int x = ((int)event->pos().x() / cellWidth) % colCount;
    int y = ((int)event->pos().y() / cellHeight) % rowCount;
    MoveGameObject(hero, hero->getCellPos(), QPoint(x, y));
}
