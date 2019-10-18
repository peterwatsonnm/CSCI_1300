// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 5 - Problem 3-- print all books
#include <iostream>
using namespace std;
#include <fstream>

/*Algorithm: prints out all the books and authors in an array
if number than books greater than 0
    loop starting at zero and going to length of arrays
        print each value of the arrays
else
    print no books stored
*/

void printAllBooks(string titles[], string authors[], int numBooks){
    if (numBooks > 0)
    {
        cout << "Here is a list of books" << endl;
        for (int i = 0; i < numBooks; i++)
        {
            cout << titles[i] << " by " << authors[i] << endl;
        }
    }
    else
    {
        cout << "No books are stored" << endl;
    }
}

int main(){
    //test case 1
    string authors1[3] = {"billy", "bobby", "sally"};
    string titles1[3] = {"the big lez", "sassy the sasquatch", "the sick cun"};
    printAllBooks(titles1, authors1, 3);
    
    //test case 2
    printAllBooks(titles1, authors1, 0);
    return 0;
}