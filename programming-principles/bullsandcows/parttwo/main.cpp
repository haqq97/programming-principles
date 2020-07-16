#include <iostream>
#include <cstdlib>
#include <chrono>
#include<cmath>
#include<ctime>

using namespace std;
////////////////////////////function prototypes////////////////////////////////
void createRandomArray(int codeArray[], int arraySize);
void createArray(int anyArray[], int code, int arraySize);
void printArray(int anyArray[], int arraySize);
bool guessChecker(int guessNumber, int guessArray[], int requiredDigits);
int integerLength(int number);
int bullsCalculator(int codeArray[], int guessArray[], int numberOfDigits);
int cowsCalculator(int codeArray[], int guessArray[], int numberOfDigits);
bool repeatedDigitsChecker(int guessArray[], int numberOfDigits);
void printResult(int numCows, int numBulls, int guessArray[], int numDigits);
///////////////////////////////////////////////////////////////////////////////

int main() {
//*********************************FIRST PART**********************************
srand(std::chrono::duration_cast<std::chrono::milliseconds>
(std::chrono::system_clock::now().time_since_epoch()).count() % 2000000000);
// needed to autograde some test cases in Mimir

//creating two large arrays to load them with input from user1 and user2
    int codeArray[1000]; //for user1 
    int guessArray[1000]; //for user2
    int selectDigit = 0; int secretCode = 0;  int numDigits = 0;
    cout << "Enter number of digits in code (3, 4 or 5): "; //input by first user
    cin >> selectDigit; 
//when user1 manunally enters code
    if (selectDigit == 0) { 
        cout << "Enter code: ";
        cin >> secretCode;
        cout << "Enter number of digits in code: ";
        cin >> numDigits;
        createArray(codeArray, secretCode, numDigits); 
        cout << "Number to guess: ";
        printArray(codeArray, numDigits); cout << endl;
    }
//user1 selects number of digits to generate a random number
    else if (selectDigit == 3 || selectDigit == 4 || selectDigit == 5) {
        numDigits = selectDigit;
        createRandomArray(codeArray, numDigits);
        cout << "Number to guess: ";
        printArray(codeArray, numDigits); cout << endl;
    }
//********************************SECOND PART**********************************
    int guessCode = 0; int cows = 0; int bulls = 0;  bool validGuess = true;  
    do { //user2 keeps entering guess until guess is valid and correct
        cout << "Enter Guess: ";
        cin >> guessCode;
        validGuess = guessChecker(guessCode, guessArray, numDigits);
        if (validGuess) {
            cows = cowsCalculator(codeArray, guessArray, numDigits);
            bulls = bullsCalculator(codeArray, guessArray, numDigits);
            printResult(cows, bulls, guessArray, numDigits);
        }
    } while (validGuess == false || bulls < numDigits);
    return 0;
}
//////////////////////////////////END OF MAIN//////////////////////////////////

//puts an integer into an array of size indicated by user
void createArray(int anyArray[], int code, int arraySize) {
    int count = 0;
    for (int i = pow(10, arraySize - 1); i > 0; i = i / 10) {
        if (i == 1)
            anyArray[count] = code;
        anyArray[count] = code / i;
        code = code % i;
        ++count;
    }
}

//checks if the user is making a valid guess 
bool guessChecker(int guessNumber, int guessArray[], int requiredDigits) {
    bool isRepeated = false;
    int guessDigits = integerLength(guessNumber);
    bool validGuess = true;
    if (guessNumber < 0) { //check for negative number
        cout << "You must guess a positive integer" << endl;
        validGuess = false;
    } else if (guessDigits - requiredDigits >= 1) { //check for a larger number
        cout << "You can only enter " << requiredDigits << " digits." << endl;
        validGuess = false;
    } else if (guessDigits - requiredDigits < -1) { //check for repeated zeros
        cout << "Each number must be different." << endl;
        validGuess = false;
    }else { 
        createArray(guessArray, guessNumber, requiredDigits);
        //check for repeated digits in a number
        isRepeated = repeatedDigitsChecker(guessArray, requiredDigits);
        if (isRepeated == true) {
            validGuess = false;
            cout << "Each number must be different." << endl;
        }
    }
    return validGuess;
}

//counts the number of digits in an integer
int integerLength(int number) {
    int count = 0;
    while (number != 0) {
        number = number / 10;
        ++count;
    }
    return count;
}

//checks for any repeated digits
bool repeatedDigitsChecker(int guessArray[], int numberOfDigits) {
    bool invalid = false;
    for (int i = 0; i < numberOfDigits; i++) {
        for (int j = 0; j < numberOfDigits; j++) {
            if (i != j) {
                if (guessArray[i] == guessArray[j])
                    invalid = true;
            }
        }
    }
    return invalid;
}

//prints the correct result depending on the number of cows and bulls scored
void printResult(int numCows, int numBulls, int guessArray[], int numDigits) {
    if (numBulls == numDigits) { //when user2 makes the correct guess
        cout << numBulls << " bulls... ";
        printArray(guessArray, numDigits);
        cout << " is correct!" << endl;
    } 
    else {
        cout << numBulls << " bulls" << endl;
        cout << numCows << " cows" << endl;
    }
}

//creates an array of size indicated by user
void createRandomArray(int codeArray[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        codeArray[i] = rand() % 10;
        for (int j = 0; j < arraySize; j++) {
            if (i != j) {
                if (codeArray[i] == codeArray[j])
                    --i;
            }
        }
    }
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

//calculates the number of correct digits but in different positions
int cowsCalculator(int codeArray[], int guessArray[], int numberOfDigits) {
    int cows = 0;
    for (int i = 0; i < numberOfDigits; i++) {
        for (int j = 0; j < numberOfDigits; j++) {
            if (i != j) { //to compare every digit but not with itself
                if (codeArray[i] == guessArray[j])
                    cows++;
            }
        }
    }
    return cows;
}

//calculates the number of correct digits in the exact positions
int bullsCalculator(int codeArray[], int guessArray[], int numberOfDigits) {
    int bulls = 0;
    for (int i = 0; i < numberOfDigits; i++) {
        for (int j = 0; j < numberOfDigits; j++) {
            if (i == j) { 
                if (codeArray[i] == guessArray[j]) 
                    bulls++;
            }
        }
    }
    return bulls;
}
