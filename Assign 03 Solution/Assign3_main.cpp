// Assignment 2
// File: Assign2_main.cpp
// Array template class definition with overloaded operators.
// Author: Bob Langelaan
// Feb 15,2016
#include "Array.h"
#include <string>
using namespace std;

int main()
{
   int ObjectCount = Array<>::getArrayCount(); //will default to Array<int,5>
   cout << "The current number of Array<int, 5> objects instantiated is: " << ObjectCount << '\n';

   ObjectCount = Array<string, 7>::getArrayCount();
   cout << "\nThe current number of Array<string, 7> objects instantiated is: " << ObjectCount << '\n';

   Array< int, 5 > intArray; // create a <int,5> Array object
   Array< int, 5 > intArray1; // create a second <int,5> Array object
   Array< int, 5 > intArray2(intArray1); // create a third <int,5> Array object
   Array< int, 6 > intArray3; // create a <int,6> Array object

   // initialize intArray with user input values
   cout << "\nEnter " << intArray.getSize() << " integer values:\n";
   intArray.inputArray();

   // output intArray
   cout << "\nThe values in intArray are:\n";
   intArray.outputArray();

   Array< string, 7 > stringArray; // create <string,7> Array object
   Array< string, 7 > stringArray2; // create 2nd <string,7> Array object

   // initialize stringArray with user input values
   cout << "\nEnter " << stringArray.getSize()
      << " one-word string values:\n";
   stringArray.inputArray();

   // output stringArray
   cout << "\nThe values in the stringArray are:\n";
   stringArray.outputArray();

// Note that if you were to overload the '=' operator (not required for this assignment),
// you would likely assume that both operands have the same number of elements and
// the same type of elements. Do you understand why such an assumption is relatively
// safe?

   intArray2 = intArray;
   stringArray2 = stringArray;

   if(intArray == intArray2)
   {
	   cout << "\nintArray == intArray2 \n";
   }

   if(stringArray == stringArray2)
   {
	   cout << "\nstringArray == stringArray2 \n";
   }

   intArray[0] = 5;
   stringArray[6] = "hello!!!";

   // output intArray after changing element 0
   cout << "\nThe values in intArray are:\n";
   intArray.outputArray();

   // output stringArray after changing element 6
   cout << "\nThe values in the stringArray are:\n";
   stringArray.outputArray();

   if(intArray != intArray2)
   {
	   cout << "\nintArray != intArray2 \n";
   }

   if(stringArray != stringArray2)
   {
	   cout << "\nstringArray != stringArray2 \n";
   }

   /*

   This code will not compile, which is why I have commented it out.
   Why will it not compile ?

   if(intArray2 != intArray3)
   {
	   cout << "\nintArray2 != intArray3 \n";
   }

   */

   // For fun, let's dynamically create and destroy another intArray object

   auto * ptr = new Array<>;
   delete ptr;

   // How many objects do we have now?
   ObjectCount = Array<int, 5>::getArrayCount();
   cout << "\nThe current number of Array<int, 5> objects instantiated is: " << ObjectCount << '\n';

   ObjectCount = Array<string, 7>::getArrayCount();
   cout << "\nThe current number of Array<string, 7> objects instantiated is: " << ObjectCount << '\n';

   return 0;
} // end main

/**************************************************************************
 * (C) Copyright 1992-2005 by Deitel & Associates, Inc. and               *
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
