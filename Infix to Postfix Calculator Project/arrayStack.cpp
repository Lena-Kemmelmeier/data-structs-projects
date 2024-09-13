#include "arrayStack.h"

template<class ItemType>
ArrayStack<ItemType>::ArrayStack(){
    top = -1;
}

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const{
    return top < 0;
}

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry){
    bool canPush = top < DEFAULT_CAPACITY - 1;

    if(canPush){
        top++;
        items[top] = newEntry;
    }
    return canPush;
}

template<class ItemType>
bool ArrayStack<ItemType>::pop(){
    bool canPop = !isEmpty();

    if (canPop){
        top--;
    }

    return canPop;
}

template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const{
    bool canPeek = !isEmpty();

    if(canPeek){
        return items[top];
    }
    else{
        throw "empty stack";
    }
}