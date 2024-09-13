/*
 * Author: Lena Kemmelmeier
 * Purpose: Create train and bus system that tracks movement and cargo
 * CS 302 - Summer '23
*/

#ifndef CARGO_H
#define CARGO_H

#include <iostream>
using namespace std;

class Cargo{
    private:
        string type; // Container, bag, etc.
        double weight; // weight in pounds (lbs)

    public:
        Cargo();
        Cargo(string newType, double newWeight);
        Cargo(Cargo& oldCargo);

        double getWeight();
        void setWeight(double newWeight);

        string getType();
        void setType(string newType);

        //overloading the == operator - needed for implementing unload behavior in Train/Bus
        bool operator==(const Cargo& rhs) const;

        //overloading the + operator - needed for reporting total weight of Cargo for Train objects in driver
        double operator+(const double& rhs) const;
};

#endif