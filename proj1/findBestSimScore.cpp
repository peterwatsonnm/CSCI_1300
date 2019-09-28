// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Project 1 - Problem 5 -- find best sim score function
#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: Write a function that takes a genome and a sequence and returns the
highest similarity score found in the genome as a double.
Type: double
two string parameters

run a loop for every possible string in the genome, same loop written in problem 2
    do simscore for each of these strings and the sequence

*/

//calcSimScore taken from problem 4
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

double findBestSimScore(string genome, string sequence){
    double highestSimScore = 0;
    int genome_length = genome.length();
    int sequence_length = sequence.length();
    string teststring = "";
    for (int n = 0; n < genome_length; n++)           //create a test string with the same number of characters as the substring
    {
        teststring = genome.substr(n, sequence_length);           //creating test string, starting with genome[n] and the same length as sequence.  this is used to compare to the string sequence
        double simScore = calcSimScore(teststring, sequence);
        if (simScore > highestSimScore)
        {
            highestSimScore = simScore;
        }
            
    }
      
    return highestSimScore;
}

int main(){
    //test case 1 inputs ATACGC and ACT should print .66667
    cout << findBestSimScore("ATACGC", "ACT") << endl;
    
    //test case 2 inputs a and aaa should print 0
    cout << findBestSimScore("a", "aaa");
}