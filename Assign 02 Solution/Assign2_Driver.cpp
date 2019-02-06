// Main driver for Assignment 2: Assign2_Driver.cpp
// Overload operators for HugeInteger class.
// Author: Bob Langelaan
// Date: January 30, 2014

#include "HugeInteger.h" // include definiton of class HugeInteger
using namespace std;

int main()
{
	HugeInteger A,B,C,D;

	// input value for A & B
	cout << "****** Test << & >> operators ******\n\n";
	cout << "Input values for A and B: ";
	cin >> A >> B;
	cout << "\nA = " << A << "\nB = " << B;

	D = B;

	// test += operator
	cout << "\n\n****** Test += operator ******\n\n";
	cout << "A = " << A << "\nB = " << B << "\nC = " << C << "\n\n";
	cout << "C = B += A\n";
	C = B += A;
	cout << "\nA = " << A << "\nB = " << B << "\nC = " << C;
	B = D;  // restore B's value

	// test -= operator
	cout << "\n\n****** Test -= operator ******\n\n";
	cout << "A = " << A << "\nB = " << B << "\nC = " << C << "\n\n";
	cout << "C = B -= A\n";
	C = B -= A;
	cout << "\nA = " << A << "\nB = " << B << "\nC = " << C;
	B = D;  // restore B's value

	// test unary - operator
	cout << "\n\n****** Test unary - operator ******\n\n";
	cout << "A = " << A << "\nB = " << B << "\nC = " << C << "\n\n";
	cout << "C = B = -A\n";
	C = B= - A;
	cout << "\nA = " << A << "\nB = " << B << "\nC = " << C;
	B = D;  // restore B's value

	// test boolean operators
	cout << "\n\n****** Test boolean operators ******\n";
	cout << "\nA = " << A << "\nB = " << B << "\n\n";
	if(A == B)
		cout << "A == B\n";
	if(A != B)
		cout << "A != B\n";
	if(A < B)
		cout << "A < B\n";
	if(A > B)
		cout << "A > B\n";
	if(A <= B)
		cout << "A <= B\n";
	if(A >= B)
		cout << "A >= B\n";
	if(B < A)
		cout << "B < A\n";
	if(B > A)
		cout << "B > A\n";
	if(B <= A)
		cout << "B <= A\n";
	if(B >= A)
		cout << "B >= A\n";
	if(!A)
		cout << "A is equal to 0\n";
	if(+A)
		cout << "A is not equal to 0\n";
	if(!B)
		cout << "B is equal to 0\n";
	if(+B)
		cout << "B is not equal to 0\n";

	// test increment and decrement operators
	cout << "\n****** Test increment and decrement operators ******\n";
	cout << "\nA = " << A << "\nB = " << B << "\n";
	cout << "\ncout << A++ << A\n";
	cout << A++ << "  " << A;
	cout << "\n\ncout << B-- << B\n";
	cout << B-- << "  " << B;
	cout << "\n\ncout << ++A << A\n";
	cout << ++A << "  " << A;
	cout << "\n\ncout << --B << B\n";
	cout << --B << "  " << B << "\n";

	// test overloaded type cast to double operator
	cout << "\n****** Test overloaded type cast to double operator ******\n";
	cout << "\nA = " << A << "\nB = " << B << "\n";
	double dA = (double) A;             // one way to invoke cast operator
	double dB = static_cast<double>(B); // another way to invoke cast operator
	cout << "\nA cast to a double is: " << dA;
	cout << "\nB cast to a double is: " << dB << '\n' << endl;

	system("pause");

	return 0;
} // end main
