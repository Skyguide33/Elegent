//2025/7/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m, t; cin >> n >> m;
  vector<vector<int>> a(n+1, vector<int> (0));
  for(int i = 1; i <= n; ++i) {
    cin >> t; 
    a[i].resize(t);
    for(int i = 0; i < t; ++i) cin >> a[i][t];
    sort(a[i].begin(), a[i].end());
  }
  if(m == 1) {
    cout << "No\n";
    return;
  }
  /* 可交换的条件：
  1、某两个操作的并集包含于靠后的操作之后所有操作的并集
  2、某两个操作互斥，且仅靠前的操作之前的任意操作才可能与该两个操作的并集有交集
  */
  int cnt = 0;
  set<int> st;
  for(int i = n; i >= 3; --i) {
    for(int& x: a[i]) {
      if(!st.count(x)) {
        st.insert(x); ++cnt;
      }
      if(cnt == m) {
        cout << 2 << ' ' << 1 << ' ';
        for(int i = 3; i <= m; ++i) cout << i << ' ';
        cout << endl;
      }
    }
  }
  
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}