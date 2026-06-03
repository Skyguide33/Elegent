//2026/2/6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dp[101][101], a[101][101];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int f, v; cin >> f >> v;
  for(int i = 1; i <= f; ++i) {
    for(int j = 1; j <= v; ++j) cin >> a[i][j];
  }
  memset(dp, 0xbf, sizeof(dp));
  for(int i = 0; i <= v-f; ++i) dp[0][i] = 0;
  for(int i = 1; i <= f; ++i) {
    for(int j = i; j <= v-f+i; ++j) {
      dp[i][j] = max(dp[i][j-1], dp[i-1][j-1]+a[i][j]);
    }
  }
  stack<int> st;
  int idx = v;
  for(int i = f; i >= 1; --i) {
    while(dp[i][idx] == dp[i][idx-1]) --idx;
    st.push(idx--);
  }
  cout << dp[f][v] << endl;
  while(!st.empty()) {
    cout << st.top() << ' ';
    st.pop();
  }
  cout << endl;
  return 0;
}