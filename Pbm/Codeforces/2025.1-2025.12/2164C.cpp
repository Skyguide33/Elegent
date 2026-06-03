//2025/11/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 200005

struct Mon { int b, c; } d[N];

bool cmp(const Mon &x, const Mon &y) { 
  if(x.c*y.c == 0) return x.c > y.c;
  return x.b < y.b; 
}

void solve() {
  int n, m, t; cin >> n >> m;
  multiset<int> st;
  for(int i = 1; i <= n; ++i) cin >> t, st.insert(t); 
  for(int i = 1; i <= m; ++i) cin >> d[i].b; 
  for(int i = 1; i <= m; ++i) cin >> d[i].c; 
  sort(d+1, d+m+1, cmp); 
  int ans = 0;
  for(int i = 1; i <= m; ++i) {
    auto it = st.lower_bound(d[i].b);
    if(it != st.end()) {
      int x = *it;
      st.erase(it);
      if(d[i].c) st.insert(max(d[i].c, x));
      ++ans;
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}