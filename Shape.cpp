// Assignment 1 Solution: Shape.cpp
// Member-function definitions for class Shape.
// Author: Bob Langelaan 
// Date: Sept. 20th, 2014

#include "Shape.h"

int Shape::mObjectCount = 0;  // init. static member
const double Shape::pi = 3.141592654;  // init. static member

// constructor
Shape::Shape(void)
:mNoOfSides(1)
{
	++Shape::mObjectCount;
}

// desstructor
Shape::~Shape(void)
{
	--Shape::mObjectCount;
}

// used to set mNoOfSides member
void Shape::setNoOfSides(const int & setVal)
{
	if (setVal > 0 )
	{
		this->mNoOfSides = setVal;
	}

	// otherwise just leave set to original value
}

// used to return current value of mNoOfSides member
int Shape::getNoOfSides() const
{
	return this->mNoOfSides;
}

// used to return current value of mObjectCount static member
int Shape::getObjectCount()
{
	return Shape::mObjectCount;
}
