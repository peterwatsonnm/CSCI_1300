// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 6 - Problem 2
//driver file for Planet class

#include <iostream>
#include <iomanip>
#include "Planet.h"
using namespace std;

/* Algorithm: find the index of the planet with the largest radius in the array.
​ two​ parameters in the following order
○ An ​ array of planet​ objects
○ An ​ integer​ , the size of the array (possibly partially filled, so this would be the
number of actual planet elements in the array)
double max = 0
for each planet in array
  do getRadius
  if radius > max
    index = maxIndex
return maxIndex
*/

int maxRadius(Planet planetList[], int length){
  double max = 0;
  int maxIndex = -1;    //will return -1 if array is empty

  for (int i = 0; i < length; i++)
  {
    if ((planetList[i].getRadius()) > max)    //check if the radius at that index is larger than current max
    {
      maxIndex = i;
      max = (planetList[i].getRadius());
    }
  }
  return maxIndex;
}

int main(){
  //test case 1
  Planet planets1[2];
  planets1[0] = Planet("Kingdom Come", 335);
  planets1[1] = Planet("Sassy World", 435);
  int idx = maxRadius(planets1, 2);
  cout << idx << endl;
  cout << planets1[idx].getRadius() << endl;
  cout << planets1[idx].getName() << endl;    //should return sassy world

  //test case 2
  Planet planets2[3];
  planets2[0] = Planet("Donny Land", 33335);
  planets2[1] = Planet("Sassy World", 4335);
  planets2[2] = Planet("Clazo Land", 35);
  idx = maxRadius(planets2, 3);
  cout << idx << endl;
  cout << planets2[idx].getRadius() << endl;
  cout << planets2[idx].getName() << endl;    //should return donny land

  return 0;
}
