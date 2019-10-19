// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 6 - Problem 3
//header file for Book class

#ifndef BOOK_H
#define BOOK_H
#include <string>

class Book
{
private:
  std::string author;
  std::string title;
public:
  Book(); //default constructor
  Book(std::string bookAuthor, std::string bookTitle);    //parameterized constructor
  void setTitle(std::string bookTitle);
  void setAuthor(std::string bookAuthor);
  std::string getAuthor();
  std::string getTitle();
};
#endif
