/* -----------------------------------------------------------------------------

FILE:              Math_Testor.cpp
DESCRIPTION:       Program that will test user based on 5th grade level arithmatic. 
COMPILER:          MinGW  C++ compiler
NOTES:             N/A

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Isaiah McLain      2019-10-29         1.0, code written out with header for file
									  and function as well as program code. 
Isaiah McLain      2019-10-31 		  1.1, Added interactive ability for student to
									  enter answer and program checks if it is wrong
									  or right and made the program more modular. 
Isaiah McLain      2019-10-31		  1.2, Made program even more modular and also 
									  created a functioning menu with a working quit option,
									  and problem options with pass by reference.
Isaiah McLain      2019-11-5          1.3, Made minor edits to text output and format. 
Isaiah McLain      2019-11-5          2.0, Edited program to fit the new project 2 requirements
									  including updated menu, display time, difficulty level added,
									  as well as a function that gets the name of the user. 
Isaiah McLain      2019-11-7		  2.1, Added addition introduction to main which gets user's information
									  and program run time. Removed get name of user function and just added it to
									  main. 
Isaiah McLain      2019-11-7		  2.2, Added answers correct counter and percentage calculator as well as 
									  multiple choice question format and function. 
Isaiah McLain      2019-11-7          2.3, Fixed logic issues in answer correct counter as well as a time keeper for
									  every problem attempted function. 
Isaiah McLain      2019-11-12         2.2, Added array_checker function that will check each element of the array to 
									  make sure no numbers are repeating in the answers. Added if statements to Multiple
									  Choice function that lets the answers be within a proper range of the difficulty chosen. 
Isaiah McLain      2019-11-14		  2.3, Added formating for outputs so it looks nice as well as file output. Got rid of array
									  checker function as it was not working properly and added a do while loop to function where 
									  answer never repeats twice. 
----------------------------------------------------------------------------- */

#include <iostream>  //Enables use of cout and cin operators 
#include <iomanip>   //Enables program to function 
#include <string>    //Allows use of string functions
#include <ctime>     //Allows use of time stamping program 
#include <fstream>   //Enables the use of opening and outputting contents of program to file

using namespace std;

const string PROGRAMMER_NAME = "Isaiah McLain";		// Global constant
//Prototypes 
void Number_Generator(int&, int&, int);  //Initilizes the creation of two random numbers function 
void Difficulty_Chooser(int&, ostream&); //Initilizes the difficulty chooser function 
int Random_Addition(int, int&, char&, ostream&);  //Initilizes addition of two random numbers function
int Random_Subtraction(int, int&, char&, ostream&); //Initilizes the subtraction of two random numbers function
int Random_Multiplication(int, int&, char&, ostream&); //Initilizes the multiplication of two random numbers function 
int Random_Division(int, int&, char&, ostream&);    //Initilizes the division of two random numbers function
int Answer_Checker(char&, int&, int, ostream&);  //Initilizes Answer_Checker function with the two arguments it 
							   //needs to check
char Get_Choice();      //Initilizes the Get_Choice function
void Multiple_Choice(int, int&, char&, int, ostream&);  //Initilizes the Multiple_Choice function 
void Time_Keeper(ostream&); //Initilizes the Time Keeper function 

const int SIZE = 4;  //Const int for array for multiple choice function 						
/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Function that will call all the other functions of the program.  
RETURNS:           0
NOTES:             Holds program open through a loop and works coherently with Get_Choice
				   to let the menu function properly. 				
