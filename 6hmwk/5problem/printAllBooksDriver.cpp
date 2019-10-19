// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 5 - Problem 3-- print all books
#include <iostream>
using namespace std;
#include <fstream>
#include "Book.h"

/*Algorithm: prints out all the books and authors in an array
if number than books greater than 0
    loop starting at zero and going to length of arrays
        print each book object's title and author
else
    print no books stored
*/

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

int main(){
    //test case 1
    Book book1("the big lez", "billy");
    Book book2("sassy the sasquatch", "bobby");
    Book book3("the sick cun", "sally");
    Book books[3] = {book1, book2, book3};
    printAllBooks(books, 3);

    //test case 2
    printAllBooks(books, 0);
    return 0;
}
