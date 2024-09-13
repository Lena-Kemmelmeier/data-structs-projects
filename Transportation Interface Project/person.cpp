/*
 * Author: Lena Kemmelmeier
 * Purpose: Create train and bus system that tracks movement and cargo
 * CS 302 - Summer '23
*/

#include "person.h"

Person::Person(){
    name = "DEFAULT NAME";
    height = -1.11; //lets us know something is up
}

Person::Person(string newName, double newHeight){
    name = newName;
    height = newHeight;
}

Person::Person(Person& oldPerson){
    name = oldPerson.name;
    height = oldPerson.height;
}

double Person::getHeight(){
    return height;
}

void Person::setHeight(double newHeight){
    height = newHeight;
}

string Person::getName(){
    return name;
}

void Person::setName(string newName){
    name = newName;
}

//overloading > operator - allows us to compare heights b/w Person objects easier
bool Person::operator>(const Person& other) const{
    return height > other.height;
}

//overloading <= operator - allows us to compare heights b/w Person objects easier
bool Person::operator<=(const Person& other) const{
    return height <= other.height;
}

//overloading the == operator - needed for implementing Transportation's unload behavior in Train/Bus
bool Person::operator==(const Person& rhs) const{
    if (name == rhs.name && height == rhs.height){
        return true;
    }
    return false;
}