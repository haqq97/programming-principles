#include "functions.h"
#include <iostream>
#include <string>
#include <cctype>


using namespace std;

int main(int argc, char* argv[]) {

	string programName;
	programName = static_cast<string> (argv[0]);  
	//exit program with usage message if user only enters program name
	if (argc <= 1) {
		printUsageInfo(programName); 
	}
	//default case ignores spaces
	bool caseSensitive = false;
	bool ignoreSpaces = true;
	bool flagPresent = true; 
	int skip = 0; //counter to skip number of arguments containing flags 
	for (int i = 1; i < argc; i++){
		string flags = static_cast<string> (argv[i]);
		if (flags == "--") { //end of flags
			skip++; 
			flagPresent = false; 
		} 
		if (flags.at(0) == '-' && flagPresent == true) {
			skip++;
			for (size_t i = 1; i < flags.length(); i++){
				if (flags.at(i) == 'c' || flags.at(i) == 'C')
				caseSensitive = true; 
				else if (flags.at(i) == 's' || flags.at(i) == 'S')
				ignoreSpaces = false;
				else
				printUsageInfo(programName); //output usage message for invalid flags
			}
			//if user does not enter input string after flags
			if (argc <= 2 || (argc - skip) <= 1) {
				printUsageInfo(programName);
				exit(1);
			}
		}
	}
	bool palindrome = false;
	//if flags are present
	if (caseSensitive == true || ignoreSpaces == false){
		for (int i = skip+1; i < argc; i++) {
			string input = static_cast<string>(argv[i]);
			string originalInput = input; 
			palindrome = isPalindrome(input, caseSensitive, ignoreSpaces);
			printResult(palindrome, originalInput);
		}
	}
	else{
		//if flags are not present i.e default case
		for (int i = 1 ; i < argc; i++) {
			string input = static_cast<string>(argv[i]);
			string originalInput = input;
			palindrome = isPalindrome(input, caseSensitive, ignoreSpaces);
			printResult(palindrome, originalInput);
		}
	}	
return 0;
}

