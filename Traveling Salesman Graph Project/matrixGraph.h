// Author: Lena Kemmelmeier
// Purpose: CS 302 Homework 7 - Traveling Salesman Problem
// Date: Summer '23

#ifndef MATRIX_GRAPH
#define MATRIX_GRAPH

#include "graph.h"
#include "arrayStack.h"
#include "arrayQueue.h"

template<class LabelType>
class MatrixGraph : public GraphInterface<LabelType>{
    private:
        static const int DEFAULT_CAPACITY = 50;
        int edges[DEFAULT_CAPACITY][DEFAULT_CAPACITY];
        LabelType vertices[DEFAULT_CAPACITY];
        int numVertices, numEdges;
        
    public:
        MatrixGraph();
        int getNumVertices() const;
        int getNumEdges() const;
        bool add(LabelType start, LabelType end, int edgeWeight);
        bool remove(LabelType start, LabelType end);
        int getEdgeWeight(LabelType start, LabelType end) const;
        void depthFirstTraversal(LabelType start, void visit(LabelType&));
        void breadthFirstTraversal(LabelType start, void visit(LabelType&));
};

#include "matrixGraph.cpp"
#endif