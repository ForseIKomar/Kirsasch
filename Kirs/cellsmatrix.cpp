#include "cellsmatrix.h"
#include "cstdlib"
#include "ctime"
#include <iostream>

using namespace std;

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
            c->setPosition(i, j);
            cVect.push_back(c);
        }
        matrix.push_back(cVect);
    }
    wSize = w;
    hSize = h;
}

bool CellsMatrix::dfs(int x, int y){
    bool **mas = new bool*[wSize];
    for (int i = 0; i < wSize; ++i)
        mas[i] = new bool[hSize];
    for (int i = 0; i < wSize; ++i)
        for (int j = 0; j < hSize; ++j)
            mas[i][j] = false;
    mas[x][y] = false;
    int xar[4] = {1, 0, -1, 0};
    int yar[4] = {0, -1, 0, 1};
    QVector<QPoint> stack;
    bool t = true;
    int count = 0;
    for (int i = 0; i < 4; ++i){
        int xx = x + xar[i];
        int yy = y + yar[i];
        if ((xx >= 0) && (xx < wSize) && (yy >= 0) && (yy < hSize)){
            if (getCellAt(xx, yy)->canWalkTo()){
                count++;
                if (t){
                    t = false;
                    stack.push_back(QPoint(xx, yy));
                    mas[xx][yy] = true;
                }
            }
        }
    }
    if (count <= 1)
        return true;
    int i = 0;
    while (i < stack.size()){
        for (int j = 0; j < 4; ++j){
            int xx = stack[i].x() + xar[j];
            int yy = stack[i].y() + yar[j];
            if ((xx >= 0) && (xx < 5) && (yy >= 0) && (yy < 5)){
                if (getCellAt(xx, yy)->canWalkTo()){
                    if (!(mas[xx][yy])){
                        stack.push_back(QPoint(xx, yy));
                        mas[xx][yy] = true;
                    }
                }
            }
            i++;
        }
    }
    t = false;
    for (int i = 0; i < 4; ++i){
        int xx = x + xar[i];
        int yy = y + yar[i];
        if ((xx >= 0) && (xx < wSize) && (yy >= 0) && (yy < hSize))
            t = t && (mas[xx][yy] || !getCellAt(xx, yy)->canWalkTo());
    }
    return t;
}

Cell* CellsMatrix::getCellAt(int x, int y){
    if ((x < wSize) && (y < hSize))
        return matrix[y][x];
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
            int k = rand() % 3;
            m->setColor(brush[k]);
            m->setPriority(0);
            m->setCellPos(j, i);
            if (k == 1){
                if (rand() % 3){
                    m->setImage(QPixmap(":/img/wall.png"));
                    m->setWalkProperty(true);
                }
                else{
                    k = 2;
                    m->setWalkProperty(false);
                }
            }
            else
                m->setWalkProperty(true);
            if (k == 0){
                m->setImage(QPixmap(":/img/ground.png"));
                TrapOnLand *trap = new TrapOnLand();
                trap->setTrap(rand()%10 , false, 3);
                trap->setCellPos(j, i);
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
        return matrix[y][x]->addGameObject(object);
    else
        return 0;
}

void CellsMatrix::removeGameObject(int x, int y, GameObject *object){
    matrix[y][x]->removeGameObject(object);
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
