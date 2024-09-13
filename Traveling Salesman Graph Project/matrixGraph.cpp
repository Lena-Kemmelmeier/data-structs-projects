// Author: Lena Kemmelmeier
// Purpose: CS 302 Homework 7 - Traveling Salesman Problem
// Date: Summer '23

template<class LabelType>
MatrixGraph<LabelType>::MatrixGraph(){
    numVertices = 0;
    numEdges = 0;

    for (int i = 0; i < DEFAULT_CAPACITY; i++){
        for (int j = 0; j < DEFAULT_CAPACITY; j++){
            edges[i][j] = __INT_MAX__; // this is our default val
        }
    }
}

template<class LabelType>
int MatrixGraph<LabelType>::getNumVertices() const{
    return numVertices;
}

template<class LabelType>
int MatrixGraph<LabelType>::getNumEdges() const{
    return numEdges;
}

template<class LabelType>
bool MatrixGraph<LabelType>::add(LabelType start, LabelType end, int edgeWeight){
    bool doesStartExist = false, doesEndExist = false, success = false;
    int startIndex = -1, endIndex = -1, i = 0, j = 0;

    if(start == end){ // precondition - a vertex cannot be adjacent to itself!
        throw "a vertex cannot be adjacent to itself!";
    }

    if(numVertices > 0){ // if we already have some vertices, check if the start and end vertices exist in our vertices array
        while(i < numVertices || (!doesStartExist && !doesEndExist)){ // stop when we have found both vertices or when we looked at all vertices
            if(vertices[i] == start){
                doesStartExist = true;
            }
            else if(vertices[i] == end){
                doesEndExist = true;
            }
            i++;
        }
    }

    // if the start does not exist yet, add it to our list of vertices
    if(!doesStartExist){
        //precondition - do we have room to add another vertex? (have we exceeded capacity of the array?)
        if(numVertices == DEFAULT_CAPACITY ){
            throw "cannot add another vertex - at max capacity!";
        }

        vertices[numVertices] = start;
        numVertices++; //increment number of vertices
    }
    // if the start does not exist yet, add it to our list of vertices
    if (!doesEndExist){
        //precondition - do we have room to add another vertex? (have we exceeded capacity of the array?)
        if(numVertices == DEFAULT_CAPACITY ){
            throw "cannot add another vertex - at max capacity!";
        }

        vertices[numVertices] = end;
        numVertices++; //increment number of vertices
    }

    // now that both the vertices exist, let's add the edge between them (undirected)

    //find the index of the start and end indices - where are we slicing in the 2D edges array?
    while(j < numVertices || (startIndex == -1 && endIndex == -1)){ // stop when we have found the indices or when we looked at all vertices
        if(vertices[j] == start){
            startIndex = j;
        }
        else if(vertices[j] == end){
            endIndex = j;
        }
        j++;
    }

    // create an edge between the start and the end + vice versa - symmetric
    edges[startIndex][endIndex] = edgeWeight;
    edges[endIndex][startIndex] = edgeWeight;
    success = true;
    numEdges++;

    return success;
}

template<class LabelType>
bool MatrixGraph<LabelType>::remove(LabelType start, LabelType end){
    bool doesStartExist = false, doesEndExist = false, success = false, endHasEdge = false, startHasEdge = false;
    int startIndex = -1, endIndex = -1, i = 0, j = 0;

    //precondition - do both the start and end vertices exist? - this is our check
    if(numVertices > 0){ // if we already have some vertices, check if the start and end vertices exist in our vertices array
        while(i < numVertices || (!doesStartExist && !doesEndExist)){
            if(vertices[i] == start){
                doesStartExist = true;
                startIndex = i;
            }
            else if(vertices[i] == end){
                doesEndExist = true;
                endIndex = i;
            }
            i++;
        }
    }

    if(!doesStartExist || !doesEndExist){ // if either of the vertices did not exist to begin with, we can't remove an edge - return false
        throw "at least one of the entered vertices does not exist!";
    }

    //precondition - was there an edge between these two edges (that exist) to begin with?
    if(edges[startIndex][endIndex] == __INT_MAX__){
        throw "cannot remove the edge - there was not one to begin with!";
    }
    

    //remove the edge between the two vertices!
    edges[startIndex][endIndex] = __INT_MAX__;
    edges[endIndex][startIndex] = __INT_MAX__;
    numEdges--;

    success = true;

    // if a vertex does not have any edges anymore, delete it! this is a connected graph
    for(int k = 0; k < numVertices; k++){
        if(edges[endIndex][k] != __INT_MAX__){
            endHasEdge = true;
        }
        if(edges[startIndex][k] != __INT_MAX__){
            startHasEdge = true;
        }
    }
    
    if(!endHasEdge){
        // shift over values in 2d edges array
        for(int i = endIndex; i < numVertices; i++){

            for(int j = 0; j < numVertices; j++){ // shift the rows
                edges[j][i] = edges[j][i + 1];
            }
            for(int j = 0; j < numVertices; j++){ // then shift the columns
                edges[i][j] = edges[i + 1][j];
            }
        }

        // shift over values in vertices array
        for(int pos = endIndex; pos < numVertices; pos++){ 
            vertices[pos] = vertices[pos + 1];
        }
        numVertices--;
    }
    if(!startHasEdge){
        // shift over values in 2d edges array
        for(int i = startIndex; i < numVertices; i++){

            for(int j = 0; j < numVertices; j++){ // shift the rows
                edges[j][i] = edges[j][i + 1];
            }
            for(int j = 0; j < numVertices; j++){ // then shift the columns
                edges[i][j] = edges[i + 1][j];
            }
        }

        // shift over values in vertices array
        for(int pos = startIndex; pos < numVertices; pos++){ 
            vertices[pos] = vertices[pos + 1];
        }
        numVertices--;
    }
    return success;
}

