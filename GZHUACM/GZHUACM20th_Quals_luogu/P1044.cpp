//2026/3/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll ans, top, n;

void dfs(int idx) {
  if(idx == n) {
    ++ans;
    return;
  } else {
    ++top;
    dfs(idx+1);
    --top;
  }
  if(top > 0) {
    --top;
    dfs(idx);
    ++top;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  dfs(0);
  cout << ans << endl;
  return 0;
}