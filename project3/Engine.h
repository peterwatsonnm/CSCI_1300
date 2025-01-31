//Engine class:
//Types of engines:  Chevy 308, Chevy 350, 7.0 Hemi, 5.7 L LS, LSX

using namespace std;
#include <string>
#include <vector>

#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
private:
  string type;
  int horsepower;
  double tilesPerGal;
  int price;
public:
  Engine();
  Engine(string name, int hp, double mpg, int price1);
  string getName();
  int getHorsepower();
  double getTPG();
  int getPrice();
};

#endif
