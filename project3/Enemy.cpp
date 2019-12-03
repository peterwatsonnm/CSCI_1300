//implementation file for enemy class

using namespace std;
#include <string>
#include "Car.h"
#include "Enemy.h"
#include <vector>

/*
int health;
int damage;
int defense;
int loot;
bool isEasy;
*/

Enemy::Enemy(){

}
Enemy::Enemy(int newHealth, int newLoot){
  health = newHealth;
  loot = newLoot;
}
int Enemy::getHealth(){
  return health;
}
int Enemy::howMuchLoot(){
  return loot;
}
void Enemy::harm(int damage){
  health -= damage;
}
