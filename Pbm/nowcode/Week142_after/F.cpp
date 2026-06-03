//2026/5/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353

vector<int> e[200005];
ll a[200005], f[200005];
bool flag;

ll inv(ll b) {
  ll p = MOD-2, res = 1;
  while(p) {
    if(p&1) res = res*b%MOD;
    b = b*b%MOD;
    p >>= 1;
  }
  return res;
}

// 下界, 上界, 概率 
tuple<int, int, ll> dfs(int u, int fa) {
  vector<tuple<int, int, ll>> lr;
  for(int v: e[u]) {
    if(v == fa) continue;
    lr.push_back(dfs(v, u));
    if(!flag) return {0, 0, 0};
  }
  if(lr.empty()) {
    return {a[u], a[u], 1};
  }
  ranges::sort(lr);
  if(get<0>(lr.front()) < a[u]) {
    flag = 0;
    return {0, 0, 0};
  }
  ll res = 1, cnt = 0, val = 0, prer = 0;
  for(auto [l, r, p]: lr) {
    if(prer > l) {
      flag = 0;
      return {0, 0, 0};
    }
    res = res*p%MOD;
    if(prer == l && l == r) {
      if(!val) {
        val = l;
        cnt = 2;
      } else ++cnt;
    } else if(val) {
      res = res*f[cnt]%MOD;
      cnt = 0;
      val = 0;
    }
    prer = r;
  }
  if(val) res = res*f[cnt]%MOD;
  res = res*inv(f[lr.size()])%MOD;
  return {a[u], get<1>(lr.back()), res};
}

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    e[i].clear();
  }
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  flag = 1;
  auto [l, r, p] = dfs(1, 0);
  cout << p << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  f[0] = 1;
  for(int i = 1; i <= 200000; ++i) f[i] = f[i-1]*i%MOD;
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}