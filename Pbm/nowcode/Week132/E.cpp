//2026/2/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int rev(int a) {
  queue<int> q;
  while(a) {
    q.push(a%10);
    a /= 10;
  }
  int res = 0;
  while(!q.empty()) {
    res = res*10+q.front(); q.pop();
  }
  return res;
} 

void solve() {
  int a, b, k; cin >> a >> b >> k;
  int len = min(1000000, b*10);
  vector<int> d(len+1, 0);
  set<int> pa;
  queue<int> q;
  q.push(a);
  d[a] = 1;
  pa.insert(a);
  while(!q.empty()) {
    a = q.front(); q.pop();
    int a1 = a+k;
    if(a1 <= len && !d[a1]) {
      q.push(a1);
      d[a1] = d[a]+1;
    } 
    if(a%10) {
      int a2 = rev(a);
      if(a2 <= len && !d[a2]) {
        q.push(a2);
        d[a2] = d[a]+1;
      }
    }
  }
  if(d[b] == 0) cout << -1 << endl;
  else cout << d[b]-1 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}