// Author(s): Lena Kemmelmeier, Marc Amandoron
// Purpose: PA6: BST and Binary Tree Implementations
// Date: Summer '23, due July 16th

//constructors
template<class ItemType>
BST<ItemType>::BST(){
    rootPtr = nullptr;
}

//helper function for the copy constructor
template<class ItemType>
LinkedTreeNode<ItemType>* BST<ItemType>::copyHelper(LinkedTreeNode<ItemType>* nodePtr){
    if(nodePtr != nullptr){
        //create a new ptr and set ptr data to the data of the passed in nodePtr
        LinkedTreeNode<ItemType>* copy = new LinkedTreeNode<ItemType>();
        copy->setItem(nodePtr->getItem());
        //Recursively call the copyHelper to return the newly created ptr containing the data from the left and right branches
        copy->setLeftChildPtr(copyHelper(nodePtr->getLeftChildPtr));
        copy->setRightChildPtr(copyHelper(nodePtr->getRightChildPtr));
        return copy;
    }
    //if at any point we reach the null ptr we just return null ptr to be set as the new nodePtr
    return nullptr;
}

//Copy constructor making use of the copyHelper function
template<class ItemType>
BST<ItemType>::BST(const BST& rhs){
    //The copy helper will ouput a ptr to a new tree with data copied from the other BST when it finishes tracing back the steps after reaching the base case
    rootPtr = copyHelper(rhs.rootPtr);
}


template<class ItemType>
BST<ItemType>::~BST<ItemType>(){
    this->clear();
}

//Protected helper functions and the public functions that utilize them
template<class ItemType>
LinkedTreeNode<ItemType>* BST<ItemType>::placeNode(LinkedTreeNode<ItemType>* subTreePtr, LinkedTreeNode<ItemType>* newNodePtr){
    //base case
    if(subTreePtr == nullptr){
        return newNodePtr;
    }
    //checks to see if the current node in the tree is greater than the newly passed in node
    //if the current node in the tree is greater than then the newData type is moved to the left branch and a recursive function call is used to check the next downstream nodes for the same condition relationsihp
    else if(subTreePtr->getItem() > newNodePtr->getItem()){
        LinkedTreeNode<ItemType>* tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
        //the function will exit the above recursion when hitting the base case of null and then execute the setting of the left child
        subTreePtr->setLeftChildPtr(tempPtr);
        return subTreePtr;

    }
    //this is for the going to the right branch
    LinkedTreeNode<ItemType>* tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
    //this function will exit the above recursion when hitting base case and set the right child ptr of the previous node as the new node created
    subTreePtr->setRightChildPtr(tempPtr);
    return subTreePtr;
}

template<class ItemType>
bool BST<ItemType>::add(const ItemType& newData){
    LinkedTreeNode<ItemType>* newNodePtr = new LinkedTreeNode<ItemType>(newData);
    rootPtr = placeNode(rootPtr, newNodePtr);

    return true;
}

template<class ItemType>
LinkedTreeNode<ItemType>* BST<ItemType>::removeValue(LinkedTreeNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful){
    //base case
    if(subTreePtr == nullptr){
        isSuccessful = false;
    }
    //if the current treePtr value is the one to remove
    else if(subTreePtr->getItem() == target){
        isSuccessful = true;
        subTreePtr = removeNode(subTreePtr);
    }
    //else we have to traverse to the left branch if the current node is greater than target
    else if(subTreePtr->getItem() > target){
        LinkedTreeNode<ItemType>* tempPtr;
        tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
        //when exiting the recursive function call have to overwrite the left ptr so tree is stays connected after modifiction of node
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else if(subTreePtr->getItem() < target){
        //else: when the target is greater than current node we traverse the right subtree
        LinkedTreeNode<ItemType>* tempPtr;
        tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
        //when exiting the recursive function call have to overwrite the right child ptr so tree is connected
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
}


template<class ItemType>
LinkedTreeNode<ItemType>* BST<ItemType>::removeNode(LinkedTreeNode<ItemType>* nodePtr){
    LinkedTreeNode<ItemType>* copyPtr;
    //node to remove is a leaf
    if(nodePtr->isLeaf()){
        delete nodePtr;
        nodePtr = nullptr;
        return nodePtr;
    }
    //node to remove has 1 child
    else if((nodePtr->getLeftChildPtr() != nullptr && nodePtr->getRightChildPtr() == nullptr) || (nodePtr->getLeftChildPtr() == nullptr && nodePtr->getRightChildPtr() != nullptr)){
        //if the single child is the left child ptr copy it
        if(nodePtr->getLeftChildPtr() != nullptr){
            copyPtr = nodePtr->getLeftChildPtr();
        }
        //if the single child is the right child ptr copy it
        else{
            copyPtr = nodePtr->getRightChildPtr();
        }
        //delete the current ptr
        delete nodePtr;
        nodePtr = nullptr;
        //return the copyPtr to overwrite where the node is
        return copyPtr;
    }
    else{
        //else: node to remove has 2 children
        ItemType inOrderSuccessor;
        //have to find leftmost leaf of right child of target. The function will take that value and pass it up while deleting the left most node. Will return a new subtree with root at current passed in subtreeptr
        copyPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), inOrderSuccessor);
        //set the root of the newly returned subtree ptr as the right child ptr of the current target node
        nodePtr->setRightChildPtr(copyPtr);
        //overwrite the target node item to contain the passed in inOrder successor value
        nodePtr->setItem(inOrderSuccessor);
        return nodePtr;
    }

}


