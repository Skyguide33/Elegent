//2025/12/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[5005], maxv[5005], minv[5005];

void solve() {
  int n, m; cin >> n >> m;
  int maxn = 1, minn = 5000;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    maxn = max(maxn, a[i]);
    minn = min(minn, a[i]);
  }
  
  while(m && maxn != minn) {
    for(int i = 1; i <= n; ++i) maxv[i] = minv[i] = 0;
    bool flag = 0;
    int maxt = 0, mint = 0, l = 1;
    a[n+1] = minn;
    for(int i = 1; i <= n+1; ++i) {
      if(a[i] == maxn) flag = 1; 
      else if(a[i] == minn) {
        if(flag) {
          ++maxt;
          flag = 0;
          for(int j = l; j < i; ++j) maxv[j] = 1;
        }
        l = i+1;
      }
    }
    a[n+1] = maxn;
    l = 1;
    // for(int i = 1; i <= n; ++i) cout << maxv[i] << minv[i] << ' ';
    // cout << endl;
    for(int i = 1; i <= n+1; ++i) {
      if(a[i] == minn) flag = 1; 
      else if(a[i] == maxn) {
        if(flag) {
          ++mint;
          flag = 0;
          for(int j = l; j < i; ++j) minv[j] = 1;
        }
        l = i+1;
      }
    }
    int t = min(maxt, mint);
    if(m >= t) {
      m -= t;
      if(maxt <= mint) {
        --maxn;
        for(int i = 1; i <= n; ++i) {
          if(maxv[i]) --a[i];
        }
      } else {
        ++minn;
        for(int i = 1; i <= n; ++i) {
          if(minv[i]) ++a[i];
        }
      }
    } else m = 0;
    cout << maxt << ' ' << mint << endl;
    for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
    cout << endl;
  }
  cout << maxn-minn << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; // cin >> T;
  while(T--) solve();
  return 0;
}