// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 5 - Problem 7 -- read ratings
#include <iostream>
using namespace std;
#include <fstream>

/*Algorithm: loads user ratings by reading the ratings.txt file. The first
value of each line in ratings.txt is the username. Each username is followed by a list of
ratings of the user for each book in books.txt.

six arguments in this order:
○ string: the name of the file to be read
○ Array of strings: users
○ 2 dimensional int array: ratings - list of ratings for each user.The number of
rows corresponds to the number of users, and the number of columns
corresponds to the number of books.
○ int: numUsers number of users currently stored in the arrays
○ int: maxRows maximum number of rows of the ratings 2D array (convention:
array[row][column]) [assume to be 100]
○ int: maxColumns maximum number of columns of the ratings 2D array [assume to be 50]

read each line in the file, while it is able to be read and the arrays aren't full
    for each line, if it isn't empty
        split the file into a temp array with length maxcolums + 1
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

int readRatings(string fileName, string users[], int ratings[][50], int numUsers, int maxRows, int maxColumns){
    ifstream file1(fileName);
    string line;
    int row = 0;
    string tempArr[maxColumns + 1];
    
    //check for unexpected values
    
    if (numUsers == maxRows)            //edge case 1
    {
        return -2;
    }
    
     if (!(file1.is_open()))
    {
        return -1;
    }
    
    
    
    while(numUsers < maxRows && getline(file1, line))              //while the ammount of users does not exceed the row storage space in the 2d array
    {
        if(line != "")                                            //do not process empty lines
        {
            split(line, ',', tempArr);
            users[numUsers] = tempArr[0];                            //fill the next space in the array with the user
            
            for (int i = 1; i < (maxColumns + 1); i++)                    //take the rest of the values in tempArr and store them as ratings, it must be maxColumns + 1 so that it can access the last column
            {
                if (tempArr[i] != "")
                {
                    
                    ratings[numUsers][i - 1] = stoi(tempArr[i]);            //subtract 1 from i so that the index is correct
                }
            }
          numUsers++;  
        }
    }
    return numUsers;
}

int main(){
    //test case 1 
    string users[10];
    int ratings[10][50];
    
    cout << readRatings("ratings.txt", users, ratings, 4, 4, 50) << endl;
    
    //test case 2
    cout << readRatings("ratings.txt", users, ratings, 0, 10, 50);
    return 0;
}