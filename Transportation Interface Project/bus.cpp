template<class itemType>
Bus<itemType>::Bus(){

    itemCount = 0; //by default, bus should start with 0 items on board
    busFair = 2.50; // default bus fair per person is $2.50

    stops[0] = "UNR";
    stops[1] = "RNO Airport";
    stops[2] = "Sparks";
    stops[3] = "Downtown";

    empty = 1; // by default, bus is empty
    currentStopIndx = 0; //bus will always start at first stop on the line
}

template<class itemType>
bool  Bus<itemType>::loadItem(const itemType& item, int loadIndex){

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
bool  Bus<itemType>::unloadItem(const itemType& item){
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
void  Bus<itemType>::emptyItems(){

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
void  Bus<itemType>::move(){ //increment the stop index (looped)
    //print current stop
    cout << "The bus is departing from " <<  stops[currentStopIndx] << endl;;

    if (currentStopIndx == 3){ //at the last stop index, the next stop will be the first one (loop back around)
        currentStopIndx = 0;
    }
    else{ // if any other stop, stop index should increment normally
        currentStopIndx++;
    }
    
    cout << "The bus has reached its next stop, " << stops[currentStopIndx] << endl;
}

template<class itemType>
bool  Bus<itemType>::isEmpty() const{
    return empty;
}

template<class itemType>
int  Bus<itemType>::reportNumItems(){
    return itemCount;
}

template<class itemType>
itemType* Bus<itemType>::getItems(){
    return items_stored;
}

template<class itemType>
void Bus<itemType>::setFair(double newFair){
    busFair = newFair;
}

template<class itemType>
double Bus<itemType>::getFair(){
    return busFair;
}

template<class itemType>
int Bus<itemType>::getMaxItems(){
    return MAX;
}