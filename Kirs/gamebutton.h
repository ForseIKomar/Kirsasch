#ifndef GAMEBUTTON_H
#define GAMEBUTTON_H

#include <QObject>
#include <QGraphicsObject>
#include <QPainter>

#include "main_settings.h"

class GameButton: public QGraphicsObject
{
public:
    explicit GameButton();
    ~GameButton();

    void setText(QString string);
    void setLeftX(int x);
    void setGeometry(int w, int h);

    int getWidth();
    int getHeigth();

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    int width, height;
    int leftX;
    QString text;

};

#endif // GAMEBUTTON_H
