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
    ui->graphicsView->setGeometry(0, 0, windowWidth * cellWidth, windowHeight * cellHeight);
    this->setGeometry(0, 40, windowWidth * cellWidth, windowHeight * cellHeight);
    this->setMaximumHeight(30 * cellHeight);
    this->setMaximumWidth(windowWidth * cellWidth);
    this->setMinimumHeight(windowHeight * cellHeight);
    this->setMinimumWidth(windowWidth * cellWidth);

    //ui->graphicsView_2->setGeometry(0, 12 * cellHeight, 14 * cellWidth,
    //                                2 * cellHeight);
    //ui->graphicsView_2->setScene(iScene);
    timer = new QTimer();
    timer->setInterval(20);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    //timer->start();
    //this->close();
    menu = new MenuScene();
    menu->basicSettings();
    ui->graphicsView->setScene(menu);
    //menu->renderMainMenu();
    connect(menu, SIGNAL(startGame()), this, SLOT(start()));
    connect(menu, SIGNAL(exitFromGame()), this, SLOT(closeGame()));

}

void MainWindow::start(){
    timer->start();
    newGame();
}

void MainWindow::closeGame(){
    this->close();
    exit;
}

void MainWindow::OpenMenu(){
    timer->stop();
    ui->graphicsView->setScene(menu);
}

void MainWindow::newGame(){
    level = new Level();
    i = 0;
    level->generateField();
    ui->graphicsView->setScene(level->getGraphics());
    level->AddHero();
    iScene = new IndicatorScene();
    iScene->getHealthBar()->setMaxHealth(100, 100);
    j = 100;
    level->updateLevel();
    GameScene *as = level->getGraphics();
    ui->graphicsView->setScene(as);
    connect(as, SIGNAL(OpenMainMenu()), this, SLOT(OpenMenu()));
    connect(as, SIGNAL(ExitFromGame()), this, SLOT(closeGame()));
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
