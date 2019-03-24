// Date_and_Times.h
// Name: Bob Langelaan
// Date: Jan 13, 2016

#ifndef DATE_AND_TIMES_H
#define DATE_AND_TIMES_H

#include "Date.h"
#include "Time.h"

// class Date_and_Times definition
class Date_and_Times
{
public:
   Date_and_Times( const Date &, const Time[], size_t ); // constructor
   Date_and_Times(const Date_and_Times &); // copy ctor								   
   const Date_and_Times & operator = (const Date_and_Times &); // Overloaded assignment operator
   ~Date_and_Times();  // destructor
   void display() const; // displays Date_and_Times object

   // For simplicity sake, you need not worry about seconds value becoming greater than 59.
   void addFiveSecs();  // adds 5 seconds to each Time object

private:
	size_t _size;  // # of Time objects to be created dynamically
	Date _date;    // Date object
	Time * _timePtr; //ptr to array of Time objects created dynamically

}; // end class Date_and_Times

#endif
