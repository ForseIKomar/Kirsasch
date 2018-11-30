#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include <QVector>
#include "gameevent.h"

class EventQueue
{
public:
    EventQueue();
    ~EventQueue();

    void AddEvent(GameEvent *event);
    GameEvent* getNextEvent();
    void deleteUnactive();

private:
    static QVector<GameEvent*> events;
    static int i;
};

#endif // EVENTQUEUE_H
