//2026/3/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[101], vis[101];

void solve() {
  ll n, c, k; cin >> n >> c >> k;
  fill(vis+1, vis+n+1, 0);
  for(int i = 1; i <= n; ++i) cin >> a[i];
  while(1) {
    int maxi = 0, maxn = -1;
    for(int i = 1; i <= n; ++i) {
      if(!vis[i] && a[i] <= c && a[i] > maxn) {
        maxn = a[i];
        maxi = i;
      }
    }
    if(!maxi) break;
    vis[maxi] = 1;
    ll d = c-a[maxi];
    if(k >= d) k -= d, d = 0; 
    else d -= k, k = 0;
    c += c-d;
  }
  cout << c << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}