------------------------------------------------------------------------------- */
int main()
{
	char (choice); //Initilizes the choice variable from Get_Choice
	bool loop;   //Sets var loop to be a bool value
	int difficulty;  //Holds the difficulty variable from Difficulty Chooser function
	int answers[SIZE]; //Holds array of answers from Multiple Choice function 
	int answer_slot;   //Holds true answer slot from Multiple Choice function 
	char user_choice;  //Holds user's choice from multiple choice function 
	time_t seed = time(0);  //Sets variable seed to the time c++ was made
	srand(seed); //Generates random numbers 

	ofstream outputFile; //Sets file call 
	

	loop = 1; //Set loop value to 1 so loop will continue on until changed. 
	
	string fullname; //String variable that will hold user's first and last name 
	cout << "Please enter your first and last name: "; //Prompts user for first and last name
	getline(cin, fullname); //Gets user's first and last name. 
	cout << endl; 
	
	string filename = fullname + "_results.txt"; //Adds _results.txt to end of user's file name
	
	// For loop that runs through user's name and if space is detected, filled with _ 
	for (int i = 0; i < filename.length(); i++) 
	{
		if (filename[i] == ' ')
		{
			filename[i] = '_';
		}
	}

	outputFile.open(filename.c_str()); // Opens the outputFile set with the user name variable
	
	cout << "Student Name: " << fullname << endl; //Displays students full name. 
	outputFile << "Student Name: " << fullname << endl;
	cout << "Program start: " << ctime(&seed); //Displays the current time that the program was run to the user
	outputFile << "Program start: " << ctime(&seed);
	cout << "Random  seed: " << seed; //Displays the random seed generated for the program 
	outputFile << "Random  seed: " << seed << endl;;
	cout << endl << endl; 

	Difficulty_Chooser(difficulty, outputFile); //Calls Difficulty function that lets user choose difficulty level 

	

	while (loop) //Loop that will hold open menu and let user access other funtions. 
	{
		choice = Get_Choice();
		switch(choice)
		{
			case 'a': //Lets user access addition 
				Random_Addition(difficulty, answer_slot, user_choice, outputFile); //Calls Random_Addition function 
				break;
			case 'b': //Lets user access subtraction
				Random_Subtraction(difficulty, answer_slot, user_choice, outputFile); //Calls Random_Subtraction function 
				break; 
			case 'c': //Lets user access multiplication 
				Random_Multiplication(difficulty, answer_slot, user_choice, outputFile); //Calls Random_Multiplication function 
				break;
			case 'd': //Lets user access division 
				Random_Division(difficulty, answer_slot, user_choice, outputFile); //Calls Random_Division function 
				break;
			case 'q': //Lets user quit program
				cout << "Thank you for using the program.\n"
				"Goodbye." << endl << endl; 
				outputFile << "Thank you for using the program.\n"
				"Goodbye." << endl << endl; 
				loop = 0; //Sets loop vvariable to 0 so program quits. 
				break;
		}
	}
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";  //Displays programmer name and program compile date. 
	outputFile << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	outputFile << __DATE__ << "  " __TIME__ << endl;
	cout << endl;
	outputFile << endl;

	outputFile.close(); //Closes file 

	system("pause"); //Pauses system 

	return 0; //Returns value 0 
}

/* -----------------------------------------------------------------------------
FUNCTION:          Difficulty_Chooser
DESCRIPTION:       Function that prompts user for the difficulty they want.   
RETURNS:           Nothing (void) 
NOTES:             Bases numbers size used for equation off of this function.
------------------------------------------------------------------------------- */
void Difficulty_Chooser(int &difficulty, ostream& outputFile)
{
	cout << "Please enter the difficulty you would like to try" << endl; //Prompts user for difficulty choice
	cout << "1. 1 digit" << endl; //Next few statements tells user what the difficulty level entails 
	cout << "2. 2 digits" << endl;
	cout << "3. 3 digits" << endl; 
	cout << "4. 4 digits" << endl;
	cout << "5. 5 digits" << endl;
	
	
	cin >> difficulty; //Stores users difficulty choice 
	if (!isdigit(difficulty)) {
	cout << "Please enter 1-5 only: " << endl; //Specifies to user that they need to only enter didgits 1-5
	}
	else {
	cout << "Difficulty #: " << difficulty << endl; //Confirms the difficulty user choose. 
	outputFile << "Difficulty #: " << difficulty << endl;
	cout << endl;
	outputFile << endl;
	}
}

