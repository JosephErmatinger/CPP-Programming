// Percentage.cpp by Joe Ermatinger 11/1/2018 

// Input: Keyboard
//   Output: Screen
//   This program calculates the percentage correct after the user inputs
//   the number of points received and points possible from the keyboard.
//   A count of the number of students processed will be accumulated, which will 
//  then be dispayed at the end.
   
//   This program will include separate functions for: heading, input,
//   processing, output and final output after it has be restructured.


#include <iostream>
#include <iomanip>

using namespace std;


//*************************************************************************************************
	// Prototypes 
void printHeading (void);
int getPtsR (void);
int getPtsP (void);
float calcPercent(int, int);
void printPts (int, int, float);
char getAgain (void);
void printFinal (void);

//*************************************************************************************************
	// Global Variables 
int count = 0;

//*************************************************************************************************
	// Start of Main 

int main (void)
{
	// Declaration 
	int ptsreceived=0, ptspossible=0;
	float percentage=0.0f;
	char again = 'Y';
	
//*************************************************************************************************
	// Heading Section 
	printHeading(); // call output function 
	
//*************************************************************************************************
	// Begin Loop 
	while (again == 'Y' || again == 'y')
	{
//*************************************************************************************************		
	// Input Section
		ptsreceived = getPtsR(); // call input function
		ptspossible = getPtsP(); // call input function
		
//*************************************************************************************************		
	// Processing Section 
		percentage = calcPercent(ptsreceived, ptspossible); // call process function

//*************************************************************************************************
	// Output Section 
		printPts(ptsreceived, ptspossible, percentage); // call output function 

//*************************************************************************************************	
	// Count and Loop 
		again = getAgain(); // call input function 
			
	}
//*************************************************************************************************	
	// Print Final Count and End Program 
		printFinal(); // call output function
	
//*************************************************************************************************
	// End of Main 
	return 0;
}

//*************************************************************************************************
	// Define printHeading Function 
	
	void printHeading (void)  
{
		cout << " Percentage Calculator by Joe Ermatinger" << endl << endl;
}
//*************************************************************************************************
	// Define getPtsR Function 
	int getPtsR (void)
{	
		int PtsR = 0;
		cout << endl << " Enter the number of points received ";
		cin >> PtsR;
			return PtsR;
}	
//*************************************************************************************************
	// Define getPtsP Fucntion 
	int getPtsP (void)
{	
		int ptsP = 0;
		cout << " Enter the number of points possible ";
		cin >> ptsP;
			return ptsP;
}
//*************************************************************************************************
	// Define calcPercent Function 
	float calcPercent (int outPtsR, int outPtsP)
{
		float cPercent = 0.0f;
		cPercent = (float) outPtsR / (float) outPtsP * 100.0f;
			return cPercent;
}
//*************************************************************************************************
	// Define printPts Function 
	void printPts (int outPtsR, int outPtsP, float outPercent)
{
		cout << endl << endl << " Student received " << outPtsR << " points out of " << outPtsP << " possible";
		cout << endl << endl << endl << " The percentage is " << setprecision(2) << fixed << showpoint << outPercent << endl << endl;
}		
//*************************************************************************************************//
	// Define getAgain Function
	char getAgain (void)
{	
		char localAgain;
		count++;
		cout << " Would you like to enter another student's points? "; 
		cin >> localAgain;
			return localAgain;
}	
//*************************************************************************************************
	// Define printFinal Function 
	void printFinal (void)
{	
		cout << endl << endl << " Total students processed: " << count; 
}