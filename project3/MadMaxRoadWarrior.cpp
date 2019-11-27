//MAD MAX: ROAD WARRIOR
//Written by Peter Watson

using namespace std;
#include <string>
#include <iostream>
#include <time.h>
#include <math.h>
#include <fstream>
#include "Player.h"
#include "Enemy.h"
#include "Engine.h"
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
    randRow = rand() % 10;    //generates a random index btwn 0 and 9
    randColumn = rand() % 40;
    map[randRow][randColumn].setEnemyConvoy(true);
    map[randRow][randColumn].setWaste(false);
  }

  //garages
  int j = 0;
  while (j < numHardGarages)
  {
    randRow = rand() % 10;    //generates a random index btwn 0 and 9
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
    randRow = 10 + rand() % 10;    //generates a random index btwn 10 and 19
    randColumn = rand() % 40;
    map[randRow][randColumn].setEnemyConvoy(true);
    map[randRow][randColumn].setWaste(false);
  }

  //garages
  int n = 0;
  while (n < numEasyGarages)
  {
    randRow = 10 + rand() % 10;    //generates a random index btwn 10 and 19
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
        if (map[b][a].getExplored() == false && b < 20 && a < 40 && b >= 0 && a >= 0) //make sure to not explore off of the map
        {
          map[b][a].setExplored();    //if the location is unexplored, explore it
        }
      }
    }
}
Player garage(Player max, Tile map[20][40]){
  /*
  If Garage is encountered:
  Upgrade engine
    types of engines:
    Small Block Ford, Chevy 350, Supercharged 3.4, 7.3 L Turbodiesel, LSX
  Upgrade damage
  Repair car
  Buy gas
  Buy rumors
  Engine(string name, int hp, int mpg, int price);
  */
  Engine engines[5] = {Engine("Small Block Ford", 200, 1, 150), Engine("Chevy 350", 275, 1, 200), Engine("Supercharged 3.4", 300, 2, 400), Engine("7.3 L Turbodiesel", 300, 3, 500), Engine("LSX", 600, 2, 600)};
  string userInp;
  int input = 0;
  bool boughtEngine = false;
  bool isEasy = false;
  int gasInput;
  int gasPrice = 20;  //gas price for hard garages will be 20
  Engine novaEngine = (max.getCar()).getEngine();
  Car tempCar = max.getCar();

  //check if it is an easy garage or hard garage
  if (((map[max.getYPos()][max.getXPos()]).getDifficulty())) //check if tile is easy tile or hard tile (isEasy returns boolean state)
  {
    isEasy = true;
  }
  cout << "welcome, traveler.  We are glad to see you back safe from your journey. \n What can we do for you?" << endl << endl;
  while (input != 6)
  {
    cout << "1. Upgrade my engine" << endl;
    cout << "2. Upgrade my weapons" << endl;
    cout << "3. Repair my car" << endl;
    cout << "4. Buy gas" << endl;
    cout << "5. Ask about rumors" << endl;
    cout << "6. Leave the garage" << endl;

    getline(cin, userInp);
    input = stoi(userInp);
    boughtEngine = false; //reset

    switch (input)
    {
      case 1:
        //upgrade engine

        cout << "New engine.  Good choice.  We have just the thing for you." << endl;
        cout << "Your " << novaEngine.getName() << " is looking bad.  You must drive this Nova hard." << endl;
        cout << "Here's what we can offer you: " << endl;
        //print out engine options
        for (int i = 0; i < 5; i++)
        {
          cout << engines[i].getName() << " with " << engines[i].getHorsepower() << " horsepower.  It will run with " << engines[i].getTPG() << " mpg., and cost " << engines[i].getPrice() << endl;
        }
        cout << "Tell us the name of the engine you want, otherwise, type none:" << endl;
        getline(cin, userInp);
        //check which one it matches
        for (int n = 0; n < 5; n++)
        {
          if (userInp == engines[n].getName() && max.howMuchLoot() >= engines[n].getPrice())    //check if max can afford the engine
          {
            cout << "Good choice.  Give us your money and we'll have it in in a jiffy" << endl;
            max.acquireLoot(max.howMuchLoot() - engines[n].getPrice());   //subtract price from max's loot
            max.setEngine(engines[n]);   //set new engine
            cout << "Your new " << ((max.getCar()).getEngine()).getName() << " is in.  You have " << max.howMuchLoot() << " loot left." << endl;

            boughtEngine = true;
          }

        }
        if (boughtEngine == false)
        {
          cout << "Either we do not have that engine or you do not have enough money.  Select again" << endl;
        }
        break;
      case 2:
        //upgrade weapons
        break;
      case 3:
        //repair Car
        break;
      case 4:
        //buy gas
        if(isEasy)
        {
          gasPrice = 10;  //gas price for easy garages is 10 loot
        }
        cout << "The price of gas is " << gasPrice << " loot per gallon. \n" << endl;
        cout << "Your Nova has " << (max.getCar()).getGas() << " gallons left.  Let's get her filled up. \n How many gallons do you want? \n";
        getline(cin, userInp);
        gasInput = stoi(userInp);
        if (max.howMuchLoot() >= (gasPrice * gasInput)) //if player has enough loot
        {
          tempCar.setGas((tempCar.getGas() + gasInput));     //set new gas to original gas + how many new gallons
          max.setCar(tempCar);    //temp car has all the same characteristics, but now has the updated gas value
          max.acquireLoot(max.howMuchLoot() - (gasPrice * gasInput));
          cout << "You've now got " << (max.getCar()).getGas() << " gallons. Use it wisely, this stuff ain't cheap." << endl;
        }
        else
        {
          cout << "What are you trying to pull on us?  You don't have enough loot for that!" << endl;
        }
        break;
      case 5:
        //ask about rumors
        break;
      case 6:
        //leave garage
        cout << "Safe travels.  Take good care of that Nova of yours." << endl << endl;
        break;
      default:
        cout << "We can't help you with that." << endl;
        break;
    }
  }
  return max;
}
void fightMenu(int enemyHP, Player max){
  // /*
  // ram vehicle
  // shoot at driver
  //
  // */
  //
  // string userInp;
  // int difference;
  // double percent;
  //
  // cout << "You downshift to engage your enemy." << endl << endl;
  // cout << "1. Ram" << endl;
  // cout << "2. Shoot Driver" << endl;
  // cout << "3. Shoot at tires" << endl;
  // getline(cin, userInp);
  // int input = stoi(userInp);
  // switch(input){
  //   case 1:
  //     //ram enemy car
  //     if ((max.getCar().getEngine()).getHorsepower() < enemyHP)
  //     {
  //       difference = enemyHP - (max.getCar().getEngine()).getHorsepower();
  //       percent = 100 - difference;   //if enemy has over 100 more hp, attack will do no damage
  //       if (percent > 0)
  //       {
  //
  //       }
  //     }
  //   case 2:
  //     //shoot at driver
  //
  //   case 3:
  //     //shoot at tires
  //
  //   default:
  //
  // }
}

