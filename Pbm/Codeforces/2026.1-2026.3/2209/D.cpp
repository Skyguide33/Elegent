//2026/3/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int r, g, b; cin >> r >> g >> b;
  int rg = 0, gb = 0, br = 0;
  while((r>0)+(g>0)+(b>0) > 1) {
    if(r <= g && r <= b) --g, --b, ++gb;
    else if(g <= r && g <= b) --r, --b, ++br;
    else --r, --g, ++rg;
  }
  if(r) {
    cout << 'R';
    while(rg--) cout << "GR";
    if(br) {
      while(br--) cout << "BR";
      while(gb--) cout << "BG";
    } else {
      while(gb--) cout << "GB";
    }
  } else if(g) {
    cout << 'G';
    while(rg--) cout << "RG";
    if(gb) {
      while(gb--) cout << "BG";
      while(br--) cout << "BR";
    } else {
      while(br--) cout << "RB";
    }
  } else {
    if(b) cout << "B";
    while(gb--) cout << "GB";
    if(br) {
      while(br--) cout << "RB";
      while(rg--) cout << "RG";
    } else {
      while(rg--) cout << "GR";
    }
  }
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}