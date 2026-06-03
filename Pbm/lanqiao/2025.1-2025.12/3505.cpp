//2025/4/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, a[31], s[31], ans = 35;
bool k[31], nc[31];

bool cmp(ll x, ll y) { return x > y; }
// dfs(当前)

void dfs(ll w, ll num, ll i) {
  if(w == m) {
    ans = min(ans, num);
    return;
  } else if(w > m) return;
  if(i > n || s[n]-s[i-1] < m-w) return;
  dfs(w, num, i+1);
  dfs(w+a[i]/2, num+1, i+1);
  dfs(w+a[i], num, i+1);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  m *= 2;
  ll sum = 0;
  for(ll i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] *= 2;
    sum += a[i];
  }
  sort(a+1, a+n+1, cmp);
  for(ll i = 1; i <= n; i++) s[i] = a[i] + s[i-1];
  dfs(0, 0, 1);
  if(ans == 35) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}