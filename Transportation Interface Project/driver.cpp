/*
 * Author: Lena Kemmelmeier
 * Purpose: Create train and bus system that tracks movement and cargo
 * CS 302 - Summer '23
*/

#include "person.h"
#include "cargo.h"
#include "train.h"
#include "bus.h"

// for this PA, some functions are only needed for a certain transport carrying a certain item; hence why they are here in driver & not templated
void reportCargoWeightTrain(Train<Cargo> train); // although either a train or bus can handle cargo, for this PA we are only interested in finding a train's cargo weight
void reportBusFairPassengers(Bus<Person> bus); // calculates total fair for a bus that can carry passengers, not interested in using this for train or something carrying cargo
int whereLoadPersonBus(Bus<Person> bus, Person newPerson); // determines where a new person should sit on a bus (ascending order of height) - not interested in using this for trains

int main(){

    // General Demos

    // check - can we instantiate Cargo and Person?
    Cargo container("container",1000); // a container weighing 1000 lbs
    Cargo luggage("luggage", 60); // luggage weighing 60 lbs
    Cargo furniture("furniture", 250); // furniture weighing 250 lbs
    Cargo machinery("machinery",2000); // machinery weighing 2000 lbs

    Person Zach("Zach",4.56); // Zach is 4.56 ft tall
    Person Adam("Adam",5.60); // Adam is 5.60 ft tall
    Person Bert("Bert",4.75); // Bert is 4.75 feet tall
    Person Tom("Tom",6.11); // Tom is 6.11 feet tall

    // check - can we instantiate Bus and Train with either Person or Cargo?
    Bus<Person> peopleBus;
    Bus<Cargo> cargoBus;

    Train<Person> peopleTrain;
    Train<Cargo> cargoTrain;

    // let's go ahead and check whether each of these transporters are empty and how many items they are carrying
    cout << "Initially . . . " << endl;
    cout << endl << "Are these transporters empty? 0 - False; 1 - True" << endl;
    cout << "peopleBus: " << peopleBus.isEmpty() << endl;
    cout << "cargoBus: " << cargoBus.isEmpty() << endl;
    cout << "peopleTrain: " << peopleTrain.isEmpty() << endl;
    cout << "cargoTrain: " << cargoTrain.isEmpty() << endl << endl;

    cout << "peopleBus is carrying " << peopleBus.reportNumItems() << " items." << endl;
    cout << "cargoBus is carrying " << cargoBus.reportNumItems() << " items." << endl;
    cout << "peopleTrain is carrying " << peopleTrain.reportNumItems() << " items." << endl;
    cout << "cargoTrain is carrying " << cargoTrain.reportNumItems() << " items." << endl << endl;




    // TRAIN & CARGO DEMOS!!

    // let's load Cargo items one at a time onto a train and a bus - it doesn't matter what way this is done
    cargoBus.loadItem(luggage, 0); // 0 here means the container will be placed at the beginning of the item array for that bus
    cargoBus.loadItem(furniture, 1); // 1 here means that it will be placed after luggage in the array (at index 1)
    cargoTrain.loadItem(furniture, 0);
    cargoTrain.loadItem(machinery, 1);

    // check how many items both of these transporters are carrying:
    cout << "After loading items . . ." << endl;
    cout << "cargoBus is carrying " << cargoBus.reportNumItems() << " items." << endl;
    cout << "cargoTrain is carrying " << cargoTrain.reportNumItems() << " items." << endl << endl;

    // let's unload an item from each of these transporters
    cargoBus.unloadItem(luggage);
    cargoTrain.unloadItem(machinery);

    cout << "After emptying . . . " << endl;
    cout << "cargoBus is carrying " << cargoBus.reportNumItems() << " items." << endl;
    cout << "cargoTrain is carrying " << cargoTrain.reportNumItems() << " items." << endl << endl;

    // let's add one more item to the cargo bus and then empty it completely
    cargoBus.loadItem(machinery, 0);
    cout << "cargoBus is carrying " << cargoBus.reportNumItems() << " items." << endl;

    cargoBus.emptyItems();
    cout << "cargoBus is carrying " << cargoBus.reportNumItems() << " items." << endl;
    cout << endl << "Is it empty? 0 - False; 1 - True: " << cargoBus.isEmpty() << endl << endl;

    // what's the total weight for the items on the Cargo train?
    reportCargoWeightTrain(cargoTrain);
    cargoTrain.loadItem(luggage, 0);
    reportCargoWeightTrain(cargoTrain);
    cargoTrain.emptyItems();
    reportCargoWeightTrain(cargoTrain);




    // BUS DEMOS!!

    // let's load people one at a time onto a bus - they are seated on the bus (array) in order of ascending height
    // Index 0 = seated at the very front of the bus (> index = farther back)
    // we can call whereLoadPersonBus to figure out where they should be seated before we load them (no need to load then sort - others should already be in order)

    int adamIndex = whereLoadPersonBus(peopleBus, Adam);
    cout << endl << "Adam will be placed at index " << adamIndex << endl; // this makes sense because Adam is the first one on the bus
    peopleBus.loadItem(Adam, adamIndex);

    int zachIndex = whereLoadPersonBus(peopleBus, Zach);
    cout << "Zach will be placed at index " << zachIndex << endl; // this makes sense because Zach is shorter than Adam
    peopleBus.loadItem(Zach, zachIndex);

    int bertIndex = whereLoadPersonBus(peopleBus, Bert);
    cout << "Bert will be placed at index " << bertIndex << endl << endl; // this makes sense because Bert is between Zach and Adam in height
    peopleBus.loadItem(Bert, bertIndex);

    // let's check how many people are on the bus now
    Person* peopleBusPeople = peopleBus.getItems();
    cout << "Number of people on the bus: " << peopleBus.reportNumItems() << endl << endl;

    // let's see where people are sitting on the bus (just a check to verify functionality on whereLoadPersonBus & oadItem) & get the total fair
    Person currentPerson;
    for (int i = 0; i < peopleBus.reportNumItems(); i++){
         currentPerson = peopleBusPeople[i];
         cout << currentPerson.getName() << endl;
    }
    cout << endl;

    reportBusFairPassengers(peopleBus);

    // let's edit the total bus fair and re-check the total price
    peopleBus.setFair(3.50); // bus fair now $3.50
    reportBusFairPassengers(peopleBus);

    // let's unload one person from the bus
    peopleBus.unloadItem(Bert);

    // let's see where people are sitting on the bus (just a check to verify functionality) - get the total fair
    peopleBusPeople = peopleBus.getItems();
    cout << endl << "Number of people on bus: " << peopleBus.reportNumItems() << endl; // good
    for (int i = 0; i < peopleBus.reportNumItems(); i++){
         currentPerson = peopleBusPeople[i];
         cout << currentPerson.getName() << endl;
    }
    cout << endl;

    reportBusFairPassengers(peopleBus);

    peopleBus.emptyItems();

    cout << endl << "What is the bus fair now that it is empty?" << endl;
    reportBusFairPassengers(peopleBus);




    // MOVEMENT DEMOS!!

    // it's time to move the transports aroud!! - let's demonstrate that both a train and bus can do this (a bit differently)
    cout << endl;
    for(int i = 0; i < 5; i++){
        peopleBus.move();
    }
    cout << endl;

    for(int i = 0; i < 5; i++){
        cargoTrain.move();
    }
    cout << endl;

    return 0;

}

