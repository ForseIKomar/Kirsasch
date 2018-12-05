#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "dialog.h"
#include "hero.h"
#include "level.h"
#include "QTimer"
#include "player.h"
#include "gamescene.h"
#include "indicatorscene.h"
#include "menuscene.h"
#include "healthbar.h"

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
    void newGame();

public slots:
    void onTimer();
    void start();
    void OpenMenu();

private:
    Ui::MainWindow *ui;
    Level *level;
    //GameScene *scene;
    Player *player;
    QTimer *timer;
    Hero *hero;
    IndicatorScene *iScene;
    Dialog *dial;
    HealthBar *h;
    MenuScene *menu;

    int i, j;
};

#endif // MAINWINDOW_H
