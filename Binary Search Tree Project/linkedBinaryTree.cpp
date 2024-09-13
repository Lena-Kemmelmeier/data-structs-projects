// Author(s): Lena Kemmelmeier, Marc Amandoron
// Purpose: PA6: BST and Binary Tree Implementations
// Date: Summer '23, due July 16th

// helper methods (for public methods)

template<class ItemType>
int LinkedBinaryTree<ItemType>::getHeightHelper(LinkedTreeNode<ItemType>* subTreePtr) const{
    if(subTreePtr == nullptr){
        return 0;
    }
    return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()) , getHeightHelper(subTreePtr->getRightChildPtr()));
}

template<class ItemType>
int LinkedBinaryTree<ItemType>::getNumberOfNodesHelper(LinkedTreeNode<ItemType>* subTreePtr) const{
    if(subTreePtr == nullptr){
        return 0;
    }
    return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
}

template<class ItemType>
LinkedTreeNode<ItemType>* LinkedBinaryTree<ItemType>::balancedAdd(LinkedTreeNode<ItemType>* subTreePtr, LinkedTreeNode<ItemType>* newNodePtr){
   
    // edge case
    if(subTreePtr == nullptr){
        return newNodePtr;
    }
    // else
    LinkedTreeNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
    LinkedTreeNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();

    // check the height of each side of the sub tree
    if(getHeightHelper(rightPtr) < getHeightHelper(leftPtr)){ // if left side is longer, add to right
        rightPtr = balancedAdd(rightPtr, newNodePtr);
        subTreePtr->setRightChildPtr(rightPtr);
    }
    else{
        leftPtr = balancedAdd(leftPtr, newNodePtr);
        subTreePtr->setLeftChildPtr(leftPtr);
    }
    return subTreePtr; //return updated sub tree pointer
}

template<class ItemType>
LinkedTreeNode<ItemType>* LinkedBinaryTree<ItemType>::removeValue(LinkedTreeNode<ItemType>* subTreePtr, const ItemType targetVal, bool& isSuccess){
    LinkedTreeNode<ItemType>* leftPtr;
    LinkedTreeNode<ItemType>* rightPtr; 

    if (subTreePtr == nullptr){
        // this node holds the target item
        isSuccess = false;
        return nullptr;
    }
    else if (subTreePtr->getItem() == targetVal){
        // remove the sub tree node from the tree (call moveValuesUpTree)
        isSuccess = true;
        subTreePtr = moveValuesUpTree(subTreePtr);
        return subTreePtr;
    }
    leftPtr = removeValue(subTreePtr->getLeftChildPtr(), targetVal, isSuccess);
    subTreePtr->setLeftChildPtr(leftPtr);
    rightPtr = removeValue(subTreePtr->getRightChildPtr(), targetVal, isSuccess);
    subTreePtr->setRightChildPtr(rightPtr);
    
    return subTreePtr;
}

template<class ItemType>
LinkedTreeNode<ItemType>* LinkedBinaryTree<ItemType>::moveValuesUpTree(LinkedTreeNode<ItemType>* subTreePtr){
    
    if(subTreePtr->isLeaf()){
        delete subTreePtr;
        return nullptr;
    }
    if(subTreePtr->getLeftChildPtr() != nullptr && subTreePtr->getRightChildPtr() == nullptr){ // has left child only
        LinkedTreeNode<ItemType>* nodePtr;

        nodePtr = subTreePtr->getLeftChildPtr(); // copy in left child
        subTreePtr->setItem(nodePtr->getItem());
        delete nodePtr;
        nodePtr = nullptr;
        subTreePtr->setLeftChildPtr(nodePtr);

        return subTreePtr;
    }
    else if(subTreePtr->getLeftChildPtr() == nullptr && subTreePtr->getRightChildPtr() != nullptr){ // has right child only
        LinkedTreeNode<ItemType>* nodePtr;

        nodePtr = subTreePtr->getRightChildPtr(); // copy in right child
        subTreePtr->setItem(nodePtr->getItem());
        delete nodePtr;
        nodePtr = nullptr;
        subTreePtr->setRightChildPtr(nodePtr);

        return subTreePtr;
    }
    // you found the target and now are deciding which side will become the new value in the current node
    else if(getHeightHelper(subTreePtr->getLeftChildPtr()) > getHeightHelper(subTreePtr->getRightChildPtr())){
        subTreePtr->setItem(subTreePtr->getLeftChildPtr()->getItem());
        LinkedTreeNode<ItemType>* nodePtr = moveValuesUpTree(subTreePtr->getLeftChildPtr());
        subTreePtr->setLeftChildPtr(nodePtr);
        return subTreePtr;
    }
    //else
    subTreePtr->setItem(subTreePtr->getRightChildPtr()->getItem());
    LinkedTreeNode<ItemType>* nodePtr = moveValuesUpTree(subTreePtr->getRightChildPtr());
    subTreePtr->setRightChildPtr(nodePtr);
    return subTreePtr;
}


template<class ItemType>
LinkedTreeNode<ItemType>* LinkedBinaryTree<ItemType>::findNode(LinkedTreeNode<ItemType>* subTreePtr, const ItemType& targetVal, bool& isSuccess) const{

    if (subTreePtr == nullptr){
        isSuccess = false;
        return nullptr;
    }
    if (subTreePtr->getItem() == targetVal){ // we located our item!
        isSuccess = true;
        return subTreePtr;
    }
    
    // check the left sub tree for the target val
    subTreePtr = findNode(subTreePtr->getLeftChildPtr(), targetVal, isSuccess);

    // if the target wasn't in the left sub tree, check the right sub tree
    if (!isSuccess){
        subTreePtr = findNode(subTreePtr->getRightChildPtr(), targetVal, isSuccess);
    }

    return subTreePtr;
}

