//Author: Peter Watson
//CSCI 1300 fall 2019
//Homework 8 - Problem 3 - team class

#ifndef TEAM_H
#define TEAM_H
using namespace std;
#include <string>
#include <vector>
#include "Player.h"

class Team
{
private:
  string teamName;
  vector<Player> players;
public:
  Team();
  Team(string name);
  void setTeamName(string name);
  void readRoster(string filename);
  string getPlayerName(int i);
  double getPlayerPoints(int i);
  int getNumPlayers();
  string getTeamName();
};
#endif
