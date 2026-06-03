//2025/4/8
#include <bits/stdc++.h>
using namespace std;

string mul(string d, int n) {
  reverse(d.begin(), d.end());
  int dotpos = d.find('.');
  d.erase(dotpos, 1);
  int r = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < d.length(); j++) {
      r += (d.at(j)-'0') * 2;
      d.at(j) = (r%10) + '0';
      r /= 10;
    }
    if(r) {
      d.push_back(r+'0');
      r = 0;
    }
  }
  if(d.at(dotpos-1) >= '5') ++d.at(dotpos);
  string res = d.substr(dotpos);
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; string d; cin >> n >> d;
  cout << mul(d, n) << endl;
  return 0;
}