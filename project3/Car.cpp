/*
bool engineRuns;
bool tiresFlat;
bool isBurning;
Engine motor;
double gas;
*/



using namespace std;
#include <string>
#include "Engine.h"
#include "Car.h"

Car::Car(){

}
Car::Car(Engine engine1, double gas1){
  motor = engine1;
  gas = gas1;
}
void Car::setGas(double newGas){
  gas = newGas;
}
double Car::getGas(){
  return gas;
}
void Car::setEngine(Engine en1){
  motor = en1;
}
Engine Car::getEngine(){
  return motor;
}
void Car::setHealth(int newh)
{
  health = newh;
}
int Car::getHealth()
{
  return health;
}
