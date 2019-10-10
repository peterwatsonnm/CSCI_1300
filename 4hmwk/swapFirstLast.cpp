// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 4 - Problem 4 -- swap first last
#include <iostream>
using namespace std;
#include <iomanip>
/*Algorithm: swaps the first and last elements of the given array of integers.
function takes two parameters in the following order:
An array of integers The number of elements in the array, type  int

store last element in variable lastElem
set last element equal to first
set first element equal to lastElem

*/

void swapFirstLast(int arr[], int length){
  int lastElem = arr[(length - 1)];
  arr[(length - 1)] = arr[0];
  arr[0] = lastElem;

}

int main(){
  //test case 1
  int arr1[] = {10, 20, 30};
  swapFirstLast(arr1, 3);
  cout << arr1[0] << endl << arr1[2] << endl;

  //test case 2
  int ari[] = {15, 20, 53};
  swapFirstLast(ari, 3);
  cout << ari[0] << endl << ari[2];
}
