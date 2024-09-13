template<class itemType>
Train<itemType>::Train(){

    itemCount = 0; //by default, train should start with 0 items on board

    stops[0] = "Reno";
    stops[1] = "Truckee";
    stops[2] = "Roseville";
    stops[3] = "Sacramento";

    empty = 1; // by default, train is empty
    currentStopIndx = 0; //train will always start at first stop on the line
}

template<class itemType>
bool  Train<itemType>::loadItem(const itemType& item, int loadIndex){

    if(itemCount < MAX && loadIndex <= (itemCount)){ //is there enough room to store the item?

    // everything before where the new item goes will stay in the same place
    // everything that comes after (greater or equal index to the loadIndex in this case) will be shifted one over to the right

        itemCount++;

        for (int i  = itemCount; i >= loadIndex; i--){
            items_stored[i] = items_stored[i-1];
        }

        items_stored[loadIndex] = item;

        empty = false; //array is not empty
        return true; //item successfully stored
    }
    return false; //item not successfully stored
}

template<class itemType>
bool  Train<itemType>::unloadItem(const itemType& item){
    bool foundItem = false;

    for (int i = 0; i < itemCount && !foundItem; i++){

        if (items_stored[i] == item){
            itemCount--;
            items_stored[i] = items_stored[itemCount];

            foundItem = true;
        }
    }

    if (itemCount < 1){
        empty = 1; //now that this item is unloaded, the train is empty of all items
    }

    return foundItem;
}

template<class itemType>
void  Train<itemType>::emptyItems(){

    int itemToRemoveIndx, originalNumItems = itemCount;

    for(int i = 0; i < originalNumItems; i++){
         itemToRemoveIndx = i - 1;

         for (int j = itemToRemoveIndx; j < itemCount; j++){
             items_stored[j] = items_stored[j+1];
         }

         itemCount--;
    }

    empty = 1; //array is now empty
}

template<class itemType>
void  Train<itemType>::move(){ //increment the stop index (looped)
    //print current stop
    cout << "The train is departing from " <<  stops[currentStopIndx] << endl;;

    if (currentStopIndx == 3){ //at the last stop index, the next stop will be the first one (loop back around)
        currentStopIndx = 0;
    }
    else{ // if any other stop, stop index should increment normally
        currentStopIndx++;
    }
    
    cout << "The train has reached its next destination, " << stops[currentStopIndx] << endl;
}

template<class itemType>
bool  Train<itemType>::isEmpty() const{
    return empty;
}

template<class itemType>
int  Train<itemType>::reportNumItems(){
    return itemCount;
}

template<class itemType>
itemType* Train<itemType>::getItems(){
    return items_stored;
}