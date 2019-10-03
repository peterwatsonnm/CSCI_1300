// CS1300 Fall 2019
// Author: Peter Watson
// Practicum problem 4
#include <iostream>
#include <math.h>
using namespace std;

void printSeriesSquareFifth(int n) {
    int sum = 0;
    int i = 1;
    while (i <= n){
    //for (int i = 1;i <= n;i++) {
        if (i%5 == 0) {
            //If the number is divisible by 5, print its square and add the square to the sum
            cout << i*i;
            sum = sum + i*i;
        }
        else {
            //If the number is not divisible by 5, print the number and add the number to the sum
            cout << i ;
            sum = sum + i;
        }
        if(i != n){
            //This check is added to not print the last '+'
            cout<<" + ";
        }
        i = (i + 1);
    }
    cout << endl << "Result of the series is " << sum << endl;
}

int main(){
  return 0;
}
