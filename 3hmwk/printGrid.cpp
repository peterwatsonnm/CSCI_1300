// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 3 - Problem 10 -- print grid function
#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm:  print a grid of n squares
type: void
one integer parameter

until countColumn = n
    until countRow = n
        print +--
        countRow++
    print + to cap the end of the grid
    endline
    until countRow = n + 1
        print "|  "
        countRow++
    endline

do one more time to cap the bottom of the grid
 until countRow = n
        print +--
        countRow++
    print + to cap the end of the grid
    endline
if number is not positive, print error mesage
*/

void printGrid(int n){
    if (n > 0)
    {
        for (int countColumn = 0; countColumn < n; countColumn++)
        {
            for (int countRow = 0; countRow < n; countRow++)
            {
                cout << "+--";
            }
            cout << "+" << endl;                                    //adds the extra + on the end
            
            for (int countRow = 0; countRow < (n + 1); countRow++)                //must be n+1 because there is one extra | on the end
            {
                cout << "|  ";
            }
            cout << endl;
            
        }
        //caps the bottom of the grid    
        for (int countRow = 0; countRow < n; countRow++)
        {
            cout << "+--";
        }
        cout << "+" << endl;
    }
    else
    {
        cout << "The grid can only have a positive number of rows and columns.";
    }
}

int main(){
    //test case 1, should print 3x3 grid
    printGrid(3);
    
    //test case 2, should pring 20x20 grid
    printGrid(20);
    
    //test case 3, returns error
    printGrid(-2);
}