// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Project 1 - Problem 0
//implementation file for Library class

#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "User.h"
#include "Book.h"
#include "Library.h"
#include <math.h>
using namespace std;

//helper functions
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
int getRatingHelper(string username, string title, User users[], Book books[], int numUsers, int numBooks){
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
int findTitleByAuthor(string author, string matchedTitles[], int numBooks, Book books[]){
  int numTitles = 0;
  string tempAuthor = "";
  //set all characters of username to lowercase
  for_each(author.begin(), author.end(), [](char & c){
    c = tolower(c);
  });
  for (int i = 0; i < numBooks; i++)
  {
    //set to lowercase
    tempAuthor = books[i].getAuthor();
    for_each(tempAuthor.begin(), tempAuthor.end(), [](char & c){
      c = tolower(c);
    });
    if (tempAuthor == author)
    {
      matchedTitles[numTitles] = books[i].getTitle();     //if authors match, store the title in the array
      numTitles ++;        //how many titles are stored in the array
    }
  }
  return numTitles;
}
int getCountReadBooksHelper(string username, User users[], int numUsers, int numBooks){
  int index = findUsername(username, users, numUsers);
  int readBooks = 0;

  //edge case
  if (numBooks == 0){
    return -3;      //no books stored in array
  }

  if (index >= 0){
    //iterate through user's ratings
    for (int i = 0; i < numBooks; i++)
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
    return -3;
  }
}


//tested
Library::Library(){
  numBooks = 0;
  numUsers = 0;
}
int Library::getSizeBook(){
  return SIZEBOOK;
}
int Library::getSizeUser(){
    return SIZEUSER;
}
int Library::getNumBooks(){
  return numBooks;
}
int Library::getNumUsers(){
  return numUsers;
}
//tested
int Library::readBooks(string filename){
  ifstream file1(filename);
  string line = "";
  string arr1[2 * SIZEBOOK];
  Book tempBook;

  //check for unexpected values
  if (!(file1.is_open()))
  {
    return -1;
  }
  if (numBooks == SIZEBOOK)
  {
    return -2;
  }

  //loop filling the arrays starting at numBookStored
  int n = 0;
  while(numBooks < SIZEBOOK && getline(file1, line))
  {
    if (!(line == ""))    //do not process empty lines
    {
       split(line, ',', arr1);
       tempBook.setAuthor(arr1[0]);      //get 1st val of array as author
       tempBook.setTitle(arr1[1]);       //get 2nd val of array as title
       books[numBooks] = tempBook;
       numBooks += 1;
    }

 }
 return numBooks;
}
//tested
void Library::printAllBooks(){
  cout << "Here is a list of books" << endl;
  for(int i = 0; i < SIZEBOOK; i++)
  {
    if (books[i].getTitle() != "" && books[i].getAuthor() != "")
    {
      cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;    //print all books
    }
  }
}
//tested
void Library::printBooksByAuthor(string author){
  string tempArr[numBooks];
  int count = 0;
  if (numBooks > 0)
  {
    for(int i = 0; i < numBooks; i++)
    {
        if(books[i].getAuthor() == author)                 //check if authors match at all indices, if a match is found, the associated book is stored in a temp array
        {
            tempArr[count] = books[i].getTitle();
            count += 1;
        }
    }
    if (count == 0)              //no matches found
    {
        cout << "There are no books by " << author << endl;
    }
    else
    {
        cout << "Here is a list of books by " << author << endl;
     for (int i = 0; i < count; i++)     //list all the books previously stored in tempArr
     {
         cout << tempArr[i] << endl;
     }
    }
  }
  else            //no books stored
  {
     cout << "No books are stored" << endl;
  }
}
//tested
int Library::readRatings(string filename){
  ifstream file1(filename);
  string line;
  int row = 0;
  string tempArr[100];
  int numberRatings = 0;
  //check for unexpected values

  if (numUsers >= SIZEUSER)            //edge case 1
  {
      return -2;
  }

   if (!(file1.is_open()))
  {
      return -1;
  }

  while(numUsers < (SIZEUSER) && getline(file1, line))              //while the ammount of users does not exceed the row storage space in the 2d array
  {
      numberRatings = 0;    //reset numRatings
      if(line != "")                                            //do not process empty lines
      {
          split(line, ',', tempArr);
          users[numUsers].setUsername(tempArr[0]);                            //populate the array value with an author

          for (int i = 1; i < (SIZEBOOK + 1); i++)                    //take the rest of the values in tempArr and store them as ratings, it must be maxColumns + 1 so that it can access the last column
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
//tested
int Library::getRating(string username, string title){
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
//tested
int Library::getCountReadBooks(string username){
  int index = findUsername(username, users, numUsers);
  int readBooks = 0;

  //edge case
  if (numBooks == 0){
    return -3;      //no books stored in array
  }

  if (index >= 0){
    //iterate through user's ratings
    for (int i = 0; i < numBooks; i++)
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
    return -3;
  }
}
//tested
void Library::viewRatings(string username, int minRating){
  //print all books a user has rated above a minimum value
  int userIndex = findUsername(username, users, numUsers);    //find the index of the user
  int rating = 0;
  bool hasRated = false;
  if (userIndex < 0)
  {
    cout << username << " does not exist." << endl;
    hasRated = true;      //do this so that last if statement is not printed
  }
  else
  {
    //iterate through user's ratings
    //for each rating greather than or equal to the min rating
    //use getTitle to print the title
    //print the rating
    for (int i = 0; i < numBooks; i ++)
    {
      rating = users[userIndex].getRatingAt(i);
      if (rating >= minRating)
      {
        if(hasRated == false)   //only do this the first time that rating >= minRating
        {
          cout << "Here are the books that " << username << " rated" << endl;
        }
        cout << "Title : " << books[i].getTitle() << endl;
        cout << "Rating : " << rating << endl;
        cout << "-----" << endl;
        hasRated = true;
      }
    }
  }
  if (hasRated == false)   //rating has not changed
  {
    cout << username << " has not rated any books yet." << endl;
  }
}
//tested
double Library::calcAvgRating(string title){
  string tempUsername = "";
  double ratingsTotal = 0;   //total value of ratings
  double ratingToAdd = 0;
  double totalRatings = 0;     //number of ratings to divide by
  double average = 0;

  //edge case
  if (numUsers == 0)
  {
    return -3;
  }

  //if title is not found
  if (findTitle(title, books, numBooks) == -3)
  {
    return -3;
  }

  //iterate through each user
  for(int i = 0; i < numUsers; i++)
  {
    tempUsername = users[i].getUsername();
    ratingToAdd = getRatingHelper(tempUsername, title, users, books, numUsers, numBooks);     //get this user's rating
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
//tested
double Library::calcAvgRatingByAuthor(string author){
  //find the titles of the author's books
  //iterate through the book array and store title every time author is found.
  //do calc avg rating for each title, then average those two values
  string matchedTitles[numBooks];       //maximum number of matched books would be numBooks.  This array will store the books written by the author
  int numTitles = findTitleByAuthor(author, matchedTitles, numBooks, books);   //populare array, record how many titles were stored
  double ratingsTotal = 0.000000;
  double ratingToAdd = 0;
  double totalRatings = 0;
  double avgByAuthor = 0.000000;
  string tempUsername;
  if(numTitles == 0)
  {
    return -3;
  }
  for (int i = 0; i < numTitles; i++)
  {
    //for each title, go through the users who have rated it
    for(int n = 0; n < numUsers; n++)
    {
      tempUsername = users[n].getUsername();
      ratingToAdd = getRatingHelper(tempUsername, matchedTitles[i], users, books, numUsers, numBooks);     //get this user's rating
      if (ratingToAdd > 0)    //if there is a rating to add
      {
        ratingsTotal += ratingToAdd;
        totalRatings++;
      }
    }
  }
  if (totalRatings == 0)  //prevent divide by 0
  {
    return 0;
  }
  avgByAuthor = (ratingsTotal / totalRatings);
  return avgByAuthor;
}
//tested
int Library::addUser(string username){
  //check if username already exists using findUsername
  //if the array is not full
  //set next empty user in users array's username
  //increment numUsers
  if (findUsername(username, users, numUsers) >= 0)
  {
    return 0;   //user exists already
  }
  else
  {
    if (numUsers == SIZEUSER)
    {
      return -2;    //array is already full
    }
    else
    {
      users[numUsers].setUsername(username);
      numUsers++;
      return 1;   //user sucessfully added
    }
  }
}
//tested
int Library::checkOutBook(string username, string title, int newRating){
  //check if rating is a valid number
  //find index of username
  //find index of book
  //users[index].setRatingat(bookIndex, newRating)


  if (newRating >= 0 && newRating <= 5)    //check if rating is valid.  Not sure yet of this should include zero or not
  {
    if (findTitle(title, books, numBooks) >= 0 && findUsername(username, users, numUsers) >= 0)   //if both user and book exist
    {
      int userIndex = findUsername(username, users, numUsers);
      int bookIndex = findTitle(title, books, numBooks);
      users[userIndex].setRatingAt(bookIndex, newRating);
      return 1;
    }
    else
    {
      return -3;  //user or book does not exist
    }
  }
  else  //rating is invalid
  {
    return -4;
  }
}
//tested
void Library::getRecommendations(string username){
  //find user index
  //for each user in database
    //if it is not the user we are getting reccomendations for, and they have rated books
    //calculate similarity score
    //if similarity score is lower than the min (only use > not >=),
      //set it to new min
      //store index
  //get the index of all books this user rated above 3
  //store in another array all the books of these that the original user has not read
  //output these books, if they exists

  int recommendations[numBooks + 1];   //will be, at the very most, numBooks + 1 long
  int booksRecommended = 0;
  int userIndex = findUsername(username, users, numUsers);
  int numIndices = 0;
  int minSsd = 2501;      //largest possible ssd.  having this sets the first ssd as the min ssd so that the rest of them can benchmark against it
  int ssd = 0;
  int closestUserIndex = 0;
  int numRecommended = 0;
  bool hasOutput = false;


  if (userIndex < 0)
  {
    cout << username << " does not exist." << endl;
  }
  else
  {

      // i is the index of the user, j is the index of the book he/she rated
      for (int i = 0; i < numUsers; i++)
      {
        if (userIndex != i && getCountReadBooksHelper(users[i].getUsername(), users, numUsers, numBooks) > 0) //do not compare to self and do not compare to new users
        {
          //calculate ssd
          for (int j = 0; j < numBooks; j++)
          {
            ssd += pow((users[userIndex].getRatingAt(j) - users[i].getRatingAt(j)), 2);    //sum up (Aj -Bj)^2 until j = numBooks
          }

          //compare ssd
          if (ssd < minSsd)
          {
            minSsd = ssd;   //update value
            closestUserIndex = i;
          }
          ssd = 0;    //reset
        }
      }
      //cout << "closest user " << users[closestUserIndex].getUsername() << endl;

      //we now have the SSD and the index of the closest user
      for (int n = 0; n < numBooks; n++)
      {
        //go through all the user's ratings and store the index in an array every time a score is in the range AND it has not been read by user
        if (users[closestUserIndex].getRatingAt(n) >= 3 && users[userIndex].getRatingAt(n) == 0)
        {
          recommendations[numRecommended] = n;
          numRecommended++;
        }
      }
      //cout << "num indices: " << numIndices << endl;
    //now have an array full of indexes of books that the best matches user rated 3 or higher AND have not been read by user


    //cout << "num indices after update: " << numIndices << endl;

    if (numRecommended > 5)
    {
      numRecommended = 5;    //print only the first 5
    }
    //cout << "numRecommended = " << numRecommended << endl;
    if (numRecommended == 0) //recommendations were not found
    {
      cout << "There are no recommendations for " << username << " at present." << endl;
    }
    else
    {
      cout << "Here is the list of recommendations" << endl;
      for (int m = 0; m < numRecommended; m++)
      {
        cout << books[recommendations[m]].getTitle() << " by " << books[recommendations[m]].getAuthor() << endl;
      }
    }
  }
}
