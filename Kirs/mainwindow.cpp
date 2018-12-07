#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include "main_settings.h"
#include <ctime>
#include <cstdlib>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
    newGame();
    cout << "A" << endl;
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
    //this->close();
   // menu = new MenuScene();
    //menu->basicSettings();
    //ui->graphicsView->setScene(menu);
    //menu->renderMainMenu();
    //connect(menu->startBtn, SIGNAL(clicked(bool)), this, SLOT(start()));
}

void MainWindow::start(){
    timer->start();
    newGame();
    GameScene *as = level->getGraphics();
    connect(as, SIGNAL(OpenMainMenu()), this, SLOT(OpenMenu()));
}

void MainWindow::OpenMenu(){
    timer->stop();
    ui->graphicsView->setScene(menu);
}

void MainWindow::newGame(){
    cout << 1;
    level = new Level();
    cout << 1;
    i = 0;
    level->generateField();
    cout << 1;
    ui->graphicsView->setScene(level->getGraphics());
    level->AddHero();
    iScene = new IndicatorScene();
    iScene->getHealthBar()->setMaxHealth(100, 100);
    for (int ii = 0; ii < rowCount; ++ii){
        for (int j = 0; j < colCount; ++j){
            cout << level->getCellAt(j, ii)->canWalkTo() << " ";
        }
        cout << endl;
    }
    cout << 5;
    j = 100;
    level->updateLevel();
    cout << 1;
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
            j = level->getPlayer()->getHero()->getHealth();
            iScene->getHealthBar()->setHealth(j);
        }
    }
    else{
        newGame();
    }
}