/* -----------------------------------------------------------------------------
FUNCTION:          Get_Choice 
DESCRIPTION:       Function that displays the menu to the user and prompts them to choose a problem.  
RETURNS:           0
NOTES:             Will return choice to main and allow the program to then run based on user's 
				   desicion. 
------------------------------------------------------------------------------- */
char Get_Choice()
{
	char choice;   //Initilzies user's choice holding variable 
	cin.clear();  //Stops program from looping infinetly if user inputs improper value.

	cout << "          ARITHMETIC PRACTICE PROGRAM" << endl << endl;   //Menu that prompts user for choice 
	cout << "Welcome to the Math Skills Practice Program." << endl << endl;
	cout << "This program allows you to practice your math skills." << endl << endl;
	cout << "Choose what to practice in the menu shown below." << endl << endl; 
	cout << "---------------------------------------------------------" << endl;
	cout << "                ARITHMETIC PRACTICE PROGRAM" << endl;
	cout << "                       MAIN   MENU" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "                a.   Addition" << endl;
	cout << "                b.   Subtraction" << endl;
	cout << "                c.   Multiplication" << endl;
	cout << "                d.   Division" << endl;
	cout << "                q.   Quit the program" << endl << endl;
	cout << "---------------------------------------------------------" << endl << endl;
	cout << "Enter your choice [ a b c d q ]: "; 
	cin >> choice;     //Stores user's choice 
	cout << endl; 

	choice = tolower(choice); //In case user inputs upper case letters 

	/*Logic that will enable program to recognize incorrect input and tell the user to input a
	  correct value */
	if (choice >= 'a' && choice <= 'd' || choice == 'q')
	{
		cout << "You entered: '" << choice << "', that is correct input." << endl << endl;
	}
	else
	{
		cout << "You did not enter 'a', 'b', 'c', 'd' or 'q'." << endl; //Only used if user inputs
		cout << "Please return the program." << endl << endl;	  // a incorrect number
	}

    return choice; //Returns user's choice to main which enables menu to function 
}

/* -----------------------------------------------------------------------------
FUNCTION:          Multiple_Choice()
DESCRIPTION:       Function that will create random numbers for the multiple choice questions
				   as well as assign the right answer to one of the letters. 
RETURNS:		   user_choice
NOTES:             N/A				
------------------------------------------------------------------------------- */
void Multiple_Choice(char &user_choice, int &answer_slot, int answer, int difficulty, ostream& outputFile)
{
	int answers[SIZE]; //Array that will hold the true and randomized answers
	answer_slot = rand() % 5; //Sets this variable to hold 5 spaces 
	int letter = 97; //Initizlizes ASCII code for 'a' into variable letter

	/*Runs a loop that gives 5 answers within a set value range of the true answer, the bigger the number, the bigger the range of answers.
	This is done because it doesn't make sense for difficulty 1 to have answers within a 99 range of numbers, however this does make sense 
	for two digit numbers and so on.  The while loop runs trhough and makes sure the right answer never repeats twice*/ 
	for (int counter = 0; counter < 5 ;counter++)  
	{
		do
			{
			if (difficulty == 1)
			{
				answers[counter] = answer + (rand() % 10);
			}
			if (difficulty == 2)
			{
				answers[counter] = answer + (rand() % 20);
			}
			if (difficulty == 3)
			{
				answers[counter] = answer + (rand() % 100);
			}
			if (difficulty == 4)
			{
				answers[counter] = answer + (rand() % 200);
			}
			if (difficulty == 5)
			{
				answers[counter] = answer + (rand() % 2000);
			}
		} 
		while (answers[counter] == answer);
	}
	
	answers[answer_slot] = answer; //Reserves one of the slots of a-e for the real answer 
	
	/*Loop that displays all the answers along with the assoicated letter to choose from which is connected
	to one of the array values. */
	for (int counter = 0; counter < 4 ; counter++ )
	{
		string spaces = "    ";
		cout << "(" << (char) letter << ")" << setw(8-answers[counter]) << spaces << answers[counter] << endl; 
		outputFile << "(" << (char) letter << ")" << setw(8-answers[counter]) << spaces << answers[counter] << endl;
		(int) letter; 
		letter++;
	}
	cout << "(" << 'e' << ")" << "NONE OF THE ABOVE" << endl; //Special case which will always be none
																		  //of the above but will potentially be the 
																		  //the right answer. 
	outputFile << "(" << 'e' << ")" << "NONE OF THE ABOVE" << endl;
	
	cin >> user_choice;  //Gets users answer
	cout << endl;
	outputFile << endl; 

}

