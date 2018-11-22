#include "landshaft.h"
#include "main_settings.h"

#include <QPainter>


Landshaft::Landshaft(): GameObject()
{
    color = Qt::green;
    this->setZValue(-10);
    pix = NULL;
}

Landshaft::~Landshaft(){

}

void Landshaft::setColor(QBrush brush){
    color = brush;
}

void Landshaft::setImage(QPixmap image){
    pix = new QPixmap();
    *pix = image;
}

void Landshaft::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    if (pix){
        painter->drawPixmap(0, 0, 50, 50, *pix);
    }
    if (color == Qt::darkGreen){
        painter->drawPixmap(0, 0, 50, 50, QPixmap(":/img/ground.png"));
        painter->drawPixmap(0, 0, 50, 50, QPixmap(":/img/31.png"));
    }
    if (color == Qt::green){
        painter->drawPixmap(0, 0, 50, 50, QPixmap(":/img/ground.png"));
    }
    Q_UNUSED(widget);
    Q_UNUSED(option);
}
