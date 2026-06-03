//2026/6/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll s[500005], dp[500005], q[500005], h, t;

double getk(int i, int j) {
  double y = (dp[i]+s[i]*s[i])-(dp[j]+s[j]*s[j]);
  double x = s[i]-s[j];
  if(x == 0.0) x += 1e-9;
  return y/x;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; 
  while(cin >> n >> m) {
    for(int i = 1; i <= n; ++i) {
      cin >> s[i];
      s[i] += s[i-1];
    }
    h = 1, t = 0;
    for(int i = 1; i <= n; ++i) {
      while(t > h && getk(q[t], i-1) <= getk(q[t-1], i-1)) --t;
      q[++t] = i-1;
      ll k = 2*s[i];
      while(h < t && getk(q[h], q[h+1]) <= k) ++h;
      int idx = q[h];
      ll x = s[idx], y = dp[idx]+s[idx]*s[idx];
      ll b = y-k*x;
      dp[i] = b+s[i]*s[i]+m;
    }
    cout << dp[n] << endl;
  }
  return 0;
}