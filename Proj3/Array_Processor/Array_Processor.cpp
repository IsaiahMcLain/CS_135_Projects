/* -----------------------------------------------------------------------------
FILE:              Array_Processor.cpp
DESCRIPTION:       Program that will take numbers from an input file and proced to run calculations of them. 
COMPILER:          MinGW  C++ compiler
NOTES:             Calculations include, sum of numbers, mean, mode, meadian, max and min values, as well as total numbers read. 

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Isaiah McLain      2019-12-3          1.0, Added code from Numbers Analysis program. 
Isaiah McLain      2019-12-3          1.1, Added the Array_Total function seperating it from the Array Average function
Isaiah McLain      2019-12-3          1.2, Edited main function to where double calling of functions isn't occuring. 
Isaiah McLain      2019-12-3          1.3, Added ability for user to specify what file they want to open 
Isaiah McLain      2019-12-3          1.4, Fixed issue with program having undefined refrences to function calls. 
Isaiah McLain      2019-12-3          1.5, Added the standard deviation function 
Isaiah McLain      2019-12-4          1.6, Fixed up the user interface for the presentation of values and also added
									  the array sorter function and array swap which organizes the 
									  array in ascending order. 
Isaiah McLain      2019-12-5		  1.7, Added if statement that enables programmer to see if array sorter is working
									  or not. Also added the Median function that calculates the median.
Isaiah Mclain      2019-12-5		  1.8, Added seperate output file and input file functions as well as the mode function
Isaiah McLain      2019-12-5          2.0, Fixed ostream issues with repition, program comments finalized. 
----------------------------------------------------------------------------- */

#include <iostream>  //Allows the use of streams including cout in the program. 
#include <iomanip>   //Allows the program to function 
#include <string>    //Allows the use of strings in the program 
#include <fstream>   //Enables an input file to be used 
#include <cmath>   //Enables the use of the pow function in standard deviation. 
#include <vector> //Enables the use of the vector class for the mode.

using namespace std;

const string PROGRAMMER_NAME = "Isaiah McLain";		// Global constant

//Prototypes
int Array_Minimum(int[], int);    //Initilizes the Array Minimum function  
int Array_Maximum(int[], int);   //Initilizes the Array Maximum function  
double Array_Average(int[], int, double); //Initilizes the Array Average function  
int Array_Reader(int[], ifstream&, int, ofstream&); //Initilizes the Array Reader function 
int Array_Total(int[], int); //Initilizes the Array Total function 
double Array_Deviation (int[], int, int); //Initilizes the Array Deviation function 
double Array_Median(int[], int); //Initilizes the Array Median function 
void Array_Mode(int[], int, ofstream&, ostream&); //Initilizes the Array Mode function 
void Array_Histogram(int[], int, ofstream&, ostream&); //Initilizes the Array Histogram function 
void File_Output(ofstream&,int,int,int,int,double,double,double,int[]); //Initilizes the File Output function 
void File_Input(ifstream&, ofstream&);  //Initilizes the File Input function 
void Print_File(ostream&,int,int,int,int,double,double, double, int[]); //Initilizes the Print File function 
void Array_Sorter(int[], int); //Initilizes the Array Sorter function 
void Array_Swap(int&, int&); //Initilizes the Array Swap function 

