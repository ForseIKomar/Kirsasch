#include "landshaft.h"
#include "main_settings.h"

#include <QPainter>


Landshaft::Landshaft(): GameObject()
{
    color = Qt::green;
    this->setZValue(-10);
}

Landshaft::~Landshaft(){

}

void Landshaft::setColor(QBrush brush){
    color = brush;
}

void Landshaft::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(color);
    painter->drawRect(0, 0, cellWidth, cellHeight);
    Q_UNUSED(widget);
    Q_UNUSED(option);
}
