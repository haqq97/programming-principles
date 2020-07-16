#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

class Product {
    //attributes:
	int id, inventory, numSold;
	char name[100];
    char description[100];
	double totalPaid;
    static int counter; // declares but does not define
public:
    //methods:
    //parametrized constructor
    Product(int productID, const char productName[]);
    //getters:
    int getID() const;
    const char* getName() const;
    const char* getDescription() const;
    int getNumberSold() const;
    double getTotalPaid() const;
    int getInventoryCount() const;
    //setters:
    void setName(const char productName[]);
    void setDescription(const char description[]);
    //other methods:
    //adds shipment quantity to inventory and shipment cost to total Paid
    bool addShipment(int shipmentQuantity, double shipmentCost); 
    //decreases inventory by purchase quantity 
    bool reduceInventory(int purchaseQuantity);
    //calculates the current price based on average cost per item plus 25% markup
    double getPrice() const;

};
//overloading output operator
std::ostream& operator<<(std::ostream& os, const Product& product);

#endif
