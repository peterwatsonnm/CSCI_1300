//Author: Peter Watson
//CSCI 1300 fall 2019
//Homework 8 - Problem 4 - game function

#include <fstream>
using namespace std;
#include <string>
#include <vector>
#include "Player.h"
#include "Team.h"
#include <iostream>

/*
check if both teams have 4 players
if the do
  if one team is a winner
    return this team's name
  if other team is winner
    return this team's name
  else
    return draw
*/

string game(Team badBoyz, Team krazyKidz){
  if (badBoyz.getNumPlayers() >= 4 && krazyKidz.getNumPlayers() >= 4)
  {
    double badBoyzPoints = 0;
    double krazyKidzPoints = 0;
    for (int i = 0; i < 4; i++)
    {
      badBoyzPoints += badBoyz.getPlayerPoints(i);
    }

    for (int n = 0; n < 4; n++)
    {
      krazyKidzPoints += krazyKidz.getPlayerPoints(n);
    }

    if (badBoyzPoints > krazyKidzPoints)
    {
      return badBoyz.getTeamName();
    }
    else if (krazyKidzPoints > badBoyzPoints)
    {
      return krazyKidz.getTeamName();
    }
    else
    {
      return "draw";
    }
  }
  else
  {
    return "forfeit";
  }
}

int main(){
  //test case 1
  Team team1("Seg Faultline");
  team1.readRoster("roster1.txt");
  Team team2("Team Maim");
  team2.readRoster("roster2.txt");
  string winner = game(team1, team2);
  cout << "The winner is: " << winner << endl;


  //test case 2
  Team team4("Thats so Ravenclaw");
  team4.readRoster("roster1.txt");
  Team team5("Planes on a Snake");
  team5.readRoster("roster1.txt");
  winner = game(team4, team5);
  cout << "The winner is: " << winner << endl;

  //test case 3

  Team team8("Hurt Shoebox");
  team8.readRoster("roster0.txt");
  Team team9("Team Maim");
  team9.readRoster("roster2.txt");
  winner = game(team8, team9);
  cout << "The winner is: " << winner << endl;
  return 0;
}
