#ifndef CELLSMATRIX_H
#define CELLSMATRIX_H

#include <QVector>

#include "cell.h"
#include "hero.h"
#include "landshaft.h"
#include "traponland.h"

class CellsMatrix
{
public:
    CellsMatrix();
    ~CellsMatrix();

    void generateMatrix(int w, int h);

    void fillMatrix();
    bool dfs(int x, int y, bool** lastMas);
    bool** placeWalls();

    int addGameObject(GameObject* object, int x, int y);
    void removeGameObject(int x, int y, GameObject* object);

    Cell* getCellAt(int x, int y);
    Cell* getCellAt(QPoint point);

    QVector<GameObject *> getAllObjects();

private:
    QVector<QVector<Cell *>> matrix;
    int wSize, hSize;
};

#endif // CELLSMATRIX_H
