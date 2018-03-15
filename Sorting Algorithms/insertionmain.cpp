#include<iostream>
#include<fstream>
#include<string>
#include<chrono>
#include "insertion.h"

using namespace std;

void printarray(long int[], long int);

int main(int argc, char* argv[]) {
	// Variable setup---------------------------------------------------------------------------------------------------
	int element;
	long int i = 0;
	string readFile = argv[1];
	fstream myFile, randomFile;
	string fileName;
	long int totalelements = 0;
	//------------------------------------------------------------------------------------------------------------------


	//------------------------------------------------------------------------------------------------------------------
	myFile.open(readFile);
	while (!myFile.eof()) {
		myFile >> element;
		totalelements += 1;
	}

	long int * array = NULL;
	array = new long int[totalelements];


	randomFile.open(readFile);
	while (!randomFile.eof()) {
		randomFile >> element;
		array[i] = element;
		i+=1;
	}

	myFile.close();


	
	insertionsort(array, totalelements);


	//------------------------------------------------------------------------------------------------------------------

	return 0;
}



void printarray(long int array[], long int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << endl;
	}
}



