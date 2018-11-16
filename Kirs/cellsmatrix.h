#ifndef CELLSMATRIX_H
#define CELLSMATRIX_H

#include <QVector>

#include "cell.h"
#include "hero.h"

class CellsMatrix
{
public:
    CellsMatrix();
    ~CellsMatrix();

    void generateMatrix(int w, int h);

    void fillMatrix();

    int addGameObject(GameObject* object, int x, int y);
    int moveGameObject(int x_from, int y_from, int pos_from, int x, int y);
    void removeGameObject(int x, int y, int pos);
    void removeGameObject(int x, int y, GameObject* object);

    Cell* getCellAt(int x, int y);

    QVector<GameObject *> getAllObjects();

private:
    QVector<QVector<Cell *>> matrix;
    int wSize, hSize;
};

#endif // CELLSMATRIX_H
