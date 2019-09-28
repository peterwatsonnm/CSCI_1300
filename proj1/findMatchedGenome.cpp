// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Project 1 - Problem 6 -- find matched genome function
#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: takes three genomes and a sequence and prints
the list of matched genomes.
type: void
takes 3 genome inputs and one sequence input


if the genomes are different lengths, return an error,
if one of the genomes is empty, return an error,
run find best sim score for each of the genomes
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
//findBestSimScore taken from problem 5
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

void findMatchedGenome(string genome1, string genome2, string genome3, string sequence){
    int genome1_length = genome1.length();
    int genome2_length = genome2.length();
    int genome3_length = genome3.length();
    int seq_length = sequence.length();
    
    double genome1_score = findBestSimScore(genome1, sequence);
    double genome2_score = findBestSimScore(genome2, sequence);
    double genome3_score = findBestSimScore(genome3, sequence);
    
    //error outputs: empty strings or strings of different length
    if (genome1_length == 0 || genome2_length == 0 || genome3_length == 0 || seq_length == 0)
    {
        cout << "Genomes or sequence is empty." << endl;
    }
    else if (genome1_length != genome2_length || genome2_length != genome3_length || genome1_length != genome3_length)
    {
        cout << "Lengths of genomes are different." << endl;
    }
    else                    //compares genome scores to eachother.  WHen one is >= to the other two, it prints that genome
    {
        if (genome1_score >= genome2_score && genome1_score >= genome3_score)
        {
            cout << "Genome 1 is the best match." << endl;
        }
         if (genome2_score >= genome1_score && genome2_score >= genome3_score)
        {
            cout << "Genome 2 is the best match." << endl;
        }
         if (genome3_score >= genome2_score && genome3_score >= genome1_score)
        {
            cout << "Genome 3 is the best match." << endl;
        }
    }

    
}

int main(){
    //expect genome 3 is the best match string, input g1 = "AATGTTTCAC"; string g2 = "GGGGTTTCCC"; string g3 = "GTACATTCAC"; string seq = "TACTA"
    findMatchedGenome("AATGTTTCAC", "GGGGTTTCCC", "GTACATTCAC", "TACTA");
    
    //expect genome or sequence is empty, input g1 = "a", g2 = "", g3 = "b", seq = "c"
    findMatchedGenome("a", "", "b", "c");
    
    return 0;
}