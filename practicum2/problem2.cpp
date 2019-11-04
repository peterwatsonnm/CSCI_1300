//problem 2
#include <iostream>
using namespace std;
#include <fstream>

string removeLower(string str){
  int length = str.length();
  string finalString = "";
  for (int i = 0; i < length; i++)
  {
    if (str[i] < 97 || str[i] > 122)
    {
      finalString += str[i];
    }
  }
  return finalString;
}

int main(){

  return 0;
}
