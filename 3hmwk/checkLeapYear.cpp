// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 3 - Problem 6 -- checkLeapYear function
#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: takes a single integer representing a year and returns true if it is a leap year and false otherwise
type: bool
one parameter
 if year is divisible by 4
    if year is greater than 1582
        if year is divisible by 100
            not a leap year
            return false
    year is a leap year
        

*/

bool checkLeapYear(int year){
    bool leap = false;                       //false by default
    if (year % 4 == 0)                       //check if year is divisible by 4
    {
        if (year >= 1582)
        {
            if (year % 100 == 0 && year % 400 != 0)             //check for gregorian correction, if year is divisible by 100 but not by 400 it is not a leap year
            {
                return false;
            }
        }
    leap = true;
    }
    return leap;
}

int main(){
    //test case 1 argument is equal to 1900, the function should return false
    cout << checkLeapYear(1900) << endl;
    
     //test case 2 argument is equal to 2000, the function should return true
    cout << checkLeapYear(2000) << endl;
    
}