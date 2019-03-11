// Main Program - used to "test drive" Complex class
// File Name: MainProg.cpp
// Author: Bob Langelaan
// Date: Feb 19, 2014

#include "Complex.h" // include definition of class Complex from Complex.h
using namespace std;

int main()
{
	Complex A,B;  // create some Complex object
	ios_base::fmtflags origFormatCin, origFormatCout, newFormat;  // Create format flags

	origFormatCin = cin.flags();  // record original cin flag settings
	cout << "The original format flag for cin is: " << origFormatCin << endl;

	origFormatCout = cout.flags();  // record original cout flag settings
	cout << "The original format flag for cout is: " << origFormatCout << endl;

	// In the situation below, which is commented out, since the two
	//    formatting requests conflict, the default value, which in
	//    this case is "right", will be chosen.  This is regardless 
	//    of what the attribute was set to before this most recent call 
	//    to the flags() member function.
    
	//	   cout.flags(ios::right|ios::left);
	


	// Test overloaded extraction and insertion operators

	//
	// Ask user to enter valid complex number using input mode 1
	//

	//set "input" to mode 1
	newFormat = origFormatCin | ios::oct;  // our way of asking for input format for Complex #s
	                                       // to be "(nnnn.nn,nnnn.nn)"
	cin.flags(newFormat); // set to new format flag value
	cout << "\nThe cin format flags are set to: " << newFormat << endl;

	cout << "\nEnter 2 Complex numbers in the form \"(real_value,imaginary_value)\" :\n";
	cin >> A >> B;

	newFormat = cin.flags();  //find out how flags are set now
	cout << "\nThe cin format flags are set to: " << newFormat << endl;

	if (!cin.fail()) // if Complex numbers ok, display Complex numbers entered by user
	{
		//set "output" to mode 1
	   
		newFormat = origFormatCout | ios::oct;  // our way of asking for output format for Complex #s
	                                            // to be "(nnnn.nn,nnnn.nn )"
	   
		cout.flags(newFormat); // set to new format flag value
		cout << "\nThe cout format flags are set to: " << newFormat << endl;
		   
		cout << "\nThe Complex numbers are:  " << A << " and " << B << endl;

		newFormat = cout.flags();  //find out how flags are set now
		cout << "\nThe cout format flags are set to: " << newFormat << endl;

		// output Complex numbers a second time
		// but first set "output" to mode 2

		newFormat &= ~ios::oct;  // Ensure oct bit is NOT set
	                             // Mode is now "nnnn.nn nnnn.nni"
		cout.flags(newFormat);
		cout << "\nThe cout format flags are set to: " << newFormat << endl;

		cout << "\nThe Complex numbers are:  " << A << " and " << B << endl;

		newFormat = cout.flags();  //find out how flags are set now
		cout << "\nThe cout format flags are set to: " << newFormat << endl;
	}

	else // if a Complex number is invalid, tell user and terminate application
	{
		cerr << "\nInvalid Complex number was entered.\n\n";
		system("pause");  // pause before leaving forever
		exit( 1 );
	} 

	//
	// Ask user to enter valid complex number using input mode 2
	//

	cout << "\n\n Part 1 Completed, On to Part 2\n\n";

	//set "input" to mode 2
	//note that this assumes that the oct bit was not originally set for the cin object
	newFormat = origFormatCin;  // our way of asking for input format for Complex #s
	                            // to be " nnnn.nn nnnn.nni "
	cin.flags(newFormat); // set to new format flag value
	cout << "\nThe cin format flags are set to: " << newFormat << endl;

	cout << "\nEnter 2 Complex numbers in the form \"nnnn.nn nnnn.nni\" :\n";
	cin >> A >> B;

	newFormat = cin.flags();  //find out how flags are set now
	cout << "\nThe cin format flags are set to: " << newFormat << endl;

	if (!cin.fail()) // if Complex numbers ok, display Complex numbers entered by user
	{
		//set "output" to mode 1
	   
		newFormat = origFormatCout | ios::oct;  // our way of asking for output format for Complex #s
	                                            // to be "( nnnn.nn, nnnn.nn )"
	   
		cout.flags(newFormat); // set to new format flag value 
		cout << "\nThe cout format flags are set to: " << newFormat << endl;
		   
		cout << "\nThe Complex numbers are:  " << A << " and " << B << endl;

		newFormat = cout.flags();  //find out how flags are set now
		cout << "\nThe cout format flags are set to: " << newFormat << endl;

		// output Complex numbers a second time

		// but first set "output" to mode 2

		newFormat &= ~ios::oct;  // Ensure oct bit is NOT set
	                             // Mode is now "nnnn.nn nnnn.nni"
		cout.flags(newFormat);
		cout << "\nThe cout format flags are set to: " << newFormat << endl;

		cout << "\nThe Complex numbers are:  " << A << " and " << B << endl;

		newFormat = cout.flags();  //find out how flags are set now
		cout << "\nThe cout format flags are set to: " << newFormat << endl;
	}

	else // if a Complex number is invalid, tell user and terminate application
	{
		cerr << "\nInvalid Complex number was entered.\n\n";
		system("pause");  // pause before leaving forever
		exit( 1 );
	} 

	cout << '\n' << endl;

	system("pause");

	return 0;

} // end main

