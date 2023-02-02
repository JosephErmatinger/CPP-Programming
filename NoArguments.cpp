
// NoArguments.cpp by Joe

// functions that take no arguments
#include <iostream>
using namespace std;

void f1 ();
void f2 (void);

main (void)
{
	f1();
	f2();
	
	return 0;
}
void f1()
{
cout << "Function f1 takes no arguments\n";
}	
void f2(void)
{
cout << "Function f2 also takes no arguments\n";
}

	