#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QObject>
#include <QGraphicsObject>
#include <QPainter>
#include "main_settings.h"

class MenuButton: public QGraphicsObject
{
public:
    explicit MenuButton();
    ~MenuButton();

    void setText(QString text);
    void redraw();

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QString btnText;
};

#endif // MENUBUTTON_H
