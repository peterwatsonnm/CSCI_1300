//implementation file for Tile class
// Will be stored in the 2d map array: each tile will be randomly generated into 3 zones: easy, medium, and hard.
//   Difficulty level: Determines what enemies may be encountered there
//   Boolean isGarage: determine if it is a garage
//     Max can dismount here to heal and buy things
//   Boolean isWaste: Determine if it is a waste tile
//     Max can drive on these
//   Boolean isEnemyConvoy: Determine if it is a tile with an enemy convoy
//     If it is, Max can fight the enemies and gain loot
//   Boolean isExplored:  Max must explore tiles on the map to see what is around them

/*
bool isEasy;
bool isGarage;
bool isWaste;
bool isEnemyConvoy;
bool isExplored;
*/

using namespace std;
#include <string>
#include <vector>
#include "Tile.h"
Tile::Tile(){
  isEasy = true;
  isGarage = false;
  isWaste = true;  //wasteland by default
  isEnemyConvoy = false;
  isExplored = false; //unexplored by default
}
Tile::Tile(bool difficulty,bool garage, bool waste, bool convoy, bool explored){
  isEasy = difficulty;
  isGarage = garage;
  isWaste = waste;
  isEnemyConvoy = convoy;
  isExplored = false; //unexplored by default
}
bool Tile::getWaste(){
  return isWaste;
}

bool Tile::getExplored(){
  return isExplored;
}
bool Tile::getDifficulty(){
  return isEasy;
}
bool Tile::getEnemyConvoy(){
  return isEnemyConvoy;
}
bool Tile::getGarage(){
  return isGarage;
}

void Tile::setExplored(){
  isExplored = true;
}
void Tile::setDifficulty(bool newDiff){
  isEasy = newDiff;
}
void Tile::setGarage(bool newGarage){
  isGarage = newGarage;
}
void Tile::setWaste(bool newWaste){
  isWaste = newWaste;
}
void Tile::setEnemyConvoy(bool newEnemy){
  isEnemyConvoy = newEnemy;
}
