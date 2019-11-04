//problem 3
#include <iostream>
using namespace std;
#include <fstream>

void printCountriesOutOfRange(string names[], int medals[], int length){
  for(int i = 0; i < length; i++)
  {
    if (medals[i] < 10 || medals[i] > 15)
    {
      cout << names[i] << " " << medals[i] << endl;
    }
  }
}


int main(){

  return 0;
}
