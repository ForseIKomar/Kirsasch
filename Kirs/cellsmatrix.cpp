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

const int wSize = 4;
const int hSize = 7;
const int xar[4] = { 1, 0, -1, 0 };
const int yar[4] = { 0, -1, 0, 1 };

bool CellsMatrix::dfs(int x, int y, bool** lastMas){
    int **mas = new int*[hSize];
    for (int i = 0; i < hSize; ++i)
        mas[i] = new int[wSize];
    for (int i = 0; i < hSize; ++i) {
        for (int j = 0; j < wSize; ++j) {
            mas[i][j] = lastMas[i][j] * 2;
        }
    }
    mas[y][x] = 2;
    vector<int> vx, vy;
    bool t = true;
    int count = 0;
    for (int i = 0; i < 4; ++i){
        int xx = x + xar[i];
        int yy = y + yar[i];
        if ((xx >= 0) && (xx < wSize) && (yy >= 0) && (yy < hSize)){
            if (mas[yy][xx] == 0){
                count++;
                if (t){
                    t = false;
                    vx.push_back(xx);
                    vy.push_back(yy);
                    mas[yy][xx] = true;
                }
            }
        }
    }
    if (count <= 1)
        return true;
    int i = 0;
    int k = vx.size();
    while (i < k){
        for (int j = 0; j < 4; ++j){
            int xx = vx[i] + xar[j];
            int yy = vy[i] + yar[j];
            if ((xx >= 0) && (xx < wSize) && (yy >= 0) && (yy < hSize)){
                if (mas[yy][xx] == 0){
                    vx.push_back(xx);
                    vy.push_back(yy);
                    k++;
                    mas[yy][xx] = true;
                }
            }
        }
        i++;
    }
    t = true;
    for (int i = 0; i < 4; ++i){
        int xx = x + xar[i];
        int yy = y + yar[i];
        if ((xx >= 0) && (xx < wSize) && (yy >= 0) && (yy < hSize))
            if (mas[yy][xx] == 0)
                t = false;
    }
    return t;
}

bool** CellsMatrix::placeWalls() {
    bool **mas = new bool*[hSize];
    for (int i = 0; i < hSize; ++i)
        mas[i] = new bool[wSize];
    for (int i = 0; i < hSize; ++i)
        for (int j = 0; j < wSize; ++j)
            mas[i][j] = false;
    for (int k = 0; k < 5; ++k)
    for (int i = 0; i < hSize; ++i) {
        for (int j = 0; j < wSize; ++j) {
            if (rand() % 6 == 0) {
                mas[i][j] = dfs(j, i, mas);
            }
        }
    }

    return mas;
}


Cell* CellsMatrix::getCellAt(int x, int y){
    if ((x < wSize) && (y < hSize) && (x >= 0) && (y >= 0))
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
    bool **mas = placeWalls();
    for (int i = 0; i < hSize; ++i){
        for (int j = 0; j < wSize; ++j){
            Landshaft *m = new Landshaft();
            m->setPriority(0);
            m->setCellPos(j, i);
            if (mas[i][j]){
                m->setColor(brush[1]);
                m->setImage(QPixmap(":/img/wall.png"));
                m->setWalkProperty(false);
                m->setDefintion(WALL);
            }
            else{
                m->setColor(brush[2]);
                m->setWalkProperty(true);
                m->setImage(QPixmap(":/img/ground.png"));
                m->setDefintion(GROUND);
                if (rand() % 2){
                    TrapOnLand *trap = new TrapOnLand();
                    trap->setTrap(rand()%10 , false, 3);
                    trap->setCellPos(j, i);
                    matrix[i][j]->addTrap(trap);
                }
            }
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
