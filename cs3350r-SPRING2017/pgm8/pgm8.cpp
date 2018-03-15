///////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Program:		CS3350 Program 8
//	Due Date:		Friday, April 14th
//	Programmer:		Douglas G Calmes
//	Purpose:		The purpose of this program is to read in a text file and create a binary tree
//						It will also ask the user if they want to replace an item in the tree with
//						a different value and allow them to replace it if valid.
//	Disclamer:		Unfortunately I was not able to get this code to work after working on it extensively
//						With that being said, I will be scheduling a learning commons visit next week
//						to hopefully get the help I need to finish it.  Being stuck on a program is not
//						something I am used to so I will make sure it works, even though it wont result
//						in any points.  Thank you very much for the challenge, it feels good to get stuck.
//						It lets you know that there is always room for improving you skills in CS!
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream> 
#include "BinarySearchTree.h"
#include "BinaryNodeTree.h"
#include "BinaryNode.h"
#include "BinaryTreeInterface.h"
#include <string> 
#include <fstream>
using namespace std;

int main(){
	BinaryNodeTree<string> nodeTree;		// Created a BinaryNodeTree item
	BinarySearchTree<string> searchTree;	// Created a BinarySearchTree item
	ifstream inputFile;						// Create infstream variable
	string line;							// Lines read in from input file
	string itemReplace, getItem;		// Variable uses to replace an item in a node

	inputFile.open("pgm8.txt");				// Open an input file

/////////////////////////////////////////////////////////////////
// This is where my problem was occuring.  For some reason my
// input file would not store any items, it was stuck in a
// continuous loop stating that there were only spaces, printing
// out no words.  This did not allow me to properly test out
// my functions.  Also not allowing me to build a visual display
// because there were no lines to text to display.
/////////////////////////////////////////////////////////////////
	while (!inputFile.eof())
	{
		getline(inputFile, line);
		nodeTree.add(line);           
		searchTree.add(line);
		
		// Test to see if the lines were being read in properly
		cout << line << "  ";
	}

	// With input file not working properly, I did not close the file
	// With the loop being continous, there was no need to close the file.

	/////////////////////////////////////////////////////////////////
	// I was not able to get the replacement algorithms to work
	// so I commented out this section in order for my code to at
	// least compile.
	/////////////////////////////////////////////////////////////////
	/*
	cout << "What getItem Will Be Replaced? " << endl;
	cin >> getItem; 
	cout << "What Would You Like to Replace it With? " << endl;
	cin >> itemReplace;

	nodeTree.replace(getItem, itemReplace);
	searchTree.replace(getItem, itemReplace); 

	*/

return 0;
}