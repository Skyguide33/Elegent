//2025/11/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  int t, x; 
  int pre = 1, mint = 0;
  for(int i = 1; i <= m; ++i) {
    cin >> t >> x;
    if(x != pre) {
      pre = x;
      ++mint;
    }
    if(x) a[t] = 1;
    else a[t] = -1;
  }
  bool now = 0;
  int maxt = 0;
  for(int i = 1; i <= t; ++i) {
    if((!now && a[i] != 1) || (now && a[i] != -1)) ++maxt, now ^= 1;
  }
  int t2 = n-t;
  int T; cin >> T;
  while(T--) {
    int s; cin >> s;
    if(!t2) {
      if(mint <= s && s <= maxt && (s-mint)%2 == 0) cout << "Yes" << endl;
      else cout << "No" << endl;
    } else {
      if(mint <= s && s <= maxt+t2 && s != maxt+t2-1) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
  return 0;
}