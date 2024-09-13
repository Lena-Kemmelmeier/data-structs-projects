// Author: Erin Keith (original) & Lena Kemmelmeier (copy constructor, insert, clear, getEntry) 
// Date: 6/11/23
// Purpose: HW2 - implementation of the linked list

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
	// enforce precondition
	if((position >= 1) && (position <= itemCount)){
		// Count from the beginning of the chain
		Node<ItemType>* curPtr = headPtr;
		for (int skip = 1; skip < position; skip++){
			curPtr = curPtr->getNext();
		}
		return curPtr;
	}
	return nullptr;
} 

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0){}

// our copy constructor - provided from the lecture slides
template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList){
	itemCount = aList.itemCount;

	if(itemCount > 0){
		Node<ItemType>* newNodePtr = new Node<ItemType>();
		headPtr = newNodePtr;

		Node <ItemType>* oldListPtr = aList.headPtr;
		newNodePtr->setItem(oldListPtr->getItem());
		
		Node<ItemType>* newListPtr = nullptr;
		for(int pos = 2; pos <= itemCount; pos++){
			oldListPtr = oldListPtr->getNext();
			newListPtr = newNodePtr;
			newNodePtr = new Node<ItemType>();
			newNodePtr->setItem(oldListPtr->getItem());
			newListPtr->setNext(newNodePtr);
		}
	}
	else{
		headPtr = nullptr;
	}
	
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const{
	return itemCount == 0; // empty if numItems is 0
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const{
	return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry){
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1); // position not zero and inserting either at an existing position or end of the list
	if (ableToInsert){
		Node<ItemType>* ptrNewNode = new Node<ItemType>(newEntry);

		if (newPosition > 1){ // this new node won't be the first in the chain
			// do some pointer rearranging - make sure that the pointer before points to this new pointer now
			Node<ItemType>* lastPtr = getNodeAt(newPosition - 1); // find the last ptr

			ptrNewNode->setNext(lastPtr->getNext());

			lastPtr->setNext(ptrNewNode); // last pointer will point to the new pointer (connected in chain)
		}
		else{ // this new node will new be the first in the chain
			ptrNewNode->setNext(headPtr); // rearrange
			headPtr = ptrNewNode;
		}

		itemCount++; // increment num of items
	}

	return ableToInsert;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position){
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove){
		Node<ItemType>* ptrToDelete = nullptr;
		if (position == 1){
			// Remove the first node in the chain
			ptrToDelete = headPtr; // Save pointer to node 
			headPtr = headPtr->getNext();// save pointer to next node
		}
		else{
			// Find node that is before the one to remove
			Node<ItemType>* prevPtr = getNodeAt(position - 1);
			// Point to node to remove
			ptrToDelete = prevPtr->getNext();
			// Disconnect indicated node from chain by connecting the prior node with the one after
			prevPtr->setNext(ptrToDelete->getNext());
		}

		ptrToDelete->setNext(nullptr);
		delete ptrToDelete;
		ptrToDelete = nullptr;
		itemCount--; // Decrease count of entries
	}
	return ableToRemove;

}

template<class ItemType>
void LinkedList<ItemType>::clear(){
    while (isEmpty() == false){
		remove(1); // keep removing the first node in the chain (eventually will remove all because of how pointers rearrange)
	}
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {
    bool ableToFind = (position >= 1) && (position <= itemCount); // precondition - is the position not 0 and within the bounds of our current list?

	if (ableToFind){
		Node<ItemType>* ptrToNode = getNodeAt(position);
		return ptrToNode->getItem(); // get the item
	}
	else{
		throw "Unable to getEntry! Invalid position";
	}
} 

template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry){
	// enforce precondition
	bool ableToReplace = (position >= 1) && (position <= itemCount);
	if (ableToReplace){
		Node<ItemType>* nodePtr = getNodeAt(position);
		ItemType oldEntry = nodePtr->getItem();
		nodePtr->setItem(newEntry);	
		return oldEntry;	
	} 
	throw "Item not found";
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList(){
	clear();
} 
