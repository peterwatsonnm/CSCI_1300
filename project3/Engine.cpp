//Engine class:
//Types of engines:  Chevy 308, Chevy 350, 7.0 Hemi, 5.7 L LS, LSX
/*
string type;
int horsepower;
int tilesPerGal;
*/


using namespace std;
#include <string>
#include <vector>
#include "Engine.h"

Engine::Engine(){
  type = "";
  horsepower = 0;
  tilesPerGal = 0;
}
Engine::Engine(string name, int hp, double mpg, int price1){
  type = name;
  horsepower = hp;
  tilesPerGal = mpg;
  price = price1;
}
string Engine::getName(){
  return type;
}
int Engine::getHorsepower(){
  return horsepower;
}
double Engine::getTPG(){
  return tilesPerGal;
}
int Engine::getPrice(){
  return price;
}
