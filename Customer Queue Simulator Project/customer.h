#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
    private:
        int arrivalTime, transactionTime;

    public:
        Customer();
        Customer(int, int);
        Customer(const Customer&);

        int getArrivalTime() const;
        int getTransactionTime() const;
};
#endif