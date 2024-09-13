#include "event.h"

Event::Event() {
    arrivalTime = 0;
    transactionTime = 0;
    departureTime = 0;
    eventTime = 0;
}

Event::Event(int newArrivalTime, int newTransactionTime, int newDepartureTime) {
    arrivalTime = newArrivalTime;
    transactionTime = newTransactionTime;
    eventTime = newArrivalTime;
    departureTime = newDepartureTime;
}
 
Event::Event(const Event& rhs) {
    arrivalTime = rhs.arrivalTime;
    transactionTime = rhs.transactionTime;
    eventTime = rhs.eventTime;
    departureTime = rhs.departureTime;
}

void Event::setArrivalTime(const int newArrivalTime) {
    arrivalTime = newArrivalTime;
    eventTime = arrivalTime;
}

void Event::setTransactionTime(const int newTransactionTime) {
    transactionTime = newTransactionTime;
}

void Event::setDepartureTime(const int newCurrentTime) {
    departureTime = newCurrentTime + transactionTime;
    setEventTime(departureTime);
    setArrivalTime(0);
}

void Event::setEventTime(int newEventTime) {
    eventTime = newEventTime;
}

int Event::getArrivalTime() const{
    return arrivalTime;
}

int Event::getTransactionTime() const{
    return transactionTime;
}

int Event::getDepartureTime() const{
    return departureTime;
}

int Event::getEventTime() const{
    return eventTime;
}

bool Event::isArrival() const{

    if (getDepartureTime() == 0) {
        return true;
    }
    return false;
}

bool Event::operator>(const Event& rhs) const{
    // if both events (an arrival and a departure event) occur at the same time, process the arrival event first
    // A > B means that A should come after B in the queue - for the priority queue implementation, this means A is lower priority

    if(this->eventTime == rhs.eventTime){ // both events occured at the same time but one is an arrival and the other is the departure
        if(isArrival()){ // if the lhs operand is an arrival, so the lhs operand go ahead of the rhs operand in the queue - A is higher priorituy
            return false;
        }
        return true; // the rhs operand is the arrival, so the rhs operand will go ahead of the lhs in the queue - A is lower priority
    }
    else{ // both events are of the same type (ex: departure)
        if(this->eventTime > rhs.eventTime){ // the lhs event happens at a time after the rhs event - so A is lower priortiy
            return true;
        }
        return false; // the lhs event happens before the event - so A is higher priority
    }
}