template<class LabelType>
int MatrixGraph<LabelType>::getEdgeWeight(LabelType start, LabelType end) const{
    int startIndex = -1, endIndex = -1, i = 0;

    //find the index of the start and end indices - where are we slicing in the 2D edges array?
    while(i < numVertices || (startIndex == -1 && endIndex == -1)){
        if(vertices[i] == start){
            startIndex = i;
        }
        else if(vertices[i] == end){
            endIndex = i;
        }
        i++;
    }

    // throw an exception if either the end or start vertex does not exist
    if(startIndex == -1 || endIndex == -1){
        throw "at least one of the entered vertices does not exist!";
    }
    else if(edges[startIndex][endIndex] == __INT_MAX__){
        throw "no edge exists between these two vertices!";
    }
    
    return edges[startIndex][endIndex];
}

template<class LabelType>
void MatrixGraph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)){
    ArrayStack<LabelType> stack;
    LabelType top;
    int topIndex, j = 0, k = 0, l = 0, nextAdjacentIndx;
    bool isVisited[numVertices], foundIndex = false, foundUnvisted, foundTopVert;

    for(int i = 0; i < numVertices; i++){
        isVisited[i] = false;
    }

    stack.push(start);
    visit(start);

    // mark start as visited
    while ((j < numVertices) && !foundIndex){
        if(vertices[j] == start){
            foundIndex = true;
            isVisited[j] = true;
        }
        j++;
    }

    while(!stack.isEmpty()){
        top = stack.peek(); // get vertex that's at the top of the stack
        
        foundTopVert = false;
        k = 0;
        // find index in vertices array that corresponds to top - helps w/ edges array
        while ((k < numVertices) && !foundTopVert){
            if(vertices[k] == top){
                foundTopVert = true;
                topIndex = k;
            }
            k++;
        }
        
        // are there any adjacent vertices adjacent to the vertex at the top of the stack?
        foundUnvisted = false;
        l = 0;
        while(l < numVertices && !foundUnvisted){
            if (edges[topIndex][l] != __INT_MAX__){ // we found an edge!
                if(isVisited[l] == false){ // this vertex has not been visited by the traversal yet
                    foundUnvisted = true;
                    nextAdjacentIndx = l;
                }
            }
            l++;
        }

        if(!foundUnvisted){
            stack.pop();
        }
        else{ 
            stack.push(vertices[nextAdjacentIndx]);
            visit(vertices[nextAdjacentIndx]);

            isVisited[nextAdjacentIndx] = true;
        }
    }
}

template<class LabelType>
void MatrixGraph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)){
    ArrayQueue<LabelType> queue;
    LabelType front;
    int frontIndex, j = 0, k;
    bool isVisited[numVertices], foundIndex = false, foundFrontVert, foundUnvisted;

    for(int i = 0; i < numVertices; i++){
        isVisited[i] = false;
    }

    queue.enqueue(start);
    visit(start);

    // mark start as visited
    while ((j < numVertices) && !foundIndex){
        if(vertices[j] == start){
            foundIndex = true;
            isVisited[j] = true;
        }
        j++;
    }

    while(!queue.isEmpty()){
        front = queue.peekFront();
        queue.dequeue();

        foundFrontVert = false;
        k = 0;

        // find index in vertices array that corresponds to front - helps w/ edges array
        while ((k < numVertices) && !foundFrontVert){
            if(vertices[k] == front){
                foundFrontVert = true;
                frontIndex = k;
            }
            k++;
        }

        // are there any adjacent vertices adjacent to the vertex at the top of the stack?
        for (int l = 0; l < numVertices; l++){
            if (edges[frontIndex][l] != __INT_MAX__){ // we found an edge!
                if(isVisited[l] == false){ // this vertex has not been visited by the traversal yet

                    // marked this vertex as visited
                    visit(vertices[l]);
                    isVisited[l] = true;

                    queue.enqueue(vertices[l]);
                }
            }
        }
    }
}