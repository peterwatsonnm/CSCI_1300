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
  //Car maxCar;
  int xPos;
  int yPos;
public:
  Player();
  int getHealth();
  int getDamage();
  int getDefense();
  int howMuchLoot();
  string getCarModel();
  string getCarEngine();
  int getCarHorsepower();
  int heal();
  int harm(int damage);
  int upgradeDamage(int pointsToAdd);
  int upgradeDefense(int pointsToAdd);
  int acquireLoot(int newLoot);
  int getXPos();
  int getYPos();
  void setXPos(int x);
  void setYPos(int y);
};

#endif
