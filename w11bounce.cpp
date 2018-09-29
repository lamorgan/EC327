// Copyright 2017 Laura Morgan lamorgan@bu.edu
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;

typedef double numbers;

struct collision {
  numbers time;
  int first, second;
  collision(numbers t, int one, int two) : time(t), first(one), second(two) { }

  bool operator<(const collision& other) const {
    return time < other.time;
  }
};

struct vehicle {
  std::string id;
  numbers rx, ry, vx, vy;
};

struct wall_hit {
  numbers wall_time;
  int first_wall;
  wall_hit(numbers w, int one_wall) : wall_time(w), first_wall(one_wall) { }

  bool operator<(const wall_hit& other) const {
    return wall_time < other.wall_time;
  }
};

numbers wall_timer(const vehicle& one, int xmin, int xmax, int ymin, int ymax) {
  double xsec, ysec;
  if (one.vx < 0) {
    xsec = ((xmin+5)-one.rx)/one.vx;
  } else if (one.vx > 0) {
    xsec = ((xmax-5)-one.rx)/one.vx;
  }
  if (one.vy < 0) {
    ysec = ((ymin+5)-one.ry)/one.vy;
  } else if (one.vy > 0) {
    ysec = ((ymax-5)-one.ry)/one.vy;
  }
  if (xsec < ysec) {
    if (xsec > 0) {
      return xsec;
    }
  } else if (xsec > ysec) {
    if (ysec > 0) {
      return ysec;
    }
  }
}

string wall_type (const vehicle& one, int xmin, int xmax, int ymin, int ymax) {
  double xsec, ysec;
  if (one.vx < 0) {
    xsec = ((xmin+5)-one.rx)/one.vx;
  } else if (one.vx > 0) {
    xsec = ((xmax-5)-one.rx)/one.vx;
  }
  if (one.vy < 0) {
    ysec = ((ymin+5)-one.ry)/one.vy;
  } else if (one.vy > 0) {
    ysec = ((ymax-5)-one.ry)/one.vy;
  }
  if (xsec < ysec) {
    if (xsec > 0) {
      return "x";
    }
  } else if (xsec > ysec) {
    if (ysec > 0) {
      return "y";
    }
  }
}
numbers collide_timer(const vehicle& one, const vehicle& two) {
  numbers a = two.rx - one.rx;
  numbers b = two.ry - one.ry;
  numbers c = two.vx - one.vx;
  numbers d = two.vy - one.vy;
  numbers A = c * c + d * d;
  numbers B = 2 * (a * c + b * d);

  numbers C = (a * a + b * b - 100);


  numbers rootarg = B * B - 4 * A * C;

  if (rootarg < 0) return 0;

  numbers root = sqrt(rootarg);

  numbers t1 = (-B  - root) / (2 * A);
  numbers t2 = (-B + root) / (2 * A);

  if (t1 > 0)
    return t1;
  if (t2 > 0)
    return t2;

  return 0;
}

numbers first_v_v(std::vector<vehicle> cars) {
  std::vector<collision> hits, real_hits;
  for (int i = 0; i < cars.size() ; i++) {
    for (int j = i + 1; j < cars.size() ; j++) {
      numbers collide_t = collide_timer(cars[i], cars[j]);
      if (collide_t)
        hits.push_back(collision(collide_t, i, j));
    }
  }
  std::vector<bool> alive(cars.size(), true);
  std::sort(begin(hits), end(hits));
  for (const auto x : hits)
    if (alive[x.first] and alive[x.second]) {
      alive[x.first] = alive[x.second] = false;
      real_hits.push_back(x);
    }
    if (real_hits.empty() == 0) {
      return real_hits[0].time;
    } else{
      return 0;
    }
}

