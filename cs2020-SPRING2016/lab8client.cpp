//////////////////////////////////////////////////////////////////////////////
// Program:             Lab 8
// Purpose:             This Program uses classes and inheritance to display
//						data about Dogs and ShowDogs
// Author:              Douglas Calmes
// Class:               CS 2020-3
// Semester:			Spring 2016
//////////////////////////////////////////////////////////////////////////////

#include "lab8dog.h"
#include "lab8show.h"
#include <string>
using namespace std;

int main()
{
	//	Declare max array size
	const int MAX_DOG = 4;

	//	Create array of pointers to Dog & ShowDog
	Dog * dogList[MAX_DOG];

	//	Setting	values to new Dog and ShowDog
	Dog dog1("Bolt", "White", 20);
	ShowDog	showdog1("Uggie", "Blk/Wht", 30, 3, 1);

	//	Creating our items in our array
	dogList[0] = new Dog("Bingo", "Tan", 20);
	dogList[1] = new ShowDog("Beethoven", "Brown", 200, 3, 1);
	dogList[2] = new ShowDog("Marley", "Yellow", 80, 10, 3);
	dogList[3] = new  Dog("Fido", "Rust", 50);

	//	Display the dogs that arent in the array
	dog1.displayDog();
	cout << endl;
	showdog1.displayDog();
	cout << endl;

	//	Loop to display the dogs in the array
	for (int i = 0; i < MAX_DOG; i++)
	{
		dogList[i]->displayDog();
		cout << endl;
	}


	system("Pause");
	return 0;
}