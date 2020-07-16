#ifndef STORE_H
#define STORE_H

#include "Product.h"
#include "Customer.h"

class Store {
    //attributes
	char name[100];
	Product* products[100];
	Customer* customers[100];
    static int counter; // declares but does not define
    int numProducts;
    int numCustomers;
public:
    //methods:
    //default constructor
    Store();
    //paramterized constructor
    Store(const char name[]);  
    //getters 
    const char* getName() const;
    Customer* getCustomer(int customerID);
    Product* getProduct(int productID); 
    //setters
    void setName(const char storeName[]);
    //other methods:
    //add product to products array
    bool addProduct(int productID, const char productName[]);
    //add customer to customers array
    // even though getProduct should be private, it helps autograding to make it public
    bool addCustomer(int customerID, const char customerName[], bool credit=false); 
    // even though getCustomer should be private, it helps autograding to make it public
    //update product with shipment quantity and cost
    bool takeShipment(int productID, int quantity, double cost); 
    //make the sale if its allowed
    bool sellProduct(int customerID, int productID, int quantity);
    //process the payment for the customer
    bool takePayment(int customerID, double amount);
    //output information about each product
    void outputProducts(std::ostream& os);
    //output information about each customer
    void outputCustomers(std::ostream& os);
};

#endif
