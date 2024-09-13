// Author(s): Lena Kemmelmeier, Marc Amandoron
// Purpose: PA6: BST and Binary Tree Implementations
// Date: Summer '23, due July 16th

#ifndef LINKED_BINARY_TREE
#define LINKED_BINARY_TREE

#include "tree.h"
#include "linkedtreenode.h"
#include <algorithm>
using namespace std;

template<class ItemType>
class LinkedBinaryTree: public TreeInterface<ItemType>{

    private:
        LinkedTreeNode<ItemType>* rootPtr;

    protected:

        // helper methods (for public methods)
        int getHeightHelper(LinkedTreeNode<ItemType>* subTreePtr) const;
        int getNumberOfNodesHelper(LinkedTreeNode<ItemType>* subTreePtr) const;
        LinkedTreeNode<ItemType>* balancedAdd(LinkedTreeNode<ItemType>* subTreePtr, LinkedTreeNode<ItemType>* newNodePtr);
        LinkedTreeNode<ItemType>* removeValue(LinkedTreeNode<ItemType>* subTreePtr, const ItemType targetVal, bool& isSuccess);
        LinkedTreeNode<ItemType>* moveValuesUpTree(LinkedTreeNode<ItemType>* subTreePtr);
        LinkedTreeNode<ItemType>* findNode(LinkedTreeNode<ItemType>* treePtr, const ItemType& targetVal, bool& isSuccess) const;
        LinkedTreeNode<ItemType>* copyTree(LinkedTreeNode<ItemType>* treePtr);
        void destroyTree(LinkedTreeNode<ItemType>* subTreePtr);

        // recursive traversal helper methods
        void preorder(void visit(ItemType&), LinkedTreeNode<ItemType>* treePtr) const;
        void inorder(void visit(ItemType&), LinkedTreeNode<ItemType>* treePtr) const;
        void postorder(void visit(ItemType&), LinkedTreeNode<ItemType>* treePtr) const;
    
    public:

        // constructors & destructor
        LinkedBinaryTree();
        LinkedBinaryTree(const ItemType& rootItem);
        LinkedBinaryTree(const ItemType& rootItem, LinkedBinaryTree<ItemType> leftTreePtr, LinkedBinaryTree<ItemType> rightTreePtr);
        LinkedBinaryTree(const LinkedBinaryTree<ItemType>& oldTree);
        ~LinkedBinaryTree();

        // public methods (tree interface)
        virtual bool isEmpty() const;
        virtual int getHeight() const;
        virtual int getNumberOfNodes() const;
        virtual ItemType getRootData() const;
        virtual void setRootData(const ItemType& newItem);
        virtual bool add(const ItemType& newItem);
        virtual bool remove(const ItemType& item);
        virtual void clear();
        virtual ItemType getEntry(const ItemType& item) const;
        virtual bool contains(const ItemType& item) const;

        //traversal methods
        virtual void preorderTraverse(void visit(ItemType&)) const;
        virtual void inorderTraverse(void visit(ItemType&)) const;
        virtual void postorderTraverse(void visit(ItemType&)) const;
};

#include "linkedBinaryTree.cpp"
#endif