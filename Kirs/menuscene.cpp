#include "menuscene.h"

MenuScene::MenuScene(QObject *parent) : QGraphicsScene(parent)
{
    this->setSceneRect(0, 0, 400, 400);
    this->addRect(0, 0, 400, 400);
    startBtn = new GameButton();
    startBtn->setPos(100, 30);
    loadBtn = new GameButton();
    loadBtn->setPos(100, 130);
    optionBtn = new GameButton();
    optionBtn->setPos(100, 230);
    exitBtn = new GameButton();
    exitBtn->setPos(100, 330);

    startBtn->setText("New game");
    loadBtn->setText("Load game");
    optionBtn->setText("Options");
    exitBtn->setText("Exit");

    addItem(startBtn);
    addItem(loadBtn);
    addItem(optionBtn);
    addItem(exitBtn);
    QGraphicsPixmapItem *pix1 = new QGraphicsPixmapItem();
    pix1->setPixmap(QPixmap(":/img/MenuWallpaper_1.png"));
    pix1->setZValue(-100);
    pix1->setPos(-(windowWidth * cellWidth - 400) / 2,
                 -(windowHeight * cellHeight - 400) / 2);
    this->addItem(pix1);

    QGraphicsPixmapItem *pix2 = new QGraphicsPixmapItem();
    pix2->setPixmap(QPixmap(":/img/MenuWallpaper_2.jpg"));
    pix2->setZValue(-90);
    pix2->setPos(0, 0);
    this->addItem(pix2);
}

MenuScene::~MenuScene(){

}

void MenuScene::basicSettings(){

}

void MenuScene::renderMainMenu(){

}

void MenuScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    int x = event->scenePos().x();
    int y = event->scenePos().y();
    if ((x >= 100) && (x <= 300) && (y >= 30) && (y <= 70)){
        emit(startGame());
    }

    if ((x >= 100) && (x <= 300) && (y >= 330) && (y <= 370)){
        emit(exitFromGame());
    }

}
