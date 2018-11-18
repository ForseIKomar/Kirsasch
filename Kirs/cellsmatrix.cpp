#include "cellsmatrix.h"
#include "cstdlib"
#include "ctime"

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

Cell* CellsMatrix::getCellAt(int x, int y){
    if ((matrix.size() > y) && (matrix[y].size() > x))
        return matrix[x][y];
    else
        return NULL;
}

void CellsMatrix::fillMatrix(){
   QBrush brush[3];
   brush[0] = Qt::darkGreen;
   brush[1] = Qt::white;
   brush[2] = Qt::green;
   for (int i = 0; i < hSize; ++i){
       for (int j = 0; j < wSize; ++j){
            Landshaft *m = new Landshaft();
            int k = rand()%3;
            m->setColor(brush[k]);
            m->setPriority(0);
            m->setCellPos(i, j);
            matrix[i][j]->setLandshaft(m);
       }
   }
}

int CellsMatrix::addGameObject(GameObject *object, int x, int y){
    object->setCellPos(x, y);
    if ((matrix.size() > y) && (matrix[y].size() > x))
        return matrix[x][y]->addGameObject(object);
}

int CellsMatrix::moveGameObject(int x_from, int y_from, int pos_from, int x, int y){
    int res = matrix[x][y]->addGameObject(matrix[x_from][y_from]->getObjectAt(pos_from));
    matrix[x][y]->getObjectAt(pos_from)->setCellPos(x, y);
    matrix[x_from][y_from]->removeGameObject(pos_from);
    return res;
}

void CellsMatrix::removeGameObject(int x, int y, int pos){
    matrix[x][y]->removeGameObject(pos);
}

void CellsMatrix::removeGameObject(int x, int y, GameObject *object){
    matrix[x][y]->removeGameObject(object);
}

QVector <GameObject *> CellsMatrix::getAllObjects(){
    QVector <GameObject *> resultVector;
    for (int i = 0; i < hSize; ++i){
        for (int j = 0; j < wSize; ++j){
            GameObject* obj = matrix[i][j]->getCurrentObject();
            GameObject* land = matrix[i][j]->getLandshaft();
            if (obj)
                resultVector.push_back(obj);
            if (land)
                resultVector.push_back(land);
        }
    }
    return resultVector;
}
