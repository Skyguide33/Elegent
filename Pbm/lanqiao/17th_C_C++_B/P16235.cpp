//2026/4/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  priority_queue<int> q;
  ll sum = 0;
  for(int i = 1; i <= n; ++i) {
    int tt; cin >> tt;
    sum += tt;
    if(tt) q.push(tt);
  }
  if(sum == 0) {
    cout << 'T' << endl;
    return;
  } else if(n < 5 || sum%5) {
    cout << 'F' << endl;
    return;
  }
  while(!q.empty()) {
    int a[6];
    for(int i = 1; i <= 5; ++i) {
      if(q.empty()) {
        cout << 'F' << endl;
        return;
      }
      a[i] = q.top(); q.pop();
    }
    for(int i = 1; i <= 5; ++i) a[i] -= a[5];
    for(int i = 1; i <= 5; ++i) {
      if(a[i]) q.push(a[i]);
    }
  }
  cout << 'T' << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}