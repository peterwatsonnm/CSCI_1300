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
#include "Engine.h"

#ifndef CAR_H
#define CAR_H

class Car
{
private:
  Engine motor;
  double gas;
  int health;
public:
  Car();
  Car(Engine engine1, double gas);
  void setGas(double newGas);
  double getGas();
  void setEngine(Engine en1);
  Engine getEngine();
  void setHealth(int newh);
  int getHealth();
};

#endif
