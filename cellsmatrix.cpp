#include "cellsmatrix.h"

CellsMatrix::CellsMatrix()
{
    wSize = 0;
    hSize = 0;
}

CellsMatrix::~CellsMatrix(){

}

void CellsMatrix::generateMatrix(int w, int h){
    for (int i = 0; i < h; ++i){
        QVector<Cell *> cVect;
        for (int j = 0; j < w; ++j){
            Cell *c = new Cell();
            c->setPosition(j, i);
            cVect.push_back(c);
        }
        matrix.push_back(cVect);
    }
    wSize = w;
    hSize = h;
}

void CellsMatrix::fillMatrix(){
   for (int i = 0; i < hSize; ++i){
       for (int j = 0; j < wSize; ++j){
            Hero *m = new Hero();
            if ((i + j) % 3 == 0)
                m->setColor(Qt::blue);
            if ((i + j) % 3 == 1)
                m->setColor(Qt::green);
            if ((i + j) % 3 == 2)
                m->setColor(Qt::black);
            m->setPriority(0);
            m->setCellPos(i, j);
            matrix[i][j]->addGameObject(m);
       }
   }
}

int CellsMatrix::addGameObject(GameObject *object, int x, int y){
    return matrix[y][x]->addGameObject(object);

}

int CellsMatrix::moveGameObject(int x_from, int y_from, int pos_from, int x, int y){
    int res = matrix[y][x]->addGameObject(matrix[y_from][x_from]->getObjectAt(pos_from));
    matrix[y_from][x_from]->removeGameObject(pos_from);
    return res;
}

void CellsMatrix::removeGameObject(int x, int y, int pos){
    matrix[y][x]->removeGameObject(pos);
}

QVector <GameObject *> CellsMatrix::getAllObjects(){
    QVector <GameObject *> resultVector;
    for (int i = 0; i < hSize; ++i){
        for (int j = 0; j < wSize; ++j){
            //for (int l = 0; l < matrix[i][j]->getVectorSize(); ++l){
                resultVector.push_back(matrix[i][j]->getObjectAt(0));
            //}
        }
    }
    return resultVector;
}
