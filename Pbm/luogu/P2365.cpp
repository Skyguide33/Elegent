//2026/6/3
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int t[300005], f[300005], dp[300005], q[300005], tl, s;

double getk(int i, int j) {
  double y = (dp[j]-f[j]*s)-(dp[i]-f[i]*s);
  double x = f[j]-f[i];
  if(x == 0.0) x += 1e-9;
  return y/x; 
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n >> s;
  for(int i = 1; i <= n; ++i) {
    cin >> t[i] >> f[i];
    t[i] += t[i-1];
    f[i] += f[i-1];
  }
  for(int i = 1; i <= n; ++i) {
    while(1 < tl && getk(q[tl-1], i-1) <= getk(q[tl-1], q[tl])) --tl;
    q[++tl] = i-1;
    int k = t[i];
    int l = 1, r = tl;
    while(l < r) {
      int mid = (l+r)>>1;
      if(getk(q[mid], q[mid+1]) >= k) r = mid;
      else l = mid+1;
    }
    int j = q[l];
    int x = f[j], y = dp[j]-f[j]*s;
    dp[i] = y-k*x+f[i]*t[i]+f[n]*s;
    // cout << dp[i] << " \n"[i==n];
  }
  cout << dp[n] << endl;
  return 0;
}