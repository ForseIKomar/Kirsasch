#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QKeyEvent>

#include "minimap.h"
#include "gameobject.h"
#include "gamebutton.h"

class GameScene: public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = 0);
    ~GameScene();

    void render(QVector<GameObject *> objects);

    QPoint* getClickPos();
    bool    checkAttack();
    bool    checkStop();

    //void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void setLeftPoint(int x, int y);

    void openContextMenu();
    void drawMinimap(int **m);
    void closeContextMenu();

    bool readyAttack;
    bool stopBtn;

signals:
    void OpenMainMenu();
    void ExitFromGame();

private:
    QPoint* lastClickPos;
    bool hasClicked;
    int leftX, leftY;
    bool menuOpened;

// for contextMenu
private:
    QGraphicsRectItem *grayScreen;
    GameButton *continueBtn;
    GameButton *saveBtn;
    GameButton *exitToMenuBtn;
    GameButton *exitNahooyBtn;

//  Indicators
private:
    Minimap *map;
    QGraphicsTextItem *Health, *Attack, *Armor;
};

#endif // GAMESCENE_H
