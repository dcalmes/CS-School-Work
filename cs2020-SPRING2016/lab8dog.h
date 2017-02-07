//////////////////////////////////////////////////////////////////////////////
// Program:             Lab 8
// Purpose:             This Program uses classes and inheritance to display
//						data about Dogs and ShowDogs
// Author:              Douglas Calmes
// Class:               CS 2020-3
// Semester:			Spring 2016
//////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

#ifndef DOG_H
#define DOG_H

class Dog
{
protected:
	string name;
	string color;
	double weight;
public:
	//	Constructors
	Dog() { name = ""; color = ""; weight = 0.0; }	//	Defult constructor
	Dog(string name, string color, double weight)	//	Overloaded constructor
	{ this->name = name; this->color = color; this->weight = weight; }

	//	Accessors
	virtual void displayDog(); 

	//	Deconstructor
	virtual ~Dog() { }
};

#endif
#pragma once
