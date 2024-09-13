// Author: Lena Kemmelmeier
// Purpose: CS 302 Homework 7 - Traveling Salesman Problem
// Date: Summer '23

#include <iostream>
#include <fstream>
using namespace std;
#include "matrixGraph.h"
#include "arrayList.h"
#include "path.h"

// functions used for gathering data from initial city + distance data to later create permutations:
void addCityVertsEdges(MatrixGraph<string>& travelGraph, ArrayList<string>& cities, ArrayList<string>& uniqueCities);
bool isCityNew(string city, ArrayList<string>& citiesList);
string findStartReturnCity(ArrayList<string>& citiesList);

// functions used for creating permutations:
ArrayList<Path> generateUniqueTravelPerms(MatrixGraph<string>& travelGraph, string startEnd);
Path swapElementsPath(Path oldPath);
Path rotatePathRight(Path oldPath);
Path rotatePathLeft(Path oldPath);
bool backToOriginalPath(Path recentPath, Path originalPath);
void writeInVert(string& vert);
Path getStartingPath(MatrixGraph<string>& travelGraph, string startReturnCity);

// functions used for file IO:
void writeAllPossiblePaths(ArrayList<Path> paths); //write all paths into txt
void clearOutputs(); // empties txt of path outputs each time program runs from start
void writeInPath(Path dispPath, string label); // helper for writeAllPossiblePaths()

// functions used for finding the cheapest path:
double calculateCostPath(double fuelEfficiency, double gasPrice, Path path, MatrixGraph<string>& travelGraph);
Path findCheapestPath(double fuelEfficiency, double gasPrice, ArrayList<Path>& paths, MatrixGraph<string>& travelGraph);

int main(){
    MatrixGraph<string> pathGraph; 
    ArrayList<string> allCityInstances, graphVertices;
    double fuelEffMPG = 40; //mps, miles per gallion
    double priceGasPerGal = 4.89; // price of gas ($) per gallon - current avg in CA according to Google

    clearOutputs();

    // gather the data needed to later generate path permutations
    addCityVertsEdges(pathGraph, allCityInstances, graphVertices);
    string startEndCity = findStartReturnCity(allCityInstances); // this finds which city we should stop and end at in each path - whichever occurs most freqeuntly

    // generate all path permutations + write into file
    ArrayList<Path> pathList = generateUniqueTravelPerms(pathGraph, startEndCity);
    writeAllPossiblePaths(pathList);

    // identify the least costly path + write into file
    Path bestPath = findCheapestPath(fuelEffMPG, priceGasPerGal, pathList, pathGraph);
    writeInPath(bestPath, "Best path");

    return 0;
}

void addCityVertsEdges(MatrixGraph<string>& travelGraph, ArrayList<string>& cities, ArrayList<string>& uniqueCities){
    ifstream file("initDistancesCities.txt");
    string start, end;
    int weight;

    if(file.is_open()){
        while(file >> start >> end >> weight){
            travelGraph.add(start, end, weight);

            cities.insert(cities.getLength() + 1, start);
            cities.insert(cities.getLength() + 1, end);

            if(isCityNew(start,uniqueCities)){
                uniqueCities.insert(uniqueCities.getLength() + 1, start);
            }
            if(isCityNew(end, uniqueCities)){
                uniqueCities.insert(uniqueCities.getLength() + 1, end);
            }
        }
    }
    file.close();
}

bool isCityNew(string city, ArrayList<string>& citiesList){
    bool isUnique = true;

    if(citiesList.isEmpty()){
        return isUnique;
    }
    for(int i = 1; i <= citiesList.getLength(); i++){
        if(citiesList.getEntry(i) == city){
            isUnique = false;
        }
    }
    return isUnique;
}

string findStartReturnCity(ArrayList<string>& citiesList){
    int maxNumOccur = 0, count;
    string startEnd;

    for(int i = 1; i <= citiesList.getLength(); i++){
        count = 1;

        for(int j = i + 1; j <= citiesList.getLength(); j++){
            if(citiesList.getEntry(i) == citiesList.getEntry(j)){
                count++;
            }
        }
        if(count > maxNumOccur){
            maxNumOccur = count;
            startEnd = citiesList.getEntry(i);
        }
    }
    return startEnd;
}

Path swapElementsPath(Path oldPath){
    ArrayList<string> oldLocations = oldPath.getLocations();
    ArrayList<string> newLocations(oldLocations);
    string secondStop, fourthStop;

    secondStop = oldLocations.getEntry(3);
    fourthStop = oldLocations.getEntry(5);

    newLocations.replace(3, fourthStop);
    newLocations.replace(5, secondStop);

    Path newPath(newLocations);
    return newPath;
}

Path rotatePathRight(Path oldPath){
    ArrayList<string> oldLocations = oldPath.getLocations();
    ArrayList<string> newLocations(oldLocations);
    string newBegin;

    // remove the first and last element of the array (start/end city - will add back later)
    string oldEnd = newLocations.getEntry(newLocations.getLength());
    string oldStart = newLocations.getEntry(1);
    newLocations.remove(newLocations.getLength());
    newLocations.remove(1);

    for(int i = newLocations.getLength(); i >= 1; i--){
        if(i > 1){
            if(i == newLocations.getLength()){
                newBegin = newLocations.getEntry(i);
            }
            newLocations.replace(i, newLocations.getEntry(i - 1));
        }
        else{
            newLocations.replace(i, newBegin);
        }
    }

    newLocations.insert(1, oldStart);
    newLocations.insert(newLocations.getLength() + 1, oldEnd);

    Path newPath(newLocations);
    return newPath;
}

