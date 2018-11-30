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

    newGame();
    ui->graphicsView->setGeometry(0, 0, 14 * cellWidth, 12 * cellHeight);
    this->setGeometry(0, 40, 14 * cellWidth, 20 * cellHeight);
    this->setMaximumHeight(30 * cellHeight);
    this->setMaximumWidth(14 * cellWidth);
    this->setMinimumHeight(14 * cellHeight);
    this->setMinimumWidth(14 * cellWidth);

    ui->graphicsView_2->setGeometry(0, 12 * cellHeight, 14 * cellWidth,
                                    2 * cellHeight);
    ui->graphicsView_2->setScene(iScene);

    timer = new QTimer();
    timer->setInterval(20);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer->start();

}

void MainWindow::newGame(){
    level = new Level();
    i = 0;
    level->generateField();
    ui->graphicsView->setScene(level->getGraphics());
    level->AddHero();
    iScene = new IndicatorScene();
    iScene->getHealthBar()->setMaxHealth(100, 100);
    for (int ii = 0; ii < 10; ++ii){
        for (int j = 0; j < 10; ++j){
            cout << level->getCellAt(j, ii)->canWalkTo() << " ";
        }
        cout << endl;
    }
    j = 100;
    level->updateLevel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(){
}

void MainWindow::onTimer(){
    if (level->getPlayer()->getHero()->getAliveProperty()){
        if (level->CheckMoving()){
            level->updateLevel();
            cout << i++ << endl;
            QPoint m = level->getPlayer()->getHero()->getCellPos();
            j = level->getPlayer()->getHero()->getHealth();
            iScene->getHealthBar()->setHealth(j);
            //if (j == 0){
            //    close();
            //}
        }
    }
    else{
        newGame();
    }
}
