// Exercise 13.14 Solution: Ex15_14.cpp
// PhoneNumber test program

// Name: Bob Langelaan
// Date: May 27, 2015

#include "PhoneNumber.h"
using namespace std;

int main()
{
    PhoneNumber telephone; // create PhoneNumber object

	// ask user to enter valid telephone number and store it
	cout << "Enter a phone number in the form (123) 456-7890:\n";
	cin >> telephone;

	// Start loop that only ends when user inputs invalid telephone number
	while (!cin.fail())
	{
		// if phone number ok, display phone number entered by user
		cout << "\nThe phone number entered was:  " << telephone << endl;

		// ask user to enter next telephone number
		cout << "Enter a phone number in the form (123) 456-7890:\n";
		cin >> telephone;
	}
	   
	cerr << "\nInvalid phone number entered.\n\n";
	system("pause");  // pause before leaving forever
   
	return 0;

} // end main
