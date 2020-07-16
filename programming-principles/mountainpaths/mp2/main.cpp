#include <iostream>
#include <fstream>
#include <stdexcept>
#include "functions.h"

using namespace std;
// Normally you should not use global variables. However, the stack is
//   limited in size and will not allow arrays of this size. We'll learn
//   later how to put these arrays on the heap instead. Regardless, for now
//   we'll use these and treat them as if they were declared in main. So
//   when used in functions, we'll pass them as we would any other array.
static int elevations[MAX_ROWS][MAX_COLS];
static Pixel image[MAX_ROWS][MAX_COLS];

int main() {
	int rows, columns = 0; 
	string fileName; 
	//exception-handling construct
	try{
		// cout << "number of rows in the map: " << endl;
		cin >> rows;
		// cout << "number of columns in the map: " << endl;
		cin >> columns;
		// cout << "file name: " << endl;
		cin >> fileName;
		if (rows <= 0 || cin.fail() ){
			throw runtime_error("Error: Problem reading in rows and columns.");
		}
		if (columns <= 0 || cin.fail()){
			throw runtime_error("Error: Problem reading in rows and columns.");
		}
		//input file stream
		ifstream infile;
		//try to open file
		infile.open(fileName); 
		//check if file opened successfully
		if (!infile.is_open()){
			cout << "Error: Unable to open file " << fileName;
			return 1;
		}
		loadData (elevations, rows, columns, infile);
		int max, min = 0;
		findMaxMin(elevations, rows, columns, max, min);
		// cout << "max: " << max << endl; 
		// cout << "min: " << min << endl;
		loadGreyscale(image, elevations, rows, columns, max, min);
		

		Pixel redPaint = {252, 25, 63};
		Pixel greenPaint = {31, 253, 13};
		int start = 0;
		int pathDistance = 0;
		int bestRow = 0; 
		int shortestPath = colorPath(elevations, image, rows, columns, redPaint, 0);

		for (start = 0; start < rows; start++){
		pathDistance = colorPath(elevations, image, rows, columns, redPaint, start);
		//finding the shortest path and the row at which this path occurs
			if (pathDistance < shortestPath){
				shortestPath = pathDistance;
				bestRow = start;
			}
		}
		//paint shortest path green
		shortestPath = colorPath(elevations, image, rows, columns, greenPaint, bestRow);
		cout << shortestPath << endl;

		//output file stream
		ofstream outfile;
		//open file
		outfile.open(fileName+".ppm");
		if (!outfile.is_open()){
	    	cout <<  "Could not open file " << fileName + ".ppm";
   		}
		//if file not opened successfully return error
 		 outputImage(image, rows, columns, outfile);
		//Done with file, so close it
		infile.close(); 
		outfile.close();
	}
	catch(runtime_error& excpt){
		cout << excpt.what() << endl;
		return 1;
	}
  return 0;
}