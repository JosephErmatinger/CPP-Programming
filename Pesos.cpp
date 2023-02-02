// Pesos.cpp created by: Joe Ermatinger 11/27/2018 CIS185

#include <iostream>
#include <iomanip>
#define CONVERT 20.47f
using namespace std;

int main()
{
	// Variable Declarations
	double numUSD = 0.0;
	double numPesos = 0.0;
	
	// Display Heading
	cout << " US Dollars to Pesos Conversion by Joe Ermatinger" << endl << endl << " US Dollar Amount: ";
	
	// Input Section
	cin >> numUSD;
	
	// Processing Section
	numPesos = CONVERT * numUSD;
	
	// Display USD-Peso Conversion
	cout << endl << " " << setprecision (2) << fixed << showpoint << numUSD << " US Dollar Amount = " 
	<< setprecision(2) << fixed << showpoint << numPesos << " Peso Amount" << endl;

	// End Program
	return 0;	
}

