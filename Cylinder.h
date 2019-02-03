// Assignment 1 Solution: Cylinder.h
// Declaration of class Cylinder.
// Member functions are defined in Cylinder.cpp.
// Author: Bob Langelaan
// Date: Sept. 20th, 2006

#pragma once
#include "ThreeDimensionalShapes.h"

class Cylinder :public ThreeDimensionalShapes
{
public:
	Cylinder(void); // constructor
	virtual ~Cylinder(void); // destructor

	void setRadius(const double &);  //set the radius
	double getRadius() const;  // get the radius

	void setHeight(const double &); // set the height
	double getHeight() const; // get the height

	virtual double Area() const override;    // overrides Area()   method of Circle class
	virtual double Volume() const override;  // overrides Volume() method of Shape  class

protected:
	double mRadius;  // member used to represent radius
	double mHeight;  // member used to represent height

};

