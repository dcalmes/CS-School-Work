/*----------------------------------------------------------------------------------
Assignement:	CS2010 - Lab 2
File name:		VossenW_CalmesD_lab2.cpp
Author:			Wiebe Vossen, Douglas Calmes
Date:			9-2-2015
Purpose:		Determine the area of the pizza and the total number of slices 
				when a radius is given.
--------------------------------------------------------------------------------------*/

#include<iostream>
using namespace std;

int main()
{
	double radius,area;
	int slices;

	//Get the radius of the pizza
	cout << "Please enter the radius of the pizza in inches: ";
	cin >> radius;

	//Calculate the area of the pizza with the following equation: Area = radius^2*PI. PI is 3.14159
	area = radius*radius*3.14159;

	//Determine the number of slices if the size of one slice is 14.125 inch^2
	slices = area / 14.125;

	//The output of the area and the number of slices.
	cout << "The area of the pizza is " << area << " inch^2."<<endl<< "The number of slices is " << slices<< 
			" if each slice is 14.125 inch^2.";

	cout << endl;
	system("pause");
	return 0;
}