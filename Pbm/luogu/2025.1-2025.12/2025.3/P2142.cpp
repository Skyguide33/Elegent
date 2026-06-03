//2025/3/20
#include <bits/stdc++.h>
using namespace std;
char a[11000], b[11000];

string sub1(string a, string b) {
  bool neg = 0;
  if(a == b) return "0";
  else if(a.size() < b.size() || (a.size() == b.size() && a < b)) {
    swap(a, b); neg = 1;
  }
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int i = 0, r = 0;
  for(; i < b.length(); i++) {
    r += a.at(i) - b.at(i);
    a.at(i) = r+((-r+10)/10*10) + '0';
    r = -(-r+10)/10;
  }
  cout << a << endl;
  return a;
}

int main() {
  string a, b;
  cin >> a >> b;
  cout << sub1(a, b) << endl;
  return 0;
}