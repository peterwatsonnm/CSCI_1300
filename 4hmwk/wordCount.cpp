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
    add one to word count
return word count
*/

int getWordCount(string str){
  int len = str.length();
  if(len == 0)
  {
    return 0;
  }
  else
  {
    int words = 1;      //there is at least 1 word in the string
    for(int i = 0; i < len; i++)
    {
      if(str[i] == ' ')      //if there is a space, it means there is a new word
      {
        words += 1;
      }
    }
    return words;
  }
}

int main(){
  //test case 1
  cout << getWordCount("a b c") << endl;
  //test case 2
  cout << getWordCount("") << endl;
  //test case 1
  cout << getWordCount("a b c hi mom") << endl;
}