const int SIZE = 1000; //Initilizes the maxium size the array can be

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Function that will open the input file as well as call upon other functions.
RETURNS:           0
NOTES:             N/A
------------------------------------------------------------------------------- */
int main()
{
	int Raw_Data[SIZE]; //Initilizes the Number_Array 
	bool Sort_Show_Switch = 0; //When enabled lets the programmer see if the array sorter is working properly. 

	ifstream inputfile; //Sets variable name for input file.
	ofstream outputfile; //Sets variable name for output file 

	File_Input(inputfile, outputfile); //Calls the function that will let user choose their input file 
	
    int Tally = Array_Reader(Raw_Data, inputfile, Tally, outputfile); //Sets tally to the return value of the Array Reader 
	
	int Minimum = Array_Minimum(Raw_Data, Tally); //Sets the Minimum vairable to the return value of the Array_Minimum

	int Maximum = Array_Maximum(Raw_Data, Tally); //Sets the Maximum variable to the return value of the Array_Maximum
	
	double Total = Array_Total(Raw_Data, Tally); //Sets the Total vairable to the return value of the Array_Total

	double Average = Array_Average(Raw_Data, Tally, Total); //Sets the average variable to the return value of the Array_Average

	double Standard_Deviation = Array_Deviation(Raw_Data, Tally, Average); //Sets the standard dev variable to the return value of the Array_Deviation 

	Array_Sorter(Raw_Data, Tally); //Calls the Array_Sorter function to sort the array 
	
	double Median = Array_Median(Raw_Data, Tally); //Sets the value median to the return value of the Array_Median
	
	File_Output(outputfile, Tally, Minimum, Maximum, Total, Average, Standard_Deviation, Median, Raw_Data); //Calls the output file function 

	if (Sort_Show_Switch) //If statement that determines whether or not the programmer is looking to see if the sorter is working or not
	{
		for (int counter = 0; counter < Tally; counter++) //Loop runs through array and couts all the values after they have been sorted. 
		{
			cout << Raw_Data[counter] << endl; 
		}
	}

	outputfile.close(); //Closes the output file

	cout << "Programmed by: " << PROGRAMMER_NAME << " -- "; //Displays programmers name and date of compiling 
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	system("pause"); //Pauses screen 

	return 0; //Returns 0 and shows program ran correctly 
}

/* -----------------------------------------------------------------------------
FUNCTION:          Array_Reader
DESCRIPTION:       Function that will read all the values from the file and put them into an array.
				   As well as keep a tally of how many values are within the array.
RETURNS:           Tally
NOTES:             N/A
------------------------------------------------------------------------------- */
int Array_Reader(int Raw_Data[], ifstream &inputfile, int Tally, ofstream &outputfile)
{
    int size = 0; //Sets size variable to 0 
	int number; //Initilizes the number variable which is used in the loop to store the number read from file. 
	
	while (inputfile >> number) //Loop that stores inputfile value into number and then into an array. 
	{
		Raw_Data[size] = number; //Assigns the number from inputfile stored from number into the array
		size++; //adds 1 to size
	    Tally = size; //Sets tally = to size
	}
	
	if (Tally > SIZE) //If statement that determines if the user overfilled the array and if they do it tells the user to restart the program. 
	{
		cout << "Array overfilled. Please restart the program and use a file with 1000 values or less." << endl; 
	}
	
	inputfile.close(); //Closes the input file

	return Tally; //Returns the accumlator of how many values were read 
}


/* -----------------------------------------------------------------------------
FUNCTION:          Array_Minimum
DESCRIPTION:       Function that will find the lowest value in the array.  
RETURNS:           Low 
NOTES:             N/A
------------------------------------------------------------------------------- */
int Array_Minimum(int Raw_Data[], int Tally)
{ 
	int count; //Initilizes the counter variable for the loop 
	int Minimum; //Initilizes variable the holds the lowest value

	Minimum = Raw_Data[0]; //Sets variable equal to the first element 
	
	//This loop is cited from the book, page 407
	for (count = 1; count < Tally;  count++) //Loop runs through with first element and then replaces the element if the comparison is lower. 
	{
		if (Raw_Data[count] < Minimum)
		{
			Minimum = Raw_Data[count]; 
		}
	}
	return Minimum; //Returns the lowest value. 
}

/* -----------------------------------------------------------------------------
FUNCTION:          Array_Maximum
DESCRIPTION:       Function that will find the highest value in the array.  
RETURNS:           High 
NOTES:             N/A
------------------------------------------------------------------------------- */
int Array_Maximum(int Raw_Data[], int Tally)
{
	int count; //Initilizes the counter variable for the loop 
	int Maximum; //Initilizes variable the holds the highest value

	Maximum = Raw_Data[0]; //Sets variable equal to the first element 
	
	//This for loop is cited from the book, page 407
	for (count = 1; count < Tally;  count++) //Loop runs through with first element and then replaces the element if the comparison is higher. 
	{
		if (Raw_Data[count] > Maximum)
		{
			Maximum = Raw_Data[count]; 
		}
	}
	return Maximum; //Returns the highest value. 
} 