int main() {
  std::vector<vehicle> cars;
  std::vector<collision> hits, real_hits;
  
  int xmin, xmax, ymin, ymax;
  int interval, period;

  std::cout.precision(8);
  
  vehicle z;
  bool survivors(false);

  cin >> interval >> period >> xmin >> ymin >> xmax >> ymax;
  cout << interval << ' ' << period << '\n';
  cout << xmin << ' ' << ymin << ' ' << xmax << ' ' << ymax << '\n';

  while (cin >> z.id >> z.rx >> z.ry >> z.vx >> z.vy){
    cars.push_back(z);
  }
    //cout << "there are " << cars.size() << " vehicles\n";
  int clock = 1;
  std::vector<vehicle> cars2 = cars;
  std::vector<wall_hit> wall;
  numbers wall_collide;
  for (int i = 0; i < cars.size(); i++) {
    wall_collide = wall_timer(cars[i], xmin, xmax, ymin, ymax);
    if (wall_collide) {
      if (wall_collide > 0) {
        wall.push_back(wall_hit(wall_collide, i));
      }
    }
  }

  while (clock < 11) {
  numbers v_v = first_v_v(cars2);

  std::sort(begin(wall), end(wall));
  numbers v_wall = wall[0].wall_time;
  numbers event;

  if (v_v != 0 && v_wall != 0) {
    if (v_v < v_wall) {
      event = v_v;
    } else if (v_v > v_wall) {
      event = v_wall;
    }
  } else if (v_v == 0) {
    event = v_wall;
  } else if (v_wall == 0) {
    event = v_v;
  }
  int timer = clock;
  while (event > timer) {
    for (int i = 0; i < cars.size(); i++) {
      cars2[i].rx = cars2[i].rx + cars2[i].vx;
      cars2[i].ry = cars2[i].ry + cars2[i].vy; 
    }
    timer++;
    cout << '\n';
  }
  clock = timer;
  if (event <= clock) {
    if (event == v_wall) {
      string w_type = wall_type(cars2[wall[0].first_wall], xmin, ymin, xmax, ymax);
      if (w_type == "x") {
        cars2[wall[0].first_wall].vx = cars2[wall[0].first_wall].vx * -1;
        numbers tim = clock - wall[0].wall_time;
        cars2[wall[0].first_wall].ry = cars2[wall[0].first_wall].ry + cars2[wall[0].first_wall].vy;
        if (cars2[wall[0].first_wall].vx > 0) {
          cars2[wall[0].first_wall].rx = 5 + (cars2[wall[0].first_wall].vx * tim);
        } else {
          cars2[wall[0].first_wall].rx = 95 - (cars2[wall[0].first_wall].vx * tim);
        }
      } else if (w_type == "y") {
          cars2[wall[0].first_wall].vy = cars2[wall[0].first_wall].vy * -1;
          numbers tim = clock - wall[0].wall_time;
          cars2[wall[0].first_wall].rx = cars2[wall[0].first_wall].rx + cars2[wall[0].first_wall].vx;
        if (cars2[wall[0].first_wall].vy > 0) {
          cars2[wall[0].first_wall].ry = 5 + (cars2[wall[0].first_wall].vy * tim);
        } else {
          cars2[wall[0].first_wall].ry = 95 - (cars2[wall[0].first_wall].vy * tim);
        }
      }
    }
    for (int i = 0; i < cars.size(); i++) {
      if (clock == interval) {
      if (wall[0].first_wall == i) {
        cout << cars2[wall[0].first_wall].id << ' ' << cars2[wall[0].first_wall].rx << ' ' << cars2[wall[0].first_wall].ry << '\n';
      } else {
          cars2[i].rx = cars2[i].rx + cars2[i].vx;
          cars2[i].ry = cars2[i].ry + cars2[i].vy; 
      }
    }
    }
    int hi = wall[0].first_wall;
    wall.clear();
    for (int i = 0; i < cars.size(); i++) {
      wall_collide = wall_timer(cars2[i], xmin, xmax, ymin, ymax);
      if (wall_collide) {
        if (wall_collide > 0) {
          wall.push_back(wall_hit(wall_collide, i));
        }
      }
      if (i != hi) {
        wall[i].wall_time = wall[i].wall_time + clock;
      }
    }
  }
  if (clock == interval) {
    cout << "at " << timer << '\n';
    cout << cars[i].id << ' ' << cars2[i].rx << ' ' << cars2[i].ry << '\n';
    cout << '\n';
  }
  //cout << real_hits[0].time << ' ' << cars[real_hits[0].first].id << 
    //  ' ' << cars[real_hits[0].second].id << '\n';
  clock++;
  }
  //cout << wall.size() << ' ' << wall[0].wall_time << ' ' << wall[1].wall_time << '\n'; 
  //cars[1].vx = 1.2;
  //cout << cars[1].vx << '\n';
  //' ' << wall[1].first_wall << '\n';
}
