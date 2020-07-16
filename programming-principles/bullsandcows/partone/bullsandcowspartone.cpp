#include <iostream>
#include <cstdlib>
#include <chrono>
#include<cmath>
#include<ctime>

using namespace std;

//function prototypes
void createRandomArray(int codeArray[], int arraySize);
void createArray(int codeArray[], int code, int arraySize);
void printArray(int anyArray[], int arraySize);

int codeArray[1000]; //global variable 

int main() {
	srand(std::chrono::duration_cast<std::chrono::milliseconds>
	(std::chrono::system_clock::now().time_since_epoch()).count() % 2000000000);
	// needed to autograde some test cases in Mimir
	
	int selectDigit = 0;
	int secretCode = 0;
	int numDigits = 0; 

	cout << "Enter number of digits in code (3, 4 or 5): "; //input by user1
	cin >> selectDigit;
	if (selectDigit == 0) {//user1 inputs code manually
		cout << "Enter code: ";
		cin >> secretCode;
		cout << "Enter number of digits in code: ";
		cin >> numDigits;
		codeArray[numDigits];  //create an empty array with size mentioned by the user 
		createArray(codeArray, secretCode, numDigits); //to convert the secret number by user1 into an array
		cout << "Number to guess: ";
		printArray(codeArray, numDigits); 
		cout << endl;
	}
	else if (selectDigit == 3 || selectDigit == 4 || selectDigit == 5) { //user1 wants a random number
		numDigits = selectDigit;
		codeArray[numDigits];
		createRandomArray(codeArray, numDigits);
		cout << "Number to guess: ";
		printArray(codeArray, numDigits);
		cout << endl;
	}
	return 0;
}

//iterates through an array and prints every element
void printArray(int anyArray[], int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		if (i == arraySize - 1)
			cout << anyArray[i];
		else
			cout << anyArray[i] << "-";
	}
}


//puts an integer into an array of size indicated by user
void createArray(int codeArray[], int code, int arraySize) {
	int count = 0;
	for (int i = pow(10, arraySize - 1); i > 0; i = i / 10) {
		if (i == 1)  //to assign the last digit of the number without making it zero
			codeArray[count] = code; 
		codeArray[count] = code / i; //extracts the last digit of the number
		code = code % i; //eliminates the extracted digit
		++count;
	}
}


//creates an array of size indicated by user
void createRandomArray(int codeArray[], int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		codeArray[i] = rand() % 10; //extracts the last digit of a random number
		for (int j = 0; j < arraySize; j++) { 
			if (i != j) {  //to make sure array is not compared at the same index
				if (codeArray[i] == codeArray[j]) //checks for repeated digits
					--i; //runs the loop again
			}
		}
	}
}
