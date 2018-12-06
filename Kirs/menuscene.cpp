#include "menuscene.h"

MenuScene::MenuScene(QObject *parent) : QGraphicsScene(parent)
{
    this->setSceneRect(0, 0, 400, 400);
    this->addRect(0, 0, 400, 400);
    text = new QGraphicsTextItem();
    startBtn = new MenuButton();
    startBtn->setPos(100, 20);
}

MenuScene::~MenuScene(){

}

void MenuScene::basicSettings(){

}

void MenuScene::renderMainMenu(){
    //this->basicSettings();
    //this->addRect(150, 20, 100, 40);
    //text->setHtml("Lel");
    //text->setPos(190, 30);
    //text->setOpacity(1);
    //this->addItem(text);
    addItem(startBtn);
}

void MenuScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    //int x = event->scenePos().x();
    //int y = event->scenePos().y();
    //if ((x >= 150) && (x <= 250) && (y >= 20) && (y <= 60)){
        emit(startGame());
    //}
    //while (this->items().size() > 0)
    //    this->removeItem(this->items().at(0));
    //renderMainMenu();
    //this->addText(QString::number(x) + " " + QString::number(y));
}
