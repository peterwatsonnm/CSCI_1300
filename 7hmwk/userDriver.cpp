// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 7 - Problem 1
//driver file for User class

#include "User.h"
#include <iostream>
using namespace std;

int main(){
  User user1;
  user1.setUsername("xjnm");
  user1.setNumRatings(45);
  cout << user1.setRatingAt(40, 0) << endl;
  cout << user1.getUsername() << endl;
  cout << user1.getRatingAt(10) << endl;
  cout << user1.getNumRatings() << endl;
  return 0;
}
