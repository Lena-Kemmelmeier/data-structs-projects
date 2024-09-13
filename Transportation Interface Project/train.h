/*
 * Author: Lena Kemmelmeier
 * Purpose: Create train and bus system that tracks movement and cargo
 * CS 302 - Summer '23
*/

#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
using namespace std;

#include "transporter.h"

template<class itemType>
class Train: public Transporter<itemType>{

    static const int MAX = 50; //max num of items train can hold at once
    itemType items_stored[MAX];
    int itemCount; //current numnber of items train is holding
    string stops[4]; //arr that stores the different stops this train makes - each train only makes four stops
    int currentStopIndx; // the number of the current stop the train is at - either 1, 2, 3, or 4
    bool empty;

    public:
        Train();
        ~Train() {};

        bool loadItem(const itemType& item, int loadIndex); //loads a particular item into items_stored at a certain index, returns whether loading successful
        bool unloadItem(const itemType& item); //unloads a particular item from items_stored, returns whether item found
        void emptyItems();
        void move();
        bool isEmpty() const;
        int reportNumItems();
        itemType* getItems();
};

#include "train.cpp"
#endif