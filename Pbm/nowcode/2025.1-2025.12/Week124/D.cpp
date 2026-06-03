//2025/12/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dge[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    ++dge[u]; ++dge[v];
  }
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    if(dge[i] == 1) ++ans;
  }
  ans -= ans/2;
  cout << ans << endl;
  return 0;
}