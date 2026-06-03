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
} q[100005];

int a[100005];

void solve() {
  int n, m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int v, l, r; cin >> l >> r >> v;
    q[i] = {l, r, v};
  }
  set<int>
}