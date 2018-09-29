// Copyright 2017 Laura Morgan lamorgan@bu.edu

#include <iostream>

int main() {
int count = 2;
int div;
int a;


while (count <= 888) {
div = 1;
a = 0;
std::cout << count << ": ";
while (count%div == 0 && count != div) {
if (div == 1) {
std::cout << div;
div = div+1;
a = 1;
} else {
std::cout << "+" << div;
a = a + div;
div = div + 1;
}
while (count%div != 0) {
div = div + 1;
}
}
std::cout << " = " << a << "\n";
count = count+1;
}
}


