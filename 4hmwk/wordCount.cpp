// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 4 - Problem 5 -- word count
#include <iostream>
using namespace std;
#include <iomanip>
/*Algorithm: takes an English sentence and returns the number of words in the sentence
one string parameter

get length of string
if string is empty
  return 0
word count = 1
for every character in string
  if character = " "
    add one to word cout
return word count
*/

int wordCount(string str){
  int len = str.length();
  cout << len << endl;
  if(len = 0)
  {
    return 0;
  }
  else
  {
    cout << "testing1" << endl;
    int wordCount = 1;      //there is at least 1 word in the string
    for(int i = 0; i < len; i++)
    {
      cout << "testing" << endl;
      cout << str[i] << endl; //testing values
      if(str[i] = ' ')      //if there is a space, it means there is a new word
      {
        wordCount += 1;
      }
    }
    return wordCount;
  }
}

int main(){
  cout << wordCount("a b c") << endl;
}
