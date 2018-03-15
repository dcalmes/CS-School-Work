// Progrmmer:	Douglas G Calmes			cs3350		M-W 6:00 - 7:20
// Program:		Program 5

#include <list>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>   
#include <cassert>
using namespace std;

// Function Prototypes
char clue1(list<string> &); 
int clue2(list<char> &, char);
int clue3(list<int> &, int);
unsigned long clue4(list<unsigned long> &, int);



int main()
{
	// Variables (Clues)
	list<string> listClue1;
	list<char> listClue2;
	list<int> listClue3;
	list<unsigned long> listClue4;
	// Variables (Iterators)
	list<string>::iterator iteratorString;
	list<char>::iterator iteratorChar;

	int q = 0;
	string temp;
	string message[10] = { "The", "secret", "to", "getting", "ahead", "is", "getting", "started", "Mark", "Twain" };

	// Creating an array of words and sotre them randomly into the list
	for (int i = 9; i > 0; i--){
		int j = rand() % i;
		temp = message[i];
		message[i] = message[j];
		message[j] = temp;
	}

	// Pusing the message that was shuffled into first list
	for (int i = 0; i < 10; i++){
		listClue1.push_back(message[i]);
	}

	int r = rand() % 10;
	iteratorString = listClue1.begin();

	while (q < r){
        q++;
		iteratorString++;

	}
	// Position that linky is getting put into
	*iteratorString = "Linky";

	// Randomly selecting letters from "linky" and store them in a list of length 10
	for (int i = 0; i < 10; i++){
		int ranNum1 = rand() % 5; 

		if (ranNum1 == 0){
			listClue2.push_back('L');
		}
		else if (ranNum1 == 1){
			listClue2.push_back('i');
		}
		else if (ranNum1 == 2){
			listClue2.push_back('n');
		}
		else if (ranNum1 == 3){
			listClue2.push_back('k');
		}
		else if (ranNum1 == 4){
			listClue2.push_back('y');
		}
	}

	// Creating a list of length 10 and adding a random number between 0 and 24 to each position
	for (int i = 0; i < 10; i++){
		int ranNum2 = rand() % 24;

		listClue3.push_back(ranNum2);
	}

	for (int i = 0; i < 25; i++){
		unsigned long ranum = ((unsigned long)rand() * 123456789 + 100000000);

		listClue4.push_back(ranum);
	}

	// Function calls
	char one = clue1(listClue1);
	int two = clue2(listClue2, one);
	int three = clue3(listClue3, two);
	unsigned long four = clue4(listClue4, three);

	system("pause");
	return 0;

}

////////////////////////////////////////////////////////
// This function will seach listClue1 to find Linky
////////////////////////////////////////////////////////
char clue1(list<string> & listClue1) 
{
	char n;
	int pos = 1;
	list<string>::iterator iteratorString;
	iteratorString = listClue1.begin();

	// Find Linky
	for (int i = 0; i < 10; i++){
		if (*iteratorString == "Linky"){
			break;
		}
		iteratorString++;
		pos++;
	}

	int j = pos % 5;

	if (j == 0){
		n = 'l';
	}
	else if (j == 1){
		n = 'i';
	}
	else if (j == 2){
		n = 'n';
	}
	else if (j == 3){
		n = 'k';
	}
	else if (j == 4){
		n = 'y';
	}

	cout << "##-------------------------------##" << endl;
	cout << "Clue 1 List" << endl;
	cout << "-----------------------------------" << endl;

	iteratorString = listClue1.begin();
	for (int a = 1; a < 10; a++){
		cout << a;
		cout << std::right << "  " << std::right << *iteratorString << endl;
		iteratorString++;
	}

	cout << "-----------------------------------" << endl;
	cout << "Clue 1 - 'Linky' found in position " << j << " in first list." << endl;
	cout << "Letter of 'Linky' to look for is " << n << endl;
	cout << "##-------------------------------##" << endl;

	return n;
}

////////////////////////////////////////////////////////
// This function will display list of "Linky" letters
//		Will return the position
////////////////////////////////////////////////////////
int clue2(list<char> & listClue2, char one){

	int num = 0;
	list<char>::iterator iteratorChar;
	iteratorChar = listClue2.begin();

	for (int i = 1; i < 11; i++){
		if (*iteratorChar == one){
			num = i;
		}
		iteratorChar++;
	}

	cout << "##-------------------------------##" << endl;
	cout << "Clue 2 List" << endl;
	cout << "-----------------------------------" << endl;

	iteratorChar = listClue2.begin();

	for (int i = 1; i < 11; i++){
		cout << i << "  " << *iteratorChar << endl;
		iteratorChar++;
	}
	cout << "-----------------------------------" << endl;
	cout << "Clue 2 - last letter " << one << " found in location " << num << endl;
	cout << "##-------------------------------##" << endl;

	return num;
}

////////////////////////////////////////////////////////
// This function will traverse listClue3 and find the
// character found by the first funciton
////////////////////////////////////////////////////////
int clue3(list<int> & listClue3, int two){
	int temp = 0, i = 1;
	list<int>::iterator intiterator;

	for (intiterator = listClue3.begin(); intiterator != listClue3.end(); intiterator++){
		if (i == two)
			temp = *intiterator;
		i++;
	}

	cout << "##-------------------------------##" << endl;
	cout << "Clue 3 List" << endl;
	cout << "-----------------------------------" << endl;
	intiterator = listClue3.begin();

	for (int k = 1; k < 11; k++){
		cout << setw(2) << k;
		cout << "  " << *intiterator << endl;
		intiterator++;
	}

	cout << "-----------------------------------" << endl;
	cout << "Clue 3 - number found in position " << two << " is " << temp << endl;
	cout << "##-------------------------------##" << endl;

	return temp;

}

unsigned long clue4(list<unsigned long> & listClue4, int three){
	int i = 1;
	unsigned long temp = 0;
	list<unsigned long>::iterator tempIiterator;
	listClue4.sort();

	for (tempIiterator = listClue4.begin(); tempIiterator != listClue4.end(); tempIiterator++){
		if (i == three){
			temp = *tempIiterator;
		}
		i++;
	}

	cout << "##-------------------------------##" << endl;
	cout << "Clue 4 List" << endl;
	cout << "-----------------------------------" << endl;
	tempIiterator = listClue4.begin();

	for (int j = 1; j < 25; j++){
		cout << j;
		cout << "  " << *tempIiterator << endl;
		tempIiterator++;
	}
	cout << "-----------------------------------" << endl;
	cout << "Clue 4 - the " << three << " largest number and combination for the safe deposit box is " << temp << endl;
	cout << "##-------------------------------##" << endl;
	return temp;
}