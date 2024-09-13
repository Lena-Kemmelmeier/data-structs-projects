// Author(s): Lena Kemmelmeier, Marc Amandoron
// Purpose: PA6: BST and Binary Tree Implementations
// Date: Summer '23, due July 16th

#ifndef LINKED_BINARY_SEARCH_TREE
#define LINKED_BINARY_SEARCH_TREE

#include "linkedBinaryTree.h"

template<class ItemType>
class BST: public LinkedBinaryTree<ItemType>{

    private:
        LinkedTreeNode<ItemType>* rootPtr;
    
    protected:

        // helper methods (for public methods)
        LinkedTreeNode<ItemType>* placeNode(LinkedTreeNode<ItemType>* subTreePtr, LinkedTreeNode<ItemType>* newNodePtr);
        LinkedTreeNode<ItemType>* removeValue(LinkedTreeNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful);
        LinkedTreeNode<ItemType>* removeNode(LinkedTreeNode<ItemType>* nodePtr);
        LinkedTreeNode<ItemType>* removeLeftmostNode(LinkedTreeNode<ItemType>* nodePtr, ItemType& inorderSuccessor);
        LinkedTreeNode<ItemType>* findNode(LinkedTreeNode<ItemType>* treePtr, const ItemType& target) const;
        LinkedTreeNode<ItemType>* copyHelper(LinkedTreeNode<ItemType>* nodePtr);

    public:

        // constructors & destructor 
        BST();
        BST(const BST& rhs);
        ~BST();

        // public methods (those included in tree interface)
        bool add(const ItemType& newData) override;
        bool remove(const ItemType&) override;
        bool contains(const ItemType& anEntry) const override;
        ItemType getRootData() const override;
        bool isEmpty() const override;
        int getNumberOfNodes() const override;
        void setRootData(const ItemType& newItem) override;
        int getHeight() const override;
        void clear() override;

        //traversal methods
        void preorderTraverse(void visit(ItemType&)) const override;
        void inorderTraverse(void visit(ItemType&)) const override;
        void postorderTraverse(void visit(ItemType&)) const override;
};

#include "linkedBinarySearchTree.cpp"
#endif