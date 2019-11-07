//Author: Peter Watson
//CSCI 1300 fall 2019
//Homework 8 - Problem 2 - player class

using namespace std;
#include <string>
#include "Player.h"
#include <iostream>

Player::Player(){
  name = "";
  points = 0.0;
}
Player::Player(string name1, double points1){
  name = name1;
  points = points1;
}
string Player::getName(){
  return name;
}
double Player::getPoints(){
  return points;
}
void Player::setName(string name1){
  name = name1;
}
void Player::setPoints(double points1){
  points = points1;
}
