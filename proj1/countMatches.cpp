// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Project 1 - Problem 2 -- count matches function
#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: count how many times one string occurs in another string
type: int
two string parameters

check if the string input holds a value,
    return -1 if it does not
for i = whole string length, i++
    for n = substr length, n++
        teststring = teststring + str[n+ + i]
    compare substr to test string  
        if equal, add 1 to count
*/

int countMatches(string str, string substr){
    if (substr.length() == 0 || str.length() == 0)              //check if the parameter string holds a value
    {                 
        return -1;
    }
    //initialize teststring and numMatches variables
    string teststring = "";                                     
    int numMatches = 0;
    
    for (int i = 0; i < str.length(); i++)                  //do this comparison sequence once for every character in the string
    {
        for (int n = 0; n < substr.length(); n++)           //create a test string with the same number of characters as the substring
        {
            teststring = teststring + str[n + i];           //creating test string, starting with "" and incrementally adding each next character of str-- this is accomplished by getting the (n+i)th character of the string and adding it to what is already there
        }
        if (teststring == substr)                           //compare each test string to substr, if there is a match, add one to count
        {
            numMatches = (numMatches + 1);
        }
        teststring = "";                                    //reset test string so that a new one can be created in the next for loop
    }
    return numMatches;
}

int main(){
    //test case 1 should return 2
    cout << countMatches("ab cd ab", "ab") << endl;
    
    //test case 2 should return 3
    cout << countMatches("ab ab ab ", "ab") << endl;
    
    //test case 3 should return -1
     cout << countMatches("ab cd ab", "g") << endl;
    return 0;
}