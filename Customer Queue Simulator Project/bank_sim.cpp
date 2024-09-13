#include "arrayQueue.h"
#include "priorityQueue.h"
#include "customer.h"
#include "event.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int readInput(string fileN, PriorityQueue<Event>& pQueue); //returns number of customers
void processArrival(PriorityQueue<Event>& pQueue, int cTime);
void processDepature(PriorityQueue<Event>& pQueue, ArrayQueue<Customer>& aQueue);
void displayStats(int pCount, float aTime);

int main() {
    ArrayQueue<Customer> bankQueue;
    PriorityQueue<Event> eventQueue;

    int currentTime, peopleCount = 0, departureTime;
    bool tellerAvailable = true;
    float waitTimeInQueue = 0, averageWaitTime;

    peopleCount = readInput("input.txt", eventQueue);

    cout << "Simulation Begins" << endl;
    while (!eventQueue.isEmpty()) {
        Event newEvent(eventQueue.peekFront()); 
        currentTime = newEvent.getEventTime(); 

        if (newEvent.isArrival()) {
            eventQueue.dequeue(); 
            Customer bankCustomer(newEvent.getArrivalTime(), newEvent.getTransactionTime());

            if (bankQueue.isEmpty() && tellerAvailable) {

                try{
                    processArrival(eventQueue, currentTime);
                    tellerAvailable = false;
                }
                catch (const char* e) {
                    cout << "Processing an arrival event at time:    " << currentTime << endl;
                    Event finalEvent(bankCustomer.getArrivalTime(), bankCustomer.getTransactionTime(), 0);
                    finalEvent.setDepartureTime(currentTime);
                    finalEvent.setEventTime(finalEvent.getDepartureTime());
                    currentTime = finalEvent.getEventTime();
                    cout << "Processing an departure event at time:  " << currentTime << endl;
                    break;

                }
            }
            else {
                bankQueue.enqueue(bankCustomer);
            }

            cout << "Processing an arrival event at time:    " << currentTime << endl;
        }
        else {
            eventQueue.dequeue();
            if (!bankQueue.isEmpty()) {
                Customer bankCustomer(bankQueue.peekFront());
                
                bankQueue.dequeue();
                departureTime = currentTime + bankCustomer.getTransactionTime();
                waitTimeInQueue += departureTime - bankCustomer.getArrivalTime() - bankCustomer.getTransactionTime();
                Event newDepartureEvent(0, 0, departureTime);
                newDepartureEvent.setEventTime(departureTime);
                eventQueue.enqueue(newDepartureEvent);
            }
            else {
                tellerAvailable = true;
            }
            cout << "Processing an departure event at time:  " << currentTime << endl;
        }
    }

    averageWaitTime = waitTimeInQueue / peopleCount;
    displayStats(peopleCount, averageWaitTime);

    return 0;
}

int readInput(string fileN, PriorityQueue<Event>& pQueue){
    int arrivalTime, transactionTime, count = 0;

    ifstream inFile;
    inFile.open(fileN);
    while (inFile >> arrivalTime >> transactionTime) { 
        Event newArrivalEvent(arrivalTime, transactionTime, 0);
        pQueue.enqueue(newArrivalEvent);
        count++;
    }
    return count;

    inFile.close();
}

void processArrival(PriorityQueue<Event>& pQueue, int cTime){
    Event newDepartureEvent(pQueue.peekFront());
    newDepartureEvent.setDepartureTime(cTime);
    newDepartureEvent.setEventTime(newDepartureEvent.getDepartureTime());
    pQueue.enqueue(newDepartureEvent);
}

void processDepature(PriorityQueue<Event>& pQueue, ArrayQueue<Customer>& aQueue){

}

void displayStats(int pCount, float aTime){
    cout << "Simulation Ends" << endl << endl;
    cout << "Final Statistics" << endl;
    cout << "   Total number of people processed: " << pCount << endl;
    cout << "   Average amount of time spent waiting: " << aTime << endl;   
}
