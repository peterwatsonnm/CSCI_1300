#include <iostream>
using namespace std;

int main(){
  char input[1];
  cin.read(input, 2);
  cout << "-" << input[1] << "-" << endl;
  return 0;
}
