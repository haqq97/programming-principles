#include "TemperatureDatabase.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
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
	}
	records.insert(id, year, month, temperature);
	infile.close();
}

//Part 2
void TemperatureDatabase::performQuery(const string& filename) {}

