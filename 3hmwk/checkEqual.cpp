// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 3 - Problem 2 -- check equal function
#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: takes three numbers as parameters, and prints
● “All same”, if they are all the same
● “All different”, if they are all different
● “Neither”, otherwise

type: void
parameters a,b,c are integers

if a=b=c
    print all same
if a!=b!=c
    print all different
else
    print neither
*/

void checkEqual(int a, int b, int c){
    if (a == b && b == c)                       //if a == b and b == c,then a == c
    {
        cout << "All same";
    }
    else if (a != b && b != c && a != c)
    {
        cout << "All different";  
    }
    else 
    {
        cout << "Neither";
    }
}

int main (){
    //test case 1 If the parameters are (1, 2, 3), the function should print All different
    checkEqual(1, 2, 3);
    cout << endl;
    
    //test case 2 If the parameters are (2, 2, 2), the function should print All same
    checkEqual(2, 2, 2);
    cout << endl;
    
    //test case 3 If the parameters are (1, 1, 2), the function should print Neither
    checkEqual(1, 1, 2);
    cout << endl;
}