#include "functions.h"
#include <string>
#include <cctype>

using namespace std;

bool isPalindromeR(string finalString) {
	int size = finalString.length();
	if (size <= 1) { //base case
		return true;
	}
	else if (finalString[0] == finalString[size - 1]) { //compare first and last characters
		finalString.erase(size - 1, 1); //remove last character
		finalString.erase(0, 1); //remove first character
		return isPalindromeR(finalString); //recursive case 
	}
	else {
		return false; 
	}
}

void preProcessString(string &originalInput){
	for (size_t i = 0; i < originalInput.length(); ++i){
		char check = originalInput.at(i);				
		if (ispunct(check)){ //remove any punctuation
			originalInput.erase(i,1);
			i--;
		}
	}
}


bool isPalindrome(string input, bool caseSensitivity, bool ignoreSpaces){
	preProcessString(input);
	if (ignoreSpaces == true){
		for (size_t i = 0; i < input.length(); i++){
			if(input.at(i) == ' '){
				input.erase(i,1); //remove spaces
				i--;
			}
		}
	}
	if (caseSensitivity == false){
		for (size_t i = 0; i < input.length(); i++){ 
			input.at(i) = tolower(input.at(i)); //make all characters lowercase
		}
	}
	return isPalindromeR(input);
}



void printUsageInfo(string programName) {
	cout << "Usage: " << programName << " [-c] [-s] string ...\n";
	cout << "  -c: turn on case sensitivity\n";
	cout << "  -s: turn off ignoring spaces\n";
	exit(1);
}


void printResult(bool palindrome, string input){
	if (palindrome == true)
		cout << "\"" << input << "\"" << " is a palindrome." << endl;
	else
		cout << "\"" << input << "\"" << " is not a palindrome." << endl;
}