//should return the left most node 
template<class ItemType>
LinkedTreeNode<ItemType>* BST<ItemType>::removeLeftmostNode(LinkedTreeNode<ItemType>* nodePtr, ItemType& inorderSuccessor){
    //determine if current node is the last node in the left most branch
    if(nodePtr->getLeftChildPtr() == nullptr){
        //since it is the leftmost node set the inOrderSuccessor to the item on current node
        inorderSuccessor = nodePtr->getItem();
        //pass the current node to the removeNode function to delete it and move valuesUp
        return removeNode(nodePtr);
    }
    LinkedTreeNode<ItemType>* tempPtr;
    tempPtr = removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor);
    nodePtr->setLeftChildPtr(tempPtr);
    return nodePtr;
}

template<class ItemType>
bool BST<ItemType>::remove(const ItemType& item){
    bool isSuccessful = false;
    rootPtr = removeValue(rootPtr, item, isSuccessful);
    return isSuccessful;
}

//helper function for the contains public function
template<class ItemType>
LinkedTreeNode<ItemType>* BST<ItemType>::findNode(LinkedTreeNode<ItemType>* treePtr, const ItemType& target) const{
    //base case of hitting the bottom of the tree without finding the target
    if(treePtr == nullptr){
        return nullptr;
    }
    //base case of finding the target
    else if(treePtr->getItem() == target){
        return treePtr;
    }
    //traverse left then traverse right if target is not in the right
    else if(treePtr->getItem() > target){
        return findNode(treePtr->getLeftChildPtr(), target);
    }
    else{
        return findNode(treePtr->getRightChildPtr(), target);
    }
}

template<class ItemType>
bool BST<ItemType>::contains(const ItemType& anEntry) const {
    LinkedTreeNode<ItemType>* tempPtr;
    tempPtr = findNode(rootPtr, anEntry);
    bool contains = false;

    if(tempPtr == nullptr){
        return contains;
    }
    else if (tempPtr->getItem() == anEntry){
        contains = true;
    }
    return contains;
}



//function inherited from BinaryTree
template<class ItemType>
ItemType BST<ItemType>::getRootData() const{
    return rootPtr->getItem();
}

template<class ItemType>
void BST<ItemType>::setRootData(const ItemType& newItem){
    rootPtr->setItem(newItem);
}

template <class ItemType>
bool BST<ItemType>::isEmpty() const{
    return rootPtr == nullptr;
}

template <class ItemType>
int BST<ItemType>::getNumberOfNodes() const{
    return this->getNumberOfNodesHelper(rootPtr);
}

template <class ItemType>
int BST<ItemType>::getHeight() const{
    return this->getHeightHelper(rootPtr);
}

template <class ItemType>
void BST<ItemType>::clear(){
    this->destroyTree(rootPtr);
}

template <class ItemType>
void BST<ItemType>::preorderTraverse(void visit(ItemType&)) const{
    this->preorder(visit, rootPtr);
}
template <class ItemType>
void BST<ItemType>::inorderTraverse(void visit(ItemType&)) const{
    this->inorder(visit, rootPtr);
}
template <class ItemType>
void BST<ItemType>::postorderTraverse(void visit(ItemType&)) const{
    this->postorder(visit, rootPtr);
}