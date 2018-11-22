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
    ui->graphicsView->setScene(level->getGraphics());
    this->setGeometry(0, 40, 14 * cellWidth, 20 * cellHeight);
    this->setMaximumHeight(30 * cellHeight);
    this->setMaximumWidth(14 * cellWidth);
    this->setMinimumHeight(14 * cellHeight);
    this->setMinimumWidth(14 * cellWidth);

    ui->graphicsView_2->setGeometry(0, 12 * cellHeight, 14 * cellWidth,
                                    2 * cellHeight);
    ui->graphicsView_2->setScene(iScene);


}

void MainWindow::newGame(){
    level = new Level();
    i = 0;
    level->generateField();
    ui->graphicsView->setScene(level->getGraphics());
    level->AddHero();
    iScene = new IndicatorScene();
    iScene->getHealthBar()->setMaxHealth(100, 100);    for (int ii = 0; ii < 10; ++ii){
        for (int j = 0; j < 10; ++j){
            cout << level->getCellAt(j, ii)->canWalkTo() << " ";
        }
        cout << endl;
    }

    timer = new QTimer();
    timer->setInterval(20);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer->start();
    j = 100;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(){
}

void MainWindow::onTimer(){
    cout << i++ << endl;
    QPoint m = level->getPlayer()->getHero()->getCellPos();
    if (level->getCellAt(m.x(), m.y())->getLandshaft()->color == Qt::darkGreen){
        level->getPlayer()->getHero()->changeHealth(5, 0);
        j -= 4;
        if (j < 0)
            j = 0;
        iScene->getHealthBar()->setHealth(j);
    }
    else{
        level->getPlayer()->getHero()->changeHealth(0, 0);
        j += 1;
        if (j > 100)
            j = 100;
        iScene->getHealthBar()->setHealth(j);
    }
    level->updateLevel();
    if (j == 0){
        close();
    }
}
