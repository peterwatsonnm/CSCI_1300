//problem 4
#include <iostream>
using namespace std;
#include <fstream>

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

int calcProduce(string fileName){
  ifstream file1(fileName);
  if (!(file1.is_open()))
  {
      return -1;
  }

  int i = 0;
  string tempLine = "";
  int numlines = 0;
  string arr1[3];
  string name = "";
  double weight = 0;
  double cost = 0;
  double lineCost = 0;
  double total = 0;

  while( getline(file1, tempLine))
  {
     if (!(tempLine == ""))       //if the line is not empty, store it in the array
     {
         split(tempLine, ',', arr1);
         name = arr1[0];
         weight = stod(arr1[1]);
         cost = stod(arr1[2]);
         lineCost = double(weight * cost);
         cout << name << ": " << lineCost << endl;
         total += lineCost;
         numlines++;
     }
  }
  cout << "Total: " << total << endl;
  file1.close();
  return numlines;
}


int main(){

  return 0;
}
