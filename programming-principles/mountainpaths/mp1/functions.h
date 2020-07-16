#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Do not add using namespace
#include <iostream>

const int MAX_ROWS = 1000;
const int MAX_COLS = 1000;

struct Pixel {
    int red;
    int green;
    int blue;
};

//scans through entire elevations erray and keeps track of the smallest and largest values
void findMaxMin(const int elevations[MAX_ROWS][MAX_COLS], int rows, int cols, 
                int& max, int& min);

//read the values from file and load them into elevations array
void loadData(int elevations[MAX_ROWS][MAX_COLS], int rows, int cols, 
                std::istream& inData);

//loads greyscale values into to each element in the image array
void loadGreyscale(Pixel image[MAX_ROWS][MAX_COLS], 
                    const int elevations[MAX_ROWS][MAX_COLS], 
                    int rows, int cols, int max, int min);

//write PPM data to the ouput file
void outputImage(const Pixel image[MAX_ROWS][MAX_COLS], int rows, int cols, 
                    std::ostream& outData);

//calculates the shade of grey using the formula provided
int scaleValue(int value, int max, int min);

#endif