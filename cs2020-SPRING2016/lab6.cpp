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

#include "lab6H.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//////////////////////////////////////////////////////////////////////////////
// Lab 6                                                                                                                                                                                                                                           /      
// Programmer:		Douglas Calmes                                                                                   
// Class:           CS 2020, Spring 2016                                     
//                                                                           
// Function:        setRadius                                                   
// Description:     This function sets the radius of the circle
// Parameters:		r- radius of the circle
// Returns:			Nothing              
//////////////////////////////////////////////////////////////////////////////

void Circle::setRadius(double r)
{
	if (r >= 0)
		radius = r;
	else
	{
		cout << "ERROR: This radius value is invalid!" << endl;		// Error msg
		exit(EXIT_FAILURE);
	}
}

//////////////////////////////////////////////////////////////////////////////
// Lab 6                                                                                                                                                                                                                                           /      
// Programmer:		Douglas Calmes                                                                                   
// Class:           CS 2020, Spring 2016                                     
//                                                                           
// Function:        setxPos                                                 
// Description:     This function sets the x coordinate of the circle
// Parameters:		x- coordinate of x
// Returns:			Nothing              
//////////////////////////////////////////////////////////////////////////////

void Circle::setxPos(double x)
{
	xPos = x;
}

//////////////////////////////////////////////////////////////////////////////
// Lab 6                                                                                                                                                                                                                                           /      
// Programmer:		Douglas Calmes                                                                                   
// Class:           CS 2020, Spring 2016                                     
//                                                                           
// Function:        setyPos                                                   
// Description:     This function sets the y coordinate of the circle
// Parameters:		y- coordinate of y
// Returns:			Nothing              
//////////////////////////////////////////////////////////////////////////////

void Circle::setyPos(double y)
{
	yPos = y;
}

//////////////////////////////////////////////////////////////////////////////
// Lab 6                                                                                                                                                                                                                                           /      
// Programmer:		Douglas Calmes                                                                                   
// Class:           CS 2020, Spring 2016                                     
//                                                                           
// Function:        getRadius                                                   
// Description:     This function gets the radius of the circle
// Parameters:		None
// Returns:			radius         
//////////////////////////////////////////////////////////////////////////////

double Circle::getRadius() const
{
	return radius;
}

//////////////////////////////////////////////////////////////////////////////
// Lab 6                                                                                                                                                                                                                                           /      
// Programmer:		Douglas Calmes                                                                                   
// Class:           CS 2020, Spring 2016                                     
//                                                                           
// Function:        getxPos                                                
// Description:     This function gets the x coordinate of the circle
// Parameters:		None
// Returns:			xPos           
//////////////////////////////////////////////////////////////////////////////

double Circle::getxPos() const
{
	return xPos;
}

//////////////////////////////////////////////////////////////////////////////
// Lab 6                                                                                                                                                                                                                                           /      
// Programmer:		Douglas Calmes                                                                                   
// Class:           CS 2020, Spring 2016                                     
//                                                                           
// Function:        getyPos                                                   
// Description:     This function gets the y coordinate of the circle
// Parameters:		None
// Returns:			yPos            
//////////////////////////////////////////////////////////////////////////////

double Circle::getyPos() const
{
	return yPos;
}

//////////////////////////////////////////////////////////////////////////////
// Lab 6                                                                                                                                                                                                                                           /      
// Programmer:		Douglas Calmes                                                                                   
// Class:           CS 2020, Spring 2016                                     
//                                                                           
// Function:        displayCircle                                                   
// Description:     This function displays the radius and coordinates of
//						the circle
// Parameters:		radius- radius of the circle
//					xPos-	x coordinate of the circle
//					yPos-	y coordinate of the circle
// Returns:			Nothing              
//////////////////////////////////////////////////////////////////////////////

void Circle::displayCircle(double radius, double xPos, double yPos)
{
	cout << "The Circle object with radius " << radius << " has coordinates (" << xPos << ", " << yPos << ")" << endl;
}

//////////////////////////////////////////////////////////////////////////////
// Lab 6                                                                                                                                                                                                                                           /      
// Programmer:		Douglas Calmes                                                                                   
// Class:           CS 2020, Spring 2016                                     
//                                                                           
// Function:        moveCircle                                                  
// Description:     This function ask the user how much they want to move
//						the circle.  User inputs how much they want to move
//						the x and y coordinates.  It uses these inputs to 
//						calculate the new position.
// Parameters:
//					xPos-	x coordinate of the circle
//					yPos-	y coordinate of the circle
//					xDelt-	move x coordinate
//					yDelt-	move y coordinate
// Returns:			Nothing              
//////////////////////////////////////////////////////////////////////////////

void Circle::moveCircle(double xDelt, double yDelt, double &xPos, double &yPos)
{
	//	Calculate new coordinates
	xPos = xPos + xDelt;
	yPos = yPos + yDelt;
}

//////////////////////////////////////////////////////////////////////////////
// Lab 6                                                                                                                                                                                                                                           /      
// Programmer:		Douglas Calmes                                                                                   
// Class:           CS 2020, Spring 2016                                     
//                                                                           
// Function:        displayQuad                                                  
// Description:     This function displays the quadrant of the circle
// Parameters:
//					xPos-	x coordinate of the circle
//					yPos-	y coordinate of the circle
// Returns:			Nothing              
//////////////////////////////////////////////////////////////////////////////

void Circle::displayQuad(double xPos, double yPos)
{
	//	If statments to determine what quadrant the circle falls in
	if (xPos > 0 && yPos > 0)
	{
		cout << "The Circle object is in Quadrant 1." << endl;
	}
	if (xPos < 0 && yPos > 0)
	{
		cout << "The Circle object is in Quadrant 2." << endl;
	}
	if (xPos < 0 && yPos < 0)
	{
		cout << "The Circle object is in Quadrant 3." << endl;
	}
	if (xPos > 0 && yPos < 0)
	{
		cout << "The Circle object is in Quadrant 4." << endl;
	}
}








