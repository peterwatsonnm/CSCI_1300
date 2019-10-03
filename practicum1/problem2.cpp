// CS1300 Fall 2019
// Author: Peter Watson
// Practicum problem 2
#include <iostream>
#include <math.h>
using namespace std;

void gameMenu(int num){
  switch(num)
  {
    case 1:
      cout << "Choice 1: Play Game \n";
      break;
    case 2:
      cout << "Choice 2: View Stats \n";
      break;
    case 3:
      cout << "Choice 3: Save Game \n";
      break;
    case 4:
      cout << "Choice 4: Exit Game \n";
      break;
    default:
      cout << "Choice " << num << ": Invalid \n";
      break;
  }
}

int main(){gameMenu(2);
  gameMenu(3);
  //gameMenu(4);
  //gameMenu(32);
  //gameMenu(2);
  //gameMenu(2);
  //gameMenu(3);
  //gameMenu(4);
  //gameMenu(32);

  return 0;
}
