//2026/5/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define lowbit(x) (x&(-x))

ll tr1[200005], tr2[200005], n, a[200005];

inline void modify(ll tr[], int x, int k) {
  while(x <= n) {
    tr[x] += k;
    x += lowbit(x);
  }
}

inline ll sum(ll tr[], int x) {
  ll res = 0;
  while(x) {
    res += tr[x];
    x -= lowbit(x);
  }
  return res;
}

inline void update(int l, int r, int k) {
  modify(tr1, l, k); modify(tr1, r+1, -k);
  modify(tr2, l, k*(l-1)); modify(tr2, r+1, -k*r);
}

inline ll query(int l, int r) {
  return r*sum(tr1, r)-sum(tr2, r)-(l-1)*sum(tr1, l-1)+sum(tr2, l-1);
}

void solve() {
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  fill(tr1+1, tr1+n+1, 0);
  fill(tr2+1, tr2+n+1, 0);
  int maxi = 0, maxn = 0;
  for(int i = 1; i <= n; ++i) {
    int cnt = query(a[i], a[i]);
    // cout << "cnt=" << cnt << endl;
    if(cnt > maxn) {
      maxn = cnt;
      maxi = i;
    }
    update(1, a[i], 1);
  }
  // cout << maxi << ' ' << maxn << endl;
  if(maxi) --a[maxi];
  fill(tr1+1, tr1+n+1, 0);
  fill(tr2+1, tr2+n+1, 0);
  ll ans = 0;
  for(int i = 1; i <= n; ++i) {
    ans += query(a[i]+1, n);
    update(1, a[i], 1);
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}