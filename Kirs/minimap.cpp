#include "minimap.h"
#include <iostream>
using namespace std;

Minimap::Minimap(): QGraphicsObject()
{
    leftX = leftY = 0;
    width = 2.3 * cellWidth;
    height = 2.3 * cellHeight;
    wMatrixSize = colCount;
    hMatrixSize = rowCount;
    wWindowSize = 12;
    hWindowSize = 12;
    matrix = NULL;
}

Minimap::~Minimap(){

}

void Minimap::redraw(){
    this->moveBy(0.1, 0);
    this->moveBy(-0.1, 0);
}

void Minimap::setLeftPoint(int x, int y){
    leftX = x;
    leftY = y;
}

void Minimap::setGeometry(int w, int h){
    width = w;
    height = h;
}

void Minimap::setMatrixGeometry(int wMatrix, int hMatrix){
    wMatrixSize = wMatrix;
    hMatrixSize = hMatrix;
}

void Minimap::setWindowGeometry(int wWind, int hWind){
    wWindowSize = wWind;
    hWindowSize = hWind;
}

void Minimap::setMatr(int **matr){
    matrix = matr;
}

QRectF Minimap::boundingRect() const{
    int w = (1.0 * width) / wMatrixSize;
    int h = (1.0 * height) / hMatrixSize;
    return QRectF(0, 0, w * wWindowSize, h * hWindowSize);
}

void Minimap::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    int w = (1.0 * width) / wMatrixSize;
    int h = (1.0 * height) / hMatrixSize;

    QPen pen;
    pen.setWidth(4);

    QBrush brush;
    brush.setColor(Qt::white);

    painter->setPen(pen);
    pen.setColor(Qt::yellow);
    painter->setPen(pen);
    painter->drawRect(0, 0, w * wMatrixSize + 2, h * hMatrixSize + 2);
    pen.setColor(Qt::black);
    pen.setWidth(0);
    painter->setPen(pen);
    if (matrix != NULL){
    for (int i = 0; i < hMatrixSize; i++){
        for (int j = 0; j < wMatrixSize; j++){
            switch (matrix[i][j]) {
            case 0:
                painter->setBrush(Qt::white);
                break;
            case 1:
                painter->setBrush(Qt::black);
                break;
            case 2:
                painter->setBrush(Qt::green);
                break;
            case 3:
                painter->setBrush(Qt::red);
                break;
            default:
                break;
            }
            painter->drawRect(i * w, j * h, w, h);
        }
    }
    }
    pen.setWidth(1);
    int lx, rx, uy, dy;
    lx = (leftX > 0) ? leftX - 1 : 0;
    rx = (leftX + wWindowSize < wMatrixSize) ? leftX + wWindowSize + 1 : wMatrixSize;
    uy = (leftY > 0) ? leftY - 1 : 0;
    dy = (leftY + hWindowSize <= hMatrixSize) ? leftY + hWindowSize - 1 : hMatrixSize;
    pen.setColor(Qt::red);
    painter->setPen(pen);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(lx * w, uy * h, (rx - lx) * w, (dy - uy) * h);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
