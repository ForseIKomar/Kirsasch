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
    QPoint getCellPos();

    void setPriority(int prir);
    int getPrioriy();

    void setWalkProperty(bool canWalk);
    bool getWalkProperty();

private:
    QRectF boundingRect() const;
    int x, y;
    int priority;
    int id;
    bool canWalkThrow;
};

#endif // GAMEOBJECT_H
