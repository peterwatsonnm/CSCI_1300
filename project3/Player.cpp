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
  health = 50;
  damage = 20;
  defense = 10;
  //maxCar.setHorsepower(200);
}
int Player::getHealth(){

}
int Player::getDamage(){

}
int Player::getDefense(){

}
int Player::howMuchLoot(){
  return loot;
}
void Player::heal(){

}
int Player::harm(int damage){

}
int Player::upgradeDamage(int pointsToAdd){

}
int Player::upgradeDefense(int pointsToAdd){

}
int Player::acquireLoot(int newLoot){
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
