#include "landshaft.h"
#include "main_settings.h"

#include <QPainter>


Landshaft::Landshaft(): GameObject()
{
    color = Qt::green;
    this->setZValue(-10);
    pix = NULL;
    type = LANDSHAFT;
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
    Q_UNUSED(widget);
    Q_UNUSED(option);
}
