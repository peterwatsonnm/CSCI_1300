// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 5 - Problem 6-- read float map
#include <iostream>
using namespace std;
#include <fstream>

/*Algorithm:  that reads from a text file, stores its contents in a 2D array,
and returns the number of lines it reads.

take three parameters in the following order:
○ A string fileName
○ A 2D array of doubles with 4 columns double arr[][4]
○ The int number of rows of the given array

read lines, and do until lines cannot be read any more or the 2d array is full
    split the line
    store the split values in a temp array
    do 4 times
        store values in the cooresponding indices in the 2d array from the temp array 
    
        

*/

int split(string splitMe, char delimeter, string arr1[]){
  string substring = "";
  int numSplits = 0;
  if(splitMe.length() == 0)                 //return 0 of there is nothing in splitMe
  {
    return 0;
  }
  if(splitMe.find(delimeter) == std::string::npos)    //check if there is only one word
  {
    arr1[0] = splitMe;
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
        arr1[numSplits] = substring;       //populate
        
        numSplits++;
        substring = "";                   //reset
      }
    }
  }
  if(!(splitMe[(splitMe.length() - 1)] == delimeter ))     //indicates that the last part was not included
  {
  arr1[numSplits] = substring;        //include the last part of the string
  numSplits++;
  }
  return numSplits;
}

int readFloatMap(string fileName, double arr[][4], int numRows){
    ifstream file1(fileName);
    const int COLUMS = 4;
    string tempArr[COLUMS];
    string line;
    int row = 0;
    
    //check for unexpected values
     if (!(file1.is_open()))
    {
        return -1;
    }
    
    while (row < numRows && getline(file1, line))     //do until array is full or there are no more lines
    {
      if (line != "")           //do not process empty lines
      {
        split(line, ',', tempArr);        //tempArr stores the 4 values in the first line of the text file as strings
        for (int i = 0; i < COLUMS; i++)
        {
          arr[row][i] = stod(tempArr[i]);        //put the 1st, 2nd, 3rd, and 4th value of tempArr in arr, convert from string to double
        }
        row += 1;
      }
    }
    return row;
}

int main(){
    //test case 1
    double floatMap[2][4];
    cout << readFloatMap("fileName2.txt", floatMap, 2);
    cout << floatMap[0][0];
    cout << floatMap[0][1] << endl;
    cout << floatMap[1][0];
    cout << floatMap[1][1] << endl;
    
    //test case 2 should return -1
    cout << readFloatMap("fileNamme2.txt", floatMap, 2);
    return 0;
}