Path rotatePathLeft(Path oldPath){
    ArrayList<string> oldLocations = oldPath.getLocations();
    ArrayList<string> newLocations(oldLocations);
    string newEnd;

    // remove the first and last element of the array (start/end city - will add back later)
    string oldEnd = newLocations.getEntry(newLocations.getLength());
    string oldStart = newLocations.getEntry(1);
    newLocations.remove(newLocations.getLength());
    newLocations.remove(1);

    for(int i = 1; i <= newLocations.getLength(); i++){
        if(i < newLocations.getLength()){
            if(i == 1){
                newEnd = newLocations.getEntry(i);
            }
            newLocations.replace(i, newLocations.getEntry(i + 1));
        }
        else{
            newLocations.replace(i, newEnd);
        }
    }

    newLocations.insert(1, oldStart);
    newLocations.insert(newLocations.getLength() + 1, oldEnd);
    
    Path newPath(newLocations);
    return newPath;  
}

void writeInPath(Path dispPath, string label){
    ArrayList<string> locations = dispPath.getLocations();

    ofstream file;
    file.open("pathsOutput.txt", std::ios_base::app);

    if(file.is_open()){
        file << label << ": ";
        for(int i = 1; i <= locations.getLength(); i++){
            file << locations.getEntry(i) <<  " ";
        }
        file << endl;      
    }
    file.close();
}

void writeInVert(string& vert){
    ofstream file;
    file.open("possiblePath.txt", std::ios_base::app);

    if(file.is_open()){
        file << vert << " ";
    }
    file.close();
}

Path getStartingPath(MatrixGraph<string>& travelGraph, string startReturnCity){
    travelGraph.depthFirstTraversal(startReturnCity, writeInVert);
    ArrayList<string> locationsDFS;
    string location;
    Path possiblePath;

     ifstream file("possiblePath.txt");

     if(file.is_open()){

        while(file >> location){
            locationsDFS.insert(locationsDFS.getLength() + 1,location);
        }
     }
    file.close();

    locationsDFS.insert(locationsDFS.getLength() + 1, startReturnCity); // add ending city
    possiblePath.setLocations(locationsDFS);

    return possiblePath;
}

ArrayList<Path> generateUniqueTravelPerms(MatrixGraph<string>& travelGraph, string startEnd){
    ArrayList<Path> pathsList;
    bool isOriginalArr = false, swapFlag = true, rotateRight = true;
    Path originalPath = getStartingPath(travelGraph, startEnd);
    Path newPath(originalPath.getLocations());

    while(!isOriginalArr){
        pathsList.insert(pathsList.getLength() + 1, newPath);

         if(swapFlag){
                newPath = swapElementsPath(newPath);
                swapFlag = !swapFlag;
            }
        else{
            if(rotateRight){ // let's rotate right!
                newPath = rotatePathRight(newPath);
            }
            else{ // let's rotate left!
                newPath = rotatePathLeft(newPath);
            }
            rotateRight = !rotateRight;
            swapFlag = !swapFlag;    
        }
        isOriginalArr = backToOriginalPath(newPath, originalPath);
    }
    return pathsList;
}

bool backToOriginalPath(Path recentPath, Path originalPath){
    bool isPathSame = true;

    ArrayList<string> recentLocations = recentPath.getLocations();
    ArrayList<string> originalLocations = originalPath.getLocations();

    for(int i = 1; i <= recentLocations.getLength(); i++){
        if (recentLocations.getEntry(i) != originalLocations.getEntry(i)){
            isPathSame = false;
        }
    }
    return isPathSame;
}

void writeAllPossiblePaths(ArrayList<Path> paths){
    for(int i = 1; i <= paths.getLength(); i++){
        writeInPath(paths.getEntry(i), "Possible path");
    }
}

void clearOutputs(){
    ofstream file;
    file.open("pathsOutput.txt", std::ofstream::out | std::ofstream::trunc);
    file.close();

    ofstream file2;
    file2.open("possiblePath.txt", std::ofstream::out | std::ofstream::trunc);
    file2.close();
}

double calculateCostPath(double fuelEfficiency, double gasPrice, Path path, MatrixGraph<string>& travelGraph){
    int totalMiles = 0;
    double test = 12.3, cost;
    ArrayList<string> locations = path.getLocations();

    for(int i = 1; i < locations.getLength(); i++){
        totalMiles += travelGraph.getEdgeWeight(locations.getEntry(i), locations.getEntry(i + 1));
    }

    cost = (gasPrice * totalMiles)/fuelEfficiency;
    return cost;
}

Path findCheapestPath(double fuelEfficiency, double gasPrice, ArrayList<Path>& paths, MatrixGraph<string>& travelGraph){
    double lowestCost = __INT_MAX__, cost;
    Path cheapestPath, currPath;

    for(int i = 1; i <= paths.getLength(); i++){
        currPath = paths.getEntry(i);
        cost = calculateCostPath(fuelEfficiency, gasPrice, currPath, travelGraph);

        if(cost < lowestCost){
            cheapestPath = currPath;
            lowestCost = cost;
        }
    }
    return cheapestPath;
}