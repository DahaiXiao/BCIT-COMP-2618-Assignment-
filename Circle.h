// Assignment 1 Solution: Circle.h
// Declaration of class Circle.
// Member functions are defined in Circle.cpp.
// Author: Bob Langelaan 
// Date: Sept. 20th, 2006

#pragma once
#include "TwoDimensionalShapes.h"

class Circle :public TwoDimensionalShapes
{
public:
	Circle(void); // constructor
	virtual ~Circle(void); // destructor

	void setRadius(const double &);  //set the radius
	double getRadius() const;  // get the radius

	virtual double Area() const override;  // overrides Area() method of Shape class

protected:	
	double mRadius;  // member used to represent radius

};
