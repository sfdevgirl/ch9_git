//
//  utilities.cpp
//  CPPUtilities
//
//  Created by Bill Komanetsky on 1/29/15.
//  Copyright (c) 2015 Bill Komanetsky. All rights reserved.
//

#include "utilities.hpp"
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>


//
//This routine will take a string and convert it to upper case
//Since a string is basically an array of char values, the string
//passed in will be processed one character at a time making each
//character upper-case
//
string makeUpperCase(string theString) {
    
    locale settings;
    string newString;
    
    for(short i = 0; i < theString.size(); ++i)
        newString += (toupper(theString[i], settings));
    
    return newString;
    
}//makeUpperCase

//
//This routine will take a string and convert it to lower case
//Since a string is basically an array of char values, the string
//passed in will be processed one character at a time making each
//character lower-case
//
string makeLowerCase(string theString) {
    
    locale settings;
    string newString;
    
    for(short i = 0; i < theString.size(); ++i)
        newString += (tolower(theString[i], settings));
    
    return newString;
    
}//makeUpperCase

//
//Clear the CIN input buffer to avoid problems
//
void clearCIN(void) {
    cin.clear();
    cin.ignore(32768, '\n');
    return;
}//clearCIN

//
//Input a string to be returned to the calling function.
//
string inputString(string promptString, int minLength, int maxLength) {
    string userInput;
    
    while (true) {
        cout << promptString << "\n";
        getline(cin, userInput);
        if (userInput.size() < minLength || userInput.size() > maxLength) {
            cout << "The string you entered is too short or too long.  Should be " << minLength << " to " << maxLength << " in Length\n";
            cout << "Please try again\n";
        }//if
        else
            break;
    }//while
    return userInput;
}//inputString

//
//Input a integer value to be returned to the calling function.  Also, validate the
//the minimum and maximum value of the integer input.
//
int inputInt(string promptString, int minValue, int maxValue, int exitValue) {
    int userInput;
    
    cout << promptString << " \n";
    while (true) {
        cin >> userInput;
        if (!cin.fail()) {
            char myChar = cin.peek();
            if (myChar == '\n')
                if ((userInput >= minValue && userInput <= maxValue) || userInput == exitValue)
                    break;
                else {
                    cout << "Invalid value entered.  Should be between " << minValue << " and " << maxValue << " Please try again\n";
                    clearCIN();
                }//else
                else {
                    cout << "Invalid value entered.  Should be between " << minValue << " and " << maxValue << " Please try again\n";
                    clearCIN();
                }//else
        }//if
        else {
            cout << "Invalid integer value entered. Please try again.\n";
            clearCIN();
        }//else
    }
    clearCIN();
    return userInput;
}//inputInt

//
//Input a double value to be returned to the calling function.  Also, validate the
//the minimum and maximum value of the double input.
//
double inputDouble(string promptString, double minValue, double maxValue, double exitValue) {
    double userInput;
    
    cout << promptString << " \n";
    while (true) {
        cin >> userInput;
        if (!cin.fail()) {
            char myChar = cin.peek();
            if (myChar == '\n')
                if ((userInput >= minValue && userInput <= maxValue) || userInput == exitValue)
                    break;
                else {
                    cout << "Invalid value entered.  Should be between " << minValue << " and " << maxValue << " Please try again\n";
                    clearCIN();
                }//else
                else {
                    cout << "Invalid value entered.  Should be between " << minValue << " and " << maxValue << " Please try again\n";
                    clearCIN();
                }//else
        }//if
        else {
            cout << "Invalid double value entered. Please try again.\n";
            clearCIN();
        }//else
    }
    clearCIN();
    return userInput;
}//inputdouble

//
//Send a string and center it in a returned string
//
string centerString(string stringToCenter, int toWidth)
{
    string outputString;
    int l = 0;
    int pos = 0;
    
    l = static_cast<int>(stringToCenter.length());
    pos=(toWidth-l)/2;
    for(int i=0;i<pos;i++) {
        outputString = outputString + " ";
    }//for
    outputString = outputString + stringToCenter;
    return outputString;
}//centerString

//
// This function will return a random integer no larger than Max
//
int getRandomInt(int Min, int Max) {
    int tempInt = 0;
    
    while (true) {
        tempInt = rand() % Max;
        if (tempInt >= Min)
            break;
        else {}
    }//while
    
    return tempInt;
}//getRandomInt

