#include "customer.h"

Customer::Customer() {
    arrivalTime = 0;
    transactionTime = 0;
}

Customer::Customer(int newArrival, int newTransaction) {
    arrivalTime = newArrival;
    transactionTime = newTransaction;
}

Customer::Customer(const Customer& rhs) {
    arrivalTime = rhs.arrivalTime;
    transactionTime = rhs.transactionTime;
}

int Customer::getArrivalTime() const{
    return arrivalTime;
}

int Customer::getTransactionTime() const{
    return transactionTime;
}