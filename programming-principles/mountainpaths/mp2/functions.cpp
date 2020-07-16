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


int colorPath(const int elevations[MAX_ROWS][MAX_COLS], Pixel image[MAX_ROWS][MAX_COLS],
					 int rows, int cols, Pixel color, int start_row){
	int colNum = 0; //current column
	int rowNum = start_row; //current row
	int forward = 0; //elevation change when moving forward
	int upward = 0; //elevation change when moving upward
	int downward = 0; //elevation change when moving downward
	int elevationChange = 0; //total elevation change

	for(int i = 0; i < cols -1; i ++){
	//color current cell
	image[rowNum][colNum].red = color.red;
	image[rowNum][colNum].green = color.green;
	image[rowNum][colNum].blue = color.blue;
		//for first row 
		if (rowNum == 0){
			forward = abs(elevations[rowNum][colNum] - elevations[rowNum][colNum+1]);
			downward = abs(elevations[rowNum][colNum] - elevations[rowNum+1][colNum+1]);
			if (forward < downward){
				elevationChange+=forward;
				++colNum; 
			}
			else if(downward < forward){
				elevationChange+=downward;
				++colNum;
				++rowNum;
			}
			else{
				elevationChange+=forward;
				++colNum;
			}
		image[rowNum][colNum].red = color.red;
		image[rowNum][colNum].green = color.green;
		image[rowNum][colNum].blue = color.blue;
		}
		//for last row
		else if(rowNum == rows-1){
			forward = abs(elevations[rowNum][colNum] - elevations[rowNum][colNum+1]);
			upward = abs(elevations[rowNum][colNum] - elevations[rowNum-1][colNum+1]);
			if (forward < upward){
				elevationChange+=forward;
				++colNum;
			}
			else if(upward < forward){
				elevationChange+=upward;
				++colNum;
				--rowNum;
			}
			else{
				elevationChange+=forward;
				++colNum;
			}
		image[rowNum][colNum].red = color.red;
		image[rowNum][colNum].green = color.green;
		image[rowNum][colNum].blue = color.blue;
		}
		//for middle rows
		else{
			forward = abs(elevations[rowNum][colNum] - elevations[rowNum][colNum+1]);
			downward = abs(elevations[rowNum][colNum] - elevations[rowNum+1][colNum+1]);
			upward = abs(elevations[rowNum][colNum] - elevations[rowNum-1][colNum+1]);
			if (forward < downward && forward < upward){
				elevationChange+=forward;
				++colNum;
			}
			else if(downward < forward && downward < upward){
				elevationChange+=downward;
				++colNum;
				++rowNum;
			}
			else if (upward < forward && upward < downward){
				elevationChange+=upward;
				++colNum;
				--rowNum;
			}
			else if (forward > downward && downward == upward){
				elevationChange+=downward;
				++colNum;
				++rowNum;
			}
			else{
				elevationChange+=forward;
				++colNum;
			}
		}
		image[rowNum][colNum].red = color.red;
		image[rowNum][colNum].green = color.green;
		image[rowNum][colNum].blue = color.blue;
	}
	return elevationChange;
}