#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QObject>
#include <QGraphicsObject>

class HealthBar: public QGraphicsObject
{
public:
    explicit HealthBar();
    ~HealthBar();

public:
    void setMaxHealth(int mHealth, int currHealth);
    void setHealth(int Health);
    void redraw();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:
    int health;
    int maxHealth;
};

#endif // HEALTHBAR_H
