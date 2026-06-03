//2026/2/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int arr[2][40005], q[40005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, W; cin >> n >> W;
  int *dp = arr[1], *old = arr[0];
  for(int i = 1; i <= n; ++i) {
    int v, w, m; cin >> v >> w >> m;
    swap(dp, old);
    for(int r = 0; r < w; ++r) {
      int h = 0, t = -1;
      for(int j = r; j <= W; j += w) {
        if(h <= t && q[h] < j-m*w) ++h;
        while(h <= t && old[q[t]]+(j-q[t])/w*v <= old[j]) --t;
        q[++t] = j;
        dp[j] = max(old[j], old[q[h]]+(j-q[h])/w*v);
      } 
    }
  }
  cout << dp[W] << endl;
  return 0;
}