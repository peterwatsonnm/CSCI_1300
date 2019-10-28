// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 6 - Problem 7
#include <iostream>
using namespace std;
#include <algorithm>
#include <fstream>
#include "Book.h"
#include "User.h"


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

int readBooks(string fileName, Book bookArr1[], int numBookStored, int size){
    ifstream file1(fileName);
    string line = "";
    string arr1[2 * size];
    Book tempBook;

    //check for unexpected values
     if (!(file1.is_open()))
    {
        return -1;
    }
    if (numBookStored == size)
    {
        return -2;
    }

    //loop filling the arrays starting at numBookStored
    int n = 0;
    while(numBookStored < size && getline(file1, line))
    {
        if (!(line == ""))    //do not process empty lines
        {
          split(line, ',', arr1);
          tempBook.setAuthor(arr1[0]);      //get 1st val of array as author
          tempBook.setTitle(arr1[1]);       //get 2nd val of array as title
          bookArr1[numBookStored] = tempBook;
          numBookStored += 1;
        }

    }
    file1.close();
    return numBookStored;
}

int readRatings(string fileName, User users[], int numUsers, int usersArrSize, int maxColumns){
    ifstream file1(fileName);
    string line;
    int row = 0;
    string tempArr[100];
    int numberRatings;


    //check for unexpected values

    if (numUsers >= usersArrSize)            //edge case 1
    {
        return -2;
    }

     if (!(file1.is_open()))
    {
        return -1;
    }



    while(numUsers < (usersArrSize) && getline(file1, line))              //while the ammount of users does not exceed the row storage space in the 2d array
    {
        if(line != "")                                            //do not process empty lines
        {
            split(line, ',', tempArr);
            users[numUsers].setUsername(tempArr[0]);                            //populate the array value with an author

            for (int i = 1; i < (maxColumns + 1); i++)                    //take the rest of the values in tempArr and store them as ratings, it must be maxColumns + 1 so that it can access the last column
            {
                if (tempArr[i] != "")
                {

                    users[numUsers].setRatingAt((i - 1), stoi(tempArr[i]));            //spopulate the array value with the ratings, i-1 to get the index starting at 0
                    numberRatings += 1;                                         //increment number of ratings stored in array
                }
            }
            users[numUsers].setNumRatings(numberRatings);                       //set num ratings for that value in the array of users
          numUsers++;

        }
    }
    return numUsers;
}

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
  int ratingsTotal = 0;   //total value of ratings
  int ratingToAdd = 0;
  int numRatings = 0;     //number of ratings to divide by

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
  for(int i = 0; i < numUsersStored; i++)
  {
    tempUsername = users[i].getUsername();
    ratingToAdd = getRating(tempUsername, title, users, books, numUsersStored, numBooksStored);     //get this user's rating
    if (ratingToAdd > 0)    //if there is a rating to add
    {
      ratingsTotal += ratingToAdd;
      numRatings++;
    }
  }
  if (ratingsTotal == 0)    //if no ratings found return 0, also prevents divide by zero error if no ratings are found
  {
    return 0;
  }
  return(double(ratingsTotal) / double(numRatings));
  //return average
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

void menu(){
  cout << "======Main Menu=====" << endl;
  cout << "1. Read books" << endl;
  cout << "2. Read ratings" << endl;
  cout << "3. Get rating" << endl;
  cout << "4. Find number of books user rated" << endl;
  cout << "5. Get average rating" << endl;
  cout << "6. Quit" << endl;
}

int main(){
  string tempinput = "";
  int input = 0;
  string nameInp;
  menu();
  Book bookArr1[50];
  User userArr[100];
  int numBooksTemp = 0;
  int numBooksStored = 0;
  int numberOfUsersTemp = 0;
  int numberOfUsersStored = 0;
  string authorInp;
  string titleInp;
  int tempRating = 0;
  int booksRead = 0;
  int avgRating = 0;

  while(input != 6)
  {
    getline(cin, tempinput);
    input = stoi(tempinput);

    if(input == 1)
    {
      cout << "Enter a book file name: " << endl;
      getline(cin, nameInp);

      numBooksTemp = readBooks(nameInp, bookArr1, numBooksStored, 50);
      if (numBooksTemp >= 0)
      {
        if ((numBooksTemp < 50))
        {
          numBooksStored = numBooksTemp;
          cout << "Total books in the database: " << numBooksStored << endl;

        }
        if (numBooksTemp == 50)
        {
          cout << "Database is full. Some books may have not been added." << endl;
          numBooksStored = 50;
        }
      }
      else if (numBooksTemp == -1)
      {
        cout << "No books saved to the database." << endl;
        numBooksStored = 0;
      }
      else if (numBooksTemp == -2)
      {
        cout << "Database is already full. No books were added." << endl;

      }
    }
    else if(input == 2)
    {
      //read ratings
      cout << "Enter a user file name:" << endl;
      getline(cin, nameInp);
      numberOfUsersTemp = readRatings(nameInp, userArr, numberOfUsersStored, 100, 50);
      if (numberOfUsersTemp == -1)
      {
        cout << "No users saved to the database." << endl;
      }
      else if (numberOfUsersTemp == -2)
      {
        cout << "Database is already full. No users were added." << endl;
      }
      else if (numberOfUsersTemp == 100)
      {
        cout << "Database is full. Some users may have not been added." << endl;
        numberOfUsersStored = numberOfUsersTemp;
      }
      else
      {
        numberOfUsersStored = numberOfUsersTemp;
        cout << "Total users in the database: " << numberOfUsersStored << endl;
      }
    }
    else if (input == 3)
    {
      //get rating
      cout << "Enter a user name:" << endl;
      getline(cin, nameInp);
      cout << "Enter a book title:" << endl;
      getline(cin, titleInp);
      tempRating = getRating(nameInp, titleInp, userArr, bookArr1, numberOfUsersStored, numBooksStored);
      if (tempRating == 0)
      {
        cout << nameInp << " has not rated " << titleInp << endl;
      }
      else if (tempRating == -3)
      {
        cout << nameInp << " or " << titleInp << " does not exist." << endl;
      }
      else
      {
        cout << nameInp << " rated " << titleInp << " with " << tempRating << endl;
      }

    }
    else if (input == 4)
    {
      //find num books user rated
      cout << "Enter a user name:" << endl;
      getline(cin, nameInp);
      booksRead = getCountReadBooks(nameInp, userArr, numberOfUsersStored, numBooksStored);
      if (booksRead == 0)
      {
        cout << nameInp << " has not rated any books." << endl;
      }
      else if (booksRead == -3)
      {
        cout << nameInp << " does not exist." << endl;
      }
      else
      {
        cout << nameInp << " rated " << booksRead << " books." << endl;
      }
    }
    else if (input == 5)
    {
      //get average rating
      cout << "Enter a book title:" << endl;
      getline(cin, titleInp);
      double(avgRating) = calcAverageRating(userArr, bookArr1, numberOfUsersStored, numBooksStored, titleInp);
      if (avgRating == -3)
      {
        cout << titleInp << " does not exist." << endl;
      }
      else
      {
        cout << "The average rating for " << titleInp << " is " << avgRating << endl;
      }
    }
    else if (input == 6)
    {
      cout << "Good bye!" << endl;
      return 0;
    }
    else
    {
      cout << "Invalid input." << endl;
    }
    menu();
  }
  return 0;
}