template<class ItemType>
LinkedTreeNode<ItemType>* LinkedBinaryTree<ItemType>::copyTree(LinkedTreeNode<ItemType>* treePtr){
    LinkedTreeNode<ItemType>* newTreePtr;

    if(treePtr != nullptr){
        newTreePtr = new LinkedTreeNode<ItemType>(treePtr->getItem(), nullptr, nullptr);
        newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
        newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
    }
    return newTreePtr;
}

template<class ItemType>
void LinkedBinaryTree<ItemType>::destroyTree(LinkedTreeNode<ItemType>* subTreePtr){
    if(subTreePtr != nullptr){
        destroyTree(subTreePtr->getLeftChildPtr());
        destroyTree(subTreePtr->getRightChildPtr());
        delete subTreePtr;
    }
}



// recursive traversal helper methods

template<class ItemType>
void LinkedBinaryTree<ItemType>::preorder(void visit(ItemType&), LinkedTreeNode<ItemType>* treePtr) const{
    if(treePtr != nullptr){
        ItemType item = treePtr->getItem();
        visit(item);
        preorder(visit, treePtr->getLeftChildPtr());
        preorder(visit, treePtr->getRightChildPtr());
    }
}

template<class ItemType>
void LinkedBinaryTree<ItemType>::inorder(void visit(ItemType&), LinkedTreeNode<ItemType>* treePtr) const{
    if(treePtr != nullptr){
        inorder(visit, treePtr->getLeftChildPtr());
        ItemType item = treePtr->getItem();
        visit(item);
        inorder(visit, treePtr->getRightChildPtr());
    }
}

template<class ItemType>
void LinkedBinaryTree<ItemType>::postorder(void visit(ItemType&), LinkedTreeNode<ItemType>* treePtr) const{
    if(treePtr != nullptr){
        postorder(visit, treePtr->getLeftChildPtr());
        postorder(visit, treePtr->getRightChildPtr());
        ItemType item = treePtr->getItem();
        visit(item);
    }
}

template<class ItemType>
void LinkedBinaryTree<ItemType>::preorderTraverse(void visit(ItemType&)) const{
    preorder(visit, rootPtr);
}
template<class ItemType>
void LinkedBinaryTree<ItemType>::inorderTraverse(void visit(ItemType&)) const{
    inorder(visit, rootPtr);
}
template<class ItemType>
void LinkedBinaryTree<ItemType>::postorderTraverse(void visit(ItemType&)) const{
    postorder(visit, rootPtr);
}


// constructors & destructor

template<class ItemType>
LinkedBinaryTree<ItemType>::LinkedBinaryTree(){
    rootPtr = nullptr;
}

template<class ItemType>
LinkedBinaryTree<ItemType>::LinkedBinaryTree(const ItemType& rootItem){
    rootPtr = new LinkedTreeNode<ItemType>(rootItem, nullptr, nullptr);
}

template <class ItemType>
LinkedBinaryTree<ItemType>::LinkedBinaryTree(const ItemType& rootItem, LinkedBinaryTree<ItemType> leftTreePtr, LinkedBinaryTree<ItemType> rightTreePtr){
    rootPtr = new LinkedTreeNode<ItemType>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr));
}

template <class ItemType>
LinkedBinaryTree<ItemType>::LinkedBinaryTree(const LinkedBinaryTree<ItemType>& oldTree){
    rootPtr = copyTree(oldTree.rootPtr);
}

template <class ItemType>
LinkedBinaryTree<ItemType>::~LinkedBinaryTree(){
    destroyTree(rootPtr);
}


// tree interface methods

template <class ItemType>
bool LinkedBinaryTree<ItemType>::isEmpty() const{
    return this->rootPtr == nullptr;
}

template <class ItemType>
int LinkedBinaryTree<ItemType>::getHeight() const{
    return getHeightHelper(rootPtr);
}

template <class ItemType>
int LinkedBinaryTree<ItemType>::getNumberOfNodes() const{
    return getNumberOfNodesHelper(rootPtr);
}

template <class ItemType>
ItemType LinkedBinaryTree<ItemType>::getRootData() const{
    return this->rootPtr->getItem();
}

template <class ItemType>
void LinkedBinaryTree<ItemType>::setRootData(const ItemType& newItem){
    rootPtr->setItem(newItem);
}

template <class ItemType>
bool LinkedBinaryTree<ItemType>::add(const ItemType& newItem){
    LinkedTreeNode<ItemType>* newNodePtr = new LinkedTreeNode<ItemType>(newItem);
    rootPtr = balancedAdd(rootPtr, newNodePtr);
    
    return true;
}

template <class ItemType>
bool LinkedBinaryTree<ItemType>::remove(const ItemType& item){
    bool success = false;

    removeValue(rootPtr, item, success);
    return success;
}

template <class ItemType>
void LinkedBinaryTree<ItemType>::clear(){
    destroyTree(rootPtr);
}

template <class ItemType>
ItemType LinkedBinaryTree<ItemType>::getEntry(const ItemType& item) const{
    bool success = false;

    if(contains(item)){ // we can only get the entry if the tree contains this item
        LinkedTreeNode<ItemType>* treeNode = findNode(rootPtr, item, success);

        return treeNode->getItem();
    }
    throw "Tree does not contain this item!";
}

template <class ItemType>
bool LinkedBinaryTree<ItemType>::contains(const ItemType& item) const{
    bool success = false;

    findNode(rootPtr, item, success);
    return success;
}