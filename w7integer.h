// division algorithim
// while R >= D do
//   Q := Q+1;
//   R := R-D;
// end
// return (Q,R);

// Copyright lamorgan@bu.edu
#ifndef INTEGER_H
#define INTEGER_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::cout;
using std::string;
using std::vector;

class Integer {
 public:
  Integer() {

  }
  Integer(int x) : val(x) {
    i = std::to_string(val);
  }
  string i;
  int val;
  Integer(string y) : j(y) {
  }
  string j;
};

#endif

Integer operator+ (const Integer& lhs, const Integer& rhs) {
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
  string k = lhs.j;
  if (k.empty()) {
    k = lhs.i;
  }
  string m = rhs.i;
  if (m.empty()) {
    m = rhs.j;
  }
  size_t n = std::max(k.size(), m.size());
  if (n > k.size())
    k = string(n-k.size(), '0') + k;
  if (n > m.size())
    m = string(n-m.size(), '0') + m;

  string final(n+1, '0');
  char carry = 0;

  string::const_reverse_iterator s1 = k.rbegin(), e = k.rend(),
                                 s2 = m.rbegin();
  string::reverse_iterator f = final.rbegin();

  for (; s1 != e; ++s1, ++s2, ++f) {
    char tmp = (*s1-'0')+(*s2-'0') + carry;
    if (tmp > 9) {
      carry = 1;
      tmp-= 10;
    } else {
      carry = 0;
    }
    *f = tmp + '0';
  }
  final[0] = carry +'0';

  n = final.find_first_not_of("0");
  if (n != string::npos) {
    final = final.substr(n);
  }
  return final;
}

std::ostream& operator<< (std::ostream& out, const Integer& arg) {
  out << arg.i << arg.j;
  return out;
}

std::istream& operator>> (std::istream& in, Integer& one) {
  in >> one.j;
  return in;
}

Integer operator- (const Integer& lhs, const Integer& rhs) {
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
  string k = lhs.j;
  if (k.empty()) {
    k = lhs.i;
  }
  string m = rhs.i;
  if (m.empty()) {
    m = rhs.j;
  }
  size_t n = std::max(k.size(), m.size());
  if (n > k.size())
    k = string(n-k.size(), '0') + k;
  if (n > m.size())
    m = string(n-m.size(), '0') + m;

  string final(n+1, '0');
  char carry = 0;

  string::const_reverse_iterator s1 = k.rbegin(), e = k.rend(),
                                 s2 = m.rbegin();
  string::reverse_iterator f = final.rbegin();

  for (; s1 != e; ++s1, ++s2, ++f) {
    char tmp;
    if ((*s1-'0') < (*s2 - '0')) {
      tmp = (*s1-'0'+10-carry)-(*s2-'0');
      carry = 1;
    } else {
      tmp = (*s1-'0'-carry)-(*s2-'0');
      carry = 0;
    }
    *f = tmp + '0';
  }
  final[0] = carry +'0';

  n = final.find_first_not_of("0");
  if (n != string::npos) {
    final = final.substr(n);
  }
  return final;
}

Integer operator* (const Integer& lhs, const Integer& rhs) {
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
  Integer other;
  string k = lhs.i;
  if (k.empty()) {
    k = lhs.j;
  }
  string m = rhs.i;
  if (m.empty()) {
    m = rhs.j;
  }
  return other;
}
Integer operator++(const Integer& one) {
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
  Integer other;
  string k = one.i;
  if (k.empty()) {
    k = one.j;
  }
  string m = "2";
  size_t n = std::max(k.size(), m.size());
  if (n > k.size())
    k = string(n-k.size(), '0') + k;
  if (n > m.size())
    m = string(n-m.size(), '0') + m;

  string final(n+1, '0');
  char carry = 0;

  string::const_reverse_iterator s1 = k.rbegin(), e = k.rend(),
                                 s2 = m.rbegin();
  string::reverse_iterator f = final.rbegin();

  for (; s1 != e; ++s1, ++s2, ++f) {
    char tmp = (*s1-'0')+(*s2-'0') + carry;
    if (tmp > 9) {
      carry = 1;
      tmp-= 10;
    } else {
      carry = 0;
    }
    *f = tmp + '0';
  }
  final[0] = carry +'0';

  n = final.find_first_not_of("0");
  if (n != string::npos) {
    final = final.substr(n);
  }
  return final;
}
Integer operator++ (const Integer& one, int a) {
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
  string k = one.i;
  if (k.empty()) {
    k = one.j;
  }
  string m = "1";
  size_t n = std::max(k.size(), m.size());
  if (n > k.size())
    k = string(n-k.size(), '0') + k;
  if (n > m.size())
    m = string(n-m.size(), '0') + m;

  string final(n+1, '0');
  char carry = 0;

  string::const_reverse_iterator s1 = k.rbegin(), e = k.rend(),
                                 s2 = m.rbegin();
  string::reverse_iterator f = final.rbegin();

  for (; s1 != e; ++s1, ++s2, ++f) {
    char tmp = (*s1-'0')+(*s2-'0') + carry;
    if (tmp > 9) {
      carry = 1;
      tmp-= 10;
    } else {
      carry = 0;
    }
    *f = tmp + '0';
  }
  final[0] = carry +'0';

  n = final.find_first_not_of("0");
  if (n != string::npos) {
    final = final.substr(n);
  }
  return final;
}

