//2025/11/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

map<ll, int> dist;
// ll maxnum = 0;

int dfs(ll n) {
  if(!dist[n]) {
    // if(maxnum < n) maxnum = n;
    if(n%2) dist[n] = dfs(3*n+1)+1;
    else dist[n] = dfs(n/2)+1;
  }
  return dist[n];
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  dist[1] = 1;
  int maxdist = 1, ans = 1;
  for(int i = 2; i <= 1000000; ++i) {
    int tt = dfs(i);
    if(maxdist < tt) {
      maxdist = tt;
      ans = i;
    }
  }
  // cout << maxnum << endl;
  cout << ans << endl;
  return 0;
}

// 837799