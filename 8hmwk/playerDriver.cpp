//Author: Peter Watson
//CSCI 1300 fall 2019
//Homework 8 - Problem 2 - player class

using namespace std;
#include <string>
#include "Player.h"
#include <iostream>


int main(){
  //test case 1
  Player stella;
  cout << stella.getName() << endl;
  cout << stella.getPoints() << endl;
  stella.setName("Stella");
  stella.setPoints(13.1);
  cout << stella.getName() << endl;
  cout << stella.getPoints() << endl;

  //test case 2
  Player hector("Hector", 6.2);
  cout << hector.getName() << endl;
  cout << hector.getPoints() << endl;
  return 0;
}
