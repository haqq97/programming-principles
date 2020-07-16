#include <iostream>
#include <sstream>
#include <string>
#include <cmath> //for round function
#include <algorithm> //for the sort function 
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

double LinkedList::AVG(string id, int year1, int year2) {
	double totalSum = 0.0; //sum of all temperature values
	double average = 0.0; 
	int totalNumber = 0; //counter for number of temperature values recorded 
	Node* current = head;
	//traverse through the list for the specific id and range of years given 
	//add all the temperature values and increment the counter for temperature values
	while (current!=nullptr){
		if (current->data.id==id && current->data.year>=year1 && current->data.year<=year2){
			totalSum+=current->data.temperature;
			totalNumber++;
		}
		current = current->next;
	}
	average = totalSum/totalNumber;
	//make sure the average is correct to 4 decimal places
	average = round(average * 10000)/10000;
	if (totalSum == 0.0) //if no value is found
		return totalSum;
	else
		return average;
}

int LinkedList::MODE(string id, int year1, int year2){
	int tempArray[1000] = {0}; //initialize an array with zeroes
	int size = 0; 	//variable to count the number of values in array
	Node* current = head;
	//traverse through the list and read in rounded temperature values into the array
	//increment size every time a number is entered into the array
	while (current!=nullptr){
		if (current->data.id==id && current->data.year>=year1 && current->data.year<=year2){
			tempArray[size] = round(current->data.temperature);
			size++;
		}
		current = current->next;
	}
	if (size == 0){ //if no values are found return zero
		return size;
	}
	if (size == 1){ //if array contains only one value, that is the mode
		return tempArray[0];
	}
	sort(tempArray, tempArray+size); //inbuilt function that sorts the array in ascending order
	int modeValue = tempArray[0];  // actual mode value
	int modeCount = 1;			   //actual mode counter
	int tempValue = tempArray[0];  //temporary mode value
	int tempCount = 0;			   //temporary mode counter
	//loop through the values in the array and one more iteration to update mode value 
	for (int i = 1; i <size+1; i++){
		//if modeValue is smaller then choose the mode with highest value
		if ((tempCount == modeCount) && (tempValue > modeValue)){
			modeValue = tempValue;
		//if another value occurs more than modeValue, that value will be the mode
		}if (tempCount > modeCount){
			modeValue = tempValue;
			modeCount = tempCount;
		//if the modeValue occurs again, keep updating the modeCount
		}if (tempArray[i] == modeValue){
			modeCount++;
		}else{ //keep track of the modes for all other values
			if (tempArray[i] != tempValue){
				tempValue = tempArray[i];
				tempCount = 1;
			}else{
				tempCount++;
			}
		}	
	}
	return modeValue;
}