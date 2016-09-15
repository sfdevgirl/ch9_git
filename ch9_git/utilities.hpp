//
//  utilities.h
//  CPPUtilities
//
//  Created by Bill Komanetsky on 1/29/15.
//  Copyright (c) 2015 Bill Komanetsky. All rights reserved.
//

#ifndef __CPPUtilities__utilities__
#define __CPPUtilities__utilities__

#include <vector>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//
//Prototypes for utilities.cpp
//
string makeUpperCase(string);
string makeLowerCase(string);
void clearCIN(void);
string inputString(string, int, int);
int inputInt(string, int, int, int);
double inputDouble(string, double, double, double);
string centerString(string, int);
int getRandomInt(int, int);
double getRandomDouble(int, int, int);
bool verifyAction(string);
char askOverWrite(void);
string getRandomString(int, int);

//Shannon's proto
void sortArray( int [], int);
void showArray(const int [], int);

void selectionSort(int [], int );
void intVectorBubbleSort(vector<int> &, char);
void intVectorSelectionSort(vector<int> &, char);
bool intVectorBinSearch(vector<int>, int);
bool intVectorLinSearch(vector<int>, int);
void displayVector(vector<int>);
void initVector(vector<int> &);
//CH9_PROTO
int *expandArray(int*,  int, int);
int *compressArray(int*,  int, int);


#endif /* defined(__CPPUtilities__utilities__) */