Integer operator-- (const Integer& one) {
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
  string k = one.j;
  if (k.empty()) {
    k = one.i;
  }
  string m = "2";
  size_t n = std::max(k.size(), m.size());
  if (n > k.size())
    k = string(n-k.size(), '0') + k;
  if (n > m.size())
    m = string(n-m.size(), '0') + m;

  string final(n+1, '0');
  char carry = 0;

  string::const_reverse_iterator s1 = k.rbegin(), e = k.rend(),
                                 s2 = m.rbegin();
  string::reverse_iterator f = final.rbegin();

  for (; s1 != e; ++s1, ++s2, ++f) {
    char tmp;
    if ((*s1-'0') < (*s2 - '0')) {
      tmp = (*s1-'0'+10-carry)-(*s2-'0');
      carry = 1;
    } else if ((*s1-'0') == 0 && (*s2-'0') == 0) {
      if (carry == 1) {
        tmp = 9;
      }
    } else {
      tmp = (*s1-'0'-carry)-(*s2-'0');
      carry = 0;
    }
    *f = tmp + '0';
  }
  final[0] = carry +'0';

  n = final.find_first_not_of("0");
  if (n != string::npos) {
    final = final.substr(n);
  }
  return final;
}
Integer operator-- (const Integer& one, int a) {
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
  string k = one.j;
  if (k.empty()) {
    k = one.i;
  }
  string m = "1";
  size_t n = std::max(k.size(), m.size());
  if (n > k.size())
    k = string(n-k.size(), '0') + k;
  if (n > m.size())
    m = string(n-m.size(), '0') + m;

  string final(n+1, '0');
  char carry = 0;

  string::const_reverse_iterator s1 = k.rbegin(), e = k.rend(),
                                 s2 = m.rbegin();
  string::reverse_iterator f = final.rbegin();

  for (; s1 != e; ++s1, ++s2, ++f) {
    char tmp;
    if ((*s1-'0') < (*s2 - '0')) {
      tmp = (*s1-'0'+10-carry)-(*s2-'0');
      carry = 1;
    } else if ((*s1-'0') == 0 && (*s2-'0') == 0) {
      if (carry == 1) {
        tmp = 9;
      }
    } else {
      tmp = (*s1-'0'-carry)-(*s2-'0');
      carry = 0;
    }
    *f = tmp + '0';
  }
  final[0] = carry +'0';

  n = final.find_first_not_of("0");
  if (n != string::npos) {
    final = final.substr(n);
  }
  return final;
}
bool operator> (const Integer& lhs, const Integer& rhs) {
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
  string k = lhs.j;
  if (k.empty()) {
    k = lhs.i;
  }
  string m = rhs.i;
  if (m.empty()) {
    m = rhs.j;
  }
  if (k.size() > m.size()) {
    return 1;
  }
  if (k > m) {
    return 1;
  } else {
    return 0;
  }
}
bool operator< (const Integer& lhs, const Integer& rhs) {
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
  string k = lhs.j;
  if (k.empty()) {
    k = lhs.i;
  }
  string m = rhs.i;
  if (m.empty()) {
    m = rhs.j;
  }
  if (k.size() < m.size()) {
    return 1;
  }
  if (k < m) {
    return 1;
  } else {
    return 0;
  }
}
bool operator== (const Integer& lhs, const Integer& rhs) {
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
  string k = lhs.j;
  if (k.empty()) {
    k = lhs.i;
  }
  string m = rhs.i;
  if (m.empty()) {
    m = rhs.j;
  }

  if (k == m) {
    return 1;
  }	else {
    return 0;
  }
}
bool operator!= (const Integer& lhs, const Integer& rhs) {
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
  string k = lhs.j;
  if (k.empty()) {
    k = lhs.i;
  }
  string m = rhs.i;
  if (m.empty()) {
    m = rhs.j;
  }

  if (k != m) {
    return 1;
  }	else {
    return 0;
  }
}
bool operator>= (const Integer& lhs, const Integer& rhs) {
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
  string k = lhs.j;
  if (k.empty()) {
    k = lhs.i;
  }
  string m = rhs.i;
  if (m.empty()) {
    m = rhs.j;
  }
  if (k > m || k == m) {
    return 1;
  } else {
    return 0;
  }
}
bool operator<= (const Integer& lhs, const Integer& rhs) {
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
  string k = lhs.j;
  if (k.empty()) {
    k = lhs.i;
  }
  string m = rhs.i;
  if (m.empty()) {
    m = rhs.j;
  }
  if (k < m || k == m) {
    return 1;
  } else {
    return 0;
  }
}
