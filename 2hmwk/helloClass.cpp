// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 2 - Problem 2 -- hello class

#include <iostream> 
using namespace std; 

int main()
{
	int courseNum;
	cout << "Enter a CS course number:" << endl;
	cin >> courseNum;								//stores user input into variable that was previously created, int courseNum
	cout << "Hello, CS " << courseNum << " World!";
	return 0;
}