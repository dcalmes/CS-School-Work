//	Program:		CS3350 Program 1
//	Due Date:		Wednesday, Jan. 18
//	Programmer:		Douglas G Calmes
//	Purpose:		The purpose of this program is to use classes and inheritence to
//					find the area of a circle and rectangle.  It uses virtual functions.

#include "pgm1Rectangle.h"
#include "pgm1Circle.h"
#include "pgm1BasicShape.h"
#include <iostream>
using namespace std;

int main()
{
	//	These are the variables used to pass into the respective class functions
	double	circleX, circleX2;
	double	circleY, circleY2;
	double	rectangleW, rectangleW2;
	double	rectangleL, rectangleL2;
	double	inputRadius, inputRadius2;
	double	inputArea = 0, inputArea2 = 0;

	//	Have the user input the x coordinate of the circle
	cout << "Please enter the x coordinate of the circle's center (int): ";
	cin >> circleX;
	cout << endl;

	//	Have the user input the y coordinatte of the circle
	cout << "Please enter the y coordinate of the cirlce's center (int): ";
	cin >> circleY;
	cout << endl;

	//	Have the user input the radius of the circle
	cout << "Please enter the radius of the circle (double): ";
	cin >> inputRadius;
	cout << endl;

	//	Call in Circle to set the x coordinate, y coordinate, and radius
	Circle <int>Circle1(circleX, circleY, inputRadius, inputArea);

	//	Print out the information of the circle
	cout << "The x and y coordinates of the circle are " << Circle1.getCenterX() << " and " << Circle1.getCenterY() << endl << endl;
	cout << "The area of the circle is " << Circle1.getArea() << endl << endl << endl;

	//	Have user input the length of the rectangle
	cout << "Please enter the length of the Rectangle (int): ";
	cin >> rectangleL;
	cout << endl;

	//	Have the user input the width of the rectangle
	cout << "Please enter the width of the Rectangle (int) :";
	cin >> rectangleW;
	cout << endl;

	//	Call in Rectangle to set the length and width
	Rectangle <int>Rectangle1(rectangleW, rectangleL, inputArea);
	//	Print out the information of the Rectangle
	cout << "The area of the rectangle is " << Rectangle1.getArea() << endl << endl << endl;

	//	Have the user input the x coordinate of the circle 2
	cout << "Please enter the x coordinate of the circle's center (double): ";
	cin >> circleX2;
	cout << endl;

	//	Have the user input the y coordinatte of the circle 2
	cout << "Please enter the y coordinate of the cirlce's center (double): ";
	cin >> circleY2;
	cout << endl;

	//	Have the user input the radius of the circle 2
	cout << "Please enter the radius of the circle (double): ";
	cin >> inputRadius2;
	cout << endl;

	//	Call in Circle to set the x coordinate, y coordinate, and radius of Circle2
	Circle <double>Circle2(circleX2, circleY2, inputRadius2, inputArea2);

	//	Print out the information of the circle 2
	cout << "The x and y coordinates of the circle are " << Circle2.getCenterX() << " and " << Circle2.getCenterY() << endl << endl;
	cout << "The area of the circle is " << Circle2.getArea() << endl << endl << endl;

	//	Have user input the length of the rectangle 2
	cout << "Please enter the length of the Rectangle (double): ";
	cin >> rectangleL2;
	cout << endl;

	//	Have the user input the width of the rectangle 2
	cout << "Please enter the width of the Rectangle (double) :";
	cin >> rectangleW2;
	cout << endl;

	//	Call in Rectangle to set the length and width of Rectangle2
	Rectangle <double>Rectangle2(rectangleW2, rectangleL2, inputArea2);

	//	Print out the information of the Rectangle2
	cout << "The area of the rectangle is " << Rectangle2.getArea() << endl << endl;


	system("Pause");
	return 0;
}