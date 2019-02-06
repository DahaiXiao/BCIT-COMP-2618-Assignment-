// HugerInteger interface file for Assignment 2: HugeInteger.h
// Overload operators for HugeInteger class.
// Author: Bob Langelaan
// Date: January 30, 2014

#include <iostream>
#include <array>

class HugeInteger
{
// need to offer friendship to these 2 functions
	friend std::istream & operator >> (std::istream & src, HugeInteger & value);
	friend std::ostream & operator << (std::ostream & dest, const HugeInteger & value);

public:
	//ctor that converts a "long long" into a HugeInteger
	HugeInteger( long long value = 0LL ); //0LL is constant literal value 0
	                                      //   of type long long
	//ctor that converts a string into a HugeInteger
	HugeInteger( const char *str );

	//adds RHS into LHS (the object pointed to by the "this" pointer) and returns result
    HugeInteger & operator +=( const HugeInteger & RHS);

	//adds a "long long" (RHS) and LHS and puts result into a temp HugeInteger
	//   and returns result
	HugeInteger operator +( long long RHS) const; 

	//adds a string (which will be converted into a HugeInteger) with LHS into a temp 
	//       HugeInteger and returns result
	HugeInteger operator +( const char * RHS) const;

	//subtracts RHS from LHS (the object pointed to by the "this" pointer) and returns result
	HugeInteger & operator -=( const HugeInteger & RHS); 

	//subtracts a "long long" (RHS) from LHS and puts result into a temp HugeInteger 
	//    and returns result
	HugeInteger operator -( long long RHS) const; 

	//subtracts a string (which will be converted into a HugeInteger) from LHS 
	//    and puts result into a temp HugeInteger and returns result
	HugeInteger operator -( const char * RHS) const; 

	//calculates the negation of the object pointed to by the this pointer and returns result
	HugeInteger operator -(void)const;

	//calculates the absolute value of the object pointed to by the this pointer and returns result
	HugeInteger operator ~(void)const; // will overload ~ as abs operator

	//Is LHS (the object pointed to by the "this" pointer) equal to RHS
	bool operator ==( const HugeInteger & RHS)const;

	//Is LHS (the object pointed to by the "this" pointer) less than RHS
	bool operator <( const HugeInteger & RHS)const;

	//Is the object pointed to by the "this" pointer equal to zero
	bool operator !(void)const;

	//Convert a string into a HugeInteger
	void input( const char *str );

	// overload typecast to double
	operator double(void)const;

	// overload preincrement operator for the HugeInteger class
	HugeInteger & operator ++ (void);
	// overload postincrement operator for the HugeInteger class
	HugeInteger operator ++ (int);

	// overload predecrement operator for the HugeInteger class
	HugeInteger & operator -- (void);
	// overload postdecrement operator for the HugeInteger class
	HugeInteger operator -- (int);

private:
	bool negative;  // will be true if number is negative
	std::array<unsigned short,40> hugeInt; // each element in the array represents 
	                           //    one digit of the number
};

// Below are the implementations of the 5 inline global functions and the
//       prototypes for the 2 global functions that are implemented in
//       the HugeInteger.cpp file.

// NOTE: The 5 inline global functions should make use of the 3 public 
//       member functions that overload the ==, < and ! operators
//       Be careful to not re-invent the wheel!

inline bool operator !=( const HugeInteger & LHS, const HugeInteger & RHS)
{
	return !( LHS == RHS );
}

inline bool operator >( const HugeInteger & LHS, const HugeInteger & RHS)
{
//	return !((LHS < RHS ) || (LHS == RHS ));  // this works
	return ( RHS < LHS );  //this is better!
}

inline bool operator >=( const HugeInteger & LHS, const HugeInteger & RHS)
{
//	return ((LHS == RHS ) || (LHS > RHS ));  //this works
	return !(LHS < RHS);  // this is better!
}

inline bool operator <=( const HugeInteger & LHS, const HugeInteger & RHS)
{
//	return ((LHS == RHS ) || (LHS <  RHS ));  //this works
	return !(RHS < LHS);  // this is better!
}

// Is_Not_Zero operator
inline bool operator +( const HugeInteger & value) // is not zero
{
	return !(!value); // invokes the unary ! operator overloaded as a method above
}

//overloads the << and >> operators for the HugeInteger class
std::istream & operator >> (std::istream & src, HugeInteger & value);
std::ostream & operator << (std::ostream & dest, const HugeInteger & value);
