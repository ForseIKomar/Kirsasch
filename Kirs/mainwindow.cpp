#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    GameScene *scene = level.graphics;

    //scene = new GameScene();
    ui->graphicsView->setGeometry(0, 0, 800, 600);
    scene->setSceneRect(0, 0, 800, 600);
    scene->generateField();
    ui->graphicsView->setScene(scene);
    this->setGeometry(400, 400, 800, 600);
    scene->removeGameObject(1, 1, 0);
    scene->update();
/*
    hero = new Hero();
    hero->setColor(Qt::yellow);
    hero->setCellPos(0, 0);
    hero->setPriority(10);
*/
    //level->AddGameObject(hero, 0, 0);



}

MainWindow::~MainWindow()
{
    delete ui;
}
