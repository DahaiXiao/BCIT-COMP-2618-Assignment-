// Assignment 1 Solution: ThreeDimensionalShapes.h
// Declaration of class ThreeDimensionalShapes.
// Member functions are defined in ThreeDimensionalShapes.cpp.
// Author: Bob Langelaan
// Date: Sept. 20th, 2006

#pragma once
#include "Shape.h"

class ThreeDimensionalShapes : public Shape
{
public:
	ThreeDimensionalShapes(void);  //constructor
	virtual ~ThreeDimensionalShapes(void); //destructor

	virtual double Volume() const = 0;   // calculate and return volume
										 //   pure virtual member function
};