// train must be able to report total weight for all cargo on board
void reportCargoWeightTrain(Train<Cargo> train){
    Cargo* itemsArr = train.getItems();
    double weightTotal = 0;
    int numItems = train.reportNumItems();

    // use overloaded + operator on Cargo here - I overloaded it in a way that was most convenient to how I use it here
     for (int i = 0; i < train.reportNumItems(); i++){
        Cargo currentItem = itemsArr[i];
        weightTotal = currentItem + weightTotal;
     }

    printf("The total weight for the %d item(s) of cargo on board is %0.2lf lbs.\n", numItems, weightTotal); // preserve format
}

// buses must be able to give a total fair for all the people on board
void reportBusFairPassengers(Bus<Person> bus){
    double totalFair, busFair = bus.getFair();
    int numPassengers = bus.reportNumItems();

    totalFair = numPassengers * busFair;

    printf("The current bus fair is $%0.2lf. With %d passenger(s), the total fair is $%0.2lf.\n", busFair, numPassengers, totalFair); // preserve format
}

// determines argument for loadItem behavior for Bus - People objects should be loaded in order of ascending height
int whereLoadPersonBus(Bus<Person> bus, Person newPerson){
    Person* personArr = bus.getItems();

    int personIndex, numPersons = bus.reportNumItems();
    bool thisPersonTaller; // whether newPerson is taller than the person they're being compared to

    if (numPersons < bus.getMaxItems()){ // only execute rest of function if the bus is not already at max capacity
        numPersons++;

        for (int i = 0; i < numPersons; i++){
            personIndex = i;

            if (newPerson > personArr[i]){
                thisPersonTaller = true;
            }
            else if (newPerson <= personArr[i]){
                thisPersonTaller = false;
                break;
            }
        }

        return personIndex;
    }

    return (bus.getMaxItems() + 1); // prevents loading later down the line - out of bounds for array
}