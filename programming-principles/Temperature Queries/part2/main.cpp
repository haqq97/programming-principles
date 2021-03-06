#include "TemperatureDatabase.h"

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <ios>
using namespace std;

//You do not need to edit this code
int main(int argc, char** argv) {
	if (argc < 3) {
		cout << "Usage: " << argv[0] << " data_file query_file" << endl;
		return 1;
	} else {
		TemperatureDatabase database;
		database.loadData(argv[1]); // Do in Part 1
		database.performQuery(argv[2]); // Do in Part 2
	}
}
