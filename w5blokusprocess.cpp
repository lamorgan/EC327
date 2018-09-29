// Copyright Laura Morgan lamorgan@bu.edu

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::cout;
using std::cin;
using std::ifstream;
using std::string;
using std::vector;

// good
bool nxn(vector<string> contents, int n) {
  int i = 0;
  while (i <= contents.size()) {
    if (contents[i].size() == n) {
      i = i+1;
    } else if (contents[i].size() == 0) {
      if (i == n || i == (2*n+1) || i == (3*n+2)) {
        i = i+1;
      }
    } else {
      return 2;
      i = i+1;
    }
  }
}

// prints the tiles if they are valid
bool print(vector<string> tile, int n) {
  int j;
  int i = 0;
  int count = 0;
  int empty;
  while (i < n) {
    j = 0;
    while (j < n) {
      if (tile[i][j] == '*') {
        j = j+1;
        count = count+1;
      } else if (tile[i][j] == '.') {
        tile[i][j]=' ';
        j = j +1;
      } else {
        empty = 1;
        j = j+1;
      }
    }
    i = i+1;
  }
  for (auto line : tile)
    cout << line << '\n';
}

// checks to make sure the tiles are valid
bool tiles(vector<string> tile, int n) {
  int j;
  int i = 0;
  int count;
  int empty;
  while (i < n) {
    j = 0;
    while (j < n) {
      if (tile[i][j] == '*') {
        j = j+1;
        count = 1;
      } else if (tile[i][j] == '.') {
        tile[i][j]=' ';
        j = j+1;
      } else {
        empty = 1;
        break;
      }
    }
    i = i+1;
  }
  if (count != 1) {
    return 3;
  } else if (empty == 1) {
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char const *argv[]) {
  int n;
  int num;
  int dog = 0;
  int count = 0;
  // std::string blokus;

  //cin >> n >> blokus;
  n = argc;

  ifstream thisfile;

  string theline;
  vector<string> contents;

  thisfile.open(argv[0]);
  while (std::getline(thisfile, theline))
    contents.push_back(theline);
  thisfile.close();

  // makes sure there is a space after each block
  // good
  if (contents[n].size() != 0) {
    return 2;
    exit(0);
  }

  if (contents[((2*n)+1)].size() != 0) {
    return 2;
    exit(0);
  }
  if (contents[((3*n)+2)].size() != 0) {
    return 2;
    exit(0);
  }
  // checks if the board is nxn
  // good
  nxn(contents, n);

  // separates the tiles
  // good

  vector<string> septile;
  vector<string> septile2;
  vector<string> septile3;



  num = contents.size()/n;


  if (num > count) {
    while (dog <= n) {
      septile.push_back(contents[dog]);
      dog = dog+1;
    }
    count = count+1;
  }

  if (num > count) {
    while (dog <= (2*n)+1) {
      septile2.push_back(contents[dog]);
      dog = dog+1;
    }

    count = count+1;
  }

  if (num > count) {
    while (dog <= (3*n)+2) {
      septile3.push_back(contents[dog]);
      dog = dog+1;
    }
    count = count+1;
  }
  // checks the tiles
  if (tiles(septile, n) == 0) {
    if (tiles(septile2, n) == 0) {
      if (tiles(septile3, n) == 0) {
        print(septile, n);
        print(septile2, n);
        print(septile3, n);
      }
    }
  }
  if ((tiles(septile, n) == 1) || (tiles(septile2, n) == 1)
    || (tiles(septile3, n) == 1)) {
    return 1;
  }

  if ((tiles(septile, n) == 3) || (tiles(septile2, n) == 3)
    || (tiles(septile3, n) == 3)) {
    return 3;
  }
}