//
//This function will return a random double with 2 decimal digits, and not greater than Max
//
double getRandomDouble(int Min, int Max, int decimalPlaces) {
    double returnNum;
    int tempInt;
    double tempDouble;
    
    while (true) {
        returnNum = ((double)rand()/RAND_MAX);
        tempInt = (returnNum * Max)*(pow(10, decimalPlaces));
        tempDouble = static_cast<double>(tempInt)/(pow(10, decimalPlaces));
        if (tempDouble >= Min)
            break;
        else {}
    }//while
    return tempDouble;
}//getRandomDouble

//
// This function will return a random integer no larger than Max
//
string getRandomString(int Min, int Max) {
    string tempString;
    
    int size = getRandomInt(Min, Max);
    for (int ctr=0; ctr<size; ctr++) {
        char tempChar = getRandomInt(97, 122);
        tempString += tempChar;
    }//for
    
    return tempString;
}//getRandomInt

//
//Display a prompt asking the user if they want to
//sort the vector ascending or descening.
//
bool verifyAction(string userPrompt) {
    char userInput;
    bool returnValue = false;
    
    while (true) {
        cout << "\n";
        cout << userPrompt << "\n";
        cout << "<Y>es, <N>o ==> ";
        cin >> userInput;
        if (toupper(userInput) == 'Y') {
            returnValue = true;
            break;
        }//if
        else if (toupper(userInput) == 'N') {
            returnValue = false;
            break;
        }//else if
        else {
            cout << "Invalid selection, please try again\n";
        }//else
        clearCIN();
    }//while
    
    clearCIN();
    return returnValue;
}//verifyAction

//
//Ask the user if they want to append, overwrite or quit the read operation
//
char askOverWrite(void) {
    char userChoice;
    
    cout << "You already have data loaded into the system\n";
    cout << "Do you want to (O)verwrite, (A)ppend or (Q)uit? ";
    cin >> userChoice;
    switch (toupper(userChoice)) {
        case 'O': {
            break;
        }//case O
        case 'A':
            break;
        case 'Q':
        default: {
            cout << "Operation Aborted\n";
            return 'Q';
        }//default
    }//switch
    
    return toupper(userChoice);
    
}//askOverwrite


//SHANNON'S============================================================


void sortArray(int array[], int size){
    
    bool swap;
    int temp;
    
    do{
        swap = false;
        for(int i=0;i < (size - 1); i++){
            if (array[i] > array[i + 1]){
                temp = array[i];
                array[i] = array[ i + 1];
                array[ i + 1] = temp;
                swap = true;
            }//if
        }//for
    } while (swap);
}//sortArray

void showArray(const int array[], int size){
    for(int i=0; i < size; i++){
        cout << array[i] << " " << endl;
    }//for
}//showArray



bool intVectorBinSearch(vector<int> vector, int value) {
    int first = 0;
    int last = ((unsigned)vector.size() - 1);
    int middle;
    bool found = false;

    while (!found && first <= last) {
        middle = (first + last) / 2;
        if (vector[middle] == value) {
            found = true;
        }//if
        else if (vector[middle] > value){
            last = middle - 1;
        }//else if
        else{
            first = middle + 1;
        }//else
    }//while
    return found;
} //binarySearch

void selectionSort(int array[], int size){
    int startScan, minIndex, minValue;
    
    for (startScan = 0; startScan < (size - 1); startScan++){
        minIndex = startScan;
        minValue = array[startScan];
        for(int index = startScan + 1; index < size; index++){
            if (array[index] < minValue){
                minValue = array[index];
                minIndex = index;
            }//if
        }//for
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }//master for
}//selectionSort

void intVectorBubbleSort(vector<int> &vector, char letter){
    bool swap;
    int temp;
    
    //'A' = sort ascending
    if (letter == 'A') {
        do {
            swap = false;
            for (unsigned int count = 0; count < (vector.size() - 1); count++) {
                if (vector[count] > vector[count + 1]) {
                    temp = vector[count];
                    vector[count] = vector[count + 1];
                    vector[count + 1] = temp;
                    swap = true;
                } //if
            } //for
        } while (swap);
    } //if
    
    //'D' = sort descending
    else if (letter == 'D') {
        do {
            swap = false;
            for (unsigned int count = 0; count < (vector.size() - 1); count++) {
                if (vector[count] < vector[count + 1]) {
                    temp = vector[count];
                    vector[count] = vector[count + 1];
                    vector[count + 1] = temp;
                    swap = true;
                } //if
            } //for
        } while (swap);
    } //else if
    else {
    } //else - to check the value of letter
    
} //intVectorBubbleSort()

