// Assignment 5 Starting Point: Complex.h
// Declaration of class Complex.
// Member functions are defined in Complex.cpp.
// Author: Bob Langelaan 
// Date: March 6, 2014

#ifndef Complex_incl
#define Complex_incl

#include <iostream>
#include <exception>

class Complex  // Complex class
{

// We must offer friendship to the functions below because they need to access the
//    the private members of the Complex class object
	friend std::ostream & operator << (std::ostream & dest, const Complex & obj);
	friend std::istream & operator >> (std::istream & input, Complex & obj);

public:
	Complex (double real = 1.0, double imag = 0.0 );  // ctor with
	   // 2 default arguments
	 
	Complex & operator+= (const Complex & RHS ) ; //Adds RHS to the Complex object invoked with this method
	                                      //  (thereby modifying the Complex object) and returns the result
	                                      //  Overloads the "+=" operator
	Complex & operator-= (const Complex & RHS ) ; //Subtracts RHS from the Complex object invoked with this method
	                                      //  (thereby modifying the Complex object) and returns the result
	                                      //  Overloads the "-=" operator

	bool operator == (const Complex & RHS) const; // Overloads "==" operator

	double getReal(void);      // Returns real part
	double getImaginary(void); // Returns imaginary part

	void display(void); // Outputs to standard output stream the Complex object
	                    //   in the format: (real_part,imaginary_part)

private:

	double real_part, // represents real part of the Complex object
		imaginary_part;     // represents imaginary part of the Complex object
};

// overloads the binary "+" operator through a global function
Complex operator + (const Complex & LHS, const Complex & RHS );

// overloads the binary "-" operator through a global function
Complex operator - (const Complex & LHS, const Complex & RHS );

// overloads the binary "!=" operator through a global function
bool operator != (const Complex & LHS, const Complex & RHS);

// overloads the binary "<<" operator through a global friend function
std::ostream & operator << (std::ostream & dest, const Complex & obj);

// overloads the binary ">>" operator through a global friend function
std::istream & operator >> (std::istream & input, Complex & obj);

// Class declarations for 2 exception classes follow

class Invalid_Mode1_Complex_Value: public std::invalid_argument
{
public:
	Invalid_Mode1_Complex_Value():invalid_argument("Invalid value for inputting Complex # using Mode 1"){}
};

class Invalid_Mode2_Complex_Value: public std::invalid_argument
{
public:
	Invalid_Mode2_Complex_Value():invalid_argument("Invalid value for inputting Complex # using Mode 2"){}
};

#endif