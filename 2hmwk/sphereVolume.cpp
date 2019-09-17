// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 2 - Problem 5 -- sphere volume function


#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: compute the volume of a sphere given the radius
function is void because it has no output
uses an input of type double which is stored in the variable radius
defines variable volume
does the calculation for volume 4/3pir^2
outputs calculated volume*/

void sphereVolume(double radius){
    double volume;                                              //declares volume variable
    volume = (4.0/3.0) * M_PI * pow(radius, 3);                 //calculates volume using pi and radius
    cout << "volume: " << volume << endl;
    
}

int main(){
    //test case 1 returns 14137.2
    cout << "test case 1"<< endl;
    sphereVolume(15);
    
    //test case 2 returns 523.599
    cout << "test case 2" << endl;
    sphereVolume(5);
    return 0;
}