// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 2 - Problem 10 -- calculate salary function
#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: function computes salary which is dependent on how many days are cold, rainy, or sunny

type: int
define pay per hour = 10
uses 3 integer parameters, coldDays, rainyDays, and sunnyDays
define coldHrs=4, rainyHrs=5, sunnyHrs=8
converts these parameters to hours worked by multiplying coldDays*coldHrs, rainyDays*rainyHrs, and sunnyDays*sunnyHrs
add these three values to get total hours worked
computes pay by multiplying pay per hour * total hours worked
return pay

*/
int calculateSalary(int rainyDays, int coldDays, int sunnyDays){
    //define hours worked on each different type of day
    int coldHrs = 4;
    int rainyHrs = 5;
    int sunnyHrs = 8;
    
    int payPerHr = 10;       //define pay per hour
    
    //convert ammount of each type of days to hours, and add to get total hours worked
    int totHrs = (coldDays * coldHrs) + (rainyDays * rainyHrs) + (sunnyDays * sunnyHrs);
    int pay = totHrs * payPerHr;
    return pay;
}

int main(){
    //test case 1
    cout << "testcase1: should return 370" << endl;
    cout << calculateSalary(1,2,3) << endl;
    
    //test case 2
    cout << "testcase2: should return 1200" << endl;
    cout << calculateSalary(4,5,10) << endl;
    
     //test case 3
    cout << "testcase3: should return 1460" << endl;
    cout << calculateSalary(10,4,10) << endl;
    return 0;
}