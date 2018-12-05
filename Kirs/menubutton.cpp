#include "menubutton.h"

MenuButton::MenuButton(): QGraphicsObject()
{
    btnText = "Default text";
}

MenuButton::~MenuButton(){

}

void MenuButton::setText(QString text){
    btnText = text;
}

void MenuButton::redraw(){
    this->moveBy(0.1, 0);
    this->moveBy(-0.1, 0);
}

QRectF MenuButton::boundingRect() const{
    return QRectF(-100, -30, 100, 30);      // Не гибкая
}

void MenuButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    //painter = new QPainter();
    painter->drawRect(-100, -30, 100, 30);
    int heigth = 14;
    int width = 10 * btnText.size();
    painter->drawText(-width / 2, -heigth / 2, btnText);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
