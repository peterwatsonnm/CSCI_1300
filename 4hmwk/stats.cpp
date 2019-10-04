// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 4 - Problem 3 -- stats
#include <iostream>
using namespace std;
#include <iomanip>
/*Algorithm: takes an array and the number of elements in the array as
arguments, computes and prints the minimum value in the array, the maximum value in the
array and the average value of all the values in the array.
set max and min as 1st value
define total value = 0
for every value in the array
  check if value > max
    update max
  check if value < min
    update min
  add value to total value
average = total value / length


*/

void stats(double arr[], int length){
  double max = arr[0];
  double min = arr[0];
  double totalVal = 0;
  for(int i = 0; i < length; i++)
  {
    //check if value is higher than max, if so make it new max
    if(arr[i] > max)
    {
      max = arr[i];
    }
    //check if value is lower than min, if so make it new min
    if(arr[i] < min)
    {
      min = arr[i];
    }
    totalVal += arr[i];
  }
  double average = (totalVal / length);       //take average
  cout << fixed;      //sets program to output 2 decimal places no matter what
  cout << "Min: " << setprecision(2) << min << endl;
  cout << "Max: " << setprecision(2) << max << endl;
  cout << "Avg: " << setprecision(2) << average << endl;
}

int main(){
  //test case 1
  double arr1[] = {0,1,2,3,4,5,6,7,8,9};
  stats(arr1, 10);
  //test case 2
  double arr2[] = {1.4, 9.8, 2.6};
  stats(arr2, 3);
  return 0;
}
