// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 5 - Problem 4-- print books by author
#include <iostream>
using namespace std;
#include <fstream>
#include "Book.h"

/*Algorithm: print out books from an array by a certain author
four parameters in the following order:
○ array of book objects
○ int: number of books
○ string: author name

if no books
    print no books stored

for each book object
    if author equals author name
    store the title associated with it in an array
    add one to count
if no books by author (count = 0)
    print no books by author
else
print values in books array


*/

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

int main(){
     //test case 1
     Book book1("the big lez", "billy");
     Book book2("sassy the sasquatch", "bobby");
     Book book3("the sick cun", "sally");
     Book book4("Chuma Island", "Cecil the sasquatch");
     Book books1[4] = {book1, book2, book3, book4};
    printBooksByAuthor(books1, 4, "sally");

    //test case 2
    printBooksByAuthor(books1, 4, "lez");


    return 0;
}
