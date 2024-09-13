template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() {
    front = 0;
    back = DEFAULT_CAPACITY - 1;
    count = 0;
}

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue(const ArrayQueue& oldQueue) {
    for (int i = 0; i <= oldQueue.count; i++) {
        items[i] = oldQueue.peekFront();
        oldQueue.dequeue();
    }
}

template<class ItemType>
ArrayQueue<ItemType>::~ArrayQueue() {}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const{
    return count == 0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry) {
    bool ableToEnqueue = false;
    if (count < DEFAULT_CAPACITY) {
        back = (back + 1) % DEFAULT_CAPACITY;
        items[back] = newEntry;
        count++;
        ableToEnqueue = true;
    }
    return ableToEnqueue;
}

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue() {
    bool ableToDequeue = false;
    if (!(isEmpty())) {
        front = (front + 1) % DEFAULT_CAPACITY;
        count--;
        ableToDequeue = true;
    }
    return ableToDequeue;
}

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const {
    if (!(isEmpty())) {
        return items[front];
    }
    throw "Unable to peekFront(), queue is empty.";
}