/*
Enemy:
This class stores attributes and actions of the enemies that you must fight in order to gain resources.  These include HP, damage, the loot that they guard, and possible special characteristics
  Enemies can be on foot or by car
  Difficulty level
  damage
  health
  defense

*/

using namespace std;
#include <string>
#include "Car.h"
#include <vector>

#ifndef ENEMY_H
#define ENEMY_H

class Enemy
{
private:
  int health;
  int loot;
  bool isEasy;
public:
  Enemy();
  Enemy(int newHealth, int newLoot);
  int getHealth();
  int howMuchLoot();
  void harm(int damage);
};

#endif
