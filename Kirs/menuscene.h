#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPushButton>
#include <QGraphicsTextItem>

#include "main_settings.h"
#include "gamebutton.h"

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

    void exitFromGame();

private:
    QGraphicsTextItem   *text;
    GameButton          *startBtn;
    GameButton          *loadBtn;
    GameButton          *optionBtn;
    GameButton          *exitBtn;
};

#endif // MENUSCENE_H
