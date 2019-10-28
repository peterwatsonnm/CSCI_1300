// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 7 - Problem 2
//read ratings

#include "User.h"
#include <iostream>
using namespace std;
#include <fstream>

/*
read each line in the file, while it is able to be read and the arrays aren't full
    for each line, if it isn't empty
        split the file into a temp array with length 50
            store 1st value of the array in the username array
            incrementing from 2nd value, store the ratings in the ratings array only if they hold a value
        increment numUsers
*/

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


int main(){
  //test case 2 checking basic operation
  User usersArr1[10];
  cout << readRatings("ratings.txt", usersArr1, 0, 10, 50) << endl;
  cout << usersArr1[0].getUsername() << endl;
  cout << usersArr1[1].getUsername() << endl;
  cout << usersArr1[2].getUsername() << endl;
  cout << usersArr1[3].getUsername() << endl;
  cout << usersArr1[0].getRatingAt(0) << endl;
  cout << usersArr1[0].getRatingAt(1) << endl;
  cout << usersArr1[0].getRatingAt(2) << endl;

  //test case 2
  User usersArr2[10];
  cout << readRatings("ratings.txt", usersArr2, 15, 10, 50) << endl;

  //test case 3 checking if it works with num users != 0
  User usersArr3[15];
  cout << readRatings("ratings.txt", usersArr3, 2, 15, 50) << endl;
  cout << usersArr3[2].getUsername() << endl;
  cout << usersArr3[3].getUsername() << endl;
  cout << usersArr3[4].getUsername() << endl;
  cout << usersArr3[5].getUsername() << endl;
  return 0;
}
