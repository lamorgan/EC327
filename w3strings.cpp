// Copyright 2017 Laura Morgan lamorgan@bu.edu
// w3strings

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;

bool is_palindrome(string num, bool & error) {
int n = 0;

if (num[n] == '0') {
  error = true;
  return false;
}
for (n = 0; n < num.size(); n++) {
  if (not isdigit(num[n])) {
    error = true;
    return false;
  }
}
if (num == string(num.rbegin(), num.rend())) {
  error = false;
  return true;
} else {
    error = false;
    return false;
}
}

bool is_word(string s) {
int n = 1;
// checks to see if string is at least one character long
if (s.size() == 0) {
return false;
}
// checks for all uppercase
if (isupper(s[0]) != 0) {
while (isupper(s[n]) != 0) {
n = n+1;
}
if (n == s.size()) {
return true;
}
}
// checks for all lowercase
if (islower(s[0]) != 0) {
n = 1;
while (islower(s[n]) != 0) {
n = n+1;
}
if (n == s.size()) {
return true;
} else {
return false;
}
}
// checks for capitalization at beginning
if (isupper(s[0]) != 0) {
n = 1;
while (islower(s[n]) != 0) {
n = n+1;
}
if (n == s.size()) {
return true;
} else {
return false;
}
}
}


// leave this line and everything below as is
int main() {
  cout << std::boolalpha;

  if (not is_word("test")) cout << "we1\n";
  if (not is_word("Test")) cout << "we2\n";
  if (not is_word("TEST")) cout << "we3\n";
  if (not is_word("thisisaword")) cout << "we4\n";

  if (is_word("123")) cout << "we5\n";
  if (is_word("")) cout << "we6\n";
  if (is_word("abc123abc")) cout << "we7\n";
  if (is_word("tEst")) cout << "we8\n";
  if (is_word("tEst")) cout << "we9\n";
  if (is_word("TESTer")) cout << "we10\n";

  bool error;

  if (not is_palindrome("12321", error) or error) cout << "pe1\n";
  if (not is_palindrome("9009", error) or error) cout  << "pe2\n";
  if (not is_palindrome("9", error) or error)  cout << "pe3\n";
  if (not is_palindrome("123456777654321", error) or error) cout << "pe4\n";

  if (is_palindrome("abcba", error) or not error) cout << "pe5\n";
  if (is_palindrome("12321 a", error) or not error) cout << "pe6\n";
  if (is_palindrome("0012100", error) or not error) cout << "pe7\n";

  if (is_palindrome("123", error) or error) cout << "pe8\n";
  if (is_palindrome("123211", error) or error) cout << "pe9\n";

  cout << "Test Other Words. Ctrl-D to exit.\n";

  string s;
  bool pal;
  while (cin >> s) {
    pal = is_palindrome(s, error);
    cout << s << " " << pal << " " << error << " " << is_word(s) << '\n';
  }

  return 0;
}