/* -----------------------------------------------------------------------------
FUNCTION:          Number_Generator()
DESCRIPTION:       Function that will create random numbers for other funtions when called.   
RETURNS:           nothing (void)
NOTES:             N/A				
------------------------------------------------------------------------------- */
void Number_Generator(int &value_1, int &value_2, int difficulty)
{
	//int difficulty;  //Variable that holds difficulty level user chooses 
	int Min_Value;   //Variable that holds range of numbers dependent on difficulty level, lowest range
	int Max_Value;   //Variable that holds range of numbers dependent on difficulty level, highest range	
	int range;      //Variable that will hold the range of the max and min values for srand. 
	int range_1;    //Variable that will hold the range of the max and min values for srand for 2nd value. 


	//If logic that runs to determine max and min variables based off the user's difficulty choice.
	
	if (difficulty == 1)
	{
		Min_Value = 1;
		Max_Value = 9;
	}
	
	if (difficulty == 2)
	{
		Min_Value = 10; 
		Max_Value = 99;
	}

	if (difficulty == 3)
	{
		Min_Value = 100;
		Max_Value = 999;
	}
	
	if (difficulty == 4)
	{
		Min_Value = 1000;
		Max_Value = 9999;
	}

	if (difficulty == 5)
	{
		Min_Value = 10000;
		Max_Value = 99999;
	}

	range = (rand() % (Max_Value - Min_Value + 1)) + Min_Value; //Equation that sets range for srand 
	range_1 = (rand() % (Max_Value - Min_Value + 1)) + Min_Value; //Equation that sets range for srand for
	
	value_1 = range; //Sets first range value to value_1 saving the random number for the addition equation. 
	value_2 = range_1;//Sets second range value to value_2 saving the random number for the addition equation. 

}

/* -----------------------------------------------------------------------------
FUNCTION:          Random_Addition 
DESCRIPTION:       Function that will add two random numbers together. 
RETURNS:           0
NOTES:             Shows two generated numbers being added and will not show user answer until
				   they hit enter so that they can practice their addition. 
------------------------------------------------------------------------------- */
int Random_Addition(int difficulty, int &answer_slot, char &user_choice, ostream& outputFile) 
{ 
	int answer;     //Variable that will hold the answer of the two added srand values. 
	int value_1;    //Variable that will hold and save the set srand value of the program
	int value_2;    //Variable that will hold and save the set srand value of the program
	Number_Generator(value_1, value_2, difficulty); //Calls number generator 
	
	answer = value_1 + value_2;  //Runs equation that will add two generated numbers 
	Time_Keeper(outputFile); //Calls the time keeper function 
	cout << endl; 
	outputFile << endl;

	string spaces = "    ";
	cout << "Solve:" << endl;
	outputFile << "Solve:" << endl;
	cout << " "  << setw(8-value_1) << spaces << value_1 << endl; //Displays first random number
	outputFile  << " " << value_1 << endl;
	cout <<  "+" << setw(8-value_2) << spaces << value_2 << endl; //Displaus second random number 
	outputFile <<  "+" << value_2 << endl; 
	string space = "  ";
	cout  << setw(8-value_1) << space << "-------" << endl;
	outputFile << setw(8-value_1) << space << "-------" << endl;
	
	Multiple_Choice(user_choice, answer_slot, answer, difficulty, outputFile); //Calls Multiple Choice function that will display answers 
	
	Answer_Checker(user_choice, answer_slot, answer, outputFile);  //Calls Answer Checker function that will determine if answer is correct.
	
	cout << "Answer: " << answer << endl;     //Displays answer 
	outputFile << "Answer: " << answer << endl;

	return 0; 
}

