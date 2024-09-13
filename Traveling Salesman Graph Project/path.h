// Author: Lena Kemmelmeier
// Purpose: CS 302 Homework 7 - Traveling Salesman Problem
// Date: Summer '23

#include "arrayList.h"
#include <iostream>
using namespace std;

#ifndef PATH
#define PATH

class Path{
    private:
        ArrayList<string> locationArr;
        double cost;
    
    public:
        Path();
        Path(const ArrayList<string>& newPath);
        Path(const Path& oldPath);

        double getCost() const;
        void setCost(const double newCost);
        ArrayList<string> getLocations() const;
        void setLocations(const ArrayList<string>& newPath);
};
#endif