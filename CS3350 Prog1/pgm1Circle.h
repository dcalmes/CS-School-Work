//	Program:		CS3350 Program 1
//	Due Date:		Wednesday, Jan. 18
//	Programmer:		Douglas G Calmes
//	Purpose:		The purpose of this program is to use classes and inheritence to
//					find the area of a circle and rectangle.  It uses virtual functions.

#ifndef CIRCLE_H
#define CIRCLE_H
#include "pgm1BasicShape.h"
using namespace std;

template<class ItemType>
//	This is the Circle class I created.  It uses base class, BasicShape.
class Circle : public BasicShape<ItemType>
{
private:
	ItemType	centerX;
	ItemType	centerY;
	double		radius;
public:
	//	Sets centerX, centerY, and radius using pointers.
	//	Calculates and returns the area of circle.
	Circle(ItemType centerX, ItemType centerY, double radius, double area) {
		this->centerX = centerX;
		this->centerY = centerY;
		this->radius = radius;

		area = calcArea();
		this->setArea(area);
	};
	//	Returns centerX
	ItemType	getCenterX() const {
		return centerX;
	};
	//	Returns centerY
	ItemType	getCenterY() const {
		return centerY;
	};
	//	Calculates and returns area of rectangle
	 double		calcArea() const {
		return 3.14159 * radius * radius;
	 };
};
#endif // !CIRCLE_H

