/*
 * TemperatureData.cpp
 *
 *  Created on: Apr 16, 2019
 *      Author: Haqqani
 */
#include "TemperatureData.h"
using namespace std;

//initialize everything
TemperatureData::TemperatureData() {}

TemperatureData::TemperatureData(std::string id, int year, int month, double temperature) 
: id(id), year(year), month(month), temperature(temperature){} 


TemperatureData::~TemperatureData() {} // You should not need to implement this

bool TemperatureData::operator<(const TemperatureData& b) {
	if (this->id < b.id)
		return true;
	if (this->id == b.id && this->year < b.year)
		return true; 
	if (this->id == b.id && this->year == b.year && this->month < b.month)
		return true;
	return false;
}

