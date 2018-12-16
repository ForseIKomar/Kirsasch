#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "level.h"
#include "QTimer"
#include "menuscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void newGame();

public slots:
    void onTimer();
    void start();
    void OpenMenu();
    void closeGame();

private:
    Ui::MainWindow *ui;
    Level *level;
    //GameScene *scene;
    Player *player;
    QTimer *timer;
    Hero *hero;
    MenuScene *menu;

    int i, j;
};

#endif // MAINWINDOW_H
