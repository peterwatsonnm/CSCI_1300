// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 2 - Problem 6 -- sphere surface area function

#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: compute the surface area of a sphere given a radius
initializes function as void because it has no output
creates variable surfaceArea
computes value of surface area using (radius)^2, pi, and 4 in the surface area of a sphere funtion, stores in surfaceArea
outputs value of surfaceArea*/

void sphereSurfaceArea(double radius){
	double surfaceArea;									//create variable surfaceArea
	surfaceArea = (4)*(M_PI)*(pow(radius, 2));			//calculate surface area
	cout << "surface area: " << surfaceArea << endl;			//output surface area
}

int main(){
    //test 1 returns 314.159
    cout << "test case 1" << endl;
    sphereSurfaceArea(5);
    
    //test 2 returns 1256.64
    cout << "test case 2" << endl;
    sphereSurfaceArea(10);
}
