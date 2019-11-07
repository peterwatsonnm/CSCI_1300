//Author: Peter Watson
//CSCI 1300 fall 2019
//Homework 8 - Problem 2 - player class

#ifndef PLAYER_H
#define PLAYER_H
using namespace std;
#include <string>
#include <vector>

class Player
{
private:
  string name;
  double points;
public:
  Player();
  Player(string name1, double points1);
  string getName();
  double getPoints();
  void setName(string name1);
  void setPoints(double points1);
};
#endif