/* -----------------------------------------------------------------------------
FUNCTION:          Array_Total
DESCRIPTION:       Function that will add all the values in the array.
RETURNS:           total
NOTES:             N/A
------------------------------------------------------------------------------- */
int Array_Total(int Raw_Data[], int Tally)
{
	double Total = 0; //Sets the total to 0

	//This for loop is cited from the book, page 406
	//Takes amount of numbers and consistently adds them to the Total until the max numbers entered has been reached. 
	for (int count = 0; count < Tally; count++) 
	{
		Total += Raw_Data[count];
	}
	return Total; //Returns the sum of the array 
}

/* -----------------------------------------------------------------------------
FUNCTION:          Array_Average 
DESCRIPTION:       Function that will take all the added values in the array and then divide them by
				   the amount of values in the array (taken from array tally) 
RETURNS:           Average 
NOTES:             N/A
------------------------------------------------------------------------------- */
double Array_Average(int Raw_Data[], int Tally, double Total)
{ 
	double Average = 0; //Sets the average to 0 
	
	Average = Total / Tally; //Takes the sum of numbers taken from the for loop and divides them by amount of numbers read or tally. 

	return Average; //Returns the aveage value of the array. 
} 

/* -----------------------------------------------------------------------------
FUNCTION:          Array_Deviation 
DESCRIPTION:       Function that will take the average and then use it in the standard deviation 
				   formula to calculate the standard devaition of the equation 
RETURNS:           Standard_Deviation 
NOTES:             N/A
------------------------------------------------------------------------------- */
double Array_Deviation (int Raw_Data[], int Tally, int Average)
{
	double Standard_Deviation = 0; //Initilizes the Standard_Devation variable 

	//This for loop and return value is cited from: "https://www.programiz.com/cpp-programming/examples/standard-deviation" 
	//Loop runs through the amount of numbers entered and then runs the deviation calculation steping through every number. 
	for(int counter = 0; counter < Tally; counter++)
        Standard_Deviation += pow(Raw_Data[counter] - Average, 2);
    
	return sqrt(Standard_Deviation / Tally); //Returns the Standard_Deviation variable with the final calulation being ran as well. 
}

/* -----------------------------------------------------------------------------
FUNCTION:          Array_Sorter
DESCRIPTION:       Function that will take the numbers of the array and sort them in ascending order. 
RETURNS:           nothing(void) 
NOTES:             N/A
------------------------------------------------------------------------------- */
void Array_Sorter(int Raw_Data[], int Tally)
{
	int minIndex; //Initilizes the variable that will hold the number being looked at
	int minValue; //Initilizes the variable that will hold the lowest value number 

	//This function was modified from the book, page 481
	//For loop runs through the array looking for the smallest value and then ordering the array in ascending order. 
	for (int start = 0; start < (Tally - 1); start++)
	{
		minIndex = start; //Sets the minIndex = to 0
		minValue = Raw_Data[start]; //Sets the minValue to the first number in the array 
		//Nested for loop enables the if statement to occur causing the swapping of the data points if they aren't in ascending order.
		for (int index = start + 1; index < Tally; index++) 
		{
			if (Raw_Data[index] < minValue)
			{
				minValue = Raw_Data[index];
				minIndex = index;
			}
		}
		Array_Swap(Raw_Data[minIndex], Raw_Data[start]); //Function call for the function that enables the values to be swapped 
	}
}

/* -----------------------------------------------------------------------------
FUNCTION:          Array_Swap
DESCRIPTION:       Function that will take the numbers given to it by Array_Sorter and swap them with three variables,
				   one being a temporary storage. 
RETURNS:           nothing(void) 
NOTES:             N/A
------------------------------------------------------------------------------- */
void Array_Swap(int &a, int &b)
{
	//This function was from the book, page 481
	int temp = a; //Sets the temporay variable holder = to the first value/ 
	a = b; //Now sets a to b
	b = temp; //Now sets temp to the value b making the swap compelte without removing a number
}

