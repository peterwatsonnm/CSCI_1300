/*
Tile objects:
Will be stored in the 2d map array: each tile will be randomly generated into 3 zones: easy, medium, and hard.
  Difficulty level: Determines what enemies may be encountered there
  Boolean isGarage: determine if it is a garage
    Max can dismount here to heal and buy things
  Boolean isWaste: Determine if it is a waste tile
    Max can drive on these
  Boolean isEnemyConvoy: Determine if it is a tile with an enemy convoy
    If it is, Max can fight the enemies and gain loot
  Boolean isExplored:  Max must explore tiles on the map to see what is around them


*/

using namespace std;
#include <string>
#include <vector>

#ifndef TILE_H
#define TILE_H

class Tile
{
private:
  bool isEasy;
  bool isGarage;
  bool isWaste;
  bool isEnemyConvoy;
  bool isExplored;
public:
  Tile();
  Tile(bool difficulty,bool garage, bool waste, bool convoy, bool explored);    //these values will be filled with random numbers when generating the map
  bool getWaste();
  bool getExplored();
  bool getDifficulty();
  bool getEnemyConvoy();
  bool getGarage();
  void setExplored();
  void setDifficulty(bool newDiff);
  void setGarage(bool newGarage);
  void setWaste(bool newWaste);
  void setEnemyConvoy(bool newEnemy);
};

#endif
