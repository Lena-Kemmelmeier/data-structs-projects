#ifndef ARRAY_STACK
#define ARRAY_STACK

#include "stack.h"

template<class ItemType>
class ArrayStack: public StackInterface<ItemType> {
private:
    static const int DEFAULT_CAPACITY = 100;
    ItemType items[DEFAULT_CAPACITY];
    int top;
public:
    ArrayStack();

    bool isEmpty() const;
    bool push(const ItemType& newEntry);
    bool pop();
    ItemType peek() const;

    ~ArrayStack() {}
};

#include "arrayStack.cpp"
#endif