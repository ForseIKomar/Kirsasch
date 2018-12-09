#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QKeyEvent>

#include "gameobject.h"

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

    void setLeftPoint(int x, int y);

    void openContextMenu();

    void closeContextMenu();

    bool readyAttack;
    bool stopBtn;

signals:
    void OpenMainMenu();

private:
    QPoint* lastClickPos;
    bool hasClicked;
    int leftX, leftY;

// for contextMenu
private:
    QGraphicsRectItem *grayScreen;
};

#endif // GAMESCENE_H
