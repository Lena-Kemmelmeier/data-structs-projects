#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

#include "queue.h"

template<class ItemType>
class ArrayQueue: public QueueInterface<ItemType> {
    protected:
        static const int DEFAULT_CAPACITY = 50;
        ItemType items[DEFAULT_CAPACITY];
        int front, back, count;
        
    public:
        ArrayQueue();
        ArrayQueue(const ArrayQueue& oldQueue);
        ~ArrayQueue();
        bool isEmpty() const;
        bool enqueue(const ItemType& newEntry);
        bool dequeue();
        ItemType peekFront() const;
};

#include "arrayQueue.cpp"
#endif