// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 6 - Problem 1
//implementation file for Planet class

#include <iostream>
#include "Planet.h"
#include <math.h>
using namespace std;

//default constructor
Planet::Planet(){
  planetName = "";
  planetRadius = 0.0;
}

//parameterized constructor
Planet::Planet(string name, double radius){
  planetName = name;
  planetRadius = radius;
}

string Planet::getName(){
  return planetName;
}

void Planet::setName(string name){
  planetName = name;
}

double Planet::getRadius(){
  return planetRadius;
}

void Planet::setRadius(double radius){
  planetRadius = radius;
}

double Planet::getVolume(){
  return (4 * (M_PI) * pow(planetRadius, 3) / 3);    //volume
}
