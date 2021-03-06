/* -----------------------------------------------------------------------------

FILE:              Calculator.cpp
DESCRIPTION:       Calculator for Project 1.
COMPILER:          MinGW  C++ compiler
NOTES:             N/A

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Isaiah McLain      2019-09-17         1.0, Function headers added, program 
									  code taken from Get_Choice_v6 as well
									  as Add_Numbers. Preprocessor drives added
									  as well as timestamp and programmer name. 
Isaiah McLain	   2019-09-19		  1.1, All programs linked together to perform
									  proper calculator and menu functions. 
									  Exit added to loop function as well as 
									  option to quit program. 
Isaiah McLain      2019-09-19		  2.0, Added another function called 
									  Get_x_and_y to program so in future 
									  versions the program can call upon this
									  function for user to enter x and y values
									  for any time of operation. Also made x and 
									  y global variables so all functions can call
									  upon these variables if needed. As is the
									  case with the Get_x_and_y function. 
Isaiah McLain      2019-09-19		  2.1, Fixed issue with bottleneck issue
									  where user inputs a value in Add_2_Numbers
									  function where any value thats not an integer
									  loops program infinetly with cin.clear in 
									  Get_Choice function. 
Isaiah McLain      2019-09-24		  3.0, Added more options to the menu function 
									  including power and roots
									  and cleaned up the user interface. Added Power_and_
									  Roots menu function. 
Isaiah McLain	   2019-09-26		  3.1, Added a square root function, 
									  called Sqaure_a_Number, and corrected
									  the menus UI and added more cases to the menu. 
Isaiah McLain	   2019-09-26		  4.0, Added global variable X_1 for my power 
									  and roots function. Also added additional 
									  while loop based function to run the Power_and
									  _Roots menu called Get_Choice_Menu2().
Isaiah McLain      2019-09-26		  4.1, Added ability for user to choose 
									  between floating and interger type numbers 
									  for basic +,-,*, and / equations through 
									  if statement and static.cast. 
Isaiah McLain      2019-09-26		  4.2 Added subtraction function and 
									  multiplication function. 
Isaiah McLain      2019-10-01         4.3, Added division function 
Isaiah McLain      2019-10-03         4.4, Added cube function as well as stream manipulation
                                      function called printFloat that edits my use of 
									  logic with the setprecision fixed manipulator. 
Isaiah McLain      2019-10-08         4.5, Added Cube_Any_Number function.
Isaiah McLain      2019-10-10         4.6, Added all Sq and Cube root functions as well as
                                      touched up menu and other functions presentations. 
Isaiah McLain      2019-10-17		  5.0, Everything working, let user quit directly from
									  either menu as well as return to main menu if wanted.
									  Reworked issue with division, forgot to cahnge logic 
									  from 'n' to 'i'. Also got rid of get_y_1 function and
									  replaced it with Get_x_and_y_1 function to make 
									  any root and any sqaure functions easier to run. 
----------------------------------------------------------------------------- */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

const string PROGRAMMER_NAME = "Isaiah McLain";		// Global constant

//Prototypes go here
char Get_Choice();					//Initilizes the Get_Choice function
char Get_Choice_Menu2();			//Initilizes the Get_Choice_Menu2 function
char Power_and_Roots();				//Initilizes the Power_and_Roots function
void Add_2_Numbers();				//Initilizes the Add_2_Numbers function
void Get_x_and_y();					//Initilizes the Get_x_and_y function 
void Square_a_Number();             //Initilizes the Square_2_Numbers function 
void Get_x_and_y_1();               //Initilizes the Get_x_and_y_1 function
void Get_x_1();						//Initilizes the Get_x function
void Subtract_2_Numbers();			//Initilizes the Subtract_2_Numbers function
void Multiply_2_Numbers();			//Initilizes the Multiply_2_Numbers function
void Divide_2_Numbers();            //Initilizes the Divide_2_Numbers function 
void Cube_a_Number();               //Initilizes the Cube_a_Number function 
void Cube_Any_Number();             //Initilizes the Cube_Any_Number function
void Squareroot_a_Number();         //Initilizes the Squareroot_a_Number function
void Cuberoot_a_Number();           //Initilizes the Cuberoot_a_Number function 
void Anyroot_by_Number();           //Initilizes the Anyroot_by_Number function

