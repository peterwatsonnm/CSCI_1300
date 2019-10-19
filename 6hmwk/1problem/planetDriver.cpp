// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 6 - Problem 1
//driver file for Planet class

#include <iostream>
#include <iomanip>
#include "Planet.h"
using namespace std;

int main(){
  //create object of planet class
  Planet planet1;
  //check that default constructor initialized correctly
  cout << planet1.getName() << "..." << planet1.getRadius() << endl;
  //call setter and getter
  planet1.setRadius(354.2);
  cout << planet1.getRadius() << endl;
  //call setter and getter
  planet1.setName("Clarence");
  cout << planet1.getName() << endl;
  //test volume function
  cout << planet1.getVolume() << endl;

  return 0;
}
