// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 3 - Problem 5 -- count hours function
#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: function returns the number of hours in the month for any given month, denoted by integer 1-12
type: int
one integer parameter

define hours = 0

switch
case 1, 3, 5, 7, 8, 10, 12:
    hours = 744
case 2:
    hours = 672
case 4,6,9,11:
    hours = 720
return hours
    
*/

int countHours(int month){
    int hours = 0;
    switch(month)
    {
        //all these months have 744 hours
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            hours = 744;
            return hours;
            break;
        //all these months have 672 hours
        case 2:
            hours = 672;
            return hours;
            break;
        //all these months have 720 hours
        case 4:
        case 6:
        case 9:
        case 11:
            hours = 720;
            return hours;
            break;
    }
}

int main(){
    //test case 1 argument is equal to 1, the function should return 744
    cout << countHours(1) << endl;
    
    //test case 2 argument is equal to 2, the function should return 672
    cout << countHours(2) << endl;
    
    //test case 3 argument is equal to 4, the function should return 720
    cout << countHours(4) << endl;
}