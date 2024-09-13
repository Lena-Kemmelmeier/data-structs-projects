
template<class ItemType>
bool PriorityQueue<ItemType>::enqueue(const ItemType& newEntry) {
    bool lowerPriority;
    int itemIndx = 0, pos;

    if(this->count < this->DEFAULT_CAPACITY){

        if(this->isEmpty() == false){ // the array is not empty - let's find what index we should be 'inserting' the new item at!

            while(itemIndx <= this->back){

                if(newEntry > this->items[itemIndx]){
                    lowerPriority = true;
                }
                else{
                    lowerPriority = false;
                    break;
                }

                if(itemIndx < (this->DEFAULT_CAPACITY - 1)){
                    itemIndx++;
                }
                else{ // index rolls over from DEFAULT_CAPACITY - 1 to 0
                    itemIndx = 0;
                }
            }
        }
        else{ // the array is empty
            itemIndx = this->front;
        }


        this->back = (this->back + 1) % this->DEFAULT_CAPACITY; //increment the back by 1
        pos = this->back;

        // go ahead and shift everything over for copying

        // this while loop will only execute if the new item is going before some old items
        while(pos > itemIndx){

            if (pos == 0){ // index rolls over from 0 to DEFAULT_CAPACITY - 1
                this->items[pos] = this->items[this->DEFAULT_CAPACITY - 1];
                pos = this->DEFAULT_CAPACITY - 1;
            }
            else{
                this->items[pos] = this->items[pos-1];
                pos--;
            }
        }

        this->items[itemIndx] = newEntry; //place the new entry in the array
        this->count++; //increment count

        return true;
    }
    return false;
}