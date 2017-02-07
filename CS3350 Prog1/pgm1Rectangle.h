//	Program:		CS3350 Program 1
//	Due Date:		Wednesday, Jan. 18
//	Programmer:		Douglas G Calmes
//	Purpose:		The purpose of this program is to use classes and inheritence to
//					find the area of a circle and rectangle.  It uses virtual functions.

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "pgm1BasicShape.h"

template<class ItemType>
//	This is the Rectangle class I created.  Uses base class, BasicShape.
class Rectangle : public BasicShape<ItemType>
{
private:
	ItemType	width;
	ItemType	length;
public:
	//	Sets the width and length using this pointers.
	//	Calculates and returns the area of rectangle.
	Rectangle(ItemType width, ItemType length, double area) {
		this->width = width;
		this->length = length;

		area = calcArea();
		this->setArea(area);
	};
	//	Returns length of rectangle
	ItemType	getLength() const {
		return length;
	};
	//	Returns width of rectangle
	ItemType	getWidth() const {
		return width;
	};
	//	Calculates the area of rectangle
	 double		calcArea() const {
		return length*width;
	 };
};


#endif // !RECTANGE_H

