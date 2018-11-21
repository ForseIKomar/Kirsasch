#ifndef LANDSHAFT_H
#define LANDSHAFT_H

#include <QObject>
#include "gameobject.h"
#include <QBrush>

class Landshaft : public GameObject
{
    Q_OBJECT
public:
    explicit Landshaft();
    ~Landshaft();

    void setColor(QBrush brush);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public:
    QBrush color;

};

#endif // LANDSHAFT_H