/* -----------------------------------------------------------------------------
FUNCTION:          Array_Median
DESCRIPTION:       Function that will take the ordered array and calculate the median based on if the
				   array has an even or odd amount of numbers in it. 
RETURNS:           Median
NOTES:             N/A
------------------------------------------------------------------------------- */
double Array_Median(int Raw_Data[], int Tally)
{
    double Median = 0; //Sets Median to 0 
    
	//If statement determines whether or not the array has odd amount or even amount of elements and then calculates the median occurdingly. 
    if(Tally % 2 == 0) 
        Median = (Raw_Data[(Tally-1) / 2] + Raw_Data[Tally / 2]) / 2.0; //Runs the calculation to determine median if the array is even. 
    else
        Median = Raw_Data[Tally / 2]; //Runs the calcualtion to determine median if the array is odd.
    
    return Median; //Returns the median 
}

/* -----------------------------------------------------------------------------
FUNCTION:          Array_Mode
DESCRIPTION:       Function that will take the ordered array and calculate the mode 
RETURNS:           Nothing(void)
NOTES:             N/A
------------------------------------------------------------------------------- */
void Array_Mode(int Raw_Data[], int Tally, ostream& s) 
{ 
	int Mode = 0; //Initilizes variable that will hold mode 
	vector<int> Modes; //Vector that will store the mode or modes
	int placer = 1; //Variable that hold the place of the array and is used to be compared to Maxplacer
	int Maxplacer = 0; //Variable that is used to be compared to Placer
	
	//For loop works through array and determines what values are equal to eachother and if they are it makes the comparison between placer and maxp happen. 
	for (int counter = 1; counter < Tally; counter++)
	{
		if (Raw_Data[counter] == Raw_Data[counter - 1])
		{
			placer++; //Adds 1 to placer
			if (placer > Maxplacer) //If placer greater than Maxplacer, Maxplacer now == placer. 
			{
				Maxplacer = placer; 
			}
		}
		else
			placer = 1; //Placer stays the same 
	}

	placer = 1; //Sets placer back to 1
	//For loop similar to the one before it except now if placer and maxplacer == eachother the vector gets the value stored within it. 
	for (int counter = 1; counter < Tally; counter++)
	{
		if (Raw_Data[counter] == Raw_Data[counter - 1])
		{
			placer++; //adds 1 to placer 
			if (placer == Maxplacer) 
			{
				Modes.push_back(Raw_Data[counter]); //Stores the value being compared into vector
			}
		}
		else
			placer = 1; //If the if statement cannot be run through placer returns back to 1. 
	}
	s << "Modes  are: "; //Tells user what the modes are

	for (int counter = 0; counter < Modes.size(); counter++) //Loop lets program open the vector and display the mode values to the user. 
	{
		s << Modes[counter] << " "; //Displays the modes
	}
	s << endl << endl; //Used for spacing 
}

/* -----------------------------------------------------------------------------
FUNCTION:          Array_Histogram
DESCRIPTION:       Function that will take the ordered array and display a histogram of what values 
                   were entered from the file. 
RETURNS:           nothing(void) 
NOTES:             N/A
------------------------------------------------------------------------------- */
void Array_Histogram(int Raw_Data[], int Tally, ostream& s)
{
	s << "Histogram: " << endl; //Displays that the next thing is a histogram to the user
	for (int numbers = 0; numbers < 10; numbers++) //Sets the y-axis of the histogram to increase by 100
		{
			int num1 = (numbers * 100); //Sets the first number within the y axis range
			int num2 = (numbers + 1) * 100; //Sets the second number within the y axis range 

			s << num1 << " - " << num2 << ": "; //Displays the two numbers and the range 
			
			for (int numbers_1 = 0; numbers_1 <= Tally; numbers_1++) //Loop steps through every number of the array to decide what range the numbers fall into 
			{	
				if (Raw_Data[numbers_1] >= num1 && Raw_Data[numbers_1] <= num2) //If statement determines if the number read fits inbetween the range 
				{
					s << "*"; //If number fits couts a * 

				}
			} 
			s << endl; //Used for spaceing 
		}
		s << endl << endl; //Used for spacing 
}

