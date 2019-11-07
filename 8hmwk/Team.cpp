//Author: Peter Watson
//CSCI 1300 fall 2019
//Homework 8 - Problem 3 - team class

#include <fstream>
using namespace std;
#include <string>
#include <vector>
#include "Player.h"
#include "Team.h"

//helper functions
int split(string splitMe, char delimeter, string arr1[]){
  string substring = "";
  int numSplits = 0;
  if(splitMe.length() == 0)                 //return 0 of there is nothing in splitMe
  {
    return 0;
  }
  if(splitMe.find(delimeter) == std::string::npos)    //check if there is only one word
  {
    arr1[0] = splitMe;
    return 1;
  }
  for (int i = 0; i < splitMe.length(); i++)
  {
    if (splitMe[i] != delimeter)        //increment substring until the value is the delimeter
    {
      substring += splitMe[i];
    }
    if (substring != "")              //so that it doesn't populate with empty strings
    {
      if (splitMe[i] == delimeter)
      {
        arr1[numSplits] = substring;       //populate

        numSplits++;
        substring = "";                   //reset
      }
    }
  }
  if(!(splitMe[(splitMe.length() - 1)] == delimeter ))     //indicates that the last part was not included
  {
  arr1[numSplits] = substring;        //include the last part of the string
  numSplits++;
  }
  return numSplits;
}

Team::Team(){
  teamName = "";
  //players is empty by default
}
Team::Team(string name){
  teamName = name;
  //players is empty by default
}
void Team::setTeamName(string name){
  teamName = name;
}
void Team::readRoster(string filename){
  ifstream file1(filename);
  string line = "";
  string arr1[2];
  Player tempPlayer;

  //check for unexpected values
  if ((file1.is_open()))
  {
    //loop filling the arrays
    while(getline(file1, line))
    {
      if (!(line == ""))    //do not process empty lines
      {
         split(line, ',', arr1);
         tempPlayer.setName(arr1[0]);      //get 1st val of array as name
         tempPlayer.setPoints(stod(arr1[1]));       //get 2nd val of array as points
         players.push_back(tempPlayer);   //add the new player to the vector
      }
    }
  }
}
string Team::getPlayerName(int i){
  if (i < players.size())
  {
    return players[i].getName();
  }
  else
  {
    return "ERROR";
  }
}
double Team::getPlayerPoints(int i){
  if (i < players.size())
  {
    return players[i].getPoints();
  }
  else
  {
    return -1;
  }
}
int Team::getNumPlayers(){
  return players.size();
}
string Team::getTeamName(){
  return teamName;
}
