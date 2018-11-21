#ifndef INDICATORSCENE_H
#define INDICATORSCENE_H

#include <QObject>
#include <QGraphicsScene>

#include <QGraphicsTextItem>
#include "healthbar.h"

class IndicatorScene: public QGraphicsScene
{
    Q_OBJECT
public:
    explicit IndicatorScene(QObject *parent = 0);
    ~IndicatorScene();

    HealthBar* getHealthBar();

    void update();

private:
    HealthBar *healthBar;

};

#endif // INDICATORSCENE_H
