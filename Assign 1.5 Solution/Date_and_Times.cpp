// Date_and_Times.cpp
// Name: Bob Langelaan
// Date: Jan 13, 2016

#include <iostream>
#include "Date_and_Times.h"
using namespace std;

// Constructor
Date_and_Times::Date_and_Times(const Date & date, const Time times[], size_t size)
	: _date(date), _size(size)
{
	this->_timePtr = new Time[this->_size];  // dynamically create an array of Time objects on the free store

	// Copy times array into newly created array of Time objects stored on the free store
	for (size_t i = 0; i < this->_size; ++i)
	{
		this->_timePtr[i] = times[i];
	}
} // end constructor

// Copy constructor
Date_and_Times::Date_and_Times(const Date_and_Times & orig)
	:_date(orig._date), _size(orig._size)
{
	this->_timePtr = new Time[this->_size];  // dynamically create an array of Time objects on the free store

	// Copy orig Time array into newly created array of Time objects stored on the free store
	for (size_t i = 0; i < this->_size; ++i)
	{
		this->_timePtr[i] = orig._timePtr[i];
	}
} // end copy constructor

// Overloaded assignment operator
const Date_and_Times & Date_and_Times::operator = (const Date_and_Times & right)
{
	if (&right != this) // avoid self-assignment
	{
		// for Time arrays of different sizes, deallocate original
		// left-side Time array, then allocate new left-side Time array
		if (this->_size != right._size)
		{
			delete[] this->_timePtr; // release space
			this->_size = right._size; // resize this object
			this->_timePtr = new Time[this->_size]; // create new Time array on the free store
		} // end inner if

		this->_date = right._date; // Copy date

		// Copy array into object on left of = operator
		for (size_t i = 0; i < this->_size; ++i) {
			this->_timePtr[i] = right._timePtr[i]; 
		}

	} // end outer if

	return *this; // enables x = y = z, for example
} // end overloaded assignment operator

// Destructor
Date_and_Times::~Date_and_Times()
{
	delete[] this->_timePtr;
	this->_timePtr = nullptr;
	this->_size = 0;  
} // end destructor

// Display object
void Date_and_Times::display() const
{ 
	// Display the date
	cout << "The date is: ";
	this->_date.print();

	// Display the times
	cout << "\nThe times are:\n";
	for (size_t i = 0; i < this->_size; ++i)
	{
		this->_timePtr[i].printUniversal();
		cout << ' ';
	}

	cout << '\n' << endl;
} // end function display

// Adds 5 seconds to each Time object
void Date_and_Times::addFiveSecs()
{
	for (size_t i = 0; i < _size; ++i)
	{
		this->_timePtr[i].setSecond(this->_timePtr[i].getSecond() + 5);
	}
}
