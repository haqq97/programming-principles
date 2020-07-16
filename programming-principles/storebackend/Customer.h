#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "Product.h"

class Customer {
    //attributes:
	int id;
	char name[100];
	bool credit;
	double balance;
	char productsPurchased[5][100];
    int numPurchased;
    static int counter; // declares but does not define
public:
    //methods:
    //parametrized constructor
    Customer(int customerID, const char customerName[], bool credit=false); 
    //getters:
    int getID() const;
    const char* getName() const;
    bool getCredit() const;
    double getBalance() const;
    //setters:
    void setName(char const customerName[]);
    void setCredit(bool hasCredit);
    //other methods:
    //add amount to balance
    bool processPayment(double amount);
    //subtract amount from balance, add product to prodcuts purchased
    bool processPurchase(double amount, Product product); 
    //output athe 5 recent purchases
    void outputRecentPurchases(std::ostream& os) const;
};

//overloaded output operator
std::ostream& operator<<(std::ostream& os, const Customer& customer);

#endif