string printFloat(double number);   //Initlizes the PrintFloat function with its parameter

float x;							//Global variable
float y;							//Global variable
char data_type;                     //Global variable 
/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Calculator menu and with addition function. 
RETURNS:           0
NOTES:             Will let user choose choice of quitting program or doing
				   addition.  
------------------------------------------------------------------------------- */

int main() //Main loop function that will call menu function or quit program command. 
{ 
	int (choice); //Initilizes choice variable 
    bool loop; //Sets loop variable data type.
	loop = true; //Sets loop value to true so loop will always run 
	
	// Display the menu and welcome user to what the program
					 // is and does.
	cout << endl << endl; 
	cout << "WELCOME to the CALCULATOR PRACTICE PROGRAM." << endl << endl; 	
	cout << "This program allows you to practice your math skills." << endl << endl;
	cout << "Choose what you want to practice in the menu shown below." << endl << endl;
											   
	while(loop)   //Loop that will hold program open unless told otherwise
	{
		choice = Get_Choice();  //Loop calls menu function or Get_Choice to screen. 
		switch (choice)
		{
		case  'a' :         // If user chooses value a, program calls addition program to run. 
			Add_2_Numbers();
			break;
		case 'b' :          // If user chooses value b, program calls subtraction program to run.
			Subtract_2_Numbers();
			break;
		case 'c' :          // If user chooses c, calls multiplication function to run.
			Multiply_2_Numbers();
			break; 
		case 'd' :          // If user chooses d, calls division function to run 
			Divide_2_Numbers();
			break;
		case 'e' :          // If user choose e, calls a new menu with powers and square roots
			choice = Get_Choice_Menu2();
			if(choice == 'q')
				loop = false;
			break;
		case  'q' :        // If user chooses value q, program will end and give user timestamp
						   //as well as programmed by information.	
			loop = false;       //Sets value of loop variable to false so when while is ran again,
			break;			    //it tests loop value which now=false, and ends the loop.
		}
		
	}
	cout << "Thank you for using the program.\n"   
			"Goodbye." << endl << endl;

	cout << "Programmed by: " << PROGRAMMER_NAME << " -- "; //Displays programmers name and
	cout << __DATE__ << "  " __TIME__ << endl;           //time program was compiled
	cout << endl;

	system("pause");
	
	return 0; //Ends program
}

/* -----------------------------------------------------------------------------
FUNCTION:          Get_Choice()
DESCRIPTION:       Menu Program for calculator.
RETURNS:           Choice
NOTES:             Menu program that lets user choose several options for math
				   functions or to quit program. 
------------------------------------------------------------------------------- */
char Get_Choice()
{
	char choice;

	cin.clear();     //Will stop program from infinetly looping if user enters non-numerical
					 //value. 
														
	cout << "-------------------------------------------------------------" << endl;
	cout << "		          Main Menu" << endl;								 //Offers menu
	cout << "-------------------------------------------------------------" << endl;//and menu choices
	cout << endl << endl;
	
	cout << "a. Addition                                             (X+Y)" << endl;
	cout << "b. Subtraction                                          (X-Y)" << endl;
	cout << "c. Multiplication                                       (X*Y)" << endl;
	cout << "d. Division                                             (X/Y)" << endl;
	cout << "e. Powers & Roots" << endl;
	cout << "q. Quit the Program" << endl;
	cout << endl;
	
	cout << "-------------------------------------------------------------" << endl;           
	cout << "Enter your choice [ a - e, q ] :"	<< endl;		//Asks user to choose value
	cout << "-------------------------------------------------------------" << endl;
	cin >> choice;					//User inputs choice
	cout << endl << endl; 

			//We now have the user's input in "choice."
			// We are going to analyze the input with decison logic.

	choice = tolower(choice); //Makes it where if user enters upper case 
							  //letter the program will automatically make 
							  //it lower case before it enters the if-else
							  //statements.
	/*If else statement that runs values a, b, and c through statement and if those
	three values are used then the program will tell the user that is a correct input.
	If the user enters anyother value, the program tells the user that the value is
	incorrect and to rerun the program. */ 
	
	if (choice >= 'a' && choice <= 'e' || choice == 'q')
		cout << "You entered: '" << choice << "', that is correct input." << endl;
	else
	{
		cout << "You did not enter 'a', 'b', 'c', 'd' or 'e'." << endl; //Only used if user inputs
		cout << "Please return the program." << endl;		  // a incorrect letter
	}

	cout << endl;

	return choice;   //Returns variable user chooses to main function which then
					 //runs through the cases set in main. 
}

