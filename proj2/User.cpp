// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 7 - Problem 1
//implementation file for User class

#include "User.h"
#include <iostream>
using namespace std;

User::User(){    //default constructor
  username = "";
  numRatings = 0;
  //size is constant at 50
  for (int i = 0; i < SIZE; i++){
    ratings[i] = 0;
  }
}

User::User(string name, int arr1[], int ratingsStored){    //paramaterized constructor
  if (ratingsStored > SIZE){        //ratingsStored cannot exceed size
    ratingsStored = SIZE;
  }
  username = name;
  for (int i = 0; i < ratingsStored; i++){    //populate array
    ratings[i] = arr1[i];

  }
  for (int r = ratingsStored; r < 50; r++)
  {
    ratings[r] = 0;
  }

  numRatings = ratingsStored;
}
string User::getUsername(){
  return username;
}
void User::setUsername(string usernm){
  username = usernm;
}
int User::getRatingAt(int index){
  if (index < SIZE){
      return ratings[index];
  }
  else
  {
    return -1;
  }
}
bool User::setRatingAt (int index, int value){

  if (value >= 0 && index < SIZE)
  {
    ratings[index] = value;
    numRatings ++;                //increment numratings 
    if (ratings[index] == value){        //fill rating at that value and return true if it worked
      return true;
    }
    else{
      return false;
    }
  }
  else
  {
    return false;
  }

}
int User::getNumRatings(){
  return numRatings;
}
void User::setNumRatings(int ratingsStored){
  numRatings = ratingsStored;
}
int User::getSize(){
  return SIZE;
}
