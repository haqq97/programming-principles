#include <iostream>
#include <sstream>
#include "Product.h"
#include "Customer.h"
#include "Store.h"

using namespace std;

int main() {
    Product p(17, "Jill");
    cout << "p (id): " << p.getID() << endl;
    cout << "p (name): " << p.getName() << endl << endl;
    
    Product q(183, "Tom");
    cout << "q (id): " << q.getID() << endl;
    cout << "q (name): " << q.getName() << endl << endl;
    
    Product badP(222, "");
    cout << "badP (id): " << badP.getID() << endl;
    cout << "badP (name): " << badP.getName() << endl << endl;
    
    p.setName("Jill Extreme");
    cout << "p (name): " << p.getName() << endl;
    
    q.setName("");
    cout << "q (name): " << q.getName() << endl;	
    
    p.setDescription("This is a fantastic product.");
    cout << "p (description): " << p.getDescription() << endl;
    
    q.setDescription("");
    cout << "q (description): " << q.getDescription() << endl << endl;

    cout << "Before 1st shipment" << endl;
    cout << "inventory: " << p.getInventoryCount() << endl;
    cout << "totalPaid: " << p.getTotalPaid() << endl;
    cout << "price: " << p.getPrice() << endl;
    cout << "numSold: " << p.getNumberSold() << endl << endl;

    p.addShipment(88, 230.44);

    cout << "After 1st shipment" << endl;
    cout << "inventory: " << p.getInventoryCount() << endl;
    cout << "totalPaid: " << p.getTotalPaid() << endl;
    cout << "price: " << p.getPrice() << endl;
    cout << "numSold: " << p.getNumberSold() << endl;
    
    p.addShipment(133, 142.11);
    
    cout << "After 2nd shipment" << endl;
    cout << "inventory: " << p.getInventoryCount() << endl;
    cout << "totalPaid: " << p.getTotalPaid() << endl;
    cout << "price: " << p.getPrice() << endl;
    cout << "numSold: " << p.getNumberSold() << endl << endl;
    
    cout << "Testing negative quantity" << endl;
    
    if (!p.addShipment(-5, 22.55)) {
        cout << "shipment failed" << endl;
    }
    else {
        cout << "shipment passed" << endl;
    }
    
    cout << "After failed shipment (nothing should change from last output)" << endl;
    cout << "inventory: " << p.getInventoryCount() << endl;
    cout << "totalPaid: " << p.getTotalPaid() << endl;
    cout << "price: " << p.getPrice() << endl;
    cout << "numSold: " << p.getNumberSold() << endl << endl;

    
    cout << "Testing negative shipment cost" << endl;
    
    if (!p.addShipment(5, -22.55)) {
        cout << "shipment failed" << endl;
    }
    else {
        cout << "shipment passed" << endl;
    }
    
    cout << "After failed shipment (nothing should change from last output)" << endl;
    cout << "inventory: " << p.getInventoryCount() << endl;
    cout << "totalPaid: " << p.getTotalPaid() << endl;
    cout << "price: " << p.getPrice() << endl;
    cout << "numSold: " << p.getNumberSold() << endl << endl;
    
    cout << "Testing reduceInventory" << endl;
   
    p.reduceInventory(33);
   
    cout << "After reduceInventory" << endl;
    cout << "inventory: " << p.getInventoryCount() << endl;
    cout << "totalPaid: " << p.getTotalPaid() << endl;
    cout << "price: " << p.getPrice() << endl;
    cout << "numSold: " << p.getNumberSold() << endl << endl;
    
    cout << "Testing reduceInventory (negative quantity)" << endl;   
    if (!p.reduceInventory(-75)) {
        cout << "reduction failed" << endl;
    }
    else {
        cout << "reduction passed" << endl;
    }
   
    cout << "After failed reduceInventory (nothing should change from last output)" << endl;
    cout << "inventory: " << p.getInventoryCount() << endl;
    cout << "totalPaid: " << p.getTotalPaid() << endl;
    cout << "price: " << p.getPrice() << endl;
    cout << "numSold: " << p.getNumberSold() << endl << endl;
  
    cout << "Testing reduceInventory (more than inventory)" << endl;
    if (!p.reduceInventory(500)) {
        cout << "reduction failed" << endl;
    }
    else {
        cout << "reduction passed" << endl;
    }
   
    cout << "After failed reduceInventory (nothing should change from last output)" << endl;
    cout << "inventory: " << p.getInventoryCount() << endl;
    cout << "totalPaid: " << p.getTotalPaid() << endl;
    cout << "price: " << p.getPrice() << endl;
    cout << "numSold: " << p.getNumberSold() << endl << endl;
    
    cout << "More testing should be done, e.g. edge cases etc." << endl;

    Customer c1(987,"Ms Jackson",true);

    Product p1(555,"Widget Gidget");
    Product p2(777,"Something simple");
    Product p3(89, "Something nice");
    Product p4(87, "Something bad");
    Product p5(90, "Something okay");
    Product p6(91, "Something weird");

    // c1.processPayment(500);
    // cout << "Balance before purchase: " << c1.getBalance() << endl;
    c1.processPurchase(1, p1);
    // c1.processPurchase(1, p2);
    // c1.processPurchase(1, p3);
    // c1.processPurchase(1, p4);
    // c1.processPurchase(1, p5);
    // c1.processPurchase(1, p6);
    // cout << "Balance after purchase: " << c1.getBalance() << endl;
    // cout << c1;
    c1.outputRecentPurchases(cout);

}