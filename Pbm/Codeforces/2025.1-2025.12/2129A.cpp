//2025/11/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  vector<int> a(n+1), b(n+1);
  for(int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
  vector<int> tag(n+1, 1);
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      if(i != j && a[i] >= a[j] && b[i] <= b[j]) {
        tag[i] = 0;
        break;
      }
    }
  }
  queue<int> ans;
  for(int i = 1; i <= n; ++i) {
    if(tag[i]) ans.push(i);
  }
  cout << ans.size() << endl;
  while(!ans.empty()) cout << ans.front() << ' ', ans.pop();
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}