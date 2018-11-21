#include "indicatorscene.h"
#include "main_settings.h"

IndicatorScene::IndicatorScene(QObject *parent):
    QGraphicsScene(parent)
{
    this->setSceneRect(0, 0, 12 * cellWidth, 2 * cellHeight);
    healthBar = new HealthBar();
    healthBar->setMaxHealth(100, 50);
    healthBar->setPos(7 * cellWidth, 0.5 * cellHeight);
    this->addItem(healthBar);
}

IndicatorScene::~IndicatorScene(){

}

void IndicatorScene::update(){
    this->removeItem(healthBar);
    this->addItem(healthBar);
}

HealthBar* IndicatorScene::getHealthBar(){
    return healthBar;
}
