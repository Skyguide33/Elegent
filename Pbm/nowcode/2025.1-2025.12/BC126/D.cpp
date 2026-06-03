//2025/12/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, q; cin >> n >> q;
  vector<int> c(n+3);
  for(int i = 1; i <= n; ++i) {
    int a, b; cin >> a >> b;
    if(a < b) swap(a, b);
    if(a-b <= 3) {
      ++c[0]; --c[b-1];
      ++c[a+2];
    } else {
      ++c[0]; --c[b-1];
      ++c[b+2]; --c[a-1];
      ++c[a+2];
    }
  }
  for(int i = 1; i <= n; ++i) c[i] += c[i-1];
  while(q--) {
    int x; cin >> x;
    cout << c[x] << ' ';
  }
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}