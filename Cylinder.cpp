// Assignment 1 Solution: Cylinder.cpp
// Member-function definitions for class Cylinder.
// Author: Bob Langelaan
// Date: Sept. 20th, 2014

#include "Cylinder.h"

// constructor
Cylinder::Cylinder(void)
:mHeight(0.0), mRadius(0.0)
{
	this->setNoOfSides(3);   // Why not init. this member in MIL ???
}

// destructor
Cylinder::~Cylinder(void)
{
	// nothing to do
}

// used to set value for mRadius member
void Cylinder::setRadius(const double & setVal)
{
	if (setVal > 0.0) // Make sure input is a valid value
	{
		this->mRadius = setVal;
	}

	// otherwise just leave set to original value
}

// used to return current value of mRadius member
double Cylinder::getRadius (void) const
{
	return this->mRadius ;
}

// used to set mHeight member
void Cylinder::setHeight(const double & setVal)
{
	if (setVal > 0.0 )  // Make sure input is a valid value
	{
		this->mHeight = setVal;
	}

	// otherwise just leave set to original value
}

// used to return current value of mHeight member
double Cylinder::getHeight (void) const
{
	return this->mHeight;
}

// used to caluclate and return area
double Cylinder::Area (void) const
{
	double TwoPiR = 2.0 * Shape::pi * this->mRadius;
	return ( TwoPiR * this->mRadius ) + ( TwoPiR * this->mHeight );
}

// used to claculate and return volume
double Cylinder::Volume (void) const
{
	return Shape::pi * this->mRadius * this->mRadius * this->mHeight;
}