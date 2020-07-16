#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <cctype>

using namespace std;
	
//prints usage message for invalid flags or no input strings
void printUsageInfo(string programName);

//processes the input after considering flags and calls the recursive function to check if the input is palindrome
bool isPalindrome(string input, bool caseSensitivity, bool ignoreSpaces);

//recrusive function that loops through the string backwards and forwards comapring each letter from both sides 
bool isPalindromeR(string finalString);

//prints result if the input string is palindrome or not
void printResult(bool palindrome, string input);

//removes any punctuation in the string 
void preProcessString(string &originalInput);
	
#endif