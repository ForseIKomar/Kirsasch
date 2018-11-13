#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new GameScene();
    ui->graphicsView->setGeometry(0, 0, 800, 600);
    scene->setSceneRect(0, 0, 800, 600);
    scene->generateField();
    ui->graphicsView->setScene(scene);
    this->setGeometry(400, 400, 800, 600);
    scene->removeGameObject(1, 1, 0);
    scene->update();

}

MainWindow::~MainWindow()
{
    delete ui;
}
