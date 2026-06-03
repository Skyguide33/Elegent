//2026/2/2
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = 1000000007;

vector<int> e[200005];
int num[200005], den[200005];

void addedge(int u, int v) {
  e[u].push_back(v);
  e[v].push_back(u);
}

int inv(int n) {
  int res = 1, b = n, p = MOD-2;
  while(p) {
    if(p&1) res = res*b%MOD;
    b = b*b%MOD;
    p >>= 1;
  }
  return res;
}

void dfs(int u, int fa) {
  int len = e[u].size();
  num[u] = 0; den[u] = 1;
  for(int i = 0; i < len; ++i) {
    int v = e[u][i];
    if(v == fa) continue;
    dfs(v, u);
    num[u] = (num[u]*den[v]%MOD+num[v]*den[u]%MOD)%MOD;
    den[u] = den[u]*den[v]%MOD;
  }
  if(len-1) den[u] = den[u]*len%MOD;
  num[u] = (num[u]+den[u])%MOD;
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v);
  }
  dfs(1, 0);
  // for(int i = 1; i <= n; ++i) {
  //   cout << num[i] << ' ' << den[i] << endl;
  // }
  cout << num[1]*inv(den[1])%MOD << endl;
  cout << inv(3) << endl;
  cout << inv(2) << endl;
  cout << inv(6) << endl;
  return 0;
}