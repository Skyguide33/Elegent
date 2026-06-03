//2025/8/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct P{
  int a, b;
} p[100005];

bool cmp(P& x, P& y) { return x.a < y.a; }

void solve() {
  int n, m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    cin >> p[i].a >> p[i].b;
  }
  sort(p+1, p+m+1, cmp);
  if(p[1].a < p[1].b) {
    cout << "No\n";
    return;
  }
  for(int i = 2; i <= m; ++i) {
    if(p[i].a-p[i-1].a != p[i].b-p[i-1].b) {
      
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}