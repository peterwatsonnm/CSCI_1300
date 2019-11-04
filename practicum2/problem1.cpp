//problem 1
#include <iostream>
using namespace std;
#include <fstream>

int Count_a_j(string str){
  int count = 0;
  if (str.length() == 0)
  {
    return -1;
  }
  int length = str.length();
  for (int i = 0; i < length; i++)
  {
    if (str[i] >= 97 && str[i] <= 106)
    {
      count ++;
    }
  }
  if (count == 0)
  {
    count = -2;
  }
  return count;
}

int main(){

  return 0;
}
