// Assignment: CS2010 - Lab 1
// FIle name: CalmesD-Lab1
// Author: Douglas Calmes
// Date: 8/26/2015
// Purpose: This program demonstrates basic imput and outbut in C++.

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string first, last;
	int age;

	// Get user's name and age
	cout << "Please enter your first name: ";
	cin >> first;
	cout << "Please enter your last name: ";
	cin >> last;
	cout << "Please enter your age: ";
	cin >> age;

	// Display welcoming message, user's name and age
	cout << endl;
	cout << "Hello " << first << " " << last << "!" << endl;
	cout << "Welcome to CS2010 where programming is fun!" << endl;
	cout << "You are " << age << " years old." << endl;

	cout << endl;
	system("pause");
	return 0;
}
