//2025/7/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class longint {
public:
  string num;
  longint() {};
  longint(string s): num(s) {}
  friend longint operator + (const longint& a, const longint& b);
  friend ostream& operator << (ostream& out, const longint& a) {
    out << a.num;
    return out;
  }
};

longint operator + (const longint& a, const longint& b) {
  const string& x = a.num, &y = b.num;
  string res;
  int r = 0, xlen = x.length(), ylen = y.length();
  for(int i = 1;; ++i) {
    int ix = xlen-i, iy = ylen-i;
    if(ix >= 0) r += x[ix] - '0';
    if(iy >= 0) r += y[iy] - '0';
    if(r || ix >= 0 || iy >= 0) {
      res = to_string(r%10) + res;
      r /= 10;
    } else break;
  }
  return longint(res);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  longint a("1"), b("1");
  longint *now = &a, *pre = &b;
  for(int i = 2; i <= n; ++i) {
    swap(now, pre);
    *now = *now + *pre;
  }
  cout << *now << endl;
  return 0;
}