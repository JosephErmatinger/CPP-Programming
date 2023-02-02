/* ReadMyFile.cpp Created by: Joe Ermatinger 12/01/2018   
   Input: Ermatinger.txt file
   Output: Screen
   This program reads multiple data types and strings. Input comes from the
   "Ermatinger.txt" data file that was created in the "FileCreation.c" application.
   Input will ccome from the text file using fscanf() for numbers and fixgets() for 
   strings. Output will be displayed to the screen using cout. For each record
   the increase in value or markup is calculated by dividing current price by initial 
   price. All of the records created will be displayed in a columnar report with headings.
   A total number of records and the sum of all records current price will be displayed 
   when the program finishes.*/ 

#include <iostream>
#include <iomanip>      
#include <ctime>
#include "fixgets.h"
using namespace std;        

//structure declaration
typedef struct {
	int id;
	int age;
	float initialPrice;
	float currentPrice;
	char botanicalName[25];
	char cultivar[25];
	char commonName[25];
	char classification[25];
} Record;

int main (void)
{													// begin main
	// variable declarations
	Record record;
	int numRecord = 0;
	float totalValue = 0.0f;
    time_t sec_since_1970;
	
	// function will produce # of seconds since 1970
	time(&sec_since_1970);
	
	// file pointer
	FILE * filePointer;
	
	// display heading including time and date stamp
	cout << "FileCreation & ReadMyFile Application by Joe Ermatinger 11/28/2018 CIS185 " << endl << ctime(&sec_since_1970) << endl;

	// if file is open read if not terminate
	if ((filePointer = fopen ("InOutFile.txt", "r")) == NULL ) {
		printf( "File could not be opened\n"); 
	}
	else { 																	// begin else
		
		// display columnar report headings
		cout << setw(5) << right << "ID";
		cout << setw(5) << "Age";
		cout << setw(15) << "Initial Price";
		cout << setw(15) << "Current Price";
		cout << setw(10) << "Markup";
		cout << setw(10) << " ";
		cout << setw(30) << left << "Botanical Name";
		cout << setw(30) << "Cultivar";
		cout << setw(30) << "Common Name";
		cout << setw(30) << "Classification" << endl;
		cout << setfill('-') << setw(200) << "" << endl;
		cout << setfill(' ');
		 
		
		while ( !feof(filePointer))											// while file pointer hasn't reached end of file
		{
			record.id = -1;												    // don't double print the last record if we didn't read any new data
			
			// get input from text file
			fscanf(filePointer, "%d\n", &record.id);
			fscanf(filePointer, "%d\n", &record.age);
			fscanf(filePointer, "%f\n", &record.initialPrice);
			fscanf(filePointer, "%f\n", &record.currentPrice);
			fixgets(record.botanicalName, 25, filePointer);
			fixgets(record.cultivar, 25, filePointer);
			fixgets(record.commonName, 25, filePointer);
			fixgets(record.classification, 25, filePointer);
			
			if (record.id == -1) 											// don't double print the last record if we didn't read any new data
				break;
			// print columnar report to screen	
			cout << setprecision(2) << showpoint << fixed;
			cout << setw(5) << right << record.id;
			cout << setw(5) << record.age;
			cout << setw(15) << record.initialPrice;
			cout << setw(15) << record.currentPrice;
			cout << setw(10) << noshowpoint << setprecision(0) << (record.currentPrice / record.initialPrice * 100) << "%";     // value calculation
			cout << setw(9) << " ";
			cout << setw(30) << left << record.botanicalName;
			cout << setw(30) << record.cultivar;
			cout << setw(30) << record.commonName;
			cout << setw(30) << record.classification << endl;
			numRecord++;																				// increment the number of records
			totalValue += record.currentPrice;								    						// add current price of all records
		}																								// end while
		
		cout << endl;
		cout << "Number of Records: " << numRecord << endl;                     						// print total number of records
		cout << showpoint << setprecision(2) << fixed << "Total Value: $" << totalValue << endl;		// print the total value

		fclose(filePointer);																			// close file
	}																									// end else
	return 0;																							// end program
}																										