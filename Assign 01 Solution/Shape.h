// Assignment 1 Solution: Shape.h
// Declaration of class Shape.
// Member functions are defined in Shape.cpp.
// Author: Bob Langelaan
// Date: Sept. 20th, 2006

#pragma once

class Shape
{
public:
	Shape(void);  //constructor
	virtual ~Shape(void); //destructor

	void setNoOfSides(const int &);  // set the # of sides
	int getNoOfSides() const;        // get the # of sides

	static int getObjectCount();     // get the object count

	virtual double Area() const = 0;   // calculate and return volume
										 //  a pure virtual member function (method)
	
protected:
	int mNoOfSides; // represents # of sides in Shape object

	static int mObjectCount; // counts # of Shape objects currently instantiated
	const static double pi; // Static member used in calculations
	                        //   Only one of these instantiated for the whole class!
};
