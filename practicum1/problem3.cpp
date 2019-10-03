// CS1300 Fall 2019
// Author: Peter Watson
// Practicum problem 3
#include <iostream>
#include <math.h>
using namespace std;

double smallestNumber(double num1, double num2, double num3){
  double min = num1;
  if(num2 < min)
  {
    min = num2;
  }
  if(num3 < min)
  {
    min = num3;
  }
  return min;
}

int main(){
  cout << smallestNumber(1.2, 3.3, 6) << endl;
  cout << smallestNumber(12, 3.3, 6) << endl;
  cout << smallestNumber(12, 3.3, 1.1) << endl;
  return 0;
}
