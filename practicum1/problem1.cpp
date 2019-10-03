// CS1300 Fall 2019
// Author: Peter Watson
// Practicum problem 1
#include <iostream>
#include <math.h>
using namespace std;
int Payout(int dealerScore, int playerScore, int bet){
  int payout = 0;
  if(playerScore <= dealerScore)
  {
    return payout;
  }
  else
  {
    payout = ((playerScore - dealerScore) * bet / 2);
    return payout;
  }
}
int main(){
  cout << Payout(15, 10, 10) << endl;
  cout << Payout(15, 20, 8) << endl;
  return 0;
}
