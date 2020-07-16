#include <iostream>
#include <cstring>
#include <sstream>
#include "Store.h"
#include "Product.h"
#include "Customer.h"
using namespace std;

int Store::counter = 0; // defines and initializes

Store::Store() : numProducts(0), numCustomers(0) {
	setName("");

}

Store::Store(const char name[]) : numProducts(0), numCustomers(0) {
	setName(name);
}


void Store::setName(const char storeName[]){
	if (strlen(storeName) > 0) {
        strcpy(this->name, storeName);
    }
    else {
        counter++;
        ostringstream oss;
        oss << "Store " << counter;
        strcpy(this->name, oss.str().c_str());
    }        
}

const char* Store::getName() const {
    return name;
}

bool Store::addProduct(int productID, const char productName[]){
	if (numProducts > 100)
		return false;
	for (int i = 0; i < numProducts; i++){
		if (productID == products[i]->getID()){
			return false;
		}
	}
	products[numProducts] = new Product(productID, productName);
	numProducts++;
	return true;
}


Product* Store::getProduct(int productID){
	for (int i = 0; i < numProducts; i++){
		if (productID == products[i]->getID() )
			return products[i];
	}
	return nullptr;
}


bool Store::addCustomer(int customerID, const char customerName[], bool credit){
	if (numCustomers > 100)
		return false;
	for (int i = 0; i < numCustomers; i++){
		if (customerID == (customers[i]->getID() )){
			return false;
		}
	}
	customers[numCustomers] = new Customer(customerID, customerName, credit);
	numCustomers++;
	return true;
}


Customer* Store::getCustomer(int customerID){
	for (int i = 0; i < numCustomers; i++){
		if (customerID == (customers[i]->getID() ))
			return customers[i];
	}
	return nullptr;
}


bool Store::takeShipment(int productID, int quantity, double cost){
	if (quantity < 0 || cost < 0)
		return false;
	for (int i = 0; i < numProducts; i++){
		if (productID == products[i]->getID() ){
			products[i]->addShipment(quantity,cost);
			return true;
		}	
	}
	return false;
}
   


bool Store::sellProduct(int customerID, int productID, int quantity){
	if (quantity < 0)
		return false;
	Customer* customerPtr = getCustomer(customerID);
		if (customerPtr== nullptr)
		return false;

	Product* productPtr = getProduct(productID);
		if (productPtr == nullptr)
		return false;

	double totalPrice = 0;
	totalPrice = quantity * (productPtr->getPrice());

	if ((productPtr->reduceInventory(quantity)) && (customerPtr->processPurchase(totalPrice,*productPtr)) )
		return true;
	else 
	return false;
}
   

bool Store::takePayment(int customerID, double amount){
	Customer* customerPtr = getCustomer(customerID);
	if (customerPtr == nullptr)
		return false;
	customerPtr->processPayment(amount);
}
    

void Store::outputProducts(std::ostream& os){
	for (int i = 0; i < numProducts; i++){
	os << "Product Name: " << products[i]->getName() << endl;
    os << "Product ID: " << products[i]->getID() << endl;
    os << "Description: " << products[i]->getDescription() << endl;
    os << "Inventory: " << products[i]->getInventoryCount() << endl;
    os << "Number Sold: " << products[i]->getNumberSold() << endl;
    os << "Total Paid: " << products[i]->getTotalPaid() << endl;
    os << "Price: " ;
    if ((products[i]->getPrice()) == -1)
    	os << "Unavailable" << endl;
    else 
    os << products[i]->getPrice() << endl;
		os << endl;

	}
}
    

void Store::outputCustomers(std::ostream& os){
	for (int i = 0; i < numCustomers; i++){
	os << "Customer Name: " << customers[i]->getName() << endl;
    os << "Customer ID: " << customers[i]->getID() << endl;
    os << "Has Credit: ";
    if (customers[i]->getCredit() == 0)
    	os << "false" << endl;
    else 
    	os << "true" << endl;
    os << "Balance: " << customers[i]->getBalance() << endl;
    customers[i]->outputRecentPurchases(os);
    os << endl;
	}
}