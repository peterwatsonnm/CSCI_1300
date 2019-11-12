/*
Car:
The car class stores the attributes and actions of your current vehicle.
These include amount of fuel, horsepower/speed (which can be improved with upgrades),
as well as possibly attack/defensive mods
  Health
  Horsepower
  boolean values to represent the status of the car
    hasflattires
    is driving
    is broken

*/


using namespace std;
#include <string>

#ifndef CAR_H
#define CAR_H

class Car
{
private:
  bool engineRuns;
  bool tiresFlat;
  bool isBurning;
  int horsepower;
  string engine;
  string model;
public:
  Car();
  Car(int newHorse, string engine1, string type);
  int setHorsepower(int newHorse);
  void setEngine(string newEngine);
  bool doesEngineRun();
  bool areTiresFlat();
  bool isCarBurning();
  int getHorsepower();
  string getEngine();
  string getModel();
};

#endif
