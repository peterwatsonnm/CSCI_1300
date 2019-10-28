// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 7 - Problem 4
//get count read books

#include "User.h"
#include <iostream>
using namespace std;
#include <algorithm>
#include <string>

/*
Algorithm: counts how many books a given user has rated.
4 parameters:
○ string​ : username
○ Array of User objects​ : ​ users
○ int​ : number of users currently stored in the ​ users​ array
○ int​ : number of books currently stored the books array

findUsername
  iterate through every user in Users array
  check if the username matches the parameter (case insensitive)
  return index
for that username
  iterate through each of the ratings in its ratings array until numBooksStored is reached
  for every rating that is not 0, add 1 to count

  return -3 if no ratings are stored or user is not found
*/

int findUsername(string username, User users[], int numUsers){
  int index = -3;
  string tempUsername = "";
  //set all characters of username to lowercase so that case doesn't matter
  for_each(username.begin(), username.end(), [](char & c){
    c = tolower(c);
  });
  for (int i = 0; i < numUsers; i++)
  {
    //set to lowercase
    tempUsername = users[i].getUsername();
    for_each(tempUsername.begin(), tempUsername.end(), [](char & c){
      c = tolower(c);
    });
    if (tempUsername == username)
    {
      index = i;                               //return the location where the username matched
      //could put code here to return multiple users if multiple users are found
    }
  }
  return index;
}

int getCountReadBooks(string username, User users[], int numUsersStored, int numBooksStored){
    int index = findUsername(username, users, numUsersStored);
    int readBooks = 0;

    //edge case
    if (numBooksStored == 0){
      return -3;      //no books stored in array
    }

    if (index >= 0){
      //iterate through user's ratings
      for (int i = 0; i < numBooksStored; i++)
      {
        if(users[index].getRatingAt(i) != 0)    //if a rating exists
        {
          readBooks++;
        }
      }
      return readBooks;
    }
    else    //username was not found
    {
      return index;
    }

}

int main(){
  //Creating 2 users
  User users[2];
  //Setting username and ratings for User1
  users[0].setUsername("User1");
  users[0].setNumRatings(2);
  users[0].setRatingAt(0,2);
  users[0].setRatingAt(1,2);
  //Setting username and ratings for User2
  users[1].setUsername("User2");
  users[1].setNumRatings(4);
  users[1].setRatingAt(0,4);
  users[1].setRatingAt(1,4);

  //test case 1: getCountReadBooks for User2
  cout << getCountReadBooks("User2", users,2,3) << endl;

  //test case 2 user does not exist
  cout << getCountReadBooks("User4", users,2,3) << endl;

  //test case 3 there is a case-sensitive typo in the username
  cout << getCountReadBooks("USer2", users,2,3) << endl;
  return 0;
}
