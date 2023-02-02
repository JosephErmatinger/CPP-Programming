// overload.cpp by Joe
// using overloaded functions

#include <iostream>
using namespace std;

// Prototypes of functions with the same name
int square (int);
double square (double);

int main (void)
{
	int integer_x;
	double double_y;
	cout << "Enter an integer: ";
	cin >> integer_x;
	cout << "The square of integer " << integer_x << " is "
		<< square(integer_x) << '\n';
		
	cout << "Enter a double: ";
	 cin >> double_y;
	 cout << "The square of double " << double_y << " is "
		<< square(double_y) << endl;
		
	return 0;
}

// integer version
int square (int x)
	{
	return x * x;
	}

// double precision version
double square (double y)
	{
	return y * y;
	}