#include <iostream>
#include <fstream>
#include <cmath>
#include <stdexcept>
#include "functions.h"
using namespace std;

void findMaxMin(const int elevations[MAX_ROWS][MAX_COLS], int rows, int cols, int& max, int& min){
//initial max and min is the first data point to compare each value
max = elevations[0][0];
min = elevations[0][0];
	for (int i = 0; i < rows; i ++){
		for (int j = 0; j < cols; j++){
			if (elevations[i][j] > max)
			max = elevations[i][j];
			if (elevations[i][j] < min)
			min = elevations[i][j];
		}
	}
}

void loadData(int elevations[MAX_ROWS][MAX_COLS], int rows, int cols, istream& inData){

	for (int i = 0; i < rows; i ++){
		for (int j = 0; j < cols; j++){
			if (inData.eof())
			throw runtime_error("Error: End of file reached prior to getting all the required data.");
			inData >> elevations[i][j];	
			if (inData.fail())
			throw runtime_error("Error: Read a non-integer value.");
		}
	}
	while (!inData.eof()){
		int excess = 0;
		inData >> excess;
		if (excess > 0 )
		throw runtime_error("Error: Too many data points.");
	}
	//to check elevation data 
	// for (int i = 0; i < rows; i ++){
	// 	for (int j = 0; j < cols; j++){
	// 		cout << elevations[i][j] << "\t";
	// 		}
	// 		cout << endl;
	// 	}
	// }
}

int scaleValue(int value, int max, int min){
	int shadeOfGrey = 0;
	//multiplying by 1.0 for implicit floating point division instead of integer division
	shadeOfGrey = round(((1.0 * value - min)/(max - min)) * 255);
	return shadeOfGrey;
}

void loadGreyscale(Pixel image[MAX_ROWS][MAX_COLS], const int elevations[MAX_ROWS][MAX_COLS], 
                    								  int rows, int cols, int max, int min){
	for (int i = 0; i < rows; i ++){
		for (int j = 0; j < cols; j++){
			image[i][j].red = scaleValue(elevations[i][j], max, min);	
			image[i][j].green = scaleValue(elevations[i][j], max, min);	
			image[i][j].blue = scaleValue(elevations[i][j], max, min);	
		}
	}
	//to check RGB values
	// for (int i = 0; i < rows; i ++){
	// 	for (int j = 0; j < cols; j++){
	// 		cout << image[i][j].red << " " << image[i][j].green << " " << image[i][j].blue << " ";
	// 	}
	// 	cout << endl;
	// }
}

void outputImage(const Pixel image[MAX_ROWS][MAX_COLS], int rows, int cols, ostream& outData) {
outData << "P3" << endl;
outData << cols << " " << rows << endl;
outData << 255 << endl;
	for (int i = 0; i < rows; i ++){
		for (int j = 0; j < cols; j++){
			outData << image[i][j].red << " " << image[i][j].green << " " << image[i][j].blue << " ";
		}
		cout << endl;
	}
}

