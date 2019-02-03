// Assignment 1 Driver Program - used to test the 3 classes
// File Name: MainProg.cpp
// Author: Bob Langelaan 
// Date: Oct 4th, 2009

#include "Cylinder.h"
#include "Circle.h"

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// next line commented out because will now cause compile error
//	Shape    shpeObj;  // instantiate a Shape object

	cout << "The Shape object count is: " << Shape::getObjectCount() << '\n';

	Circle   crclObj;  // instantiate a Circle object
	Cylinder cyldObj;  // instantiate a Cylinder object

	// Count will be 2 in statement below because a Shape object is contained
	//     within each Circle and Cylinder object.
	cout << "The Shape object count is: " << Shape::getObjectCount() << "\n";

	Shape * shpePtr = &cyldObj;   // declare a Shape pointer
	                      // and have it point to the Cylinder object
	Shape & shpeRef = cyldObj;  // declare a Shape reference
	                      // and have it reference the Cylinder object

	// The above 2 statments are ok because a derived class object IsA base class object!

	// No additional objects created, so the count is still the same.
	cout << "The Shape object count is: " << Shape::getObjectCount() << "\n";

	// Dynamically create 2 objects
	Shape * shpePtr2 = new Circle;
	Shape & shpeRef2 = *new Cylinder; 

	// The count should now be 4
	cout << "The Shape object count is: " << Shape::getObjectCount() << "\n";

	// Now destroy the 2 dynamically created objects!
	delete shpePtr2;
	delete &shpeRef2;

	//The count should now be 2 again.
	cout << "The Shape object count is: " << Shape::getObjectCount() << "\n\n";
       
	/*  Can no longer test Shape class, since it is now an Abstract Base Class (ABC)
	// Test Shape class

	shpeObj.setNoOfSides(0);

	cout << "The number of sides   is: " << shpeObj.getNoOfSides() << "\n\n";
	cout << "The area   of shpeObj is: " << shpeObj.Area() << '\n';
	cout << "The volume of shpeObj is: " << shpeObj.Volume() << "\n\n\n";
	*/

	// Test Circle class

	crclObj.setRadius(3.0);

	cout << fixed << setprecision(4); // force use of decimal point and 4 digits of 
	                                  //     precision after the decimal place
	cout << "The radius of crclObj is: " << crclObj.getRadius() << "\n\n";
	cout << "The number of sides   is: " << crclObj.getNoOfSides() << "\n\n";
	cout << "The area   of crclObj is: " << crclObj.Area() << '\n';
	// next line no longer valid in my solution for this assignment
	//cout << "The volume of crclObj is: " << crclObj.Volume() << "\n\n\n";

	// Test Cylinder class

	cyldObj.setRadius(5.5);
	cyldObj.setHeight(2.5);

	cout << "The radius of cyldObj is: " << cyldObj.getRadius() << '\n';
	cout << "The height of cyldObj is: " << cyldObj.getHeight() << "\n\n";
	cout << "The number of sides   is: " << cyldObj.getNoOfSides() << "\n\n";
	cout << "The area   of cyldObj is: " << cyldObj.Area() << '\n';
	cout << "The volume of cyldObj is: " << cyldObj.Volume() << "\n\n";

	return 0;
}