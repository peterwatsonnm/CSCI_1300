// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 3 - Problem 4 -- count digits function
#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: take an integer parameter and return the number of digits as an integer
type: integer
takes one parameter, an integer

if integer is negative
    multiply by -1
    
convert integer to string

use string.size function to count number of characters in string

return number of characters in string
*/

int countDigits (int number){
    if (number < 0)            //if number is negative, make it positive
    {
       number = (-1 * number); 
    }
    
    string numberStr = to_string(number);        //convert the integer number to a string so that its digits can be counted
    int digits = numberStr.size();              //use string.size function to count how many digits are in the string
    return digits;
}

int main (){
   //test case 1 argument is equal to 123, the function should return 3
   cout << countDigits(123) << endl;
   
   //test case 2 argument is equal to -75, the function should return 2
   cout << countDigits(-75) << endl;
}