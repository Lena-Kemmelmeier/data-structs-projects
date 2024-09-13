/*
 * Author: Lena Kemmelmeier
 * Purpose: Create train and bus system that tracks movement and cargo
 * CS 302 - Summer '23
*/

#ifndef TRANSPORTER_H
#define TRANSPORTER_H

template <class itemType>
class Transporter{

    public:
        virtual bool loadItem(const itemType& item, int loadIndex) = 0;
        virtual bool unloadItem(const itemType& item) = 0;
        virtual void emptyItems() = 0;
        virtual void move() = 0;
        virtual bool isEmpty() const = 0;
        virtual int reportNumItems() = 0;
        virtual itemType* getItems() = 0; // this is useful for both Train and Bus to implement Transportation's behaviors - refer to driver
};

#endif