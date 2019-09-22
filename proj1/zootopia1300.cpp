// CS1300 Fall 2019
// Author: Peter Watson 
// Recitation: 103 Telly Umada
// Project 1 - Problem 3 -- hire score function
#include <iostream>
#include <math.h>
using namespace std;

/*Algorithm: take two scores of animal traits, and then output a hire score based on these traits
type: void
two double inputs

while input != 4
    if input = 4
        break;
    print menu
    prompt for user input
    agility = 0.0
    strength = 0.0
    speed = 0.0
    switch
        case 1:
            ask for agility and strength for a Fox
        case 2:
            ask for agility and speed for a Bunny
        case 3:
            ask for strength and speed for a Sloth
    hireScore(agility, strength, speed)
    
Algorithm: compute the hire score
type double
3 double parameters

hireScore = 1.8 * agility + 2.16 * strength + 3.24 * speed
*/


// showMenu function for problem 3 in proj 1
//taken from CS 1300 moodle page
void printMenu(){
	cout<<"Select a numerical option:"<<endl;
	cout<<"=== menu ==="<<endl;
	cout<<"1. Fox"<<endl;
	cout<<"2. Bunny"<<endl;
	cout<<"3. Sloth"<<endl;
	cout<<"4. Quit"<<endl;
}

double hireScore(double agility, double strength, double speed){
    return 1.8 * agility + 2.16 * strength + 3.24 * speed;
}

int main(){
    int input;
    
    while (input != 4)
    {
        double agility = 0.0;                   //reset variables
        double strength = 0.0;
        double speed = 0.0;
        printMenu();
        cin >> input;
        if (input == 4)                         //quit
        {
            break;
        }
        switch (input)                          //asks for different inputs given which animal it is
        {
            case 1:
                cout << "Enter agility:" << endl;
                cin >> agility;
                cout << "Enter strength:" << endl;
                cin >> strength;
                break;
            case 2: 
                cout << "Enter agility:" << endl;
                cin >> agility;
                cout << "Enter speed:" << endl;
                cin >> speed;
                break;
            case 3:
                cout << "Enter strength:" << endl;
                cin >> strength;
                cout << "Enter speed:" << endl;
                cin >> speed;
                break;
        }
        cout << "Hire Score: " << hireScore(agility, strength, speed) << endl;
    }
    return 0;
}