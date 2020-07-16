#include "TemperatureDatabase.h"

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	string id; int year; int month; double temperature;
	ifstream infile; string line;
	infile.open(filename); 
	if (!infile.is_open()){
		cout << "Error: Unable to open " << filename << endl;	
		return;
	}while (getline(infile, line)){  //extract file input line by line
	istringstream iss(line);
	iss >> id >> year >> month >> temperature;
	//Validating inputs
		if (iss.fail()){ //clear the stream and start loop again
			cout << "Error: Other invalid input" << endl;
			iss.clear(); 
			continue;
		}if (year < 1800 || year > 2018){ 
			cout << "Error: Invalid year " << year << endl;
			continue;
		}if (month < 1 || month > 12){
			cout << "Error: Invalid month " << month << endl;
			continue;
		}if((temperature < -50 || temperature > 50) && temperature!= -99.99){
			cout << "Error: Invalid temperature " << temperature << endl;
			continue;
		}
		records.insert(id, year, month, temperature);
	}
	infile.close();
}

//Part 2
void TemperatureDatabase::performQuery(const string& filename) {
	string id; string query; int year1; int year2; 
	ifstream infile; string line; ofstream outfile;
	infile.open(filename);
	if (!infile.is_open()){
		cout << "Error: Unable to open " << filename << endl;	
		return;}
	outfile.open("result.dat");
	if (!outfile.is_open()){
		cout << "Error: Unble to open result.dat \n";
		return;
	}while (getline(infile, line)){  //extract file input line by line
	istringstream iss(line);
	iss >> id >> query >> year1 >> year2;
	//Validating inputs:
		if (iss.fail()){ //clear the stream and start loop again
			cout << "Error: Other invalid query" << endl;
			iss.clear(); 
			continue;
		}if (year1<1800 || year2<1800 || year1>2018 || year2>2018 || ((year2-year1)<0)){ 
			cout << "Error: Invalid range " << year1 << "-" << year2 << endl;
			continue;
		}
		bool validQuery = false;
		if (query=="AVG" || query=="MODE"){
		validQuery = true;
		}if (validQuery == false){
			cout << "Error: Unsupported query " << query << endl;
			continue;
		}
		string requestedQuery = "";
		if (query == "AVG"){
			double average = records.AVG(id, year1, year2);
			if (average == 0.0) //if no data was found for the query
				requestedQuery = "unknown";
			else { //convert double to string and remove extra zeroes
			requestedQuery = to_string(average);
			requestedQuery.erase(requestedQuery.find_last_not_of('0') + 1, string::npos);
			requestedQuery.erase(requestedQuery.find_last_not_of('.') + 1, string::npos);
			}
		}if (query == "MODE"){
			int mode = records.MODE(id, year1, year2);
			if (mode == 0) //if no data was found for the query
				requestedQuery = "unknown";
			else{
				requestedQuery = to_string(mode);
			}
		} //read to result.dat
		outfile<<id<<" "<<year1<<" "<<year2<<" "<<query<<" "<<requestedQuery<< endl; 
	}//close both files
	outfile.close();
	infile.close();
}

