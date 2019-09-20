// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 3 - Problem 9 -- print odd for while function
#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm:  print all positive odd integers less than or equal to a max value
type: void
one integer parameter

if number is positive
    if number is even
        count up to number - 1
    if number is one
        print 1
    if number is odd
        count up to number
    
*/

void printOddNumsFor(int num){
    if (num >= 1)
    {
        if (num % 2 == 0 && num != 1)
        {
            for (int count = 1; count <= num - 1; (count = count + 2))             //counts up from 1 to even number -1
            {
                cout << count << endl;
            }
        }
        else if (num == 1)
        {
            cout << num << endl;
        }
        else                                                    //number is odd
        {
            for (int count = 1; count <= num; (count = count + 2))                  //counts up from 1 to odd number
            {
                cout << count << endl;
            }
        }
    }
}

int main(){
    //test case 1 parameter is 11, the expected output should be 1 3 5 7 9 11
    printOddNumsFor(11);
    
    //test case 2 for parameter 10, output should be 1 3 5 7 9
    printOddNumsFor(10);
    return 0;
}