// Copyright 2017 Laura Morgan lamorgan@bu.edu

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

// using namespace std;
using std::cout;
using std::endl;
using std::ifstream;
// array<array<char,3>,3> board;

int main() {
  // ifstream thisfile;
  // string theline;
  // vector<string> contents;

  // thisfile.open("tictactoeboards.txt");

  // while (getline(thisfile, theline))
  // contents.push_back(theline);

  // thisfile.close();
  std::ifstream input("tictactoeboards.txt");

  // for (auto line : contents) { //contents instead of thisfile
  for (std::string line; getline(input, line);) {
    int count = 0;
    int o = 0;
    int x = 0;
    int space = 0;
    int num = 0;

    while (count < 9) {
      if (line[count] == 'o') {
        o = o+1;
        count = count+1;
      }
      if (line[count] == 'x') {
        x = x+1;
        count = count+1;
      }
      if (line[count] == '#') {
        space = space+1;
        count = count+1;
      }
    }

    if (x > o+1 || o > x) {
      cout << line << " i" << endl;
    }

    if (x == o+1) {
      if (line[0] == 'x' && line[1] == 'x' && line[2] == 'x') {
        cout << line << " x" << endl;
        num = 1;
      }
      if (line[3] == 'x' && line[4] == 'x' && line[5] == 'x') {
        cout << line << " x" << endl;
        num = 1;
      }
      if (line[6] == 'x' && line[7] == 'x' && line[8] == 'x') {
        cout << line << " x" << endl;
        num = 1;
      }
      if (line[0] == 'x' && line[3] == 'x' && line[6] == 'x') {
        cout << line << " x" << endl;
        num = 1;
      }
      if (line[1] == 'x' && line[4] == 'x' && line[7] == 'x') {
        cout << line << " x" << endl;
        num = 1;
      }
      if (line[2] == 'x' && line[5] == 'x' && line[8] == 'x') {
        cout << line << " x" << endl;
        num = 1;
      }
      if (line[0] == 'x' && line[4] == 'x' && line[8] == 'x') {
        cout << line << " x" << endl;
        num = 1;
      }
      if (line[2] == 'x' && line[4] == 'x' && line[6] == 'x') {
        cout << line << " x" << endl;
        num = 1;
      }
    }
    if (o == x && num != 1) {
      if (line[0] == 'o' && line[1] == 'o' && line[2] == 'o') {
        cout << line << " o" << endl;
        num = 1;
      }
      if (line[3] == 'o' && line[4] == 'o' && line[5] == 'o') {
        cout << line << " o" << endl;
        num = 1;
      }
      if (line[6] == 'o' && line[7] == 'o' && line[8] == 'o') {
        cout << line << " o" << endl;
        num = 1;
      }
      if (line[0] == 'o' && line[3] == 'o' && line[6] == 'o') {
        cout << line << " o" << endl;
        num = 1;
      }
      if (line[1] == 'o' && line[4] == 'o' && line[7] == 'o') {
        cout << line << " o" << endl;
        num = 1;
      }
      if (line[2] == 'o' && line[5] == 'o' && line[8] == 'o') {
        cout << line << " o" << endl;
        num = 1;
      }
      if (line[0] == 'o' && line[4] == 'o' && line[8] == 'o') {
        cout << line << " o" << endl;
        num = 1;
      }
      if (line[2] == 'o' && line[4] == 'o' && line[6] == 'o') {
        cout << line << " o" << endl;
        num = 1;
      }
    }

    if (num != 1 && space >= 0) {
      if (x == o || x == o+1 || o == x-1) {
        cout << line << " c" << endl;
      }
    }

    if (num != 1 && o == x-1 && x == o+1) {
      if (space == 0) {
        cout << line << " t" << endl;
      }
    }


//    cout << line << " x: " << x << " o: " << o << " #: " << space << endl;
  }

  return 0;
}
