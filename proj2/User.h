// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 7 - Problem 1
//header file for User class

#ifndef USER_H
#define USER_H
using namespace std;
#include <string>

class User
{
private:
  const int SIZE = 50;
  string username;
  int ratings[50];
  int numRatings;

public:
  User();    //default constructor
  User(string name, int arr1[], int ratingsStored);    //paramaterized constructor
  string getUsername();
  void setUsername(string usernm);
  int getRatingAt(int index);
  bool setRatingAt (int index, int value);
  int getNumRatings();
  void setNumRatings(int ratingsStored);
  int getSize();
};
#endif
