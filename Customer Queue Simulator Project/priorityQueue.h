#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include "arrayQueue.h"

template<class ItemType>
class PriorityQueue:public ArrayQueue<ItemType> {
    
    public:
        bool enqueue(const ItemType& newEntry);

};

#include "priorityQueue.cpp"
#endif