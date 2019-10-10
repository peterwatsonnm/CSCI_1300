// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 5 - Problem 1 -- get lines from file
#include <iostream>
using namespace std;
#include <fstream>

/*Algorithm: reads from a text file and stores its contents in an
array. Each line in the file will either contain a single integer or be empty

three parameters in the following order:
 A string fileName
 An array of integers
 The int length of the given array

open file
check if file opened

do for i < length
    line = getline(file.txt)
    if line is not blank
        store integer in array[i]
        i++
        numInts++
if numints is zero
    return -1
return numints
close file

*/

int getLinesFromFile(string fileName, int arr[], int length){
    //open file and check if it opened
    ifstream file1(fileName);
    if (!(file1.is_open()))
    {
        return -1;
    }
    
    int i = 0;
    string tempLine = "";
    int numInts = 0;
    
    while(i < length && getline(file1, tempLine))
    {
       if (!(tempLine == ""))       //if the line is not empty, store it in the array
       {
           arr[i] = stoi(tempLine);     //store it as an integer
           //increment
           i++;     
           numInts++;
       }
    }
    file1.close();
    return numInts;
}

int main(){
    //test case 1 should return 4
    int arr1[4];
    cout << getLinesFromFile("test1.txt", arr1, 4) << endl;
    
    
    //test case 2 should return 0
    int arr2[3];
    cout << getLinesFromFile("test2.txt", arr2, 3) << endl;
    return 0;
}