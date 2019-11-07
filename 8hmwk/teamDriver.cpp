//Author: Peter Watson
//CSCI 1300 fall 2019
//Homework 8 - Problem 3 - team class

#include <fstream>
using namespace std;
#include <string>
#include <vector>
#include "Player.h"
#include "Team.h"
#include <iostream>

int main(){
  //test case 1
  // Using roster1.txt from Moodle
  Team team1("Seg Faultline");
  cout << team1.getTeamName() << endl;
  team1.readRoster("roster1.txt");
  int n1 = team1.getNumPlayers();
  cout << n1 << endl;
  for (int i = 0; i < n1; i++)
  {
  cout << team1.getPlayerName(i) << " ";
  cout << team1.getPlayerPoints(i) << endl;
  }
  //test case 2
  // Using roster1.txt from Moodle
  Team team3("Oh no!");
  cout << team3.getTeamName() << endl;
  team3.readRoster("roster1.txt");
  int n3 = team3.getNumPlayers();
  cout << n3 << endl;
  cout << team3.getPlayerName(-1) << " ";
  cout << team3.getPlayerPoints(-1) << endl;
  cout << team3.getPlayerName(4) << " ";
  cout << team3.getPlayerPoints(4) << endl;
  return 0;
}
