//2025/11/19
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  vector<int> p(n+1), s(n+1), x(n+1), ans;
  char tt;
  int pos1 = 0, posn = 0;
  for(int i = 1 ; i <= n; ++i) {
    cin >> p[i]; 
    if(p[i] == 1) pos1 = i;
    else if(p[i] == n) posn = i;
  }
  for(int i = 1 ; i <= n; ++i) {
    cin >> tt; s[i] = tt-'0';
  }
  if(s[1] || s[n] || s[pos1] || s[posn]) {
    cout << -1 << endl;
    return;
  }
  int minn = 1, maxn = p[1];
  for(int i = 2; i < pos1; ++i) {
    if(p[i] > minn && p[i] < maxn) s[i] = 1;
  }
  minn = p[1], maxn = n;
  for(int i = 2; i < posn; ++i) {
    if(p[i] > minn && p[i] < maxn) s[i] = 1;
  }
  minn = 1, maxn = p[n];
  for(int i = pos1+1; i < n; ++i) {
    if(p[i] > minn && p[i] < maxn) s[i] = 1;
  }
  minn = p[n], maxn = n;
  for(int i = posn+1; i < n; ++i) {
    if(p[i] > minn && p[i] < maxn) s[i] = 1;
  }
  minn = 1, maxn = n;
  int p1 = pos1, p2 = posn;
  if(p1 > p2) swap(p1, p2);
  for(int i = p1+1; i < p2; ++i) {
    if(p[i] > minn && p[i] < maxn) s[i] = 1;
  }
  for(int i = 1; i <= n; ++i) {
    if(x[i]-s[i] > 0) {
      cout << -1 << endl;
      return;
    }
  }
  cout << 5 << endl;
  cout << 1 << ' ' << pos1 << endl;
  cout << pos1 << ' ' << n << endl;
  cout << 1 << ' ' << posn << endl;
  cout << posn << ' ' << n << endl;
  cout << p1 << ' ' << p2 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
}