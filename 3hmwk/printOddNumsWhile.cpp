// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 3 - Problem 8 -- print odd nums while function
#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm:  print all positive odd integers less than or equal to a max value
type: void
one integer parameter
if number is greater than or equal to 1
if number is even
    count up to number - 1
if number is 1
    print 1
else
    count up to number
*/

void printOddNumsWhile(int num){
    if(num >= 1)
    {
        if (num % 2 == 0 && num != 1)                  //runs if number is even and not 1
        {
            int count = 1;
            cout << count << endl;
            while (count < num - 1)                 //counts up to 1 below the even number
            {
                count = count + 2;
                cout << count << endl;
            }
        }
        else if (num == 1)                      //only runs when number = 1
        {
            cout << num;
        }
        else                                    //runs when number is odd
        {
            int count = 1;
            cout << count << endl;              
            while (count < num)                 //counts up to the odd number
            {
                count = count + 2;
                cout << count << endl;
            } 
        }
    }
}

int main(){
    //test case 1 num = 3, expect 1 3
    printOddNumsWhile(3);
    
    //test case 2 num = 10, expect 1 3 5 7 9
    printOddNumsWhile(10);
    return 0;
}