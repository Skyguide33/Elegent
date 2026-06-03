//2026/5/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define lowbit(x) (x&(-x))

ll tr1[500005], tr2[500005], tr3[500005], tr4[500005], n;

inline void modify(ll tr[], int x, ll k) {
  while(x <= n/2) {
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

inline void update1(int l, int r, ll k) {
  modify(tr1, l, k); modify(tr1, r+1, -k);
  modify(tr2, l, k*(l-1)); modify(tr2, r+1, -k*r);
}

inline ll query1(int l, int r) {
  return r*sum(tr1, r)-sum(tr2, r)-(l-1)*sum(tr1, l-1)+sum(tr2, l-1);
}

inline void update0(int l, int r, ll k) {
  modify(tr3, l, k); modify(tr3, r+1, -k);
  modify(tr4, l, k*(l-1)); modify(tr4, r+1, -k*r);
}

inline ll query0(int l, int r) {
  return r*sum(tr3, r)-sum(tr4, r)-(l-1)*sum(tr3, l-1)+sum(tr4, l-1);
}

ll a[1000005];

void solve() {
  int n; cin >> n;
  ll sum = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  if(sum%n) {
    cout << -1 << endl;
    return;
  }
  ll avg = sum/n;
  for(int i = 1; i <= n; ++i) {
    a[i] -= avg;
    if(i%2) update1((i+1)/2, (i+1)/2, a[i]);
    else update0(i/2, i/2, a[i]);
  }
  for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
  cout << endl;

}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}