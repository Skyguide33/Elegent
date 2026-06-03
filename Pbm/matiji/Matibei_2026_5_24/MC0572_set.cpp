//2026/5/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Query {
  int l, r, v;
  bool operator<(const Query &other) const {
    if(v == other.v) {
      if(l == other.l) return r < other.r;
      return l < other.l;
    }
    return v < other.v;
  }
} q[200005];

int a[200005];

void solve() {
  int n, m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int l, r, v; cin >> l >> r >> v;
    q[i] = {l, r, v};
  }
  sort(q+1, q+m+1);
  int last = 1;
  for(int i = 2; i <= m; ++i) {
    if(q[i].v == q[last].v && q[last].r >= q[i].l) {
      q[last].r = max(q[last].r, q[i].r);
      q[i].v = 0;
    } else last = i;
  }
  int cnt = 0;
  for(int i = 1; i <= m; ++i) {
    if(q[i].v) q[++cnt] = q[i];
  }
  set<int> st;
  for(int i = 1; i <= n; ++i) {
    a[i] = 1e9;
    st.insert(i); 
  }
  for(int i = 1; i <= cnt; ++i) {
    auto [l, r, v] = q[i];
    auto it = st.lower_bound(l);
    if(it == st.end() || *it > r) {
      cout << "No" << endl;
      return;
    }
    while(it != st.end() && *it <= r) {
      a[*it] = v;
      auto oit = it;
      ++it;
      st.erase(oit);
    }
  }
  cout << "Yes" << endl;
  for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
  cout << endl;
} 

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}