/*
 * TemperatureData.h
 *
 *  Created on: Apr 16, 2019
 *      Author: Haqqani
 */

#ifndef TEMPERATUREDATA
#define TEMPERATUREDATA
#include <string>

struct TemperatureData {
	// Put data members here
	std::string id;
	int year;
	int month;
	double temperature;
	//default constructor
	TemperatureData();
	//parametrized constructor
	TemperatureData(std::string id, int year, int month, double temperature);
	//destructor
	virtual ~TemperatureData();
	//overloaded < operator
	bool operator<(const TemperatureData& b);
};

#endif /* TEMPERATUREDATA */
