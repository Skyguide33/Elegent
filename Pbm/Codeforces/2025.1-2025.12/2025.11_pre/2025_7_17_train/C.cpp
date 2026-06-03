//2025/7/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int h[100005];

void solve() {
  int n, k; cin >> n >> k;
  for(int i = 1; i <= n; ++i) cin >> h[i];
  int now = h[k];
  sort(h+1, h+n+1);
  int idx = 1;
  bool sink = 0;
  while(h[idx] != now) ++idx;
  for(int i = idx; i < n; ++i) {
    if(h[i+1]-h[i] > now) {
      sink = 1;
      cout << "No" << endl;
      break;
    }
  }
  if(!sink) cout << "Yes" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}