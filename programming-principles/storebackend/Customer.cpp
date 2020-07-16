#include <iostream>
#include <cstring>
#include <sstream>
#include "Customer.h"
#include "Product.h"
using namespace std;

int Customer::counter = 0; // defines and initializes

Customer::Customer(int customerID, const char customerName[], bool credit) :
	id(customerID), balance(0.0), credit(credit), numPurchased(0){
setName(customerName);
	for (int i = 0; i < 5; i++){
	strcpy(productsPurchased[i], ""); 	
	}
}

int Customer::getID() const {return id; }

const char* Customer::getName() const {return name;	}

void Customer::setName(const char customerName[]) {
    if (strlen(customerName) > 0) {
        strcpy(this->name, customerName);
    }
    else {
        counter++;
        ostringstream oss;
        oss << "Customer " << counter;
        strcpy(this->name, oss.str().c_str());
    }        
}

bool Customer::getCredit() const {return credit; }

void Customer::setCredit(bool hasCredit) {
	credit = hasCredit;
}


double Customer::getBalance() const {return balance;}

bool Customer::processPayment(double amount) {
	if (amount < 0)
		return false;
	balance+=amount;
	return true;

}


bool Customer::processPurchase(double amount, Product product){
	//no purchase if amount is negative
	if (amount < 0)
		return false;
	//purchase allowed if credit is true
 	else if (credit == true){
 		balance-=amount;
 		//do nothing if product name is already present
 		for(int i = 0; i < numPurchased; i++){
 			if ( (strcmp( productsPurchased[i], product.getName() )) == 0 ) 
 				return true;
  		}
  		//remove oldest product and add latest to the list
		if (numPurchased == 5){
			for (int i = 0; i < 4; i ++){
 				strcpy(productsPurchased[i], productsPurchased[i+1]);
			}
			strcpy(productsPurchased[4], product.getName());
			return true;
 		} 
 		//add product to an empty slot
 		else{
			strcpy(productsPurchased[numPurchased], product.getName());
			numPurchased++;
		 	return true;
		}
 	}
 	else if (credit == false){
 	//purchase only allowed if balance is greater than or equal to amount
 		if (balance >= amount){
 			balance-=amount;
	 		for(int i = 0; i < numPurchased; i++){
	 			if ( (strcmp( productsPurchased[i], product.getName() )) == 0 ) 
	 				return true;
	  		}
	  		//remove oldest product and add latest to the list
			if (numPurchased == 5){
				for (int i = 0; i < 4; i ++){
	 				strcpy(productsPurchased[i], productsPurchased[i+1]);
				}
				strcpy(productsPurchased[4], product.getName());
				return true;
	 		} 
	 		//add product to an empty slot
	 		else{
				strcpy(productsPurchased[numPurchased], product.getName());
				numPurchased++;
			 	return true;
			} 
		}	
		else 
 		return false;
 	}
 }


void Customer::outputRecentPurchases(std::ostream& os) const {
 	os << "Products Purchased --" << endl;
 	//run a for loop from 0 to numPurchased. print them.
 	//run a for loop from numPurchased-1 to 0. print them.
 	if (numPurchased > 0){
 		for (int i = 4; i > -1; i--){
 			if (strcmp(productsPurchased[i], "") != 0){
	 		os << productsPurchased[i];
	 		os << endl;
 			}
 		}
 	}
}

 
std::ostream& operator<<(std::ostream& os, const Customer& customer){
	os << "Customer Name: " << customer.getName() << endl;
    os << "Customer ID: " << customer.getID() << endl;
    os << "Has Credit: ";
    if (customer.getCredit() == 0)
    	os << "false" << endl;
    else 
    	os << "true" << endl;
    os << "Balance: " << customer.getBalance() << endl;
    customer.outputRecentPurchases(os);
    return os;
}