/* -----------------------------------------------------------------------------
FUNCTION:          Random_Subtraction 
DESCRIPTION:       Function that will subtract two random numbers. 
RETURNS:           0 
NOTES:             Shows two generated numbers being subtracted and will not show user answer until
				   they hit enter so that they can practice their subtraction. Will also not output
				   a negative answer
------------------------------------------------------------------------------- */
int Random_Subtraction(int difficulty, int &answer_slot, char &user_choice, ostream& outputFile) 
{ 
	int answer;     //Variable that will hold the answer of the two added srand values. 
	int value_1;    //Variable that will hold and save the set srand value of the program
	int value_2;    //Variable that will hold and save the set srand value of the program

	Number_Generator(value_1, value_2, difficulty); //Calls number generator 

	/*Runs logic to determine if value being subtracted is smaller than subtracting value.
	  If it is, the if statement will reverse the values in the order they are subtracted 
	  so no negative answers occur. */  
	Time_Keeper(outputFile); //Calls the time keeper function 
	cout << endl; 
	outputFile << endl;
	

	if (value_1 < value_2) //Switches display since numbers swapped 
	{
		answer = value_2 - value_1; //Swapped equation 
	
		cout <<  " " << value_2 << endl; //Displays first random number
		outputFile  << " " << value_2 << endl;
		cout << "-" << value_1 << endl; //Displaus second random number
		outputFile  << "-" << value_1 << endl;
		cout  << "-------" << endl;
		outputFile  << "-------" << endl;
		Multiple_Choice(user_choice, answer_slot, answer, difficulty, outputFile); //Calls Multiple Choice function that will display answers 
	}
	else //Leaves numbers and equation the same 
	{	
		answer = value_1 - value_2;  //Runs equation that will subtract two generated numbers 

		cout <<  " " << value_1 << endl; //Displays first random number
		outputFile  << " " << value_2 << endl;
		cout  << "-" << value_2 << endl; //Displaus second random number 
		outputFile  << "-" << value_1 << endl;
		cout  << "-------" << endl;
		outputFile  << "-------" << endl;
		Multiple_Choice(user_choice, answer_slot, answer, difficulty, outputFile); //Calls Multiple Choice function that will display answers 
	}
	
	Answer_Checker(user_choice, answer_slot, answer, outputFile);  //Calls Answer Checker function that will determine if answer is correct.
	
	if (value_1 < value_2) //Same logic but answer included 
	{
		cout << "Answer: " << answer << endl;     //Displays answer 
		outputFile << "Answer: " << answer << endl; 
	}
	else //Same logic but answer is included 
	{
		cout << "Answer: " << answer << endl;     //Displays answer 
		outputFile << "Answer: " << answer << endl; 
	}

	return 0; 
}

/* -----------------------------------------------------------------------------
FUNCTION:          Random_Multiplication  
DESCRIPTION:       Function that will multiply two random numbers. 
RETURNS:           0 
NOTES:             Shows two generated numbers being multiplied and will not show user answer until
				   they hit enter so that they can practice their multiplication.
------------------------------------------------------------------------------- */
int Random_Multiplication(int difficulty, int &answer_slot, char &user_choice, ostream& outputFile)
{	
	int answer;     //Variable that will hold the answer of the two added srand values. 
	int value_1;    //Variable that will hold and save the set srand value of the program
	int value_2;    //Variable that will hold and save the set srand value of the program

	Number_Generator(value_1, value_2, difficulty); //Calls number generator 

	answer = value_1 * value_2;  //Runs equation that will multiply two generated numbers 

	Time_Keeper(outputFile); //Calls the time keeper function 
	cout << endl; 
	outputFile << endl;
	

	cout << " " << value_1 << endl; //Displays first random number
	outputFile  << " " << value_1 << endl;
	cout  << "*" << value_2 << endl; //Displaus second random number 
	outputFile  << "*" << value_2 << endl;
	cout  << "-------" << endl;
	outputFile << setw(13) << "-------" << endl;
	
	Multiple_Choice(user_choice, answer_slot, answer, difficulty, outputFile); //Calls Multiple Choice function that will display answers 
	
	
	Answer_Checker(user_choice, answer_slot, answer, outputFile);  //Calls Answer Checker function that will determine if answer is correct.
	
	cout << "Answer: " << answer << endl;     //Displays answer 
	outputFile << "Answer: " << answer << endl;

	return 0; 
}

