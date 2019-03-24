// Assignment 6 solution: Complex.cpp
// Member-function definitions for class Complex.
// Author: Bob Langelaan 
// Date: March 6, 2014

#include "Complex.h"
#include <iomanip>
using namespace std;

// ctor
Complex::Complex ( double real, double imag )
{
	this->real_part = real;
	this->imaginary_part = imag;
}

// overload the "+=" operator
Complex & Complex::operator += (const Complex & op )
{
	this->real_part += op.real_part;
	this->imaginary_part += op.imaginary_part;

	return (*this);
}

// overload the "-=" operator
Complex & Complex::operator -= (const Complex & op )
{
	this->real_part -= op.real_part;
	this->imaginary_part -= op.imaginary_part;

	return (*this);
}

// overload the "==" operator
bool Complex::operator == (const Complex & RHS) const
{
	if (this->real_part != RHS.real_part)
	{
		return false;
	}
	else if (this->imaginary_part != RHS.imaginary_part)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// return the real part of the complex #
double Complex::getReal(void)
{
	return this->real_part;
}

// return the imaginary part of the complex #
double Complex::getImaginary(void)
{
	return this->imaginary_part;
}

// display the complex #
void Complex::display (void)
{
   // set floating-point number format
   cout << fixed << setprecision(3);

   cout << "( " << this->getReal() << " , " << this->getImaginary() << " )";
}

// overloads the binary '+' operator through a global function
Complex operator + (const Complex & LHS, const Complex & RHS )
{
	Complex temp = LHS;
	temp += RHS; // uses the overloaded "+=" operator
	return temp;
}

// overloads the binary '-' operator through a global function
Complex operator - (const Complex & LHS, const Complex & RHS )
{
	Complex temp = LHS;
	temp -= RHS; // uses the overloaded "-=" operator
	return temp;
}

// overloads the binary "!=" operator through a global function
bool operator != (const Complex & LHS, const Complex & RHS)
{
	return !(LHS == RHS); // uses overloaded "==" operator
}

// overloads the binary "<<" operator through a global friend function
//   Complex object will be formatted in the following format:
//   ( -125.00, 23.44 )
ostream & operator << (ostream & dest, const Complex & obj)
{

	ios_base::fmtflags origFormat;  // Create format flag

	origFormat = dest.flags();  // save original flag setting

	if (origFormat & ios::oct) // mode 1
	{
		dest << showpos << setprecision(2) << fixed << showpoint << internal;
		dest << "(" << setw(10) << obj.real_part << "," << setw(10) << obj.imaginary_part << ")";
	}

	else // mode 2
	{
		dest << fixed << setprecision(4) << fixed << showpoint;
		dest << obj.real_part << " " << obj.imaginary_part << 'i';
	}

	// restore format flags
	dest.flags(origFormat);

	return dest; // enables  cout << a << b << c
}


// overloads the binary ">>" operator through a global friend function
istream & operator >> (istream & input, Complex & obj)
{
	// First check if the failbit is set
	if( input.fail() )
	{
		return input;  //if so, go home
	}

	ios_base::fmtflags origFormat;  // Create format flag
	origFormat = input.flags();  // save original flag setting

 	if (origFormat & ios::oct) // mode 1
	{
		// Proscess '('
		input.ignore(2,'('); // skip over '('
		
		// Process real part
		input >> obj.real_part; // read the real component of the Complex #

		// Process ','
		if (input.peek() == ',')
		{
			input.get(); // swallow ','
		}

		else // we have a problem
		{
			// restore format flags
			input.flags(origFormat);

			// and then throw exception
			throw Invalid_Mode1_Complex_Value();
		}

		// Process imaginary part

		// read the imaginary component of the Complex #
		input >> obj.imaginary_part; 

		// Process ')'
		if (input.peek() == ')')
		{
			input.get(); // swallow ')'
		}

		else // we have a problem
		{
			// restore format flags
			input.flags(origFormat);

			// and then throw exception
			throw Invalid_Mode1_Complex_Value();
		}
	
	}
	else //mode 2
	{
		// for now, assume first # is real the part

		// read the real component of the Complex #
		input >> obj.real_part; 

		// check if next char is a blank or a 'i'
		if (input.peek() == 'i')
		{
			input.get(); // swallow 'i'

			// now we know we actually read imaginary part earlier on
			obj.imaginary_part = obj.real_part; 
			obj.real_part = 0.0;
		}

		// user has supplied both real and imaginary inputs
		else
		{
			// read the imaginary component of the Complex #
			input >> obj.imaginary_part; 

			// Process 'i'
			if (input.peek() == 'i')
			{
				input.get(); // swallow 'i'
			}

			else  // we have a problem!
			{
				// restore format flags
				input.flags(origFormat);

				// and then throw exception
				throw Invalid_Mode2_Complex_Value();
			}
		}
	}

	// restore format flags
	input.flags(origFormat);

	return input; // enables  cin >> a >> b >> c
}


