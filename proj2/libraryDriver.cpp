//Author: Peter Watson
//Driver file for testing Library class
//project 2

#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "User.h"
#include "Book.h"
#include "Library.h"
using namespace std;

int main(){
  Library lib1;
  lib1.readBooks("books.txt");
  //lib1.printAllBooks();
  //lib1.printBooksByAuthor("Alice Hoffman");
  lib1.readRatings("ratings.txt");
  //cout << lib1.getRating("diane", "hatchet") << endl;
  //cout << lib1.getCountReadBooks("diane") << endl;
  // lib1.viewRatings("megan", 2);
  // cout << "test 2" << endl;
  // lib1.viewRatings("megan", 6);
  // cout << "test 3" << endl;
  // lib1.viewRatings("megaaan", 2);
  cout << lib1.calcAvgRating("inkHeArt") << endl;
  cout << lib1.calcAvgRatingByAuthor("Cornelia Funke") << endl;
  cout << lib1.calcAvgRatingByAuthor("J R R Tolkien") << endl;
  cout << lib1.getNumUsers() << endl << "adding a user" << endl;
  lib1.addUser("Froggy");
  cout << lib1.getNumUsers() << endl << "adding a user that has already been added" << endl;
  // lib1.addUser("Froggy");
  // cout << lib1.getNumUsers() << endl;
  //
  // cout << lib1.getRating("Froggy", "Watership Down") << endl << "froggy read watership down and rated as 4" << endl;
  // lib1.checkOutBook("froggy", "watership down", 4);
  // cout << lib1.getRating("Froggy", "Watership Down") << "is waht froggy rated watership down" << endl;
  //
  // lib1.getRecommendations("John");
  // lib1.getRecommendations("Joan");
  // lib1.getRecommendations("arthur");
  // lib1.getRecommendations("John");
  //
  // lib1.getRecommendations("adam");
  lib1.getRecommendations("pamela");
  //lib1.getRecommendations("adam");
  //lib1.getRecommendations("naomi");
  return 0;
}
