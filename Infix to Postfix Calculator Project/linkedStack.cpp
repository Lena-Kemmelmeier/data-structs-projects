// Author: Lena Kemmelmeier
// Date: 6/17/23
// Purpose: CS 302 HW 3

//default constructor
template<class ItemType>
LinkedStack<ItemType>::LinkedStack(){
    topPtr = nullptr;
}

//copy constructor
template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& oldStack){
    Node<ItemType>* chainPtr = oldStack.topPtr;

    if (chainPtr != nullptr){ // stack we're copying is not empty

        // let's first copy the top pointer over
        topPtr = new Node<ItemType>;
        topPtr->setItem(chainPtr->getItem());
        Node<ItemType>* newChainPtr = topPtr;
        
        // now, let's traverse the linked stack (until nullptr) to copy the rest of the stack over
        chainPtr = chainPtr->getNext();

        while (chainPtr != nullptr){
            ItemType nextItem = chainPtr->getNext();
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

            newChainPtr->setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
            chainPtr = chainPtr->getNext();

        }
    }
    else{ // stack we're copying is empty - just make the top pointer null
        topPtr = nullptr;
    }
}

//destructuor
template<class ItemType>
LinkedStack<ItemType>::~LinkedStack(){
    while (isEmpty() == 0){
        pop();
    }
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const{
    return topPtr == nullptr;
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem){
    Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, topPtr);
    topPtr = newNodePtr;
    newNodePtr = nullptr;

    return 1; // we can always push something to the stack, so this will always return true
}

template<class ItemType>
bool LinkedStack<ItemType>::pop(){
    bool canPop = 0;

    if (isEmpty() == 0){ // if the stack is not empty, delete the top item
        Node<ItemType>* deleteMe = topPtr;
        topPtr = topPtr->getNext();
        deleteMe->setNext(nullptr);

        delete deleteMe;
        deleteMe = nullptr;

        canPop = 1;
    }
    return canPop;
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const{
    if (isEmpty() == 0){
        return topPtr->getItem();
    }
    else{
        throw "stack is empty! could not peek!";
    }
}