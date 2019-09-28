// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Project 1 - Problem 4 -- calc sim score function
#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: calcSimScore that returns the similarity score for two sequences. The similarity score for two sequences is calculated as follows:
similarity_score = (string_length - hamming_distance) / string_length
Type: double
two string parameters
calculate length of string
if length of strings are unequal
    return 0
calculate hamming distance
    for every haracter in the string
        if str1[n] != str2[n]
            hamming_distance = hamming_distance + 1
similarity_score = (string_length - hamming_distance) / string_length

*/

double calcSimScore(string str1, string str2){
    int str1_length = str1.length();
    int str2_length = str2.length();
    if (str1_length != str2_length)
    {
        return 0.0;                       //sim score can only be calculated if the strings are of equal length
    }
    if (str1_length == 0 || str2_length == 0)
    {
        return 0.0;                       //can't compare an empty string
    }
    
    //calculate hamming distance, at this point str1_length = str2_length
    int hamming_distance = 0; 
    for (int n = 0; n < str1_length; n++)
    {
        if (str1[n] != str2[n])
            hamming_distance += 1;                 //increment hamming_distance for every time that the string character is n0t equal
    }
    double similarity_score = (double(str1_length) - hamming_distance) / str1_length;           //calculate similarity score with double operations
    return similarity_score;
}

int main(){
    //test case 1 inputs ATGC and ATGA should return .75
    cout << calcSimScore("ATGC", "ATGA") << endl;
    
    //test case 2 inputs AAAA and A should return 0
    cout << calcSimScore("AAAA", "A") << endl;
    
    //test case 3 inputs GT and GT
    cout << calcSimScore("GT", "GT") << endl;
}