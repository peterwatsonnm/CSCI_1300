#include <curses.h>
#include <iostream>
#include <stdio.h>
using namespace std;

string navigate(){
  const int up = 119;
  const int left = 97;
  const int down = 115;
  const int right = 100;
  int arrow;
  string direction = "";
  //initscr();  //start ncurses mode
  //clear();
  noecho();  //do not print wasd in terminal window
  cbreak(); //put in cbreak mode
  cout << "Press q to quit, use WASD keys to navigate"<< endl;
    refresh();
    //cout << direction << endl;
    arrow = getch();

    //clear();
    if (arrow == up)
    {
      direction = "up";
      //cout << "up\n";
    }
    else if (arrow == left)
    {
      direction = "left";
      //cout << "left" << endl;
    }
    else if (arrow == down)
    {
      direction = "down";
      //cout << "down" << endl;
    }
    else if (arrow == right)
    {
      direction = "right";
      //cout << "right" << endl;
    }
    else
    {
      //cout << "invalid key" << endl;
    }
    //endw()
  return direction;
}

int main (){
  string test = navigate();
  cout << test << endl;
  test = navigate();
  cout << test << endl;







  // int arrow;
  // initscr();
  // cbreak();
  // arrow = getch();
  // cout << arrow << endl;
  // // cbreak();
  // //   arrow = getch();
  // //   if (arrow == 'a')
  // //   {
  // //     cout << "a was pressed" << endl;
  // //   }
  return 0;

}
