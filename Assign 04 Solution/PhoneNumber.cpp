// Exercise 13.14 Solution: PhoneNumber.cpp
// Member function definition of class PhoneNumber

// Name: Bob Langelaan
// Date: May 27, 2015

#include <cstdlib>
#include <cstring>
#include <ctype.h>

#include "PhoneNumber.h"
using namespace std;

// PhoneNumber default constructor
PhoneNumber::PhoneNumber()
{
   // set all char arrays to null character
   this->phone[ 0 ] = '\0';
   this->areaCode[ 0 ] = '\0';
   this->exchange[ 0 ] = '\0';
   this->line[ 0 ] = '\0';
} // end PhoneNumber constructor

// overloaded << operator
ostream &operator<<( ostream &output, const PhoneNumber &number )
{
   // display PhoneNumber
   output << "(" << number.areaCode << ") " << number.exchange
        << "-" << number.line << '\n';
   return output; // return ostream object
} // end overloaded << operator

// overloaded >> operator
istream &operator>>( istream &input, PhoneNumber &number )
{
   // get phone number from input stream
   input.getline( number.phone, 15 );

   // validate length of PhoneNumber
   if ( strlen( number.phone ) != 14 ){
      input.clear( ios::failbit );
	  return input;
   }

   // validate ( ) and -
   if ( number.phone[ 0 ] != '(' || number.phone[ 4 ] != ')' ||
	   number.phone[ 9 ] != '-' ){
      input.clear( ios::failbit );
	  return input;
   }

   // validate first digit of area code and exchange
   if ( number.phone[ 1 ] == '0' || number.phone[ 6 ] == '0' ||
	   number.phone[ 1 ] == '1' || number.phone[ 6 ] == '1'){
      input.clear( ios::failbit );
	  return input;
   }

   // validate middle digit of area code
   if ( number.phone[ 2 ] != '0' && number.phone[ 2 ] != '1' ){
	   input.clear( ios::failbit );
	   return input;
   }

   // ensure that chars that should be digits actually are digits 
   // and at same time move them into 

   int loop;
   bool validDigits = true;
   for (loop = 0; loop <= 2; loop++ ) 
   {
	   number.areaCode[ loop ] = number.phone[ loop + 1 ];
	   number.exchange[ loop ] = number.phone[ loop + 6 ];
	   if (!(isdigit(number.areaCode[loop]) && isdigit(number.exchange[loop])))
	   {
		   validDigits = false;
	   }
   } // end for

   // place null-terminating character at end of area code and exchange
   number.areaCode[ loop ] = number.exchange[ loop ] = '\0';

   // set line class member
   for ( loop = 0; loop <= 3; loop++ ){
	   number.line[ loop ] = number.phone[ loop + 10 ];
	   if (!(isdigit(number.line[loop])))
	   {
		   validDigits = false;
	   }
   }

   // place null-terminating character at end of line array
   number.line[ loop ] = '\0';

   // if not all valid digits set fail bit as well
   if (!validDigits)
   {
	   input.clear(ios::failbit);
   }

   return input; // return istream object
} // end overloaded >> operator
