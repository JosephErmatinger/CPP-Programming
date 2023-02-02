// SteamManipulate.cpp by Joe
// This program illustrates the use of setprecision(), setw(),
// and fixed and showpoint manipulators

#include <iostream>
#include <iomanip>		// allows use of stream manipulators that format
										// streams of data
										
using namespace std;
int main ()
{
 double amount = 0.0;
 
 cout << "Enter the amount  ";
 cin >> amount;
 
 // doing some crazy math to create a number with many decimal positions
 amount *= 1.069786;
 
 // Bare variable, no modifications on output
 cout << endl << "Bare variable in default mode" << endl;
 cout << amount << endl << endl;
 
 float fValue;
 fValue = 1.2222222222222222f;
 cout << fValue << endl;
 fValue = 111.22222222222222f;
 cout << fValue << endl;
 fValue = 123456.77777777f;
 cout << fValue << endl << endl << endl;
 
 // variable with setprecision()
 cout << "setprecision in default mode - that is with no notation specified" << endl;
 cout << "2 digit precision in default mode" << endl;
 cout << setprecision(2) << amount << endl << endl;
 cout << "6 digit precision in default mode" << endl;
 cout << setprecision(6) << amount << endl << endl;
 cout << "4 digit precision in default mode" << endl;
 cout << setprecision(4) << amount << endl << endl;
 cout << "10 digit precision in default mode" << endl;
 cout << setprecision(10) << amount << endl << endl;
 cout << "8 digit precision " << endl;
 cout << setprecision(8) << amount << endl << endl;
 
 // variable with setprecision and setw
 cout << "8 digit precision in a field width of 20" << endl;
 cout << setprecision(8) << setw(20) << amount << endl << endl;
 
 // setw only applies to next item in stream
 cout << setw(15) << "this" << "that" << "another thing" << endl;
 
 // variable rounded to 2 decimal places
 // showpoint - forces the decimal point and trailing zeros
 // fixed - forces fixed point output, not scientific notation
 cout << "rounded to 2 places because of the combining setprecision with fixed notation"
	  << endl;
 cout << setprecision(2) << fixed << showpoint << amount
	  << " and now here is fValue " << fValue << endl << endl;
 
 return 0;
} 
	  