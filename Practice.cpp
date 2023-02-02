
// Test to make sure C++ environment is good

#include <iostream>
using namespace std;

int main (void)
{
	// input prompt
	cout << "Enter two integers: ";
	
	// declaration and input of 2 variables
	int x, y;
	cin >> x >> y;
	
	// Output of values using multiple "arguments"
	cout << "The sum of " << x << " and " << y
		 << " is " << x + y << '\n';
		 
	// Declaration of i within for's initialization
	for (int i = 0; i <=5; i++)
		cout << i << '\n';

	return 0;
}	

