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
    setSceneRect(0, 0, 12 * cellWidth, 12 * cellHeight);
    readyAttack = false;

    menuOpened = false;
    //context menu
    grayScreen = new QGraphicsRectItem();

    grayScreen->setRect(-1.5 * cellWidth, -1.5 * cellHeight, windowWidth * cellWidth, windowHeight * cellHeight);
    grayScreen->setOpacity(0.5);
    grayScreen->setBrush(Qt::black);
    grayScreen->setZValue(50);
    continueBtn = new GameButton();
    saveBtn = new GameButton();
    exitToMenuBtn = new GameButton();
    exitNahooyBtn = new GameButton();
    continueBtn->setPos(3.5 * cellWidth, 2 * cellHeight + 0.96 * cellHeight);
    saveBtn->setPos(3.5 * cellWidth, 2 * cellHeight + 2.72 * cellHeight);
    exitToMenuBtn->setPos(3.5 * cellWidth, 2 * cellHeight + 4.48 * cellHeight);
    exitNahooyBtn->setPos(3.5 * cellWidth, 2 * cellHeight + 6.24 * cellHeight);

    continueBtn->setOpacity(0.8);
    saveBtn->setOpacity(0.8);
    exitToMenuBtn->setOpacity(0.8);
    exitNahooyBtn->setOpacity(0.8);

    continueBtn->setZValue(60);
    saveBtn->setZValue(60);
    exitToMenuBtn->setZValue(60);
    exitNahooyBtn->setZValue(60);

    continueBtn->setText("Continue");
    saveBtn->setText("Save game");
    exitToMenuBtn->setText("Exit to main menu");
    exitNahooyBtn->setText("Exit Nahooy");

    map = new Minimap();
    map->setPos(5, 11.64 * cellHeight + 5);
    //map->setPos(5 + cellWidth, 11.5 * cellheight + 5);

    Health = new QGraphicsTextItem();
    Health->setPos(8.4 * cellWidth, 11.6 * cellHeight);
    Attack = new QGraphicsTextItem();
    Armor = new QGraphicsTextItem();
    Attack->setPos(8.4 * cellWidth, 12.3 * cellHeight);
    Armor->setPos(8.4 * cellWidth, 13.0 * cellHeight);
}

GameScene::~GameScene(){

}

void GameScene::openContextMenu(){
    menuOpened = true;

    this->addItem(grayScreen);
    this->addItem(continueBtn);
    this->addItem(saveBtn);
    this->addItem(exitToMenuBtn);
    this->addItem(exitNahooyBtn);

}

void GameScene::closeContextMenu(){
    menuOpened = false;
    this->removeItem(grayScreen);
    this->removeItem(continueBtn);
    this->removeItem(saveBtn);
    this->removeItem(exitToMenuBtn);
    this->removeItem(exitNahooyBtn);
}

void GameScene::drawMinimap(int **m){
    map->setLeftPoint(leftX, leftY);
    map->redraw();
    map->setMatr(m);
    this->addItem(map);
}