void displayVector(vector<int> vector) {
    for (unsigned int count = 0; count < vector.size(); count++) {
        cout << vector[count] << " ";
        cout << endl;
    } //for
} //displayintVector()

void intVectorSelectionSort(vector<int> &vector, char letter) {
    unsigned int startScan;
    int minIndex;
    int minValue;
    int maxValue;
    int maxIndex;
    
    if (letter == 'A') {
        for (startScan = 0; startScan < (vector.size()); startScan++) {
            minIndex = startScan;
            minValue = vector[startScan];
            for (unsigned int index = startScan + 1; index < vector.size();
                 index++) {
                if (vector[index] < minValue) {
                    minValue = vector[index];
                    minIndex = index;
                } //if
            } //for - inner
            vector[minIndex] = vector[startScan];
            vector[startScan] = minValue;
        } //for
        
    } //if
    else if (letter == 'D') {
        for (startScan = 0; startScan < vector.size(); startScan++) {
            maxIndex = startScan;
            maxValue = vector[startScan];
            for (unsigned int index = startScan + 1; index < vector.size();
                 index++) {
                if (vector[index] > maxValue) {
                    maxValue = vector[index];
                    maxIndex = index;
                } //if
            } //for - inner
            vector[maxIndex] = vector[startScan];
            vector[startScan] = maxValue;
        } //for
        
    } //else if
    else {
    } //else
    
} //intVectorSelectionSort



bool intVectorLinSearch(vector<int> vector, int value) {
    unsigned int index = 0;
    bool found = false;
    
    while (index < vector.size() && !found) {
        if (vector[index] == value) {
            found = true;
        } //if
        index++;
    } //while
    return found;
} //linearSearch

void initVector(vector<int> &vector) {
    int value;
    do {
        //get an integer from the user
        cout << "Please enter an integer [enter -999 when finished]: ";
        cin >> value;
        
        if(value != -999) {
            vector.push_back(value);
            
        }
        else{
            break;
        }//else
        
        
    } while (value != -999);
} //initVector

//CH9_DEFS
int* expandArray(int* intAP,  int CURRENT_SIZE, int max) {
    
    int* tempAP = nullptr;
    tempAP = new int[max];
    
    if ( CURRENT_SIZE < max){
        
        
        
        
        // allocate
        for (int i = 0; i < max; i++) {
            *(tempAP + i) = 0;
        }//for
        
        
        // copy old into new
        for (int i = 0; i < CURRENT_SIZE; i++) {
            *(tempAP + i) = *(intAP + i);
            
            //        //display copy
            //        cout << "Copying row "  << "[" << i << "]"
            //        << " with data " << intAP[i]
            //       << " into the new array \n";
            
            
        }//for
        
        //display new
        cout << "\nExpanded array! (+8)\n";
        
        for (int i = 0; i < max; i++){
            cout << "Entry at " << i << " Is " << tempAP[i] << endl;
        }//for
        
        cout << "\n";
        
        for (int i = 0; i < max; i++) {
            *(tempAP + i) = *(intAP + i);
            
            //display copy
            cout << "Copying row "  << "[" << i << "]"
            << " with data " << *(intAP + i)
            << " into the new array \n";
            
            
        }//for
        cout << "\n";
        
        
        
        //deallocate
        delete[] intAP;
        intAP = nullptr;
        
    }
    else{}
    return tempAP;
}//expandArray



int* compressArray(int* intAP,  int CURRENT_SIZE, int max) {
    
    int* tempAP = nullptr;
    tempAP = new int[max];
    
    
    if ( CURRENT_SIZE > max){
        // allocate
        for (int i = 0; i < max; i++) {
            *(tempAP + i) = 0;
        }//for
        
        // copy old into new
        for (int i = 0; i < CURRENT_SIZE; i++) {
            *(tempAP + i) = *(intAP + i);
            
        }//for
        
        //display new
        cout << "\nCompressed array! (-5)\n";
        
        for (int i = 0; i < max; i++){
            cout << "Entry at " << i << " Is " << tempAP[i] << endl;
        }//for
        
        cout << "\n";
        
        for (int i = 0; i < max; i++) {
            *(tempAP + i) = *(intAP + i);
            
        }//for
        cout << "\n";
        
        
        
        //deallocate
        delete[] intAP;
        intAP = nullptr;
        
    }
    else{}
    return tempAP;
}//compressArray

