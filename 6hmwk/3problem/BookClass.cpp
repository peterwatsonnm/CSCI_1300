// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 6 - Problem 3
//driver file for Book class

#include "Book.h"
#include <iostream>
using namespace std;

int main(){
  Book myBook("Sassy's adventure", "Donny");
  cout << myBook.getTitle() << endl;
  cout << myBook.getAuthor() << endl;
  myBook.setAuthor("abc");
  myBook.setTitle("clazzo");
  cout << myBook.getTitle() << endl;
  cout << myBook.getAuthor() << endl;

  return 0;
}
