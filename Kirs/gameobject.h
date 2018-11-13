#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>
#include <QGraphicsObject>

class GameObject: public QGraphicsObject
{
public:
    explicit GameObject();
    ~GameObject();

public:
    void setCellPos(int x, int y);
    void setPriority(int prir);
    int getPrioriy();

private:
    QRectF boundingRect() const;
    int priority;
    int id;
};

#endif // GAMEOBJECT_H
