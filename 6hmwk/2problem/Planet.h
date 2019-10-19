// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 6 - Problem 2
//Header file for Planet class
#ifndef PLANET_H
#define PLANET_H

#include <string>

class Planet
{
private:
  std::string planetName = "";
  double planetRadius = 0.0;

public:
  Planet();    //default constructor
  Planet(std::string planetName, double planetRadius);     //parameterized constructor
  std::string getName();
  void setName(std::string name);
  double getRadius();
  void setRadius(double name);
  double getVolume();


};
#endif
