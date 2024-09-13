// Author(s): Lena Kemmelmeier, Marc Amandoron
// Purpose: PA6: BST and Binary Tree Implementations
// Date: Summer '23, due July 16th

#include "linkedtreenode.h"
#include "linkedBinarySearchTree.h"

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

void clearFileContents(); // because we use append in our write methods, we implemented this to clear file each time exe is run (gives a fresh slate)
void writeIn(int& item); //argument for visit for traversal methods- writes the item value of a node (int) into the txt
void fillTreeRandNums(BST<int>& tree, int numNodes); //takes a tree object and the number of desired nodes in tree; adds random nums till it is full
void writeInTraversalLabel(string whichTraversal); //this puts a line into txt that labels the following traversal data
void writeInHeight(BST<int>& tree); //takes a tree and writes final height into the txt

int main(){
    BST<int> testTree;
    clearFileContents();
    fillTreeRandNums(testTree, 100);

    writeInTraversalLabel("Preorder");
    testTree.preorderTraverse(writeIn);
    writeInTraversalLabel("Inorder");
    testTree.inorderTraverse(writeIn);
    writeInTraversalLabel("Postorder");
    testTree.postorderTraverse(writeIn);
    writeInHeight(testTree);

    return 0;
}


void fillTreeRandNums(BST<int>& tree, int numNodes){
    int ranNum;
    srand((unsigned) time(NULL)); // random numbers will be different each time the program is run

    do{
        ranNum = (rand() % 200) + 1; //generates a random number between 1 and 200 - double checked this range

        if(!(tree.contains(ranNum))){ //if number is unique, add to tree
            tree.add(ranNum);
        }

    } while(tree.getNumberOfNodes() < numNodes); //loop until there are 200 nodes in the tree
}

void writeInHeight(BST<int>& tree){
    ofstream file;
    file.open("BST_stats.txt", std::ios_base::app);
    file << endl << endl << "Height: " << tree.getHeight() << endl;
    file.close();
}

void writeIn(int& item){
    ofstream file;
    file.open("BST_stats.txt", std::ios_base::app);
    file << item << " ";
    file.close();  
}

void writeInTraversalLabel(string whichTraversal){
    ofstream file;
    file.open("BST_stats.txt", std::ios_base::app);
    file << endl << endl << whichTraversal << ": " << endl ;
    file.close();
}

void clearFileContents(){
    ofstream file;
    file.open("BST_stats.txt", std::ofstream::out | std::ofstream::trunc);
    file.close();
}