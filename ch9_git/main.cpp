//*****************

//Project Name: Chapter 9 Project: Array Pointer!

//Project Description: We need a new function in our array of Utilities which will expand an array when we run out of room.

//Project Author: Smith, Shannon

//Is this an extra credit Project:  No

//Date completed: 09/07/2016 (9/13/16)

//Operating system used: OSX

//IDE Used:  xCode
//************ TESTING 1 2 3 *****
//*****************
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include "utilities.hpp"

void printArray(int testArray[], int arraySize){
    for(int i=0; i < arraySize; i++){
        cout << testArray[i] << endl;
    }
}
using namespace std;
//MAIN
int main(int argc, const char * argv[]) {
    
    
    int size = 5;
    int shrink = 8;
    int expanded = 13;
    srand((unsigned)time(0));
    
    int *iPtr = nullptr;
    iPtr = new int[size];
    
    
    
    for(int i= 0; i < size; i++){
        int temp =(rand()%101);
        iPtr[i] = temp;
    }//for
    
    
    cout << "Welcome to my dynamic array demenstration.\n";
    cout << "\nOriginal array!\n";
    
    for (int i = 0; i < size; i++){
        cout << "Entry at " << i << " is " << iPtr[i] << endl;
    }
    
    cout << "\n";
    
    iPtr = expandArray(iPtr, size, expanded);
    printArray(iPtr, expanded);
    
    iPtr = compressArray(iPtr, expanded, shrink);
    printArray(iPtr, shrink);
    
    cout << "Goodbye; have a great day!\n";
    
    return 0;
}//MAIN