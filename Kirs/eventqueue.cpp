#include "eventqueue.h"

int EventQueue::i = 0;
QVector<GameEvent *> EventQueue::events = QVector<GameEvent*>();

EventQueue::EventQueue()
{

}

EventQueue::~EventQueue(){

}

void EventQueue::AddEvent(GameEvent *event){
    events.push_back(event);
}

void EventQueue::deleteUnactive(){
    for (int j = 0; j + i < events.size(); ++j){
        events[j] = events[j + i];
    }
    for (int j = 0; j < events.size() - i; ++j){
        events.pop_back();
    }
}

GameEvent* EventQueue::getNextEvent(){
    if (i < events.size())
        return events[i++];
    return NULL;
}
