/*
 * Author: Lena Kemmelmeier
 * Purpose: Create train and bus system that tracks movement and cargo
 * CS 302 - Summer '23
*/

#ifndef BUS_H
#define BUS_H

#include <iostream>
using namespace std;

#include "transporter.h"

template<class itemType>
class Bus: public Transporter<itemType>{

    static const int MAX = 50; //max num of items bus can hold at once
    itemType items_stored[MAX];

    int itemCount; //current numnber of items bus is holding
    double busFair; // bus fair per person in dollars
    string stops[4]; //arr that stores the different stops this bus makes - each bus only makes four stops
    int currentStopIndx; // the number of the current stop the bus is at - either 1, 2, 3, or 4
    bool empty;

    public:
        Bus();
        ~Bus() {};

        bool loadItem(const itemType& item, int loadIndex); //loads a particular item into items_stored at a certain index, returns whether loading successful
        bool unloadItem(const itemType& item); //unloads a particular item from items_stored, returns whether item found
        void emptyItems();
        void move();
        bool isEmpty() const;
        int reportNumItems();
        itemType* getItems();

        void setFair(double newFair);
        double getFair();
        int getMaxItems();
};

#include "bus.cpp"
#endif