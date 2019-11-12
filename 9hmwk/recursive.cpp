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
● Your function should use recursion
● Your function should return the binary representation of the given value as a ​ string

take input number,
divide by 2
recursively call function
  add this to remainder
return remainder

*/

string decimalToBinaryRecursive(int numToDivide){
  string binRep = "";
  int temp;
  string binRepFinal = "0";

  binRep += to_string(numToDivide % 2);     //will be 0 or 1
  numToDivide = numToDivide / 2;
  if (numToDivide != 0)
  {
    binRep = decimalToBinaryRecursive(numToDivide) + binRep;
  }
  return binRep;
}


int main(){
  cout << decimalToBinaryRecursive(5) << endl;
  cout << decimalToBinaryRecursive(0) << endl;
  cout << decimalToBinaryRecursive(1) << endl;
  cout << decimalToBinaryRecursive(26) << endl;
  return 0;
}
