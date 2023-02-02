//   Grader.c Created by: Joe Ermatinger 11/27/2018 CIS185
//   Input: Keyboard
//   Output: Screen
//   This program calculates the number of questions a user answered correctly
//   on a multiple-choice quiz along with their percentage and letter grade.
//   Input will come from the keyboard using cin. Output will be displayed on 
//   the screen using cout. The user will be prompted to answer each question 
//   with the uppercase letters A, B, C, D, and E. The total number of correct and 
//   incorrect answers will be accumulated. The number of correct answers will be used 
//   to assign a percentage which will then be used to assign a letter grade. The total 
//   number of incorrect answers will be used to warn the user if they make too many mistakes. 
//   A do while loop will be used to validate user input to ensure they enter only the uppercase 
//   letters A, B, C, D, and E. When a wrong answer has been given, the correct answer to that question 
//   will be displayed. Once a user has answered more than three questions incorrectly, a warning will 
//   appear. A progressively stronger worded warning will appear every two mistakes thereafter. The number 
//   of questions a user has answered correctly are displayed along with their percentage and letter grade
//   are displayed when the loop terminates. 

#include <iostream>
#include <iomanip>
using namespace std;

// Prototypes 
char getGrade(float);
int validAnswer(char);
char getAnswer(int);

int main()
{
	
	// Variable Declarations
	int ncorrect = 0;
	int i = 0;
	float percentage = 0.0f;
	int incorrect = 0;
	
	// Array Declarations
	char key [10] = {'A', 'B', 'C', 'D', 'E', 'A', 'C', 'B', 'B', 'E'};
	char answers [10];

	// Display Heading
	cout << "Quiz Application by Joe Ermatinger CIS185" << endl << endl;
	cout << "Enter your answers below. Choices are A, B, C, D, or E. Use uppercase!" << endl;
	
	// Begin Main Loop
	for(; i < 10; i++){
		
		char answer = getAnswer(i + 1); 
		answers[i] = answer;
		
		if(answer == key [i]){
			ncorrect ++;                                                            // Increment Correct
		}
		// Incorrect Output Section
		else {
			cout << "\tWrong answer! The correct answer is " << key [i] << endl;
			incorrect ++;                                                           // Increment Incorrect
			if(incorrect == 3){
				cout << "\a\tTake your time & be more careful!" << endl; 
			}
			else if(incorrect == 5){
				cout << "\a\tYou call that trying? You can do better than that!" << endl; 
			}
			else if(incorrect == 7){
				cout << "\a\tIs that really the best you can do? Try harder!" << endl;
			}
			else if(incorrect == 9){
				cout << "\a\tAt least you didn't get them all wrong, yet. Try again!" << endl;		
			}		
		}	
		cout << endl;
	}
	percentage = ((float) ncorrect / 10.0f) * 100.0f;                                                                           // Calculate Percentage
	
	// Display Final Grade
	cout << endl << "Student got " << ncorrect << " out of 10 correct" << endl << endl;                                         // Display Number Correct
	cout << "The percentage correct is " << setprecision(2) << fixed << showpoint << percentage << endl << endl;                // Display Percentage
	cout << "The letter grade is " << getGrade(percentage);                      												// Display Grade 
}
// Define getGrade Function
char getGrade(float percentage){
	if      (percentage < 60.0f)
		{	
			return 'E';
		}
		else if (percentage < 70.0f)
		{
			return 'D';
		}	
		else if (percentage < 80.0f)
		{
			return 'C';
		}
		else if (percentage < 90.0f)
		{
			return 'B';
		}
		else 
		{
			return 'A';
		}
}
// Define validAnswer function
int validAnswer(char answer){
	return answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D' || answer == 'E';
}
// Define getAnswer function
char getAnswer(int questionNum){
char answer;	
	do {
			cout << "What is your answer to question # " << questionNum << " ";                           // Prompt and Input Answer
			cin >> answer;
			if (!validAnswer(answer))
			{
				cout << "\tAnswer invalid! Choices are A, B, C, D, or E. Use uppercase!" << endl;         // Display Answer Invalid
			}		
		} while (!validAnswer(answer));
		return answer;
}
