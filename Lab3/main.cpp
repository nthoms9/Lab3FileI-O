/*
Nick Thoms
C++ 2019
Due: 09/26/19
Lab 3 User and File I/O
Description:This program takes a set of data in the form of integers from both user
input and a data file, then uses the data to calculate the mean and standard deviation 
of the set of numbers.
*/

#include<iostream>
#include<cmath>        // <cmath> is needed for calculating standard deviation
#include<fstream>      // needed for input files and output files


using namespace std;

float mean(int, int, int, int);             // function prototype for mean calculation
float stdDeviation(int, int, int, int, float mean); //prototype for standard deviation

int main()
{
	int a, b, c, d; // identifiers for the user input variables
	int e, f, g, h; // identifiers for the file input variables
	
	// locations for the input and output files
	string inMeanStd = "C:/Users/THOMS4/Documents/C++ Projects/Lab3/inMeanStd.dat";
	string outMeanStd = "C:/Users/THOMS4/Documents/C++ Projects/Lab3/outMeanStd.dat";

	ifstream inFile;   //declares the inFile identifier for ifstream
	ofstream outFile;  //declares the outFile identifier for ofstream

	inFile.open(inMeanStd);         // reads the location for the input file
	outFile.open(outMeanStd);       // reads the location for the output file

	inFile >> e >> f >> g >> h;     // sets values to the file input variables

	cout << "To calculate the mean and standard devation, please type 4 integers, then" 
		    " press enter. \n(Be sure to leave a space in between each integer)\n\n";

	cin >> a >> b >> c >> d;        // sets values to the user input variables

	/*calls to the functions then displays the calculations for each data set to the 
	  screen*/
	cout << "\nThe numbers you inputted are: " << a <<" "<< b <<" "<< c <<" "<< d;
	cout << "\nThe mean of your input is: " << mean(a, b, c, d) << endl;
	cout << "The standard deviation of your input is: " 
		 << stdDeviation(a, b, c, d, mean(a, b, c, d)) << endl;
	cout << "\nThe numbers the file inputted are: " << e <<" "<< f <<" "<< g <<" "<< h;
	cout << "\nThe mean of the file input is: " << mean(e, f, g, h) << endl;
	cout << "The standard deviation of the file input is: "
		 << stdDeviation(e, f, g, h, mean(e, f, g, h)) << endl;

	/*calls to the functions then outputs the calculations for each data set to the
	  output file*/
	outFile << "The numbers you inputted are: " << a <<" "<< b <<" "<< c <<" "<< d;
	outFile << "\nThe mean of your input is: " << mean(a, b, c, d) << endl;
	outFile << "The standard deviation of your input is: " 
			<< stdDeviation(a, b, c, d, mean(a, b, c, d)) << endl;
	outFile << "\nThe numbers the file inputted are: " << e <<" "<< f <<" "<< g <<" "<< h;
	outFile << "\nThe mean of the file input is: " << mean(e, f, g, h) << endl;
	outFile << "The standard deviation of the file input is: " 
			<< stdDeviation(e, f, g, h, mean(e, f, g, h));

	inFile.close();     // closes the input file
	outFile.close();    // closes the output file

	return 0;
}

float mean(int a, int b, int c, int d) //function definition for the mean calulation
{
	return float(a + b + c + d) / float(4);
}

//function definition for the standard deviation calculation
float stdDeviation(int a, int b, int c, int d, float mean)
{
	return sqrt((pow((a - mean), 2) + pow((b - mean), 2) + pow((c - mean), 2) + pow((d - mean), 2)) / 4);
}