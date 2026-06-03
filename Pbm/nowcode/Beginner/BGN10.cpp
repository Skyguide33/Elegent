//2026/3/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[1000005];

void solve() {
  string s; cin >> s;
  int n = s.length(), sum = 0;
  int cnt2 = 0, cnt3 = 0;
  for(int i = 1; i <= n; ++i) {
    a[i] = s[i-1]-'0';
    sum += a[i];
    if(a[i] == 2) ++cnt2;
    else if(a[i] == 3) ++cnt3;
  }
  int tar = (9-sum%9)%9;
  for(int i = 0; i <= min(cnt2, 8); ++i) {
    for(int j = 0; j <= min(cnt3, 2); ++j) {
      if((i*2+j*6)%9 == tar) {
        cout << "YES" << endl;
        return;
      } 
    }
  }
  cout << "NO" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}