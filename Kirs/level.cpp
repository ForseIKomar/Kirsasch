#include "level.h"
#include "main_settings.h"

#include <iostream>
using namespace std;

Level::Level()
{

    field = new CellsMatrix();
    graphics = new GameScene();
    player = new Player();
    enemy = new Computer();
    enemy->setField(field);
    //enemy2 = new Computer();
    //enemy2->setField(field);
    events = new EventQueue();
    AddGameObject(enemy->getMonster(), enemy->getMonster()->getCellPos().x(), enemy->getMonster()->getCellPos().y());
    //AddGameObject(enemy2->getMonster(), enemy2->getMonster()->getCellPos().x(), enemy2->getMonster()->getCellPos().y());
}

Level::~Level(){

}

void Level::AddGameObject(GameObject *object, int x, int y){
    field->addGameObject(object, x, y);
}

void Level::AddHero(){
    int x, y;
    do{
        x = rand() % colCount;
        y = rand() % rowCount;
    }while (!field->getCellAt(x, y)->canWalkTo());
    player->setNextPoint(x, y);
    AddGameObject(player->getHero(), x, y);
}

void Level::MoveGameObject(GameObject *object, int to_x, int to_y){
    RemoveGameObject(object);
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

void Level::updateLevel(){
    cout << "\nStart updating\n";
    moveHero();
    enemy->update();
    //enemy2->update();

    GameEvent* nextEvent = NULL;
    while (nextEvent = events->getNextEvent()){
       activateEvent(nextEvent);
    }
    //enemy->isUpdateDone();
    //enemy2->isUpdateDone();
    while (nextEvent = events->getNextEvent()){
        activateEvent(nextEvent);
     }
    render();
}

void Level::render(){
    graphics->render(field->getAllObjects());
    cout << "End of update\n";
}

void Level::checkTraps(LivingObject *object){
    int x = object->getCellPos().x();
    int y = object->getCellPos().y();
    QVector<TrapOnLand *> traps = field->getCellAt(x, y)->getTraps();
    for (int i = 0; i < traps.size(); ++i){
        GameEvent *event = new GameEvent();
        event->AttackEvent(traps[i], object, traps[i]->getDamage());
        events->AddEvent(event);
        cout << "added attack event x = " << x << ", y = " << y << endl;

    }
}

void Level::generateField(){
    field->generateMatrix(colCount, rowCount);
    field->fillMatrix();
}

bool Level::CheckMoving(){
    QPoint* p = graphics->getClickPos();

    if (p != NULL){
        int x = p->x() + player->getHero()->getCellPos().x();
        int y = p->y() + player->getHero()->getCellPos().y();
        if (!((x < 0) || (x >= colCount) || (y < 0) || (y >= rowCount))){
            if (graphics->checkAttack()){
            QVector<LivingObject* > m = field->getCellAt(x, y)->getLivings();
            for (int i = 0; i < m.size(); ++i){
                if (m[i]->getObjectType() == LIVING_OBJECT){
                    GameEvent *event = new GameEvent();
                    LivingObject *at = field->getCellAt(x, y)->getLiving(0);
                    event->AttackEvent(player->getHero(), at, 10);
                    events->AddEvent(event);
                    return true;
                }
            }
            if (graphics->checkStop()){
                return true;
            }
            graphics->readyAttack = false;
        }
        else{
            if (field->getCellAt(x, y)->canWalkTo()){
                player->setNextPoint(p->x() + player->getHero()->getCellPos().x(),
                                     p->y() + player->getHero()->getCellPos().y());
                return true;
            }
            else
                cout << "Not this time\n";
        }
        }
    }
    return false;
}

void Level::moveHero(){
    bool* t = new bool(false);              //  Установка положения поля
    QPoint p = player->getNextMovingPoint(t);
    graphics->setLeftPoint(p.x(), p.y());

    player->update();                       //  Само передвижение
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

void Level::activateEvent(GameEvent *event){
    switch (event->command){
    case COMMAND_ATTACK:{
        cout << "Atk event with dmg: " << event->damage << endl;
        if (event->sender->getAliveProperty()){
            event->reciever->changeHealth(event->damage);
            if (event->reciever->getHealth() <= 0){
                GameEvent *event2 = new GameEvent();
                event2->KillEvent(event->sender, event->reciever);
                events->AddEvent(event2);
            }
        }
        break;
    };
    case COMMAND_MOVE:{
        cout << "MoveEvent from (" << event->sender->getCellPos().x() << ", " << event->sender->getCellPos().y()
             << ") to (" << event->movingPoint.x() << ", " << event->movingPoint.y() << ")" << " isClosednow?: ";

        Cell* cell = field->getCellAt(event->movingPoint.x(), event->movingPoint.y());
        if (cell && (cell->canWalkTo())){
            cout << endl;
            this->MoveGameObject(event->sender, event->movingPoint);
            checkTraps(event->sender);
        }
        else{
            cout << " - Declined." << endl;
        }
        break;
    };
    case COMMAND_KILL:{
        this->RemoveGameObject(event->reciever);
        event->reciever->setAliveProperty(false);
        cout << "somebody has killed\n";
        break;
    };
    case COMMAND_DELETE:{
        this->RemoveGameObject(event->deletableObject);
        break;
    };
    }
}
