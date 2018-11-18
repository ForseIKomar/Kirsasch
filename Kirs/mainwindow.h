#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "hero.h"
#include "level.h"
#include "QTimer"
#include "player.h"
#include "gamescene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void timerEvent();

public slots:
    void onTimer();

private:
    Ui::MainWindow *ui;
    Level *level;
    //GameScene *scene;
    Player *player;
    QTimer *timer;
    Hero *hero;
    int i;
};

#endif // MAINWINDOW_H