void GameScene::render(QVector<GameObject *> objects){
    while (this->items().size() > 0){
        this->removeItem(items().at(0));
    }
    QVector<GameObject *> m = objects;
    int x, y;
    QGraphicsPixmapItem *pix = new QGraphicsPixmapItem();
    pix->setPixmap(QPixmap(":/img/s1200.jpg"));
    pix->setPos(-5 * cellWidth,
                -1.5 * cellHeight);
    pix->setZValue(-100);
    this->addItem(pix);
    int **mas = new int*[colCount];
    for (int i = 0; i < colCount; ++i){
        mas[i] = new int[rowCount];
        for (int j = 0; j < rowCount; ++j)
            mas[i][j] = -1;
    }
    for (int i = 0; i < m.size(); ++i){
        x = m[i]->getCellPos().x();
        y = m[i]->getCellPos().y();
        if (m[i]->getSecondType() == -1){
            if (mas[x][y] < 0)
                mas[x][y] = (m[i]->getWalkProperty());
        }
        if ((x >= leftX - 1) && (x < leftX + 13) &&
                (y >= leftY - 1) && (y < leftY + 11)){
            m[i]->setPos(x * cellWidth - leftX * cellWidth,
                         y * cellHeight - leftY * cellHeight);
            this->addItem(m[i]);
            if (m[i]->getSecondType() == 3){
                mas[x][y] = 2;
            }
            if (m[i]->getSecondType() == 4){
                mas[x][y] = 3;
            }
        }
    }
    this->addRect(5 - cellWidth, 11.5 * cellHeight + 5,
                  13.8 * cellWidth,  2.3 * cellHeight);

    drawMinimap(mas);

    Health->setHtml("<font size=\"18\">Health: 35/100</font>");
    this->addItem(Health);
    Attack->setHtml("<font size=\"18\">Attack: 10 (+0)</font>");
    this->addItem(Attack);
    Armor->setHtml("<font size=\"18\">Armor: 10</font>");
    this->addItem(Armor);

    cout << "Count of redrawed objects: " << this->items().size() << endl;
}

void GameScene::keyPressEvent(QKeyEvent *event){
    cout << "keyPressed: ";
    int dx = 0;
    int dy = 0;
    stopBtn = false;
    readyAttack = false;
    if (!menuOpened){
        switch(event->key()){
            case Qt::Key_Right:{ dx = 1; cout << "rigth\n"; break; }
            case Qt::Key_Left:{ dx = -1; cout << "left\n"; break; }
            case Qt::Key_Up:{ dy = -1; cout << "up\n"; break; }
            case Qt::Key_Down:{ dy = 1; cout << "down\n"; break; }
            case Qt::Key_S:{ stopBtn = true; cout << "stop\n"; break; }
            case Qt::Key_1:{ readyAttack = true; cout << "Attack!\n"; break; }
            case Qt::Key_Escape:{
                openContextMenu();
                cout << "Menu has been opened" << endl;
                //emit(OpenMainMenu());
                break;
            }
        default: {
            readyAttack = false;
            stopBtn = false;
            cout << "Stop!\n"; break;
        }
        }
    }
    else{
        cout << "Menu opened" << endl;
    }
    if ((dx != 0) || (dy != 0) || (stopBtn)){
        hasClicked = true;
        lastClickPos->setX(dx);
        lastClickPos->setY(dy);
    }
    cout << "readyAttack? " << readyAttack << endl;
}

QPoint* GameScene::getClickPos(){
    if (hasClicked){
        hasClicked = false;
        return lastClickPos;
    }
    else
        return NULL;
}

bool GameScene::checkAttack(){
    return readyAttack;
}

bool GameScene::checkStop(){
    return stopBtn;
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
    cout << "Scene rect x and y: " << leftX << " " << leftY << endl;
}

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    int x = event->scenePos().x();
    int y = event->scenePos().y();

    //      Обработка событий для меню
    if (menuOpened){
        //(3.5 * cellWidth, 2 * cellHeight + 0.96 * cellHeight);
        //(3.5 * cellWidth, 2 * cellHeight + 2.72 * cellHeight);
        //(3.5 * cellWidth, 2 * cellHeight + 4.48 * cellHeight);
        //(3.5 * cellWidth, 2 * cellHeight + 6.24 * cellHeight);
        if ((x >= 3.5 * cellWidth) && (x <= 8.5 * cellWidth)&&
                (y >= 2.96 * cellHeight) && (y <= 3.76 * cellHeight)){
            closeContextMenu();
        }
        if ((x >= 3.5 * cellWidth) && (x <= 8.5 * cellWidth)&&
                (y >= 6.48 * cellHeight) && (y <= 7.28 * cellHeight)){
            emit(OpenMainMenu());
        }
        if ((x >= 3.5 * cellWidth) && (x <= 8.5 * cellWidth)&&
                (y >= 8.24 * cellHeight) && (y <= 10.04 * cellHeight)){
            emit(ExitFromGame());
        }

    }
}
