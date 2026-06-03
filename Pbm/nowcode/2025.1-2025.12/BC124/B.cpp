//2025/11/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005];

bool cmp(int x, int y) { return x > y; }

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1, cmp);
  for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}