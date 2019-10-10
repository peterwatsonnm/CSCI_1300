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

if the string has no length
  return 0
Go through the string, character by character
  if the character is not the delimeter, add it to substring
  else
    if the charcter is the delimeter
      set substring as arr[numsplits]
      i++
      numSplits ++
include the last part of the string if it has not been done so yet
      
*/

int split(string splitMe, char delimeter, string arr[], int max){
  string substring = "";
  int numSplits = 0;
  if(splitMe.length() == 0)                 //return 0 of there is nothing in splitMe
  {
    return 0;
  }
  if(splitMe.find(delimeter) == std::string::npos)    //check if there is only one word
  {
    arr[0] = splitMe;
    return 1;
  }
  for (int i = 0; i < splitMe.length(); i++)
  {
    if (splitMe[i] != delimeter)        //increment substring until the value is the delimeter
    {
      substring += splitMe[i];
    }
    if (substring != "")              //so that it doesn't populate with empty strings
    {
      if (splitMe[i] == delimeter)
      {
        arr[numSplits] = substring;       //populate
        
        numSplits++;
        substring = "";                   //reset
      }
    }
  }
  if(splitMe[(splitMe.length() - 1)] != delimeter )     //indicates that the last part was not included
  {
  arr[numSplits] = substring;        //include the last part of the string
  numSplits++;
  }
  return numSplits;
}

int main(){
  //test case 1
  string words[6];
  cout << split(" one small step ", ' ', words, 6) << endl;
  cout << words[0] << endl;
  cout << words[1] << endl;
  cout << words[2] << endl;
  cout << words[3] << endl;
  
  //test case 2
  string words2[6];
  cout << split("cow/pig//big fish", '/', words2, 6) << endl;
  cout << words2[0] << endl;
  cout << words2[1] << endl;
  cout << words2[2] << endl;
  cout << words2[3] << endl;
}