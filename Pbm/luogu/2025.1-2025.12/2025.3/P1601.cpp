//2025/3/20
#include <bits/stdc++.h>
using namespace std;

string add1(string a, string b) {
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  if(a.length() < b.length()) swap(a, b);
  int i = 0, r = 0;
  for(; i < b.length(); i++) {
    r += a.at(i) + b.at(i) - 2*'0';
    a.at(i) = (r % 10) + '0';
    r /= 10;
  }
  for(; i < a.length() && r; i++) {
    r += a.at(i) - '0';
    a.at(i) = (r % 10) + '0';
    r /= 10;
  }
  if(r) a.push_back(r+'0');
  reverse(a.begin(), a.end());
  return a;
  
}

int main() {
  string a, b;
  cin >> a >> b;
  cout << add1(a, b) << endl;
  return 0;
}