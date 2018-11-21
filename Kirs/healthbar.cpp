#include "healthbar.h"
#include "main_settings.h"

#include <QPainter>

HealthBar::HealthBar():
    QGraphicsObject()
{
    health = 1;
    maxHealth = 1;
}

HealthBar::~HealthBar(){

}

void HealthBar::setMaxHealth(int mHealth, int currHealth){
    maxHealth = mHealth;
    health = currHealth;
    redraw();
}

void HealthBar::setHealth(int Health){
    health = Health;
    redraw();
}

void HealthBar::redraw(){
    this->moveBy(0.1, 0);
    this->moveBy(-0.1, 0);
}

void HealthBar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(Qt::white);
    painter->drawRect(0, 0, 4 * cellWidth, cellHeight);
    painter->setBrush(Qt::red);
    painter->drawRect(0, 0, (1.0 * health / maxHealth) * 4 * cellWidth, cellHeight);
    QFont m;
    m.setPixelSize(20);
    painter->setFont(m);
    painter->drawText(1.5 * cellWidth, cellHeight / 2 + 10, QString::number(health) + QString('/') + QString::number(maxHealth));
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF HealthBar::boundingRect() const{
    return QRectF(0, 0, 4 * cellWidth, cellHeight);
}

