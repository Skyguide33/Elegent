//2026/5/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  vector<int> a;
  for(int i = 1; i < n; ++i) {
    for(int j = i+1; j <= n; ++j) {
      a.push_back(i);
      a.push_back(j);
    }
  }
  while(a.size() < n*n) a.push_back(1);
  for(int i = 1; i <= n; ++i) {
    if(i&1) {
      for(int j = 1; j <= n; ++j) {
        cout << a[(i-1)*n+j-1] << ' ';
      }
    } else {
      for(int j = n; j >= 1; --j) {
        cout << a[(i-1)*n+j-1] << ' ';
      }
    }
    cout << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}