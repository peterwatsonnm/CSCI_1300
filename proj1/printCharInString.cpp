// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Project 1 - Problem 1 -- print char in string function
#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: print all the characters in a string on their own line, or report that the string is empty 
type: void
one string parameter

store string length in variable length
if length == 0
    error message
loop (length) times, starting at n = 0
    output the nth letter of the string, end line
    increment n
*/

void printCharInString(string str){
    int length = str.length();           // store length of string as an integer
    if (length == 0)
    {
        cout << "Given string is empty!";
    }
    for (int n = 0; n < length; n++){
        cout << str[n] << endl;         //outputs nth character of string
    }
}

int main(){
    //test case 1-- should print a b c d e
    printCharInString("abcde");
    
    //test case 2-- should print h e l l o w o r l d
    printCharInString("helloworld");
    return 0;
}