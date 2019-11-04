// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Project 1 - Problem 0
//header file for Library class

#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include "User.h"
#include "Book.h"
using namespace std;

class Library
{
private:
  const int SIZEBOOK = 50;
  const int SIZEUSER = 100;
  Book books[50];
  User users[100];
  int numBooks;
  int numUsers;
public:
  Library();
  int getSizeBook();
  int getSizeUser();
  int getNumBooks();
  int getNumUsers();
  int readBooks(string filename);
  void printAllBooks();
  void printBooksByAuthor(string author);
  int readRatings(string filename);
  int getRating(string username, string title);
  int getCountReadBooks(string username);
  void viewRatings(string username, int minRating);
  double calcAvgRating(string title);
  double calcAvgRatingByAuthor(string author);
  int addUser(string username);
  int checkOutBook(string username, string title, int newRating);
  void getRecommendations(string username);

};
#endif
