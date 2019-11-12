//Author:  Peter Watson
//CSCI 1300 Fall 2019

using namespace std;
#include <string>
#include <vector>
#include <iostream>

/*
Algorithm:
converts a decimal value to binary using a
loop. This function takes a single parameter, a non-negative integer, and returns a string
corresponding to the binary representation of the given value.
● Your function should be named ​ decimalToBinaryIterative
● Your function should take a single argument
○ An ​ integer​ to be converted to binary
● Your function should not print anything
● Your function should use a loop
● Your function should return the binary representation of the given value as a ​ string

take input number,
while numToDivide is not 0
  divide by 2
  store the remainder in a string
  the result is nor numToDivide

*/

string decimalToBinaryIterative(int decNum){
  int numToDivide = decNum;
  string binRep = "";
  int temp;
  while (numToDivide != 0)
  {
    temp = numToDivide % 2;     //will be 0 or 1
    numToDivide = numToDivide / 2;
    binRep += to_string(temp);
  }
  //reverse string
  string binRepFinal = "0";
  for (int i = (binRep.length() - 1); i >= 0; i--)
  {
    binRepFinal += binRep[i];
  }
  return binRepFinal;
}

int main(){
  //test case 1, 11010
  cout << decimalToBinaryIterative(26) << endl;
  cout << decimalToBinaryIterative(0) << endl;
  cout << decimalToBinaryIterative(1) << endl;
  cout << decimalToBinaryIterative(5) << endl;
  //test case 2
  cout << decimalToBinaryIterative(2136) << endl;
  return 0;
}
