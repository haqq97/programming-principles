#include <string>
#include "Node.h"

using namespace std;

// Default constructor
Node::Node() : next(nullptr) {}

// Parameterized constructor
Node::Node(string id, int year, int month, double temperature)
	: next(nullptr){
	this->data.id  = id;
	this->data.year = year;
	this->data.month = month;
	this->data.temperature = temperature;
}


bool Node::operator<(const Node& b) {
	return this->data < b.data;
}
