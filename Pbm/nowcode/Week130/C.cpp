//2026/2/8
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dge[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  int maxdge = 0;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    ++dge[u]; ++dge[v];
    maxdge = max({maxdge, dge[u], dge[v]});
  }
  if(maxdge > 3) cout << 0 << endl;
  else {
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
      if(dge[i] <= 2) ++ans;
    }
    cout << ans << endl;
  }
  return 0;
}