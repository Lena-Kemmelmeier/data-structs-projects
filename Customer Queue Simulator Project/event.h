#ifndef EVENT_H
#define EVENT_H

class Event {
    private:
        int arrivalTime, transactionTime, departureTime, eventTime;
        
    public:
        Event();
        Event(int, int, int);
        Event(const Event&);

        void setArrivalTime(const int);
        void setTransactionTime(const int);
        void setDepartureTime(const int);
        void setEventTime(const int);
        
        int getArrivalTime() const;
        int getTransactionTime() const;
        int getDepartureTime() const;
        int getEventTime() const;

        bool isArrival() const;

        bool operator >(const Event&) const;

};
#endif