#include "traponland.h"
#include "main_settings.h"

#include <QPainter>

TrapOnLand::TrapOnLand(): LivingObject()
{
    setPriority(1);
    alwaysWork = false;
    image = new QImage();
    image->load(":/img/31.jpg");
    type = TRAP_OBJECT;
}

TrapOnLand::~TrapOnLand(){

}

int TrapOnLand::getDamage(){
    if (alwaysWork)
        return dmg;
    else{
        if (health > 0){
            this->changeHealth(1);
            this->moveBy(0.1, 0);
            this->moveBy(-0.1, 0);
            return dmg;
        }
        else
            return 0;
    }
}

void TrapOnLand::setTrap(int actDamage, bool twoMoreWork, int coWork){
    alwaysWork = twoMoreWork;
    dmg = actDamage;
    this->setMaxHealth(coWork);
}

void TrapOnLand::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    if ((alwaysWork) || ((!alwaysWork) && (health > 0))){
        painter->drawPixmap(0, 0, 50, 50, QPixmap(":/img/31.png"));
    }
    Q_UNUSED(option);
    Q_UNUSED(widget)
}
