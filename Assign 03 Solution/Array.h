// Assignment 2
// File: Array.h
// Array template class definition with overloaded operators.
// Author: Bob Langelaan
// Feb. 15, 2016

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

template <typename elementType = int, int numberOfElements = 5>
class Array
{
public:
   Array(); // default constructor

   Array( const Array & ); // copy constructor

   ~Array(); // destructor
   int getSize() const; // return size

// Comment out overloaded = operator
//  const Array &operator=( const Array & ); // assignment operator

   bool operator==( const Array & ) const; // equality operator

   // inequality operator; returns opposite of == operator
   bool operator!=( const Array &right ) const  
   { 
      return ! ( *this == right ); // invokes Array::operator==
   } // end function operator!=
   
   // subscript operator for non-const objects returns modifiable lvalue
   elementType &operator[]( int );              

   // subscript operator for const objects returns rvalue
   elementType operator[]( int ) const;  

   // input and output functions defined below
   void inputArray(); // input the array elements
   void outputArray() const; // output the array elements

   static int getArrayCount(); // return count of array<elementType> objects currently instantiated

private:
   elementType myArray[numberOfElements]; // Array of type elementType and size numberOfElements
   static int arrayCount; // # of Arrays currently instantiated
}; // end class Array

// What follows is what would usually be in the class .cpp file

// initialize static data member at file scope
template < typename elementType, int numberOfElements >
int Array< elementType, numberOfElements >::arrayCount = 0; // no objects

// default constructor for class Array
template <typename elementType, int numberOfElements>
Array<elementType, numberOfElements>::Array()
{
   // Increment object count
   Array<elementType, numberOfElements>::arrayCount++;
} // end Array default constructor

// copy constructor for class Array;
// must receive a reference to an Array
template <typename elementType, int numberOfElements>
Array<elementType, numberOfElements>::Array( const Array &arrayToCopy )
{
	*this = arrayToCopy;  // just copy the object over

	// The following statement is the _ONLY_ reason we need this copy ctor !!!
	Array<elementType, numberOfElements>::arrayCount++; // Increment object count
} // end Array copy constructor


// destructor for class Array
template <typename elementType, int numberOfElements>
Array< elementType, numberOfElements >::~Array()
{
   // Decrement count of objects
   Array<elementType, numberOfElements>::arrayCount--;
} // end destructor

// return number of elements of Array
template <typename elementType, int numberOfElements>
int Array< elementType, numberOfElements >::getSize() const
{
   return numberOfElements; // number of elements in Array
} // end function getSize

// return the number of Array objects instantiated
template < typename elementType, int numberOfElements >
int Array< elementType, numberOfElements >::getArrayCount() 
{
   return Array<elementType, numberOfElements>::arrayCount; 
} // end function getArrayCount

/*
   Comment out unecessary assignment operator

// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3
const Array &Array::operator=( const Array &right )
{
   if ( &right != this ) // avoid self-assignment
   {
      // for Arrays of different sizes, deallocate original
      // left-side Array, then allocate new left-side Array
      if ( size != right.size )
      {
         delete [] ptr; // release space
         size = right.size; // resize this object
         ptr = new int[ size ]; // create space for Array copy
      } // end inner if

      for ( size_t i = 0; i < size; ++i )
         ptr[ i ] = right.ptr[ i ]; // copy array into object
   } // end outer if

   return *this; // enables x = y = z, for example
} // end function operator=
*/

// determine if two Arrays are equal and
// return true, otherwise return false
template <typename elementType, int numberOfElements>
bool Array< elementType, numberOfElements >::operator==( const Array &right ) const
{
   for ( int i = 0; i < numberOfElements; ++i )
   {
      if ( this->myArray[ i ] != right.myArray[ i ] )
	  {
         return false; // Array contents are not equal
	  }
   }

   return true; // Arrays are equal
} // end function operator==

// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
template <typename elementType, int numberOfElements>
elementType & Array< elementType, numberOfElements >::operator[]( int subscript )
{
   // check for subscript out-of-range error
   if ( subscript < 0 || subscript >= numberOfElements )
   {
      throw out_of_range( "Subscript out of range" );
   }

   return this->myArray[ subscript ]; // reference return
} // end function operator[]


// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
template <typename elementType, int numberOfElements>
elementType Array< elementType, numberOfElements >::operator[]( int subscript ) const
{
   // check for subscript out-of-range error
   if ( subscript < 0 || subscript >= numberOfElements )
   {
      throw out_of_range( "Subscript out of range" );
   }

   return this->myArray[ subscript ]; // returns copy of this element
} // end function operator[]

template <typename elementType, int numberOfElements>
void Array< elementType, numberOfElements >::inputArray() // input the array elements
{
	// get values of array from user
	for ( int i = 0; i < numberOfElements; i++ )
	{
		cin >> this->myArray[ i ];
	}
}

template <typename elementType, int numberOfElements>
void Array< elementType, numberOfElements >::outputArray() const // output the array elements
{
   int i;

   // output array
   for ( i = 0; i < numberOfElements; i++ ) 
   {
      cout << this->myArray[ i ] << ' ';

      // form rows for output
      if ( ( i + 1 ) % 10 == 0 )
	  {
         cout << '\n';
	  }
   } // end for

   if ( i % 10 != 0 )
   {
      cout << '\n';
   }
}

#endif

/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