/* -----------------------------------------------------------------------------
FUNCTION:          Random_Division  
DESCRIPTION:       Function that will divide two random numbers. 
RETURNS:           0 
NOTES:             Shows two generated numbers being divide and will not show user answer until
				   they hit enter so that they can practice their division.
------------------------------------------------------------------------------- */
int Random_Division(int difficulty, int &answer_slot, char &user_choice, ostream& outputFile)
{
	int answer;     //Variable that will hold the answer of the two added srand values. 
	int value_1;    //Variable that will hold and save the set srand value of the program
	int value_2;    //Variable that will hold and save the set srand value of the program
	int dividend;   //Variable that will hold the value that is being divided 
	Number_Generator(value_1, value_2, difficulty); //Calls number generator 

	dividend = value_1 * value_2; //Runs equation that will divide two generated numbers to create the dividend
								  //eliminating remainder answers. 
	answer = dividend / value_1;  //Takes dividend divided by value 1 to get the answer

	Time_Keeper(outputFile); //Calls the time keeper function 
	cout << endl; 
	outputFile << endl;

	cout << dividend << " / " << value_1 << " =" << endl; //Displays divison equation 
	outputFile << dividend << " / " << value_1 << " =" << endl;
	cout << endl;
	outputFile << endl;
	Multiple_Choice(user_choice, answer_slot, answer, difficulty, outputFile); //Calls Multiple Choice function that will display answers 

	Answer_Checker(user_choice, answer_slot, answer, outputFile);  //Calls Answer Checker function that will determine if answer is correct.
	
	cout << "Answer: " << answer << endl;     //Displays answer 
	outputFile << "Answer: " << answer << endl;

	return 0; 
}

/* -----------------------------------------------------------------------------
FUNCTION:          Answer_Checker 
DESCRIPTION:       Function that will check users input and determine if answer is correct. 
RETURNS:           0 
NOTES:             N/A
------------------------------------------------------------------------------- */
int Answer_Checker(char &user_choice, int &answer_slot, int answer, ostream& outputFile) //Function arguments passed from any the math function and Multiple choice. 
{ 
	static int Total_Right = 0; //Holds user's total amount right of answers
	static int Total_Attempts = 0; //Holds user's total amount of attempts 
	static float Percent_Right; //Holds user's current percentage of right and wrong answers 
	
	/*Loop that gives user 3 (1 attempt already done) attempts to answer a problem and will keep track of every right 
	  and wrong answer leading it to calcualte a total percent correct. */
	for (int Attempts = 0; Attempts < 2; Attempts++) 
		{
				 
				if (user_choice == answer_slot + 'a') //Runs logic to see if user's choice or answer is = to programs answer
				{
					Total_Right++; //Adds 1 to total right 
					Total_Attempts++; //Adds 1 to total attempts 
					cout << "You chose: " << user_choice << endl; //Tells user their choice
					outputFile << "You chose: " << user_choice << endl;
					cout << "Congratulations!" << endl; //Tells user if it's correct 
					outputFile << "Congratulations!" << endl;
					break; //Ends loop no matter how many iterations left
				}
				else
				{
					if(Attempts == 0) Total_Attempts++; //Adds 1 to total attempts by recognizing user already attempted question once 
					cout << "You chose: " << user_choice << endl; //Tells user their choice 
					outputFile << "You chose: " << user_choice << endl;
					cout << "Wrong!" << endl; //Tells user if their wrong
					outputFile << "Wrong!" << endl;
					cin >> user_choice;  //Lets user input choice again 
					Total_Attempts++; //Adds 1 to total attempts 
				}	
		}
		
	Percent_Right = Total_Right / (float)Total_Attempts * 100; //Calculates user's percentage correct 
	cout << Total_Right << "/" << Total_Attempts << endl; //Displays users total right compared to total attempts 
	outputFile << Total_Right << "/" << Total_Attempts << endl;
	cout << "Your Score: % " << fixed << setprecision(3) << Percent_Right << endl; //Tells user if it's incorrect
	outputFile << "Your Score: % " << fixed << setprecision(3) << Percent_Right << endl;
	return 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Time_Keeper
DESCRIPTION:       Function that will display current time of problems attempt 
RETURNS:           Nothing(void)
NOTES:             N/A
------------------------------------------------------------------------------- */
void Time_Keeper(ostream& outputFile)
{
	time_t seed = time(0);  //Sets variable seed to the time c++ was made
	static int Total_Problems = 0; //Holds amount of problems attempted 
	Total_Problems++; //Adds 1 to total problems attempted every time function is called 
	cout << "Problem # " << Total_Problems << " " << ctime(&seed) << endl; //Displays time and problem number 
	outputFile << "Problem # " << Total_Problems << " " << ctime(&seed) << endl;
} 


			
															