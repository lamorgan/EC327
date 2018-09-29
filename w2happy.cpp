// Copyright 2017 Laura Morgan lamorgan@bu.edu

#include <iostream>
using std::cout;

int main() {
int num = 0;
int i = 0;
int j;
int k = 1;
int total = 0;
int count = 0;
int happy = 1;

while (happy <= 888) {
count = 0;
num = num+1;
i = num;
while (count < 20) {
total = 0;
k = 1;
while (i/k %10 == 0) {
k = k*10;
}
while (i/k %10 != 0) {
j = (i/k) %10;
total = total+(j*j);
k = k*10;
if (i/k %10 == 0) {
k = k*10;
if (i/k %10 == 0) {
k = k*10;
}
}
}
i = total;
count = count+1;
}
if (total == 1) {
cout << num << '\n';
happy = happy+1;
}
}
return 0;
}


