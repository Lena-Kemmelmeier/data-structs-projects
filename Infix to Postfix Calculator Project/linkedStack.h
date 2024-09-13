// Author: Lena Kemmelmeier
// Date: 6/17/23
// Purpose: CS 302 HW 3

#ifndef LINKED_STACK
#define LINKED_STACK

#include "stack.h"
#include "node.h"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType>{
    Node<ItemType>* topPtr;

    public:
        LinkedStack();
        LinkedStack(const LinkedStack<ItemType>& oldStack);
        virtual ~LinkedStack();

        bool isEmpty() const;
        bool push(const ItemType& newItem);
        bool pop();
        ItemType peek() const;
};


#include "linkedStack.cpp"
#endif