// Author: Lena Kemmelmeier
// Purpose: CS 302 Homework 7 - Traveling Salesman Problem
// Date: Summer '23

#include "path.h"

Path::Path(){
    cost = 0;
}

Path::Path(const ArrayList<string>& newPath){
    locationArr = newPath;
    cost = 0;
}

Path::Path(const Path& oldPath){
    cost = oldPath.cost;
    locationArr = oldPath.locationArr;
}

double Path::getCost() const{
    return cost;
}

void Path::setCost(const double newCost){
    cost = newCost;
}

ArrayList<string> Path::getLocations() const{
    return locationArr;
}

void Path::setLocations(const ArrayList<string>& newPath){
    locationArr = newPath;
}