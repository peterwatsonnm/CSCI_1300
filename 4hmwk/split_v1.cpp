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


int split(string splitMe, char delimiter, string arr[], int max){
  int markedPos = 0;
  int numSplits = 0;
  string index = "";
  int i = 0;
  int counter = 0;
  int arrayCounter = 0;
  if(splitMe.length() == 0)   //return 0 if there is no string to be split
  {
    return 0;
  }
  if(splitMe.find(delimiter) == std::string::npos)    //check if there is only one word
  {
    arr[0] = splitMe;
    return 1;
  }
  while(splitMe[i] == delimiter)
  {
    if(splitMe[i] == delimiter)
    {
      i += 1;       //advance past first (invalid) delimeter(s)
    }
  }
  do    //do until max strings are found
  {
    index = splitMe[i];
    if (i == splitMe.length())  //if, during this loop, the string ends, return the number of times it was split
    {
      return numSplits;
    }
    if (splitMe[i] == delimiter)        //if the sequence reaches the delimiter, create a substring (the split string) from the position of the last delimiter to the length that it has traveled along the sequence
    {
      if(numSplits == 0)
      {
        string substring = splitMe.substr(markedPos, (counter));      //create substring from last marked position to delimeter
        markedPos = counter + 1;
        arr[arrayCounter] = substring;
        numSplits += 1;
        counter = 0;                    //reset counter
        arrayCounter++;                 //increment array counter only once a value has been stored in the array
      }
      else 
      {
        string substring = splitMe.substr(markedPos, (counter - 1));      //create substring from last marked position to delimeter
        markedPos = counter + 1;
        arr[arrayCounter] = substring;
        
        numSplits += 1;
        counter = 0;                    //reset counter
        arrayCounter++;                 //increment array counter only once a value has been stored in the array
      }
    }
    counter++;
    i++;
  } while(i < splitMe.length() && numSplits <= max);
  if(splitMe[splitMe.length()] != delimiter)
  {
  arr[numSplits] = splitMe.substr((splitMe.length() - counter + 1), (counter + 1));        //include the last part of the string
  }
  return (numSplits + 1);
}

int main(){
  //test case 1 
  string words[6];
  cout << split(" one small step ", ',', words, 6) << endl;
  cout << words[0] << endl;
  cout << words[1] << endl;
  cout << words[2] << endl;

  return 0;
}
