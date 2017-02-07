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

#ifndef LAB6_H
#define LAB6_H

// Declaration of class Circle

class Circle
{
private:
	double radius;
	double xPos;
	double yPos;
public:
	//	Accessors
	double getRadius() const;
	double getxPos() const;
	double getyPos() const;

	//	Mutators
	void setRadius(double);
	void setxPos(double);
	void setyPos(double);

	//	Constructors
	void displayCircle(double, double, double);
	void moveCircle(double, double, double&, double&);
	void displayQuad(double, double);
};

#endif

