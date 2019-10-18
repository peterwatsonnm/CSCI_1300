// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 5 - Problem 4-- print books by author
#include <iostream>
using namespace std;
#include <fstream>

/*Algorithm: print out books from an array by a certain author
four parameters in the following order:
○ Array of strings: titles
○ Array of strings: authors
○ int: number of books
○ string: author name

if no books
    print no books stored

for each value in authors
    if it equals author name
    store the book associated with it in an array
    add one to count
if no books by author (count = 0)
    print no books by author
else
print values in books array


*/

void printBooksByAuthor(string titles[], string authors[], int numBooks, string author){
    string tempArr[numBooks];
    int count = 0;
    if (numBooks > 0)
    {
       for(int i = 0; i < numBooks; i++)
       {
           if(authors[i] == author)                 //check if authors match at all indices, if a match is found, the associated book is stored in a temp array
           {
               tempArr[count] = titles[i];
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
    string authors1[4] = {"billy", "bobby", "sally", "sally"};
    string titles1[4] = {"the big lez", "sassy the sasquatch", "the sick cun", "cecil the sasquatch"};
    printBooksByAuthor(titles1, authors1, 4, "sally");
    
    //test case 2
    printBooksByAuthor(titles1, authors1, 4, "lez");
    
    
    return 0;
}