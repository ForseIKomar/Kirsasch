#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    level = new Level();

    GameScene *scene = level->graphics;
    level->generateField();
    ui->graphicsView->setGeometry(0, 0, 800, 600);
    scene->setSceneRect(0, 0, 800, 600);
    ui->graphicsView->setScene(scene);
    this->setGeometry(400, 400, 800, 600);
    scene->update();
    level->AddHero();
    level->updateScene();
}

MainWindow::~MainWindow()
{
    delete ui;
}
