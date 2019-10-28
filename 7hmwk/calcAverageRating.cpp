// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 7 - Problem 5
//get average rating

#include "Book.h"
#include "User.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <algorithm>
#include <string>

/*
Algorithm:  Return average rating for a particular book
5 input arguments in the following order:
○ Array of User objects​ : ​ users
○ Array of Book objects​ : ​ books
○ int​ : number of users currently stored in the ​ users​ array
○ int​ : number of books currently stored the ​ books​ array
○ string​ : title of the book

iterate through getRating for each user in users
stop when numUsers is reached
store each value
average values over number of users that rated the book
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

int findTitle(string title, Book books[], int numBooks){
  int index = -3;
  string tempTitle = "";
  //set all characters of username to lowercase
  for_each(title.begin(), title.end(), [](char & c){
    c = tolower(c);
  });
  for (int i = 0; i < numBooks; i++)
  {
    //set to lowercase
    tempTitle = books[i].getTitle();
    for_each(tempTitle.begin(), tempTitle.end(), [](char & c){
      c = tolower(c);
    });
    if (tempTitle == title)
    {
      index = i;        //return the location where the title matched
    }
  }
  return index;
}

int getRating(string username, string title, User users[], Book books[], int numUsers, int numBooks){
  int userIndex = findUsername(username, users, numUsers);
  //return userIndex;
  int titleIndex = findTitle(title, books, numBooks);
  //return titleIndex;
  int rating = 0;
  if (titleIndex > -1 && userIndex > -1)
  {
    rating = users[userIndex].getRatingAt(titleIndex);    //rating the specified user gave to the specified book
  }
  else
  {
    rating = -3;    //user or title was not found
  }
  return rating;
}

double calcAverageRating(User users[], Book books[], int numUsersStored, int numBooksStored, string title){
  string tempUsername = "";
  double ratingsTotal = 0;   //total value of ratings
  double ratingToAdd = 0;
  double totalRatings = 0;     //number of ratings to divide by
  double average = 0;

  //edge case
  if (numUsersStored == 0)
  {
    return -3;
  }

  //if title is not found
  if (findTitle(title, books, numBooksStored) == -3)
  {
    return -3;
  }

  //iterate through each user
  for(int i = 0; i < numUsersStored - 1; i++)
  {
    tempUsername = users[i].getUsername();
    ratingToAdd = getRating(tempUsername, title, users, books, numUsersStored, numBooksStored);     //get this user's rating
    if (ratingToAdd > 0)    //if there is a rating to add
    {
      ratingsTotal += ratingToAdd;
      totalRatings++;
    }
  }
  if (ratingsTotal == 0)    //if no ratings found return 0, also prevents divide by zero error if no ratings are found
  {
    return 0;
  }
  average = ratingsTotal / totalRatings;
  return average;
}

int main(){
  //Create list of books
  Book books[2];
  books[0].setTitle("Title1");
  books[0].setAuthor("Author1");
  books[1].setTitle("Title2");
  books[1].setAuthor("Author2");
  // books[2].setTitle("Title3");
  // books[2].setAuthor("Author3");
  //Create list of users
  User users[3];
  //Setting username and ratings for User1
  users[0].setUsername("User1");
  users[0].setNumRatings(2);
  users[0].setRatingAt(0,0);
  users[0].setRatingAt(1,2);
  //Setting username and ratings for User2
  users[1].setUsername("User2");
  users[1].setNumRatings(4);
  users[1].setRatingAt(0,4);
  users[1].setRatingAt(1,4);

  users[2].setUsername("User3");
  users[2].setNumRatings(4);
  users[2].setRatingAt(0,2);
  users[2].setRatingAt(1,2);
  //test case 1 calcAvgRating for Title2 should return 3
  cout << calcAverageRating(users, books, 2, 2, "title2") << endl;

  //test case 2 title does not exist should return -3
  cout << calcAverageRating(users, books, 2, 2, "Clazzo Land") << endl;

  //test case 3 0 users stored
  cout << calcAverageRating(users, books, 0, 2, "title2") << endl;

  //test case 4 case sensitive typo should return 3
  cout << calcAverageRating(users, books, 3, 2, "TiTle1") << endl;
  return 0;
}
