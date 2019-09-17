// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 2 - Problem 8 -- population function

#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: write a function to calculate
the U.S. population in exactly one year (365 days)

NOTE: THIS FUNCTION DOES NOT INCLUDE EMMIGRATION AS A FACTOR 

currentPop = 328,441,687
SecondsInYear = (3.154*10^7)

BirthsPerSecond = 1/8
DeathsPerSecond = 1/12
ImmigrantsPerSecond = 1/27

BirthsPerYear = (BirthsPerSecond * SecondsInYear) integer
DeathsPerYear = (DeathsPerSecond * SecondsInYear) integer
ImmigrantsPerYear = (ImmigrantsPerSecond * SecondsInYear) integer

USPopulationFinal = currentPop + BirthsperYear - DeathsPer Year + ImmigrantsPerYear

return USPopulationFinal 

*/

int population(int currentPop){
    int secInYear = 31536000;        //multiplied by per second rates to get total number of births/deaths/immigrants in a year
    
    //define birth, death, and immigration rates
    double birthPerSec = .125;
    double deathPerSec = 0.083333333;
    double immigrantPerSec = 0.037037037;
    
    //calculate births, deaths, and immigrants per year
    int birthsPerYear = birthPerSec * secInYear;
    int deathsPerYear = deathPerSec * secInYear;
    int immigrantsPerYear = immigrantPerSec * secInYear;
    
    int finalPop = currentPop + birthsPerYear - deathsPerYear + immigrantsPerYear;      //calculate population after a year
    
    return finalPop;
}

int main(){
    //test case 1 returns 4572770
    cout << "testcase1" << endl;
    int populationReturn = population(2090770);
    cout << populationReturn << endl;
    
     //test case 2 4562390
    cout << "testcase2" << endl;
    populationReturn = population(2080390);
    cout << populationReturn << endl;
}