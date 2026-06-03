//2025/10/31
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dge[51];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    ++dge[u]; ++dge[v];
  }
  int res = 0;
  for(int i = 1; i <= n; ++i) res += (dge[i] > 1);
  if(res&1 || n == 2) cout << "Bob" << endl;
  else cout << "Alice" << endl;
  return 0;
}