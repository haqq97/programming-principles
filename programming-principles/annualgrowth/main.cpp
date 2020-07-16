#include <iostream>
#include <string>
using namespace std; 

int main(){

string firstName =  "";
string lastName = "";
int birthYear = 0;
int feet = 0;
int inches = 0;
int age = 0;
double height = 0;
double annualGrowth = 0;

cout << "First name: " ;
cin >> firstName;

cout << "Last name: " ;
cin >> lastName;

cout << "Birth year: " ;
cin >> birthYear;

cout << "Height in feet (do not include inches): " ; 
cin >> feet;

cout << "Height in inches (do not include feet): " ; 
cin >> inches;

age = 2019 - birthYear;
height = (feet*30.48) + (inches*2.54);
annualGrowth = (height-51)/(age);

cout << "Hello " << firstName << " " << lastName << "." << endl;
cout << "You are " << age << " years old in 2019." << endl;
cout << "Your height is " << height << " cm." << endl;
cout << "You grew an average of " << annualGrowth << " cm per year (assuming you were 51 cm at birth)."<< endl;



return 0;


}