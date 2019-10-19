// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 5 - Problem 2 -- read books
#include <iostream>
using namespace std;
#include <fstream>
#include "Book.h"

/*Algorithm: populates a pair of arrays with book objects found in books.txt.
Accept 4 input arguments in this order:
    string fileName: the name of the file to be read.
    Array of book objects
    int numBookStored: the number of books currently stored in the arrays. You can always assume this is the correct number of actual elements in the arrays.
    int size: capacity of the authors/titles arrays. This number should always be greater or equal to the number of books currently stored in the arrays.

    open books.txt
    check if books.txt opened

    When numBookStored is equal to the size, return -2
    When the file is not opened successfully, return -1


    starting at position numBookStored in both arrays, do until array is full
        get line from file
        split it into author and title strings
        store authors in author array
        store titles in title array
*/

int split(string splitMe, char delimeter, string arr1[], int max){
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

int readBooks(string fileName, Book bookArr[], int numBookStored, int size){
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
          split(line, ',', arr1, size);
          tempBook.setAuthor(arr1[0]);      //get 1st val of array as author
          tempBook.setTitle(arr1[1]);       //get 2nd val of array as title
          bookArr[numBookStored] = tempBook;
          numBookStored += 1;
        }

    }
    return numBookStored;
}

int main(){
  //test case 1
  Book books1[10];
  cout << readBooks("fileName.txt", books1, 0, 10) << endl;
  cout << books1[0].getTitle() << endl;
  cout << books1[0].getAuthor() << endl;
  cout << books1[1].getTitle() << endl;
  cout << books1[1].getAuthor() << endl;
  //test case 2
  Book books2[8];
  cout << readBooks("books.txt", books2, 2, 8) << endl;
  cout << books2[4].getTitle() << endl;
  cout << books2[4].getAuthor() << endl;
  cout << books2[5].getTitle() << endl;
  cout << books2[5].getAuthor() << endl;
  return 0;
}
