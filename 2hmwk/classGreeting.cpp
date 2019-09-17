// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 2 - Problem 3 -- classGreeting function

/*algorithm: output a hello string based on input of courseNum
parameter is one integer value (courseNum)
take value and print a string using that value to print a hello message to the user's csci class
*/

#include <iostream> 
using namespace std; 


void classGreeting(int courseNum) { 							//initializes function classGreeting

	cout << "Hello, CS " << courseNum << " World!" << endl;		//outputs string using value on courseNum variable
		
}

int main()
{
	//Test 1
	cout << "test case 1" << endl;
	int courseNum = 1300;
	classGreeting(courseNum);
	
	//Test 2
	cout << "test case 2" << endl;
	courseNum = 1200;
	classGreeting(courseNum);
	return 0;
}