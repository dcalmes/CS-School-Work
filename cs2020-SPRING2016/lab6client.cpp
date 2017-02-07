///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Program:     Lab 6
// Purpose:		This programs purpose is to use a class in order to find and display a Circles radius, positions,
//				and the quadrant it belongs to.
// Input:		This program requires the user to input the radius, x coordinate, and y coordinate.  Also, in order to
//				move the circle it calls for the user to input how much the user wants to move each x and y.
// Processing:  This program will use the circle information the user inputs and will go through various functions in
//				order to display the circle's radius, x coordinate, and y coordinate.  It will then use the inputs of
//				how much the user wants to move the circle in order to display its new location and its radius.  This
//				program will also use the x and y coordinates in order to tell the user what quadrant the circle will
//				fall under.
// Output:		This program outputs the circles radius, x coordinate, and y coordnate of the circle.  Also, after moving
//				the circle it will output the new x and y coordinate.  Also, it will output the quadrant that the circle
//				will fall under.
// Programmer:  Douglas Calmes
// Class:       CS 2020 Spring 2016
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "lab6H.h"
using namespace std;

int main()
{
	Circle ring;
	double ringRadius;
	double ringxPos;
	double ringyPos;
	double ringxMove;
	double ringyMove;

	//	Get the radius, xpos, and ypos from user.
	cout << "Please enter radius, x coordinate, and y coordinate: ";
	cin >> ringRadius;
	cin >> ringxPos;
	cin >> ringyPos;

	//	These functions store the variables of the circle
	ring.setRadius(ringRadius);
	ring.setxPos(ringxPos);
	ring.setyPos(ringyPos);

	//	This function displays the circle's inputs and displays the quadrant
	ring.displayCircle(ringRadius, ringxPos, ringyPos);
	ring.displayQuad(ringxPos, ringyPos);

	//	This function moves the circle and displays the quadrant
	cout << "Please enter delta x, delta y: ";
	cin >> ringxMove;
	cin >> ringyMove;

	ring.moveCircle(ringxMove, ringyMove, ringxPos, ringyPos);
	ring.displayCircle(ringRadius, ringxPos, ringyPos);
	ring.displayQuad(ringxPos, ringyPos);

	system("Pause");
	return 0;
}