/* -----------------------------------------------------------------------------
FUNCTION:          Add_2_Numbers()
DESCRIPTION:       Adds 2 numbers inputted by user.
RETURNS:           Nothing (void) 
NOTES:             Will take an x and y value and then add them together 
				   giving the user an answer. 
------------------------------------------------------------------------------- */
void Add_2_Numbers()
{
    float sum;    

	Get_x_and_y();   //Calls the Get_x_and_y function to let user input x and y values. 
	
	sum = x + y;  //Defines addition equation. 
	cout << endl << endl;  //Spaces out program 
	
	cout << "    x + y = " << printFloat(x) << " + " << printFloat(y)  //Shows user math equation being ran. 
		 << " = " << printFloat(sum) << endl;             //Give user answer to their math problem. 
	cout << endl;
	 
} 

/* -----------------------------------------------------------------------------
FUNCTION:          Subtract_2_Numbers
DESCRIPTION:       Function for subtracting two numbers  
RETURNS:           Nothing (void)
NOTES:             Lets user subtract two diffrent numbers. 
------------------------------------------------------------------------------- */
void Subtract_2_Numbers()
{
	float diffrence;    

	Get_x_and_y();   //Calls the Get_x_and_y function to let user input x and y values. 
	
	diffrence = x - y;  //Defines subtraction equation. 
	cout << endl << endl;  //Spaces out program 
	
	cout << "    x - y = " << printFloat(x) << " - " << printFloat(y)  //Shows user math equation being ran. 
		 << " = " << printFloat(diffrence) << endl;             //Give user answer to their math problem. 
	cout << endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Multiply_2_Numbers
DESCRIPTION:       Function for multiplying two numbers  
RETURNS:           Nothing (void)
NOTES:             Lets user multiply two diffrent numbers. 
------------------------------------------------------------------------------- */
void Multiply_2_Numbers()
{
	float product;    

	Get_x_and_y();   //Calls the Get_x_and_y function to let user input x and y values. 
	
	product = x * y;  //Defines multiplication equation. 
	cout << endl << endl;  //Spaces out program 
	
	cout << "    x * y = " << printFloat(x) << " * " << printFloat(y) //Shows user math equation being ran. 
		 << " = " << printFloat(product) << endl;             //Give user answer to their math problem. 
	cout << endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Divide_2_Numbers
DESCRIPTION:       Function for dividing two numbers  
RETURNS:           Nothing (void)
NOTES:             Lets user divide two diffrent numbers. 
------------------------------------------------------------------------------- */
void Divide_2_Numbers()
{
	float quotient; //Initilizes quotient value where division is stored. 

	Get_x_and_y();  // Calls Get_x_and_y function to let user input x and y values.

	quotient = x / y;  //Equation for division 
	cout << endl << endl;
	
	cout << endl << endl; 
	
	if (tolower(data_type) == 'i')  //Runs logic that set quotient to an int value if user choose int notation. 
		{
			quotient = int (quotient); 
		}		
	if (y == 0)    //Runs logic that prevents user from dividing by zero because it is undefined. 
	{
		cout << "   x / y = " << x << " / " << y 
			 << " = " << "Undefined, please enter new y value.\n" << endl;
		cout << endl;
	}
	else
		cout << "    x / y = " << printFloat(x) << " / " << printFloat(y)  //Shows user math equation being ran. 
			 << " = " << printFloat(quotient) << endl;             //Give user answer to their math problem. 
		cout << endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Get_x_and_y()
DESCRIPTION:       Reusable code stub for calculator 
RETURNS:           Nothing (Void)
NOTES:             Lets user input x and y values for any kind of function created
				   in program. 
------------------------------------------------------------------------------- */
void Get_x_and_y()
{ 	
	//Asks user to choose data type
	cout << "Do you wish for your answer to be in decimal or non-decimal form?" << endl << endl; 
	cout << "Please choose F, for float form or I, for integer form." << endl << endl;
	cin >> data_type;
	

	cout << "Please input a numerical value for x and y: ";   //Asks user to input values. 
	cin >> x;                             //User puts in var x
	cin >> y;                             //User puts in var y
	
	if (data_type == 'i' || data_type == 'I' ) //Runs logic determing if user wants
	{										   //decimal or interger notation
		x = static_cast<int>(x);  //Forces any data entered by user to be an integer 
		y = static_cast<int>(y); 
	}
	
}

/* -----------------------------------------------------------------------------
FUNCTION:          Power_and_Roots()
DESCRIPTION:       Menu for Power and Root functions for calculator.  
RETURNS:           Choice_1
NOTES:             Lets user choose what type of square or root function
				   they want to perform. 
------------------------------------------------------------------------------- */
char Power_and_Roots()
{
	char choice_1; //Sets variable choice to char so user can select a letter in the menu. 
	
	cin.clear();     //Will stop program from infinetly looping if user enters non-numerical
					 //value. 
	
	cout << "-------------------------------------------------------------" << endl;
	cout << "                    Powers & Roots Menu" << endl;
	cout << "-------------------------------------------------------------" << endl;
	
	cout << "a. Square a number                                      (X^2)" << endl;    //Lets user choose amongst
	cout << "b. Cube a number                                        (X^3)" << endl;    //list of options based
	cout << "c. Raise to any power                                   (X^Y)" << endl;    //on what they want
	cout << "d. Square root a number                                 (X^1/2)" << endl;
	cout << "e. Cube root a number                                   (X^1/3)" << endl;
	cout << "f. Take any root                                        (X^1/Y)" << endl;
	cout << "m. Return to Main Menu" << endl;  //sends program back to Get_Choice()
	cout << "q. Quit the program" << endl; //Ends the program
	
	cout << "-------------------------------------------------------------" << endl;           
	cout << "Enter your choice [ a - f, m, q ] :"	<< endl;		//Asks user to choose value
	cout << "-------------------------------------------------------------" << endl;
	cin >> choice_1;					//User inputs choice
	cout << endl << endl; 
	
	choice_1 = tolower(choice_1);		//Makes it where if user enters upper case 
							  //letter the program will automatically make 
							  //it lower case before it enters the if-else
							  //statements.
	
	//Runs logic that determines what user chooses and returns that choice to switch function. 
	if (choice_1 >= 'a' && choice_1 <= 'f' || choice_1 == 'm' || choice_1 == 'q')     
		cout << "You entered: '" << choice_1 << "', that is correct input." << endl;  
	else
	{
		cout << "You did not enter 'a', 'b', 'c', 'd', 'f', 'm' or 'q'." << endl; //Only used if user inputs
		cout << "Please return the program." << endl;							 //a incorrect letter
	}

	cout << endl;
	
	return choice_1; //Returns user choice for Power Menu only
}

/* -----------------------------------------------------------------------------
FUNCTION:          Get_Choice_Menu2()
DESCRIPTION:       Holds Power_and_Roots function open.
RETURNS:           choice 
NOTES:             Holds open loop for Power and Roots menu as well as 
				   enables user to choose what they want within the menu
------------------------------------------------------------------------------- */
char Get_Choice_Menu2()
{
	//Initilizes choice variable 
	int (choice_1); //Initilizes choice_1 variable 
    bool loop; //Sets loop variable data type.
	loop = true; //Sets loop value to true so loop will always run 
	
	cout << "Welcome to the Powers & Roots Menu." << endl << endl;  //Introduces user to the menu
	cout << "This menu allows you to take powers and roots of a number." << endl << endl;

	while(loop)   //Loop that will hold program open unless told otherwise
	{
		choice_1 = Power_and_Roots();  //Loop calls Power_and_Roots menu to screen. 
		switch (choice_1)
		{
		case  'a' :         // If user chooses value a, program calls addition program to run. 
			Square_a_Number(); //Calls Square_a_Numbe function
			break;
		case 'b' :
			Cube_a_Number(); //Calls Cube_a_Number function
			break;
		case 'c' :
			Cube_Any_Number(); //Calls Cube_Any_Number function
			break;
		case 'd' :
			Squareroot_a_Number();   //Calls Squareroot_a_Number function 
			break; 
		case 'e' : 
			Cuberoot_a_Number(); //Calls Cuberoot_a_Number function 
			break;
		case 'f' :
			Anyroot_by_Number();  //Calls Anyroot_by_Number function 
			break;
		case 'm' :
			loop = false;       //Sets value of loop variable to false so when while is ran again,
			break;			    //it tests loop value which now=false, and ends the loop, returning user to main.
		case  'q' :         //If user chooses value q, program will end and give user timestamp
			loop = false;   //as well as programmed by information.
			break; 		 	
		
		}	
	}
	return choice_1; //Returns back to main menu 
}

/* -----------------------------------------------------------------------------
FUNCTION:          Square_a_Number()
DESCRIPTION:       Function for squaring a number.  
RETURNS:           Nothing (void)
NOTES:             Lets user square a number. 
------------------------------------------------------------------------------- */
void Square_a_Number()
{
	float square;  //Sets data type of float  	
	Get_x_1();  //Calls Get_x_1 function
	
	square = pow(x,2);  //Defines power to 2 equation. 
	cout << endl << endl;  //Spaces out program 

	cout << "   x^2 = " << x << "^2"  //Shows user math equation being ran. 
		 << " = " << square << endl;             //Give user answer to their math problem. 
	cout << endl;
}
/* -----------------------------------------------------------------------------
FUNCTION:          Cube_a_Number()
DESCRIPTION:       Function for cubing a number.  
RETURNS:           Nothing (void)
NOTES:             Lets user cube a number. 
------------------------------------------------------------------------------- */
void Cube_a_Number()
{
	float cube;  //Sets data type of float  	
	Get_x_1();  //Calls Get_x_1 function
	
	cube = pow(x,3);  //Defines power to 3 equation. 
	cout << endl << endl;  //Spaces out program 

	cout << "   x^3 = " << x << "^3"  //Shows user math equation being ran. 
		 << " = " << cube << endl;             //Give user answer to their math problem. 
	cout << endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Cube_Any_Number()
DESCRIPTION:       Function for cubing a number by any number.  
RETURNS:           Nothing (void)
NOTES:             Lets user cube a number by any number. 
------------------------------------------------------------------------------- */
void Cube_Any_Number()
{
	float cube;  //Sets data type of float  	
	//Get_x_1();  //Calls Get_x_1 function
	//Get_y_1();  //Calls Get_y_1 function
	Get_x_and_y_1();

	cube = pow(x,y);  //Defines power to any power equation. 
	cout << endl << endl;  //Spaces out program 

	cout << "   x^y = " << x << "^" << y  //Shows user math equation being ran. 
		 << " = " << cube << endl;             //Give user answer to their math problem. 
	cout << endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Sqrt_a_Number()
DESCRIPTION:       Function for square rooting a number. 
RETURNS:           Nothing (void)
NOTES:             Lets user square root a number. 
------------------------------------------------------------------------------- */
void Squareroot_a_Number()
{
	float square;  //Sets data type of float  	
	Get_x_1();  //Calls Get_x_1 function

	square = sqrt(x);  //Defines sqrt equation. 
	cout << endl << endl;  //Spaces out program 

	if (x < 0)
	{
		cout << "   x^(1/2) = " << x << "^(1/2)" 
			 << " = " << "Not a Real Number, please enter new x value.\n" << endl;
		cout << endl;
	}
	else 
		cout << "   x^(1/2) = " << x << "^" << "(1/2)"  //Shows user math equation being ran. 
			 << " = " << square << endl;             //Give user answer to their math problem. 
		cout << endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Cuberoot_a_Number()
DESCRIPTION:       Function for cube rooting a number. 
RETURNS:           Nothing (void)
NOTES:             Lets user cube root a number. 
------------------------------------------------------------------------------- */
void Cuberoot_a_Number()
{
	float cube;  //Sets data type of float  	
	Get_x_1();  //Calls Get_x_1 function

	cube = cbrt(x);  //Defines cube rt equation. 
	cout << endl << endl;  //Spaces out program 
 
	cout << "   x^(1/3) = " << x << "^" << "(1/3)" //Shows user math equation being ran. 
		 << " = " << cube << endl;             //Give user answer to their math problem. 
	cout << endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Anyroot_by_Number()
DESCRIPTION:       Function for square rooting a number by any number. 
RETURNS:           Nothing (void)
NOTES:             Lets user square root a number by any number of their choosing. 
------------------------------------------------------------------------------- */
void Anyroot_by_Number()
{
	float root;  //Sets data type of float  	
	//Get_x_1();  //Calls Get_x_1 function
   // Get_y_1();  //Calls Get_y_1 function 
	Get_x_and_y_1();

	root = pow(x , (1/y));  //Defines any root equation. 
	cout << endl << endl;  //Spaces out program 

	/* Runs logic that deterimines whether y is an even or odd number, if odd goes through 
	   if statement 1 that lets user be able to have a negative answer. If even, goes through 
	   else if statement that then determines if value of x is positive then value can be squared
	   or if val = negative then it is undefined. */
	
	if (int(y) % 2 )    
	{
		root = pow(abs(x), (1/y));  //x turned to positive to let program work properly
		if (x < 0)
		{
			x = -abs(x);   //answer and x then converted to negatives before being shown to user
			root = -abs(root);
			cout << "   x^(1/y) = " << x << "^" << "(1/" << y << ")" //Shows user math equation being ran. 
		         << " = " << root << endl;             //Give user answer to their math problem. 
			cout << endl;
		}
	}
	else 
		 if (x < 0)  //Logic for if answer is undefined 
		{
			cout << "   x^(1/2) = " << x << "^(1/2)" 
				 << " = " << "Not a Real Number, please enter new x value.\n" << endl;
			cout << endl;
		}
		if (x > 0)
		{
			//if not undefined answer is returned normally to user. 
			cout << "   x^(1/y) = " << x << "^(1/ " << y << ")" 
				 << " = " << root << endl;
			cout << endl;
		}   
}

/* -----------------------------------------------------------------------------
FUNCTION:          Get_x_1()
DESCRIPTION:       Reusable code stub for calculator 
RETURNS:           Nothing (void)
NOTES:             Lets user choose x value for power and root functions.  
------------------------------------------------------------------------------- */
void Get_x_1()
{	
	cout << "Please input a numerical x value." << endl; //Asks user to input value
	cin >> x; //User inputs x value
	cout << endl; 
}

/* -----------------------------------------------------------------------------
FUNCTION:          Get_x_and_y_1()
DESCRIPTION:       Reusable code stub for calculator 
RETURNS:           Nothing (void)
NOTES:             Lets user choose x and y value for power and root functions.  
------------------------------------------------------------------------------- */
void Get_x_and_y_1()
{	
	cout << "Please input a numerical x and y value." << endl; //Asks user to input value
	cin >> x; //User inputs x value
	cin >> y; //User inputs y value
	cout << endl; 
}

/* -----------------------------------------------------------------------------
FUNCTION:          printFloat()
DESCRIPTION:       Reusable code stub for calculator
RETURNS:           stream.str()
NOTES:             Runs logic that determines how to output floating point values 
                   in a asthetically pleasing fashion.
------------------------------------------------------------------------------- */
string printFloat(double number)
{
	stringstream stream; //Initilizes stream as a string
	
	double fraction = number - int(number);  /*Runs equation that determines if there is
                                               a decimal after 0. */
	
	/* Takes answer from equation to determine whether or not number is in float or int mode
	   and if it needs to add a .0 at the end of the number to let user know that they are in 
	   float mode.*/
	
	if ( data_type == 'I' || data_type == 'i' || fraction > 0  || -fraction > 0)  
		{                                              
			stream << number;
		} 	
	else
			stream << number << ".0";
	
return stream.str();  //Returns answer value of x, y and answer(varies on function calling it)

} 