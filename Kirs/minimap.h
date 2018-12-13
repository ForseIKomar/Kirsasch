#ifndef MINIMAP_H
#define MINIMAP_H

#include <QGraphicsObject>
#include <QObject>
#include <QPainter>
#include <QPen>

#include "main_settings.h"

class Minimap: public QGraphicsObject
{
public:
    explicit Minimap();
    ~Minimap();

    void setLeftPoint(int x, int y);
    void setGeometry(int w, int h);
    void setMatrixGeometry(int wMatrix, int hMatrix);
    void setWindowGeometry(int wWind, int hWind);
    void setMatr(int **matr);
    void redraw();
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int leftX, leftY;
    int width, height;
    int wMatrixSize, hMatrixSize;
    int wWindowSize, hWindowSize;
    int **matrix;
};

#endif // MINIMAP_H
