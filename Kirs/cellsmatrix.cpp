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

Cell* CellsMatrix::getCellAt(QPoint point){
    return this->getCellAt(point.x(), point.y());
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
            if (k == 1){
                m->setImage(QPixmap(":/img/wall.png"));
                m->setWalkProperty(false);
            }
            else
                m->setWalkProperty(true);
            if (k == 0){
                m->setImage(QPixmap(":/img/ground.png"));
                TrapOnLand *trap = new TrapOnLand();
                trap->setTrap(rand()%10 , false, 3);
                trap->setCellPos(i, j);
                matrix[i][j]->addTrap(trap);
            }
            if (k == 2)
                m->setImage(QPixmap(":/img/ground.png"));
            matrix[i][j]->setLandshaft(m);
       }
   }
}

int CellsMatrix::addGameObject(GameObject *object, int x, int y){
    object->setCellPos(x, y);
    if ((matrix.size() > y) && (matrix[y].size() > x))
        return matrix[x][y]->addGameObject(object);
    else
        return 0;
}

void CellsMatrix::removeGameObject(int x, int y, GameObject *object){
    matrix[x][y]->removeGameObject(object);
}

QVector <GameObject *> CellsMatrix::getAllObjects(){
    QVector <GameObject *> resultVector;
    for (int i = 0; i < hSize; ++i){
        for (int j = 0; j < wSize; ++j){
            QVector<GameObject*> objs = matrix[i][j]->getObjects();
            GameObject* land = matrix[i][j]->getLandshaft();
            for (int i = 0; i < objs.size(); ++i)
                resultVector.push_back(objs[i]);
            if (land)
                resultVector.push_back(land);
        }
    }
    return resultVector;
}
