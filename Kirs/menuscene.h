#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPushButton>
#include "menubutton.h"

#include <QGraphicsTextItem>

class MenuScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MenuScene(QObject *parent = 0);
    ~MenuScene();

    void basicSettings();

    void renderMainMenu();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void startGame();

private:
    QGraphicsTextItem *text;

public:
    MenuButton *startBtn;
};

#endif // MENUSCENE_H
