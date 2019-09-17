// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 2 - Problem 4

/*algorithm:
prompt input into variable radius
create variable volume
calculate volume, 4/3pir^2
create variable surfaceArea
calculate surface area 4pir^2
output surface area, volume
*/

#include <iostream>
#include <math.h>
using namespace std;

//written using sphereVolumeArea from CSCI 1300 Moodle page
int main(){
    cout << "Enter a radius: " << endl;
    double radius;
    cin >> radius;
    double volume;
    volume = (4.0/3.0) * M_PI * pow(radius, 3); 		//calculate volume
    cout << "volume: " << volume << endl;
	double surfaceArea;									//create variable surfaceArea
	surfaceArea = (4)*(M_PI)*(pow(radius, 2));			//calculate surface area
	cout << "surface area: " << surfaceArea;			//output surface area
	return 0;	
}