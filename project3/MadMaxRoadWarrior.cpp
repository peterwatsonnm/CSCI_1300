//MAD MAX: ROAD WARRIOR
//Written by Peter Watson

using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Player.h"
#include "Enemy.h"
#include "Tile.h"
#include "Car.h"


//helper functions
void generateMap(Tile map[20][40]){
  int numHardConvoys = 58;
  int numEasyConvoys = 36;
  int numHardGarages = 2;
  int numEasyGarages = 4;
  int randRow = 0;
  int randColumn = 0;
  //generate random map of 20x40, with 200 easy tiles and 200 hard tiles
  //set all tiles to wasteland tiles

  //initialize random seed
  srand (time(NULL));

  //all tiles on map are initialized to waste and easy by default
  //set the top half to hard
  for (int i = 0; i < 10; i++)
  {
    //go across columns
    for (int j = 0; j < 40; j++)
    {
      map[i][j].setDifficulty(false);
    }
  }

  //initialize top part with enemy convoys and garages
  //convoys:
  for (int i = 0; i < numHardConvoys; i++)
  {
    randRow = 10 + rand() % 10;    //generates a random index btwn 10 and 19
    randColumn = rand() % 40;
    map[randRow][randColumn].setEnemyConvoy(true);
    map[randRow][randColumn].setWaste(false);
  }

  //garages
  int j = 0;
  while (j < numHardGarages)
  {
    randRow = 10 + rand() % 10;    //generates a random index btwn 10 and 19
    randColumn = rand() % 40;       //generates a random index btwn 0 and 39
    if (map[randRow][randColumn].getWaste() == true)   //if the tile is a waste tiles
    {
      map[randRow][randColumn].setGarage(true);
      map[randRow][randColumn].setWaste(false);
      j++;
    }
  }

  //initialize lower part with enemy convoys and garages (easy)
  for (int i = 0; i < numEasyConvoys; i++)
  {
    randRow = rand() % 10;    //generates a random index btwn 0 and 10
    randColumn = rand() % 40;
    map[randRow][randColumn].setEnemyConvoy(true);
    map[randRow][randColumn].setWaste(false);
  }

  //garages
  int n = 0;
  while (n < numEasyGarages)
  {
    randRow = rand() % 10;    //generates a random index btwn 0 and 10
    randColumn = rand() % 40;       //generates a random index btwn 0 and 39
    if (map[randRow][randColumn].getWaste() == true)   //if the tile is a waste tiles
    {
      map[randRow][randColumn].setGarage(true);
      map[randRow][randColumn].setWaste(false);
      n++;
    }
  }
}
void explore(int maxPosX, int maxPosY, Tile map[20][40]){
  //explore a 3x3 square around max's current location
  for (int a = maxPosX - 1; a <= maxPosX + 1; a++)  //process max's column index
  {
    for (int b = maxPosY - 1; b <= maxPosY + 1; b++)    //process max's row index
    {
      if (map[b][a].getExplored() == false)
      {
        map[b][a].setExplored();    //if the location is unexplored, explore it
      }
    }
  }
}
Player drive(Tile map[20][40], Player max, int xIndex, int yIndex){
  //for each y index, add it to current index, and check if the index contains a garage or an enemy
  int maxPosY;
  int maxPosX;
  int i = 1;
  int j = 1;
  int xIncrement = 1;
  int yIncrement = 1;
  if (xIndex < 0)
  {
    xIncrement = -1;   //if the direction of travel is negative, make the increment negative
  }
  if (yIndex < 0)
  {
    yIncrement = -1;    //if the direction of travel is negative, make the increment negative
  }
  while (i <= abs(yIndex))    //must be abs in case y index is negative
  {
    maxPosY = max.getYPos();
    maxPosX = max.getXPos();
    //explore a 3x3 square around max's current location
    explore(maxPosX, maxPosY, map);
    //check if next place on map contains enemy/garage
    if (map[maxPosY + yIncrement][maxPosX].getGarage() == true)
    {
      //interact with garage
      i++;    //placeholder
      max.setYPos(maxPosY + yIncrement); //increment by 1
      maxPosY += yIncrement;
      explore(maxPosX, maxPosY, map);
    }
    else if (map[maxPosY + yIncrement][maxPosX].getEnemyConvoy() == true)
    {
      //fight enemy
      i++;    //placeholder
      max.setYPos(maxPosY + yIncrement); //increment by 1
      maxPosY += yIncrement;
      explore(maxPosX, maxPosY, map);
    }
    else  //is a waste tile, increment position to next tile
    {
      i ++;
      max.setYPos(maxPosY + yIncrement); //increment by 1
      maxPosY += yIncrement;
      explore(maxPosX, maxPosY, map);
    }
  }
  //done moving in y direction
  //now move in x direction
  while (j <= abs(xIndex))    //must be abs in case xIndex is negative
  {
    maxPosY = max.getYPos();
    maxPosX = max.getXPos();
    //explore a 3x3 square around max's current location
    explore(maxPosX, maxPosY, map);
      //check if next place on map contains enemy/garage
      if (map[maxPosY][maxPosX + xIncrement].getGarage() == true)
      {
        //interact with garage
        j++;//placeholder
        max.setXPos(maxPosX + xIncrement);
        maxPosX += xIncrement;
        explore(maxPosX, maxPosY, map);
      }
      else if (map[maxPosY][maxPosX + xIncrement].getEnemyConvoy() == true)
      {
        //fight enemy
        j++; //placeholder
        max.setXPos(maxPosX + xIncrement);
        maxPosX += xIncrement;
        explore(maxPosX, maxPosY, map);
      }
      else  //is a waste tile, increment position to next tile
      {
        j ++;
        max.setXPos(maxPosX + xIncrement);
        maxPosX += xIncrement;
        explore(maxPosX, maxPosY, map);
      }
    }
  return max; //return max with updated position
}
void showMap(Tile map[20][40], Player max){
  //print out the map in its current state
  for (int i = 0; i < 20; i++)
  {
    cout << 19-i;
    if ( 19 - i < 10)
    {
      cout << " ";    //fix the offset
    }
    //go through each column
    for (int j = 0; j < 40; j++)
    {

      //first, check if the tile is max's location
      if (max.getYPos() == 19 - i && max.getXPos() == j)
      {
        cout << "M";
      }
      else
      {
        if (map[19-i][j].getExplored() == true)
        {
          if (map[19-i][j].getWaste() == true && map[19-i][j].getDifficulty() == false)
          {
            //print a wasteland tile
            cout << "▓";
          }
          else if (map[19-i][j].getWaste() == true && map[19-i][j].getDifficulty() == true)
          {
            cout << "▒";
          }
          else if (map[19-i][j].getGarage() == true)
          {
            cout << 'G';
          }
          else if (map[19-i][j].getEnemyConvoy() == true)
          {
            cout << 'E';
          }
        }
        else
        {
          cout << "░";
        }
      }
    }
    cout << endl;
  }
}
void navigate(Tile map[20][40], Player max){
  //function to use wasd to navigate around the map
  //uses
  const string up = "w";
  const string left = "a";
  const string down = "s";
  const string right = "d";
  string arrow;

  cout << "Press q to quit, use WASD keys to navigate"<< endl;
  while(arrow != "q")
  {
    cin >> arrow;
    if (arrow == up)
    {
      drive(map, max, 0, 1);
    }
    else if (arrow == left)
    {
      drive(map, max, -1, 0);
    }
    else if (arrow == down)
    {
      drive(map, max, 0, 1);
    }
    else if (arrow == right)
    {
      drive(map, max, 1, 0);
    }
    else
    {
      cout << "invalid key" << endl;
    }
    showMap(map, max);
  }
}
int main(){
  Tile map[20][40];
  generateMap(map);
  Player max;
  max.setXPos(3);
  max.setYPos(3);
  explore(max.getXPos(), max.getYPos(), map);
  showMap(map, max);
  navigate(map, max);
  // //cout << "before " << max.getXPos() << "   " << max.getYPos() << endl;
  // max = drive(map, max, 15, 8);
  // //cout << "after " << max.getXPos() << "   " << max.getYPos() << endl;
  // showMap(map, max);
  // max = drive(map, max, -2, -8);
  // showMap(map, max);
  return 0;
}
