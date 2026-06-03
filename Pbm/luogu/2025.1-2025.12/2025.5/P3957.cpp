//2025/5/9
#include <bits/stdc++.h>
using namespace std;

int n, d, k, x[500005], s[500005];
long long dp[500005];

inline int read() {
  int x = 0, f = 1; char ch = getchar();
  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
  while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ '0'); ch = getchar(); }
  return x * f;
}

bool check(int g) {
  memset(dp, -127, sizeof(dp)); dp[0] = 0;
  int lp = max(1, d-g), rp = d+g, j = 0;
  deque<int> q;
  for(int i = 1; i <= n; ++i) {
    while(x[i]-x[j] >= lp) {
      if(dp[j] > -1e12) {
        while(!q.empty() && dp[q.back()] < dp[j]) q.pop_back();
        q.push_back(j);
      }
      ++j;
    }
    while(!q.empty() && x[i]-x[q.front()] > rp) q.pop_front();
    if(!q.empty()) dp[i] = dp[q.front()] + s[i];
    if(dp[i] >= k) return 1;  
  }
  return 0;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  n = read(); d = read(); k = read();
  for(int i = 1; i <= n; ++i) {
    x[i] = read(); s[i] = read();
  }
  int l = max(1, x[1]-d), r = x[n]-d+1, mid = l + (r-l)/2;
  while(l < r) {
    if(check(mid)) r = mid;
    else l = mid+1;
    mid = l + (r-l)/2;
  }
  if(l == x[n]-d+1) cout << -1 << endl;
  else cout << l << endl;
  return 0;
}