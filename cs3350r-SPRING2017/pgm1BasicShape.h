//	Program:		CS3350 Program 1
//	Due Date:		Wednesday, Jan. 18
//	Programmer:		Douglas G Calmes
//	Purpose:		The purpose of this program is to use classes and inheritence to
//					find the area of a circle and rectangle.  It uses virtual functions.

#ifndef BASICSHAPE_H
#define BASICSHAPE_H

template<class ItemType>
//	This is the BasicShape class I created
class BasicShape
{
private:
	double	area;
public:
	//	Set area to area using this pointer
	void		setArea(double area) {
		this->area = area;
	};
	//	This function returns the area
	double	getArea() const {
		return area;
	};
	//	Virtual function to calculate the area
	virtual	double calcArea() const = 0;

};
#endif // !BASICSHAPE_H
