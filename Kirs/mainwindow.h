#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    Level *level;
    //GameScene *scene;
    Player *player;

    Hero *hero;
};

#endif // MAINWINDOW_H
