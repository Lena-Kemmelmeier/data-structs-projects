// Author: Lena Kemmelmeier
// Purpose: CS 302 Homework 7 - Traveling Salesman Problem
// Date: Summer '23

template<class ItemType>
ArrayList<ItemType>::ArrayList() : maxCount(DEFAULT_CAPACITY), itemCount(0){}

// our copy constructor
template<class ItemType>
ArrayList<ItemType>::ArrayList(const ArrayList<ItemType>& aList){

    itemCount = aList.itemCount;
    maxCount = aList.maxCount;

    for (int i = 1; i <= itemCount ; i++){ // ignoring items[0] - copy over all the items
        items[i] = aList.items[i];
    }
}

template<class ItemType>
ArrayList<ItemType>::~ArrayList(){}

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const{
    return itemCount == 0; // self-explanatory
}

template<class ItemType>
int ArrayList<ItemType>::getLength() const{
	return itemCount;
}

template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry){
    bool ableToInsert = (newPosition >= 1) &&
                        (newPosition <= itemCount + 1) &&
                        (itemCount < maxCount);
    if (ableToInsert){
        for(int pos = itemCount + 1; pos > newPosition; pos--){
            items[pos] = items[pos - 1];
        }
        items[newPosition] = newEntry;
        itemCount++;
    }
    return ableToInsert;
}

template<class ItemType>
bool ArrayList<ItemType>::remove(int position){
    bool ableToRemove = (position <= itemCount) && (position >= 1); // is the position valid?

    if (ableToRemove){
        for(int pos = position; pos < itemCount; pos++){ 
            items[pos] = items[pos + 1]; // shifting over - remove by overriding
        }
        itemCount--;
    }
    return ableToRemove;
}

template<class ItemType>
void ArrayList<ItemType>::clear(){
	itemCount = 0;
}

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const {
	bool ableToGet = (position >= 1) && (position <= itemCount);

	if (ableToGet){
		return items[position];
	} 
	throw "Item not found";
} 

template<class ItemType>
ItemType ArrayList<ItemType>::replace(int position, const ItemType& newEntry){
    bool ableToReplace = (position <= itemCount) && (position >= 1); // is the position valid? greater than 0 and the position of an existing item

    if (ableToReplace){
        ItemType replaceThisEntry = items[position]; // entry that we are kicking out
        items[position] = newEntry; // new entry that is replacing old entry is put in

        return replaceThisEntry;
    }
    else{
        throw "Unable to replace! The position is invalid";
    }
}