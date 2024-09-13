/*
 * Author: Lena Kemmelmeier
 * Purpose: Create train and bus system that tracks movement and cargo
 * CS 302 - Summer '23
*/

#include "cargo.h"

Cargo::Cargo(){
    type = "DEFAULT";
    weight = 0.00;
}
Cargo::Cargo(string newType, double newWeight){
    type = newType;
    weight = newWeight;
}

Cargo::Cargo(Cargo& oldCargo){
    type = oldCargo.type;
    weight = oldCargo.weight;
}

double Cargo::getWeight(){
    return weight;
}

void Cargo::setWeight(double newWeight){
    weight = newWeight;
}

string Cargo::getType(){
    return type;
}

void Cargo::setType(string newType){
    type = newType;
}

bool Cargo::operator==(const Cargo& rhs) const{
    if (weight == rhs.weight && type == rhs.type){
        return true;
    }
    return false;
}

// ik ik this looks weird, but it's useful for how I calculate total weight in driver
double Cargo::operator+(const double& rhs) const{
    return weight + rhs;
}