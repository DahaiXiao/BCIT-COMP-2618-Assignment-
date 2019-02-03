// Assignment 1 Solution: Circle.cpp
// Member-function definitions for class Circle.
// Author: Bob Langelaan
// Date: Sept. 20th, 2014

#include "Circle.h"

// constructor 
Circle::Circle(void)
:mRadius(0.0)
{
	this->setNoOfSides(1);  //  Why not init. this member in MIL ???
}

// destructor 
Circle::~Circle(void)
{
	// nothing to do
}

// used to set value for mRadius member
void Circle::setRadius(const double & setVal)
{
	if (setVal > 0.0) // Make sure input is a valid value
	{
		this->mRadius = setVal;
	}

	// otherwise just leave set to original value
}

// used to return current value of mRadius member
double Circle::getRadius (void) const
{
	return this->mRadius ;
}

// used top calculate and return area.
double Circle::Area (void) const
{
	return Shape::pi * this->mRadius * this->mRadius ;
}
