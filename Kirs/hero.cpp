#include "hero.h"
#include "main_settings.h"

#include <QPainter>

Hero::Hero(): LivingObject()
{
    setWalkProperty(false);
    image = new QImage();
    image->load("img/hero.jpg");
    secType = HERO;
    defintion = HERO;
}

Hero::~Hero(){

}

void Hero::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawPixmap(1, 1, cellWidth - 1, cellWidth - 1, QPixmap(":/img/2.png"));
    Q_UNUSED(widget);
    Q_UNUSED(option);
}
