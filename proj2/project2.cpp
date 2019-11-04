// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Project 2
#include <iostream>
using namespace std;
#include <algorithm>
#include <fstream>
#include "Book.h"
#include "User.h"
#include "Library.h"

void menu(){
    cout << "Select a numerical option:" << endl;
    cout << "======Main Menu=====" << endl;
    cout << "1. Read books" << endl;
    cout << "2. Read ratings" << endl;
    cout << "3. Print all books" << endl;
    cout << "4. Print books by author" << endl;
    cout << "5. Get rating" << endl;
    cout << "6. Find number of books user rated" << endl;
    cout << "7. View ratings" << endl;
    cout << "8. Get average rating" << endl;
    cout << "9. Get average rating by author" << endl;
    cout << "10. Add a user" << endl;
    cout << "11. Checkout a book" << endl;
    cout << "12. Get recommendations" << endl;
    cout << "13. Quit" << endl;
}
int main(){
  string tempinput = "";
  int input = 0;
  string nameInp;
  menu();

  int numBooksTemp = 0;
  int numBooksStored = 0;
  int numberOfUsersTemp = 0;
  int numberOfUsersStored = 0;
  string authorInp;
  string titleInp;
  int tempRating = 0;
  int booksRead = 0;
  int avgRating = 0;
  int minRatingInp = 0;
  Library Norlin;
  int temp = 0;
  int newRating = 0;
  string stringTemp;

  while(input != 13)
  {
    getline(cin, tempinput);
    input = stoi(tempinput);

    if(input == 1)
    {
      cout << "Enter a book file name: " << endl;
      getline(cin, nameInp);

      numBooksTemp = Norlin.readBooks(nameInp);
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
      numberOfUsersTemp = Norlin.readRatings(nameInp);
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
      if (numberOfUsersStored == 0 || numBooksStored == 0) //database not initialized
      {
        cout << "Database has not been fully initialized." << endl;
      }
      else
      {
        Norlin.printAllBooks();
      }
    }
    else if (input == 4)
    {
      if (numberOfUsersStored == 0 || numBooksStored == 0) //database not initialized
      {
        cout << "Database has not been fully initialized." << endl;
      }
      else
      {
        cout << "Enter an author name: " << endl;
        getline(cin, nameInp);
        Norlin.printBooksByAuthor(nameInp);
      }
    }
    else if (input == 5)
    {
      //get rating
      cout << "Enter a user name:" << endl;
      getline(cin, nameInp);
      cout << "Enter a book title:" << endl;
      getline(cin, titleInp);
      if (numberOfUsersStored == 0 || numBooksStored == 0) //database not initialized
      {
        cout << "Database has not been fully initialized." << endl;
      }
      else
      {
        tempRating = Norlin.getRating(nameInp, titleInp);
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

    }
    else if (input == 6)
    {

      if (numberOfUsersStored == 0 || numBooksStored == 0) //database not initialized
      {
        cout << "Database has not been fully initialized." << endl;
      }
      else
      {
        //find num books user rated
        cout << "Enter a user name:" << endl;
        getline(cin, nameInp);
        booksRead = Norlin.getCountReadBooks(nameInp);
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

    }
    else if (input == 7)
    {
      if (numberOfUsersStored == 0 || numBooksStored == 0) //database not initialized
      {
        cout << "Database has not been fully initialized." << endl;
      }
      else
      {
        cout << "Enter a user name:" << endl;
        getline(cin, nameInp);
        cout << "Enter a minimum rating:" << endl;
        getline(cin, stringTemp);
        minRatingInp = stoi(stringTemp);
        Norlin.viewRatings(nameInp, minRatingInp);
      }
    }
    else if (input == 8)
    {
      if (numberOfUsersStored == 0 || numBooksStored == 0) //database not initialized
      {
        cout << "Database has not been fully initialized." << endl;
      }
      else
      {
        //get average rating
        cout << "Enter a book title:" << endl;
        getline(cin, titleInp);
        double(avgRating) = Norlin.calcAvgRating(titleInp);
        if (avgRating == -3)
        {
          cout << titleInp << " does not exist." << endl;
        }
        else
        {
          cout << "The average rating for " << titleInp << " is " << avgRating << endl;
        }
      }

    }
    else if(input == 9)
    {
      if (numberOfUsersStored == 0 || numBooksStored == 0) //database not initialized
      {
        cout << "Database has not been fully initialized." << endl;
      }
      else
      {
        cout << "Enter an author name:" << endl;
        getline(cin, nameInp);
        double(avgRating) = Norlin.calcAvgRatingByAuthor(nameInp);
        if (avgRating == -3)
        {
          cout << nameInp << " does not exist." << endl;
        }
        else
        {
          cout << "The average rating for " << nameInp << " is " << avgRating << endl;
        }
      }
    }
    else if(input == 10)
    {
        cout << "Enter a user name:" << endl;
        getline(cin, nameInp);
        temp = Norlin.addUser(nameInp);
        if (temp == 1)
        {
          cout << "Welcome to the library " << nameInp << endl;
           numberOfUsersStored++;
        }
        else if(temp == 0)
        {
          cout << nameInp << " already exists in the database." << endl;
        }
        else
        {
          cout << "Database is already full. " << nameInp << " was not added." << endl;
        }
    }
    else if(input == 11)
    {
      if (numberOfUsersStored == 0 || numBooksStored == 0) //database not initialized
      {
        cout << "Database has not been fully initialized." << endl;
      }
      else
      {
        cout << "Enter a user name:" << endl;
        getline(cin, nameInp);
        cout << "Enter a book title:" << endl;
        getline(cin, titleInp);
        cout << "Enter a new rating:" << endl;
        getline(cin, stringTemp);
        newRating = stoi(stringTemp);
        temp = Norlin.checkOutBook(nameInp, titleInp, newRating);
        if (temp == 1)
        {
          cout << "We hope you enjoyed your book. The rating has been updated." << endl;
        }
        else if (temp == -4)
        {
          cout << newRating << " is not valid." << endl;
        }
        else if (temp == -3)
        {
          cout << nameInp << " or " << titleInp << " does not exist." << endl;
        }
      }
    }
    else if(input == 12)
    {
      if (numberOfUsersStored == 0 || numBooksStored == 0) //database not initialized
      {
        cout << "Database has not been fully initialized." << endl;
      }
      else
      {
        cout << "Enter a username:" << endl;
        getline(cin, nameInp);
        Norlin.getRecommendations(nameInp);
      }
    }
    else if (input == 13)
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
