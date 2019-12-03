//implementation file for player class
/*
int health;
int damage;
int defense;
int loot;
Car maxCar;
int xPos;
int yPos;
*/

using namespace std;
#include <string>
#include "Car.h"
#include "Player.h"
#include "Engine.h"
#include <vector>



Player::Player(){
  /*
  Default characteristics of Max:
  Car starts with 200 horsepower
  Max starts with 10 defense
  20 damage
  50 health
  */
  health = 205;
  //maxCar.setHorsepower(200);
}
int Player::getHealth(){
  return health;
}
int Player::howMuchLoot(){
  return loot;
}
void Player::heal(int healthToAdd){
  health += healthToAdd;
}
void Player::harm(int damage){
  health = health - damage;
}
void Player::acquireLoot(int newLoot){
  loot = newLoot;
}
int Player::getXPos(){
  return xPos;
}
int Player::getYPos(){
  return yPos;
}
void Player::setXPos(int x){
  xPos = x;
}
void Player::setYPos(int y){
  yPos = y;
}
Car Player::getCar(){
  return nova;
}
void Player::setCar(Car newCar){
  nova = newCar;
}
void Player::setEngine(Engine en1){
  nova.setEngine(en1);
}
