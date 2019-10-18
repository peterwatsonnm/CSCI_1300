// CS1300 Fall 2019
// Author: Peter Watson
// Recitation: 103 Telly Umada
// Homework 5 - Problem 5-- flood map
#include <iostream>
using namespace std;
#include <fstream>

/*Algorithm:  prints out a “map” of which points in the array are below or
above the water level.The function takes a two-dimentional array where each element indicates
the height of the terrain at a particular point (assume that there are 4 columns). Each point at or
below the water level will be represented with a * and each position above the water level will be
represented with an underscore _.

string array map

for each row
    do 4 times
    if point is above level, fill map array with _
    if point is below level, fill map array with *

*/

void floodMap(double terrain[][4], int rows, double level){
    
    string map[rows][4];
    
    for(int i = 0; i < rows; i++)           //i is the row that it is accessing
    {
        for (int n = 0; n < 4; n++)         //n is the colum that is is accessing
        {
            if (terrain[i][n] > level)
            {
                map[i][n] = "_";            //point is above level, fill map with _
                cout << map[i][n];
            }
            else                            //point is below level
            {
                map[i][n] = "*";
                cout << map[i][n];
            }
        }
        cout << endl;
    }
}

int main(){
    //test case 1
    double map1[1][4] =  {{0.2, 0.8, 7.3, 0.2}};
    floodMap(map1, 1, 6.0);
    
    //test case 2
     double map2[2][4] = {{0.2, 0.8, 7.3, 0.2},
                        {0.2, 0.8, 7.3, 0.2}};
    floodMap(map2, 2, 6.0);
    return 0;
}