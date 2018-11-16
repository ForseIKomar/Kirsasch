#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QObject>

#include "hero.h"
#include "cellsmatrix.h"

class GameScene: public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = 0);
    ~GameScene();

    void generateField();
    void update();
    void removeGameObject(int x, int y, int pos);

    //void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

    CellsMatrix* getMatrix();

private:
    CellsMatrix *matr;
    QVector<GameObject *> lastVect;
    Hero *hero;

};

#endif // GAMESCENE_H
