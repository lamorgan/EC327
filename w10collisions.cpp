// Copyright lamorgan@bu.edu

#include <iostream>
#include <istream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using std::sort;
using std::cout;
using std::cin;
using std::string;
using std::vector;

int main() {
  string id1;
  double x1;
  double y1;
  double vx1;
  double vy1;
  vector<string> id;
  vector<double> x;
  vector<double> y;
  vector<double> vx;
  vector<double> vy;
  vector<double> collisiontime;
  vector<string> collidedcars;

  while (cin >> id1 >> x1 >> y1 >> vx1 >> vy1) {
    id.push_back(id1);
    x.push_back(x1);
    y.push_back(y1);
    vx.push_back(vx1);
    vy.push_back(vy1);
  }
  cout << "there are " << id.size() << " vechicles" << '\n';

  for (int n = 0; n < id.size() - 1; n++) {
    for (int h = n+1; h < id.size(); h++) {
      double r1 = x[h] - x[n];
      double r2 = y[h] - y[n];
      double v1 = vx[h] - vx[n];
      double v2 = vy[h] - vy[n];
      double b = (2*r1*v1) + (2*r2*v2);
      double a = (v1*v1) + (v2*v2);
      double c = ((r1*r1) + (r2*r2)) -100;
      double s = (b*b)-(4*a*c);
      if (s > 0) {
        double t1 = ((b*-1) + sqrt(s)) / (2*a);
        double t2 = ((b*-1) - sqrt(s)) / (2*a);
        if (t1 < t2) {
          if (t1 > 0) {
            collidedcars.push_back(id[n]);
            collidedcars.push_back(id[h]);
            collisiontime.push_back(t1);
          }
        } else {
          if (t2 > 0) {
            collidedcars.push_back(id[n]);
            collidedcars.push_back(id[h]);
            collisiontime.push_back(t2);
          }
        }
      }
    }
  }
  // need to print out survivors
  // need to find duplicate collisions within the collided cars and find which
  // has the first collision time
  vector<double> order;
  vector<string> duplicates;

  cout << "collision report" << '\n';
  if (collidedcars.size() == 0) {
    cout << "none" << '\n';
  }
  int k = 0;
  int z;
  for (int i = 0; i < collidedcars.size(); i++) {
    z = i+1;
    for (z; z < collidedcars.size(); z++) {
      if (collidedcars[i] == collidedcars[z]) {
        duplicates.push_back(collidedcars[i]);
        duplicates.push_back(collidedcars[z]);
        if (collisiontime[i/2] < collisiontime[z/2]) {
        	order.push_back(collisiontime[i/2]);
        } else {
       	  order.push_back(collisiontime[z/2]);
        }
      }
    }
  }
  int err;
  for (int p = 0; p < collidedcars.size(); p++) {
    err = 0;
    for (int u = 0; u < duplicates.size(); u++) {
      if (collidedcars[p] == duplicates[u] || collidedcars[p+1] == duplicates[u]) {
        err = 1;
      }
    }
    if (err == 0) {
    	order.push_back(collisiontime[p/2]);
    }
    p++;
  }
  sort(order.begin(), order.end());
  vector<string> non;

  for (int t = 0; t < order.size(); t++) {
  	for (int w = 0; w < collisiontime.size(); w++) {
  		if (order[t] == collisiontime[w]) {
  			cout << "at " << order[t] << ' ' << collidedcars[w*2] << " collided with " << collidedcars[(w*2)+1] << '\n';
  			non.push_back(collidedcars[w*2]);
  			non.push_back(collidedcars[(w*2)+1]);
  		}
  	}
  }
  int error;
  cout << "the remaining vechicles are" << '\n';
  if (non.size() >= id.size()) {
    cout << "none" << '\n';
  }
  for (int j = 0; j < id.size(); j++) {
    error = 0;
    for (int m = 0; m < non.size(); m++) {
      if (non[m] == id[j]) {
        error = 1;
      }
    }
    if (error == 0) {
      cout << id[j] << ' ' << x[j] << ' ' << y[j] << ' ' << vx[j] << ' ' << vy[j] << '\n';
    }
  }
}
