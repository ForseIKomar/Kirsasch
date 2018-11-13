#include "hero.h"
#include "main_settings.h"

#include <QPainter>

Hero::Hero(): GameObject()
{
    color = Qt::red;
}

Hero::~Hero(){

}

void Hero::setColor(QBrush brush){
    color = brush;
}

void Hero::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(color);
    painter->drawEllipse(0, 0, cellWidth, cellHeight);
    Q_UNUSED(widget);
    Q_UNUSED(option);
}
