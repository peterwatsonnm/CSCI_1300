/*
Player:
The player class stores the attributes and actions of Max, who you play.
  Health, damage, defense, loot
  Boolean value: in car vs not in car.  These two states will essentially be the same, but when max is in the car, he will have attributes & actions of the Car class
  If in car, can travel around map, encounter and fight random enemies on map
  If not in car, can fight enemies in encampment and interact with garage
*/

using namespace std;
#include <string>
#include "Car.h"
#include "Engine.h"
#include <vector>

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
  int health;
  int damage;
  int defense;
  int loot;
  int xPos;
  int yPos;
  Car nova;
public:
  Player();
  int getHealth();
  int getDamage();
  int getDefense();
  int howMuchLoot();
  void heal();
  int harm(int damage);
  int upgradeDamage(int pointsToAdd);
  int upgradeDefense(int pointsToAdd);
  int acquireLoot(int newLoot);
  int getXPos();
  int getYPos();
  void setXPos(int x);
  void setYPos(int y);
  Car getCar();
  void setCar(Car newCar);
  void setEngine(Engine en);
};

#endif
