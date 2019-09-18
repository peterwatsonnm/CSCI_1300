// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 3 - Problem 3 -- chess board function
#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: function has two parameters in this order: a character and an integer

● If function receives as input a valid character and number, then it prints either
“black” or “white”, depending on the color of the square given by those coordinates. 

● If function receives as input anything other than a-h for character, and 1-8 for number,
then it must print “Chessboard squares can only have letters between a-h
and numbers between 1-8.” 

if numper parameter greater than or equal to 1 but less than or equal to 8
    if number parameter is even, 
        if  character parameter string found within string "a, c, e, g"
            sqare is white
        else
            square is black
    else,
        if character parameter string found within string "b, d, f, h"
            square is white
        else
            square is black
else
    print error message
*/

void chessBoard(char character, int number){
    string allLetters = "a, b, c, d, e, f, g, h";
    string evenWhiteString = "a, c, e, g";               //all the letter values that yield a white square when the number is even
    string oddWhiteString = "b, d, f, h";                //all the letter values that yield a white square when the number is odd
    string letter(1, character);                        //converts character input to string so that it can be compared to another string
    
    // checking that the number and letter are on the board.  allLetters.find(letter) searches for letter inside allLetters, returns "npos" if letter does not exist in allLetters
    if (number > 0 && number < 9 && allLetters.find(letter) != std::string::npos)                      
    {
        if (number % 2 == 0)                                        //check if number is even
        {
            if (evenWhiteString.find(letter) != std::string::npos)      //use .find() to see if letter is within range of letters that make the square white
            {
                cout << "white" << endl;
            }
            else
            {
            cout << "black" << endl;                            //if the number is even but the letter is not within the list of evenWhiteString, then the square must be black
            }
        }
        else                                                    //if number is not even then it is odd
        {
            if (oddWhiteString.find(letter) != std::string::npos)           //use .find() to see if letter is within range of letters that make the square white
            {
                cout << "white" << endl;
            }
            else
            {
                cout << "black" << endl;                        //if the number is odd but the letter is not within the list of oddWhiteString, then the square must be black
            }
        }
    }
    else
    {
        cout << "Chessboard squares can only have letters between a-h and numbers between 1-8." << endl;
    }
}


int main(){
    //test case 1  arguments are (‘g’, 5), the function should print black
    chessBoard('g', 5);
    
    //test case 2 arguments are (‘A’, 10), the function should print Chessboard squares can only have letters between a-h and numbers between 1-8
    chessBoard('A', 10);
    
    //test case 3 arguments are (‘c’, 4), the function should print white
    chessBoard('c', 4);
    return 0;
}