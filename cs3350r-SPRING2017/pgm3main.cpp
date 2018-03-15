// Programmer:	Douglas G Calmes		CS3350		MW 6:00 - 7:20
// Program:		Program 3

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include "pgm3bag.h"
using namespace std;

// Prototype functions
void displaySize(const LinkedBag<string>&);
void readinputFile(const string&, LinkedBag<string>&);

int main()
{
	LinkedBag<string> dictionary;
	LinkedBag<string> checkWords;
	LinkedBag<string> wrongBag;

	// Read in files
	readinputFile("lib/dictionary.txt", dictionary);
	readinputFile("lib/checkWords.txt", checkWords);

	// Checking words in dictionary
	cout << "Number of words in dictionary" << endl;
	displaySize(dictionary);
	cout << "Number of words in check" << endl;
	displaySize(checkWords);

	// Checking words spelled wrong
	dictionary.spellCheck(checkWords, wrongBag);
	cout << "Words that are spelled incorrectly" << endl;
	displaySize(wrongBag);
	system("pause");
	return 0;
}
void readinputFile(const string& fileName, LinkedBag<string>& linkedBag){
	ifstream inputFile;
	string input;
	inputFile.open(fileName);

	// Error message if file can not open
	if (!inputFile.is_open()){
		cout << "ERROR: File can not open!" << endl;
	}
	else{
		// Load in info from input file
		while (!inputFile.eof()){
			getline(inputFile, input);
			linkedBag.add(input);
		}
	}
}

void displaySize(const LinkedBag<string>& passedBag){
	// Initialize size to the size of bag
	int size = passedBag.getCurrentSize();
	vector<string> items = passedBag.toVector();

	cout << "Bag Size: " << size << endl;
	cout << "Bag Contents: " << endl;
	for (int i = 0; i < size; i++){
		cout << items[i] << endl;
	}
}