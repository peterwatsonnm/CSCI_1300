// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Homework 4 - Problem 1 -- array pilgrimage
#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: 
*/

int main(){
    const int TEMP_VAL = 10;
    double temps[TEMP_VAL];
    for (int i = 0; i < 10; i++){
        temps[i] = -459.67;
        //test case for temps[]
        cout << temps[i] << endl;
    }
    string colors[5] = {"Red", "Blue", "Green", "Cyan", "Magenta"};

    //test case for colors[]
    for (int i = 0; i < 5; i++){
        cout << colors[i] << endl;
    }

    const int SEQ_VAL = 100;
    int sequence[SEQ_VAL];
    for (int i = 0; i < 100; i++){
        sequence[i] = (i + 1);
        //test case for sequence[]
        cout << sequence[i] << endl;
    }

    const int CHAR_VAL = 52;
    string letters[CHAR_VAL];
    for (int i = 0; i < 26; i++){
        letters[i] = 'A' + i;
        letters[i] += ' ';
        letters[i] += 'a' + i;
        cout << letters[i] << endl;
    }
    return 0;

}