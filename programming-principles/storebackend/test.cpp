#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

int main (){

   // Initialize 2D array 
    char color[4][10];
   	strcpy(color[0], "Blue"); 
     strcpy(color[1], "white");
     strcpy(color[2], "Green");
     strcpy(color[3], "Orange");
    // Printing Strings stored in 2D array  
    for (int i = 0; i < 4; i++)  
        cout << color[i] << "\n"; 
      
    return 0; 
} 

