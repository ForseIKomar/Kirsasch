#include "gamebutton.h"

GameButton::GameButton():
    QGraphicsObject()
{
    width = 4 * cellWidth;
    height = cellHeight * 0.8;
    leftX = cellWidth;
    text = "NULL";
}

GameButton::~GameButton(){

}

void GameButton::setText(QString string){
    text = string;
    this->moveBy(0.1, 0);
    this->moveBy(-0.1, 0);
}

void GameButton::setLeftX(int x){
    leftX = x;
}

void GameButton::setGeometry(int w, int h){
    width = w;
    height = h;
}

QRectF GameButton::boundingRect() const{
    return QRectF(0, 0, width, height);
}

void GameButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(Qt::white);
    painter->drawRect(0, 0, width, height);
    QFont font;
    font.setPixelSize(16);
    font.setFamily("Times New Roman");
    painter->setFont(font);
    painter->drawText(leftX, 26, text);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

int GameButton::getHeigth(){
    return height;
}

int GameButton::getWidth(){
    return width;
}
