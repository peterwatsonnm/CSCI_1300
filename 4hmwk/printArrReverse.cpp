// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 4 - Problem 2 -- print array reverse
#include <iostream>
using namespace std;

/*Algorithm: print a given array in reverse order
parameters: integer array and length of array

for length of the array
	Print last character, second to last character, etc
*/
void printArrReverse(int arr[], int len){
	for (int i = 0; i < len; i++)
	{
		//output the characters of the array, starting at length - 1 and going to length - 1 - length
		cout << arr[len - 1 - i];
		cout << endl;
	}
}
int main(){
	//test case 1
	int arr[6] = {1, 2, 3, 4, 5, 6};
	printArrReverse(arr, 6);

	//test case 2
	int arr2[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	printArrReverse(arr2, 8);
	return 0;
}
