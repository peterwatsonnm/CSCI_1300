// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 3 - Problem 1 -- collatz step function
#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: for an integer parameter n, If the given value n is even, the next value should be n/2. 
If n is odd, the next value should be 3n+1.
If the given value is not positive, the function should return 0.

type int
if n <= 0, 
    return 0
elif n is even
    divide n by 2
elif n is odd
    multiply n by 3 and add 1
*/

int collatzStep(int n){
    int finalOut;          //define finalOut to be the final value to be returned
    if (n <= 0) {
        finalOut = 0;
    }
    else if (n % 2 == 0) {                //uses mod operator to check if n is divisible by two (even)
        finalOut = (n / 2);
    }
    else {                      //no need for a conditional because odd is the only other condition possible
        finalOut = (3 * n + 1);
    }
    return finalOut;
}

int main(){
    //test case 1 When the argument is equal to 4, the function should return 2
    cout << collatzStep(4) << endl;
    
    //test case 2 When the argument is equal to 7, the function should return 22
    cout << collatzStep(7) << endl;
    
    //test case 3  When the argument is equal to -5, the function should return 0
    cout << collatzStep(-5) << endl;
    return 0;
}