Player fight(Player max, Tile map[20][40], bool isEasy, int xDirection, int yDirection){
  //fight max against an enemy warboy, using the following algorithm:
  /*
  Each time you attack, generate a random number between 1 and 20
  If this number is higher than the enemy’s defense, you inflict your full damage
  If this number is lower than the enemy’s defense, you inflict  a percent of your full damage, calculated by (Rand #) * (Damage) / (defense)
  Turn based, IE, you have a turn, then you are attacked by your enemy

  Vehicle combat:
  If Max’s tile index matches that of an enemy convoy, he can choose to fight it or run from it
  There will be some sort of indicator as to the strength and speed of the convoy.
  Max can only outrun a convoy if he is faster than them, Otherwise, when he chooses to run, he will still have to engage them, but be a turn behind.
  Combat will be turn based
  You can either disable enemies’ vehicles or kill the enemy inside them
  Ram vehicle:  Has a chance to pop tires, damage enemy, and/or set vehicle on fire
  	These chances will be dependant on your car’s horsepower
  Shoot at driver:
  	Do damage to the car’s driver based on your damage and their defense
  	If driver is killed, car crashes and sets on fire
  */

  //initialize random seed
  srand (time(NULL));

  int loot;
  int horsepower;
  string userInp;
  int difference;
  double percent;
  int chance;
  bool fighting = true;
  //generate random enemy
  if (isEasy == true)
  {
      loot = (rand() % (110 - 90 + 1)) + 90;
      horsepower = (rand() % (210 - 190 + 1)) + 190;    //generate random hp between 210 and 190
  }
  else //hard Enemy
  {
    loot = (rand() % (300 - 250 + 1)) + 250;
    horsepower = (rand() % (600 - 550 + 1)) + 550;    //generate random hp between 550 and 600
  }

  //set attributes to tempEnemy
  Enemy tempEnemy(1, 1, 1, loot);
  Engine tempEngine("Clunker", horsepower, 1, 1);
  Car tempCar(tempEngine, 1);

  cout << "Engines roar in the distance.  You've come across an enemy convoy. Choose wisely, for your life hangs from your actions." << endl << endl;
  //give indicator of the horsepower of the enemy
  //cout << horsepower << endl << endl;
  cout << "It looks like your enemy has somewhere between " << horsepower - (rand() % 10) << " and " << horsepower + (rand() % 10) << " horsepower." << endl << endl;
  cout << "Will you choose to take them on in battle, or flee back to safety? \n \n";
  while (fighting == true)
  {
    cout << "Select 'run' or 'fight' by typing one below: \n";
    getline(cin, userInp);
    if (userInp == "run")
    {
      //check if your HP is higher than their HP
      //cout << horsepower << endl << endl;
      //cout << "max hp " << ((max.getCar()).getEngine()).getHorsepower() << endl << endl;
      if (((max.getCar()).getEngine()).getHorsepower() >= horsepower)
      {
        cout << "Tires smoking, you peeled away from the enemy convoy.\n\nYour " << ((max.getCar()).getEngine()).getName() << " had just enough juice to get away.  Live to fight another day.\n";
        //update max's position, using int direction to choose which way to run
        max.setXPos((max.getXPos()) - xDirection);    //x direction will either be 0 or +-1, signed oposite of the direction in which max should run
        max.setYPos((max.getYPos()) - yDirection);    //y direction will either be 0 or +-1, signed oposite of the direction in which max should run
        fighting = false;
      }
      else
      {
        cout << "You gave it all your poor " << ((max.getCar()).getEngine()).getName() << " had, but it wasn't enough.\n\nYour Nova was overrun by a warboy convoy.  Rest in peace, Max. \n";
        //end game
        fighting = false;
      }
    }
    else if (userInp == "fight")
    {
      cout << "You downshift to engage your enemy." << endl << endl;
      cout << "1. Ram" << endl;
      cout << "2. Shoot Driver" << endl;
      cout << "3. Shoot at tires" << endl;
      getline(cin, userInp);
      int input = stoi(userInp);
      switch(input){
        case 1:
          //ram enemy car
          if ((max.getCar().getEngine()).getHorsepower() < tempEngine.getHorsepower())
          {
            difference = tempEngine.getHorsepower() - (max.getCar().getEngine()).getHorsepower();
            percent = 100 - difference;   //if enemy has over 100 more hp, attack will do no damage
            if (percent > 0)
            {
              //as difference increases, percent decreases
              chance = (rand() % 100) + 1;
              if (percent >= chance)    //by comparing percent to a random number between 1 and 100, a percentage is achieved
              {
                //do standard ram damage etc
              }
              else
              {
                cout << "You hit them hard, but not enough to get through that tough armour \n \n";
              }
            }
            else
            {
              cout << "You couldn't get going fast enough to ram them effectively.  This fight isn't looking so good \n \n";
            }
          }
          break;

        case 2:
          //shoot at driver
          break;

        case 3:
          //shoot at tires
          break;

        default:

          break;
      }
    }
    else
    {
      cout << "You're wasting valuable time \n \n";
    }
  }
  return max;
}
void showMap(Tile map[20][40], Player max){
  //print out the map in its current state
  for (int i = 0; i < 20; i++)
  {
    cout << i;
    if ( i < 10)
    {
      cout << " ";    //fix the offset
    }
    //go through each column
    for (int j = 0; j < 40; j++)
    {

      //first, check if the tile is max's location
      if (max.getYPos() == i && max.getXPos() == j)
      {
        cout << "M";
      }
      else
      {
        if (map[i][j].getExplored() == true)
        {
          if (map[i][j].getWaste() == true && map[i][j].getDifficulty() == true)
          {
            //print a wasteland tile
            cout << "▓";
          }
          else if (map[i][j].getWaste() == true && map[i][j].getDifficulty() == false)
          {
            cout << "▒";
          }
          else if (map[i][j].getGarage() == true)
          {
            cout << 'G';
          }
          else if (map[i][j].getEnemyConvoy() == true)
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
Player drive(Tile map[20][40], Player max, int xIndex, int yIndex){
  //for each y index, add it to current index, and check if the index contains a garage or an enemy
  int maxPosY;
  int maxPosX;
  int i = 1;
  int j = 1;
  int xIncrement = 0;
  int yIncrement = 0;
  Car tempCar = max.getCar();
  int tpg = ((max.getCar()).getEngine()).getTPG();
  if (xIndex < 0)
  {
    xIncrement = -1;   //if the direction of travel is negative, make the increment negative
  }
  else if (xIndex > 0)  //keep set to 0 if xIndex  = 0
  {
    xIncrement = 1; //positive travel
  }
  if (yIndex < 0)
  {
    yIncrement = -1;    //if the direction of travel is negative, make the increment negative
  }
  else if (yIndex > 0)  //keep set to 0 if yIndex  = 0
  {
    yIncrement = 1;   //positive travel
  }

  maxPosY = max.getYPos();
  maxPosX = max.getXPos();
  if ((max.getCar()).getGas() > 0)    //check if max has gas
  {
    //make sure player cannot move out of map
    if ((maxPosY + yIncrement) < 20 && (maxPosY + yIncrement) >= 0 )
    {
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
          i ++;
          max.setYPos(maxPosY + yIncrement); //increment by 1
          //reduce gas
          //tempCar.setGas(tempCar.getGas() - (1 / tpg));
          max.setCar(tempCar);    //tempCar has all the same attributes but now with less gas.
          maxPosY += yIncrement;
          explore(maxPosX, maxPosY, map);
          showMap(map, max);
          max = garage(max, map);
          break;
        }
        else if (map[maxPosY + yIncrement][maxPosX].getEnemyConvoy() == true)
        {
          //fight enemy
          //need to pass direction and bool isEasy
          //fight(Player max, Tile map[20][40], bool isEasy, int xDirection, int yDirection)
          i ++;
          max.setYPos(maxPosY + yIncrement); //increment by 1
          //reduce gas
          tempCar.setGas(tempCar.getGas() - (1 / tpg));
          max.setCar(tempCar);    //tempCar has all the same attributes but now with less gas.
          maxPosY += yIncrement;
          explore(maxPosX, maxPosY, map);
          showMap(map, max);
          max = fight(max, map, (map[maxPosY + yIncrement][maxPosX].getDifficulty()), xIncrement, yIncrement);
          //cout << "x: " << xIncrement << " Y: " << yIncrement << endl << endl;
        }
        else  //is a waste tile, increment position to next tile
        {
          i ++;
          max.setYPos(maxPosY + yIncrement); //increment by 1
          //reduce gas
          tempCar.setGas(tempCar.getGas() - (1 / tpg));
          max.setCar(tempCar);    //tempCar has all the same attributes but now with less gas.
          maxPosY += yIncrement;
          explore(maxPosX, maxPosY, map);
        }
        xIncrement = 0;
        yIncrement = 0; //reset for fight function
      }
    }
    //done moving in y direction
    //now move in x direction
    //make sure player cannot move out of map
    if ((maxPosX + xIncrement) < 40 && (maxPosX + xIncrement >= 0))
    {
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
          j ++;
          max.setXPos(maxPosX + xIncrement);
          //reduce gas
          //tempCar.setGas(tempCar.getGas() - (1 / tpg));
          max.setCar(tempCar);    //tempCar has all the same attributes but now with less gas.
          maxPosX += xIncrement;
          explore(maxPosX, maxPosY, map);
          showMap(map, max);
          max = garage(max, map);
          break;
        }
        else if (map[maxPosY][maxPosX + xIncrement].getEnemyConvoy() == true)
        {
          //fight enemy
          //fight(Player max, Tile map[20][40], bool isEasy, int xDirection, int yDirection)
          j ++;
          max.setXPos(maxPosX + xIncrement);
          //reduce gas
          tempCar.setGas(tempCar.getGas() - (1 / tpg));
          max.setCar(tempCar);    //tempCar has all the same attributes but now with less gas.
          maxPosX += xIncrement;
          explore(maxPosX, maxPosY, map);
          showMap(map, max);
          max = fight(max, map, (map[maxPosY][maxPosX + xIncrement].getDifficulty()), xIncrement, yIncrement);
          //cout << "x: " << xIncrement << " Y: " << yIncrement << endl << endl;
        }
        else  //is a waste tile, increment position to next tile
        {
          j ++;
          max.setXPos(maxPosX + xIncrement);
          //reduce gas
          tempCar.setGas(tempCar.getGas() - (1 / tpg));
          max.setCar(tempCar);    //tempCar has all the same attributes but now with less gas.
          maxPosX += xIncrement;
          explore(maxPosX, maxPosY, map);
        }
        xIncrement = 0;
        yIncrement = 0; //reset for fight function
      }
    }

  }
  return max; //return max with updated position
}
Player navigate(Tile map[20][40], Player max){
  //function to use wasd to navigate around the map
  //uses cin to get wasd value, user must press enter
  const string up = "w";
  const string left = "a";
  const string down = "s";
  const string right = "d";
  string arrow;

  showMap(map, max);
  cout << "you have " << (max.getCar()).getGas() << " gallons left." << endl;
  cout << "you can travel " << (max.getCar()).getGas() * ((max.getCar()).getEngine()).getTPG() << " miles." << endl;
  cout << "You have " << max.howMuchLoot() << " loot left." << endl;
  cout << "Press q to quit, use WASD keys to navigate.  Press enter after each selection."<< endl;
  while(arrow != "q")
  {
    if ((max.getCar()).getGas() > 0)
    {
      getline(cin, arrow);
      if (arrow == up)
      {
        max = drive(map, max, 0, -1);    //update max with new position, must be -1 because map is backwards
      }
      else if (arrow == left)
      {
        max = drive(map, max, -1, 0);
      }
      else if (arrow == down)
      {
        max = drive(map, max, 0, 1);  //must be 1 because map is backwards
      }
      else if (arrow == right)
      {
        max = drive(map, max, 1, 0);
      }
      else if (arrow == "q")
      {
        cout << "Done navigating. Good luck on your journey." << endl;
        break;
      }
      else
      {
        cout << "invalid key" << endl;
      }
      showMap(map, max);
      cout << "you have " << (max.getCar()).getGas() << " gallons left." << endl;
      cout << "you can travel " << (max.getCar()).getGas() * ((max.getCar()).getEngine()).getTPG() << " miles." << endl;
      cout << "You have " << max.howMuchLoot() << " loot left." << endl;
    }
    else
    {
      cout << "you just guzzled your last gallon.  You will be forever stranded in the wastes. \n As your skeleton melts into the soil, your car will live on in the hands of a greasy Warboy. Rest in peace, Max." << endl;
      break;
    }
  }
   //returns max with the new position
  return max;
}
void menu(){
  /*
  Menu:
  See map
  Travel to place on map (by car)

  */

}
int main(){
  //print title screen
  string line = "";
  ifstream madmax("madmax.txt");
  if (!(madmax.is_open()))
  {
    return 0;
  }
  while(getline(madmax, line))
  {
    cout << line << endl;
  }
  cout << endl << endl;

  Tile map[20][40];
  generateMap(map);
  Player max;
  Engine sbf("Small Block Ford", 220, 1, 220);
  Car charger(sbf, 4000);
  max.setCar(charger);
  max.acquireLoot(4000);
  max.setXPos(3);
  max.setYPos(15);
  explore(max.getXPos(), max.getYPos(), map);
  //showMap(map, max);
  //fight(max, map, true, -1, 1);
  max = navigate(map, max);   //returns max with the new position

  //max = garage(max, map);


  return 0;
}
