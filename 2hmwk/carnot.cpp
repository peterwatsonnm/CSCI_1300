// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 2 - Problem 9 -- carnot function

#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: takes in two integer parameters (asbTempCold and absTempHot) and will return the carnot efficiency
Define variable carnotEfficiency 
carnotEfficiency = 1 - (absTempCold/absTempHot)
return carnotEfficiency as a double

*/

double carnot(int absTempCold, int absTempHot){
    double carnotEfficiency = (1 - ((double)absTempCold / (double)absTempHot));   //calculates carnot efficiency based on two integer parameters, which are converted to doubles for the division
    return (carnotEfficiency);
}

int main(){
    //test case 1
    cout << "testcase1: should return -6.14286 --> " << carnot(100,14) << endl;
    
     //test case 2
    cout << "testcase2: should return 0.4375 --> " << carnot(9,16) << endl;
}