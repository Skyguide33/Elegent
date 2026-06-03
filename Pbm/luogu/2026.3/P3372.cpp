//2026/3/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 100005
#define lowbit(x) (x&(-x))

ll tr1[N], tr2[N], n;

inline void modify(ll tr[], int x, ll k) {
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

inline void update(int l, int r, ll k) {
  modify(tr1, l, k); modify(tr1, r+1, -k);
  modify(tr2, l, k*(l-1)); modify(tr2, r+1, -k*r);
}

inline ll query(int l, int r) {
  return r*sum(tr1, r)-sum(tr2, r)-(l-1)*sum(tr1, l-1)+sum(tr2, l-1);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    ll tt; cin >> tt;
    update(i, i, tt);
  }
  while(m--) {
    int op, x, y; cin >> op >> x >> y;
    if(op == 1) {
      ll k; cin >> k;
      update(x, y, k);
    } else cout << query(x, y) << endl;
  }
  return 0;
}