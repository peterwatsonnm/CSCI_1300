// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 6 - Problem 7
#include <iostream>
using namespace std;
#include <fstream>
#include "Book.h"

void printBooksByAuthor(Book booksArr[], int numBooks, string author){
    string tempArr[numBooks];
    int count = 0;
    if (numBooks > 0)
    {
       for(int i = 0; i < numBooks; i++)
       {
           if(booksArr[i].getAuthor() == author)                 //check if authors match at all indices, if a match is found, the associated book is stored in a temp array
           {
               tempArr[count] = booksArr[i].getTitle();
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

void printAllBooks(Book booksArr[], int numBooks){
    if (numBooks > 0)
    {
        cout << "Here is a list of books" << endl;
        for (int i = 0; i < numBooks; i++)
        {
            cout << booksArr[i].getTitle() << " by " << booksArr[i].getAuthor() << endl;
        }
    }
    else
    {
        cout << "No books are stored" << endl;
    }
}

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
          split(line, ',', arr1, size);
          tempBook.setAuthor(arr1[0]);      //get 1st val of array as author
          tempBook.setTitle(arr1[1]);       //get 2nd val of array as title
          bookArr1[numBookStored] = tempBook;
          numBookStored += 1;
        }

    }
    file1.close();
    return numBookStored;
}

void menu(){
  cout << "======Main Menu=====" << endl;
  cout << "1. Read books" << endl;
  cout << "2. Print all books" << endl;
  cout << "3. Print books by author" << endl;
  cout << "4. Quit" << endl;
}

int main(){
  string tempinput = "";
  int input = 0;
  string nameInp;
  menu();
  Book bookArr1[50];
  int numBooks = 0;
  string authorInp;

  while(input != 4)
  {
    getline(cin, tempinput);
    input = stoi(tempinput);

    if(input == 1)
    {
      cout << "Enter a book file name: " << endl;
      getline(cin, nameInp);

      numBooks = readBooks(nameInp, bookArr1, numBooks, 50);
      if (numBooks >= 0)
      {
        if ((numBooks < 50))
        {
          cout << "Total books in the database: " << numBooks << endl;
        }
        if (numBooks == 50)
        {
          cout << "Database is full. Some books may have not been added." << endl;
        }
      }
      else if (numBooks == -1)
      {
        cout << "No books saved to the database." << endl;
        numBooks = 0;
      }
      else if (numBooks == -2)
      {
        cout << "Database is already full. No books were added." << endl;
        numBooks = 3;
      }
    }
    else if(input == 2)
    {
      printAllBooks(bookArr1, numBooks);
    }
    else if (input == 3)
    {
      cout << "Enter name of author: " << endl;
      //cin >> authorInp;
      getline(cin, authorInp);
      printBooksByAuthor(bookArr1, numBooks, authorInp);
    }
    else if (input == 4)
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
