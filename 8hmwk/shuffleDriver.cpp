//Author: Peter Watson
//CSCI 1300 fall 2019
//Homework 8 - Problem 1 - shuffle

using namespace std;
#include <string>
#include <vector>
#include <iostream>

/*
Algorithm:
check if both vectors are empty
check which vector is the longest
while index is less than length of smallest vector
**push back
  outputVector[index] = v1[index]
  outputVector[index + 1] = v2[index]
*/

vector<int> shuffle(vector<int> vec1, vector<int> vec2){
  int count = 0;
  vector<int> outputVector;
  vector<int> longestVector;
  vector<int> shortestVector;
  if (vec1.size() == 0 && vec2.size() == 0)
  {
    return outputVector;
  }
  if(vec1.size() >= vec2.size())
  {
    longestVector = vec1;   //determine the longest vector
    shortestVector = vec2;
  }
  else
  {
    longestVector = vec2;
    shortestVector = vec1;
  }
  for (int i = 0; i < longestVector.size(); i++)
  {
    //fill every other line with longest vector's values
    outputVector.push_back(longestVector[i]);
    if (i < shortestVector.size())
    {
        outputVector.push_back(shortestVector[i]);
    }
  }

  return outputVector;
}

int main(){
  //test case 1
  vector<int> v1{1,3,5};
  vector<int> v2{2,4,6,8,10,12};
  vector<int> test1 = shuffle(v1, v2);
  for (int i = 0; i < test1.size(); i++)
  {
    cout << test1[i] << " ";
  }

  //test case 2
  vector<int> v3{};
  vector<int> v4{};
  vector<int> test2 = shuffle(v3, v4);
  for (int i = 0; i < test2.size(); i++)
  {
    cout << test2[i] << " ";
  }
  return 0;
}
