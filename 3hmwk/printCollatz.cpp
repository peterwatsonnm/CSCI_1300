// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 3 - Problem 7 -- print collatz function
#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: takes the starting number of the collatz sequence and prints the entire sequence
type void
one integer parameter

function only runs if input is a valid number, returns error otherwise

while n doesnt equal 1
if n is even
    divide n by 2
elif n is odd
    multiply n by 3 and add 1
print n
*/

void printCollatz(int startNum){
    if (startNum > 0)               //checks if startNum is a valid number
        {
        cout << startNum << " ";  
        while (startNum > 1)     //loop runs until it reaches 1, then end of the sequence
           {
                if (startNum % 2 == 0)           //uses mod operator to check if startNum is divisible by two (even)
                {               
                    startNum = (startNum / 2);
                }
                else                //no need for a conditional because odd is the only other condition possible
                {                      
                    startNum = (3 * startNum + 1);
                }
                cout << startNum << " ";
           }
        }
    else
    {
       cout << "invalid number";
    }
}

int main(){
    //test case 1  parameter is equal to 6, the function should print “6 3 10 5 16 8 4 2 1”
    printCollatz(6);
    cout << endl;
    
    //test case 2  parameter is equal to -5, the function should print “invalid number”
    printCollatz(-5);
    cout << endl;
    
    //test case 3  When the parameter is equal to 4, the function should print “4 2 1”
    printCollatz(4);
    cout << endl;
    return 0;
}