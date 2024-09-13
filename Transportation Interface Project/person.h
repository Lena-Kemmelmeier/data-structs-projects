/*
 * Author: Lena Kemmelmeier
 * Purpose: Create train and bus system that tracks movement and cargo
 * CS 302 - Summer '23
*/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person{
    private:
        string name; // first name of person
        double height; // height in feet

    public:
        Person();
        Person(string newName, double newHeight);
        Person(Person& oldPerson);

        double getHeight();
        void setHeight(double newHeight);

        string getName();
        void setName(string newName);

        //overloading > operator - allows us to compare heights b/w Person objects easier
        bool operator>(const Person& other) const;

        //overloading <= operator - allows us to compare heights b/w Person objects easier
        bool operator<=(const Person& other) const;

        //overloading the == operator - needed for implementing Transportation's unload behavior in both Train/Bus
        bool operator==(const Person& rhs) const;

};

#endif