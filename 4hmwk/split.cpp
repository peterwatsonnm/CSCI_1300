// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 4 - Problem 6 -- split
#include <iostream>
using namespace std;

/*Algorithm: takes four input arguments: 
a string to be split, 
a character to split on (“a delimiter”), 
an array of strings to fill with the split pieces of the input string, 
and an integer representing the maximum number of split string pieces. 

The function will split the input string in to pieces separated by the delimiter, 
and populate the array of strings with the split pieces up to the provided maximum number of pieces

position = 0

do this until i= max, i++
  while character != delimeter
  if character = delimeter
    mark position
    create substring from last marked position to this new marked position
    store this substring in the array
*/

/*void popArray(string str, string arr1[], int length){     //length = maximum number of split pieces
  for(i = 0, i < length, i++)
  {
  
  }
}*/

int split(string splitMe, char delimiter, string arr[], int max){
  int markedPos = 0;
  int numSplits = 0;
  for(int i = 0; i < max; i++)      //do until 6 strings are found
  {
    if (splitMe[i] == std::string::npos)
    {
      return numSplits;
    }
    if (splitMe[i] == delimiter)
    {
      string substring = splitMe.substr(markedPos, (i - 1));      //create substring from last marked position to delimeter
      markedPos = i + 1;
      arr[i] = substring;
      numSplits += 1;
    }
  }
}

int main(){
  //test case 1 
  
  return 0;
}
