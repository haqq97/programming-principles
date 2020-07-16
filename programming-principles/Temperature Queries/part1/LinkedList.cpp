#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <ios>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr){}


LinkedList::~LinkedList() {
	clear();
}

LinkedList::LinkedList(const LinkedList &source) {
	head = tail = nullptr;
	Node* temp = source.head;
	//copy data from source to current list
	while (temp != nullptr) {
		insert(temp->data.id, temp->data.year, temp->data.month, temp->data.temperature);
		temp = temp->next;
	}
}

LinkedList& LinkedList::operator=(const LinkedList &source) {
	//return current object if it's the same as source object
	if (this == &source)
		return *this;
	clear();  //delete the current list
	Node* temp= source.head; //temp is the head
	//copy data from source to current list
	while (temp != nullptr) {
		insert(temp->data.id, temp->data.year, temp->data.month, temp->data.temperature);
		temp = temp->next;
	}
	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	if (temperature == -99.99) //unknown temperature
		return;
	Node* newNode = new Node(location, year, month, temperature);
	//if list is empty, insert node at head
	if (head == nullptr) {
		head = tail = newNode;
	}else {
		Node* currentNode = head;
		//insert before head if new node's data is less than current head's data
		//new node becomes the new head
		if (newNode->data < currentNode->data) {
			newNode->next = currentNode;
			head = newNode;
		}else {
			//traverse thorugh the list
			while (currentNode->next != nullptr) {
				//insert if a node's data is less than new node's data
				//stop traversing through list
				if (newNode->data < currentNode->next->data) {
					newNode->next = currentNode->next;
					currentNode->next = newNode;
					break;
				}else {
					//move to next node
					currentNode = currentNode->next;
				}
			}
			//insert at end if new node has not been inserted yet
			if (newNode->next == nullptr) {
				currentNode->next = newNode;
				tail = newNode;
			}
		}
	}
}

void LinkedList::clear() {
	Node* current = head;
	//traverse through list
	//delete current node
	//assign current node to the next node
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}
	//empty list has tail and head point to each other
	head = tail = nullptr;
}

Node* LinkedList::getHead() const { return head; }

string LinkedList::print() const {
	Node* ptr = head;
	string outputString;
	string tempString;
	//traverse through list and add data to string
	while (ptr != nullptr) {
    tempString = to_string(ptr->data.temperature);
    //remove trailing zeros after decimal point
	tempString.erase (tempString.find_last_not_of('0') + 1, string::npos);
	tempString.erase (tempString.find_last_not_of('.') + 1, string::npos );
	//combine all data in a string with spaces in between
	outputString += ptr->data.id + " " + to_string(ptr->data.year) + " " +
	to_string(ptr->data.month) + " " + tempString + '\n';
	ptr = ptr->next;
	}
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}