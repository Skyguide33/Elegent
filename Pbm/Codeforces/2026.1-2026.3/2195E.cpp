//2026/3/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007

int ls[300005], rs[300005], p[300005];

void dfs1(int u) {
  if(ls[u]) {
    p[u] = 4;
    dfs1(ls[u]);
    dfs1(rs[u]);
    p[u] = ((p[u]+p[ls[u]])%MOD+p[rs[u]])%MOD;
  } 
} 

void dfs2(int u, int fa) {
  p[u] = (p[u]+p[fa]+1)%MOD;
  if(ls[u]) {
    dfs2(ls[u], u);
    dfs2(rs[u], u);
  }
}

void solve() {
  int n; cin >> n;
  fill(p+1, p+n+1, 0);
  for(int i = 1; i <= n; ++i) {
    cin >> ls[i] >> rs[i];
  }
  dfs1(1);
  dfs2(1, 0);
  for(int i = 1; i <= n; ++i) cout << p[i] << ' ';
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}