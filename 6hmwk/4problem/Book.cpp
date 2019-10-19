// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 6 - Problem 3
//implementation file for Book class

#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(){      //default constructor
  title = "";
  author = "";
}
Book::Book(string bookTitle, string bookAuthor){            //parameterized constructor
  title = bookTitle;
  author = bookAuthor;
}
void Book::setTitle(string bookTitle){
  title = bookTitle;
}
void Book::setAuthor(string bookAuthor){
  author = bookAuthor;
}
string Book::getAuthor(){
  return author;
}
string Book::getTitle(){
  return title;
}