/* -----------------------------------------------------------------------------
FUNCTION:          File_Output 
DESCRIPTION:       Function that prompts user what file they want the data saved to. 
RETURNS:           nothing(void) 
NOTES:             N/A
------------------------------------------------------------------------------- */
void File_Output(ofstream &outputfile, int Tally, int Minimum, int Maximum, int Total, double Average, double Standard_Deviation, double Median, int Raw_Data[])
{ 
	string user_file_out; //Initilizes the string variable that will hold the output file name.

	Print_File(cout, Tally, Minimum, Maximum, Total, Average, Standard_Deviation, Median, Raw_Data);

	Array_Mode(Raw_Data, Tally, cout); //Calls Array Mode function 
	
	Array_Histogram(Raw_Data, Tally, cout); //Function call that will display the Histogram 
	
	//Prompts user to enter a file name with the .txt added
	cout << "Please enter the file name you would like to send the data to, please include .txt at the end." << endl; 
	cin >> user_file_out; //Lets user input the file name into the program 

	outputfile.open(user_file_out); //Function call for the output file function 

	//Logic that tells if file opended or not and lets the user know which case occured. 
	if (outputfile)
	{
		cout << "File opended sucessfully." << endl;
		Print_File(outputfile, Tally, Minimum, Maximum, Total, Average, Standard_Deviation, Median, Raw_Data); //Will print the results to the file
		Array_Mode(Raw_Data, Tally, outputfile); //Calls Array Mode function so it can be printed to file 
		Array_Histogram(Raw_Data, Tally, outputfile); //Function call that will print the histogram to the file
	}
	else 
		cout << "File opening error." << endl; 
}

/* -----------------------------------------------------------------------------
FUNCTION:          File_input              
DESCRIPTION:       Function that prompts user what file they want the data read from. 
RETURNS:           nothing(void) 
NOTES:             N/A
------------------------------------------------------------------------------- */
void File_Input(ifstream &inputfile, ofstream &outputfile)
{ 
	string user_file;  //Initilizes the string variable that will hold the file name. 

	//Prompts user to enter a file name with the .txt added
	cout << "Please enter the file name you would like to open, please include .txt at the end." << endl; 
	cin >> user_file; //Lets user input the file name into the program 

	inputfile.open(user_file); //Opens the numbers.txt file for the user 

	//Logic that tells if file opended or not and lets the user know which case occured. 
	if (inputfile)
		cout << "File opended sucessfully." << endl;
	else 
		cout << "File opening error." << endl; 
}

/* -----------------------------------------------------------------------------
FUNCTION:          Print_File           
DESCRIPTION:       Function that prints all the data outputted to the console to the file
RETURNS:           nothing(void) 
NOTES:             N/A
------------------------------------------------------------------------------- */
void Print_File(ostream &s, int Tally, int Minimum, int Maximum, int Total, double Average, double Standard_Deviation, double Median, int Raw_Data[])
{
    
	s << "Here is the data gathered from your file" << endl << endl; //Displays to outputfile what the data is coming from 
	s << "No. points: " << Tally << endl; //Displays to ouputfile the amount of numbers read from file 
	s << "The Min is: " << Minimum << endl; //Displays to outputfile the lowest value read
	s << "The Max is: " << Maximum << endl; //Displays to outputfile the highest value read 
	s << "Sum  Total: " << Total << endl; //Displays to outputfile the total of all the numbers read from the file 
	s << "The Avg is: " << Average << endl; //Displays to outputfile the average of the values read 
	s << "Std Dev is: " << Standard_Deviation << endl; //Displays to outputfile the standard deviation of the values read 
	s << "Median  is: " << Median << endl; //Displays to outputfile the median of the values read	*/

}