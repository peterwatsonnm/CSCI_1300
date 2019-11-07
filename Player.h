/*
Player:
The player class stores the attributes and actions of Max, who you play.  
  Health, damage, defense, loot
  Boolean value: in car vs not in car.  These two states will essentially be the same, but when max is in the car, he will have attributes & actions of the Car class
  If in car, can travel around map, encounter and fight random enemies on map
  If not in car, can fight enemies in encampment and interact with garage
*/

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
  int health;
  int damaage;
  int defense;
  int loot;
  bol inCar;
private:
  
};

#endif
