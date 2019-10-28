// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 7 - Problem 3
//get ratings

#include "Book.h"
#include "User.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <algorithm>
#include <string>

/*
Algorithm: given a user’s name and a book’s title, returns the rating that the user
gave for that book.

function takes 6 parameters in the following order:
○ string​ : username
○ string​ : title of the book
○ Array of User objects​ : ​ users
○ Array of Book objects​ : ​ books
○ int​ : number of users currently stored in the ​ users​ array
○ int​ : number of books currently stored the ​ books​ array

findUsername
  iterate through every user in Users array
  check if the username matches the parameter (case insensitive)
  return index
findTitle
  iterate through the books arrays
  look for author that matches the parameter
  return index
findRating
  return rating at the index of the book which matches the user
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

int main(){

  //Creating 3 books
  Book books[3];
  //Setting book title and author for book 1
  books[0].setTitle("Title1");
  books[0].setAuthor("Author1");
  //Setting book title and author for book 2
  books[1].setTitle("TiTle2");
  books[1].setAuthor("Author2");
  //Setting book title and author for book 3
  books[2].setTitle("Title3");
  books[2].setAuthor("Author3");

  //Creating 2 users
  User users[2];
  //Setting username and ratings for User1
  users[0].setUsername("User1");
  users[0].setNumRatings(3);
  users[0].setRatingAt(0,1);
  users[0].setRatingAt(1,4);
  users[0].setRatingAt(2,2);
  //Setting username and ratings for User2
  users[1].setUsername("User2");
  users[1].setNumRatings(3);
  users[1].setRatingAt(0,0);
  users[1].setRatingAt(1,5);
  users[1].setRatingAt(2,3);

  //test case 1
  cout << getRating("USEr1", "Title2", users, books, 2, 3) << endl;

  //test case 2
  cout << getRating("User4", "Title1", users, books, 2, 3) << endl;

  //test case 3
  cout << getRating("User12", "Title10", users, books, 2, 3) << endl;
  return 0;
}
