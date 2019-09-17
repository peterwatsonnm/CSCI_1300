// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 2 - Problem 7 -- convert seconds function
#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: function takes one integer input as seconds and converts it to hours,
minutes and seconds

define variable minutes
define variable hours
minutes = seconds / 60 without remainder
seconds = remainder of (inputSeconds / 60)
hours = minutes / 60 without remainder
minutes = remainder of (inputMinutes/60)
days = hours / 24 without remainder
hours = remainder of (inputHours / 24)
Print “(hours) hours, (minutes)      minutes, and (seconds) seconds.
*/

void convertSeconds(int seconds){
    int minutes;
    int hours;
    minutes = seconds / 60;           //divide total number of seconds by 60 to get total number of whole minutes (integer value)
    seconds = seconds % 60;         //uses mod operator to get the leftover seconds, value of which becomes final value of seconds
    hours = minutes / 60;           //total number of minutes divided by 60 yields total number of whole hours (integer value)
    minutes = minutes % 60;          //uses mod to get the leftover minutes, value of which becomes final value of minutes
    
    cout << hours << " hour(s) " << minutes << " minute(s) " << seconds << " second(s) ";
}

int main(){
    //test case 1, should return 0 hour(s) 2 minute(s) 0 second(s) 
    cout << "testcase1" << endl;
    convertSeconds(120);
    cout << endl;
    
    //test case 2, should return 1 hour(s) 0 minute(s) 0 second(s) 
    cout << "testcase2" << endl;
    convertSeconds(3600);
    cout << endl;
    
    //test case 3, should return 1 hour(s) 1 minute(s) 5 second(s) 
    cout << "testcase3" << endl;
    convertSeconds(3665);
    
    return 0;
}