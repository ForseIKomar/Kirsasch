#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QVector>

QVector<QVector<int>> FindPath(QVector<QVector<bool>> map, int x, int y, int to_x, int to_y){
    QVector<QVector<int>> matr;
    for (int i = 0; i < map.size(); ++i){
        QVector<int> vect;
        for (int j = 0; j < map[i].size(); ++j){
            if (map[i][j])
                vect.push_back(0);
            else
                vect.push_back(-1);
        }
        matr.push_back(vect);
    }

    QVector<int> matrX;
    QVector<int> matrY;
    int j = 0;
    matrX.push_back(x);
    matrY.push_back(y);
    while ((matrX.size() > j) && !((matrX[j] == to_x) && (matrY[j]) == to_y)){

    }
}

void Recursive(QVector<QVector<int>> &map){

}

#endif // ALGORITHM_H
