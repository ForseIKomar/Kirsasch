#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include "main_settings.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    level = new Level();
    i = 0;
    GameScene *scene = level->graphics;
    level->generateField();
    ui->graphicsView->setGeometry(0, 0, colCount * cellWidth, rowCount * cellHeight);
    scene->setSceneRect(0, 0, colCount * cellWidth, rowCount * cellHeight);
    ui->graphicsView->setScene(scene);
    this->setGeometry(400, 400, 800, 600);
    scene->update();
    level->AddHero();
    level->updateScene();

    timer = new QTimer();
    timer->setInterval(20);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(){
}

void MainWindow::onTimer(){
    cout << i++ << endl;
    level->CheckMoving();
    level->updateScene();

}
