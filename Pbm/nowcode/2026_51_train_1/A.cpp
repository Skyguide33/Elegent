//2026/5/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string sx, sy; cin >> sx >> sy;
  ll x = 0, y = 0;
  if(sx == "0" && sy != "0") cout << -1 << endl;
  else {
    for(int i = 0; sx[i]; ++i) {
      x = x*2+sx[i]-'0';
    }
    for(int i = 0; sy[i]; ++i) {
      y = y*2+sy[i]-'0';
    }
    cout << abs(x-y) << endl;
  }
  return 0;
}