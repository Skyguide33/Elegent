//2026/2/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int prime[1005], vis[1005], cnt;
ll dp[1005];

void eular_sieve() {
  int n = 1000;
  for(int i = 2; i <= n; ++i) {
    if(!vis[i]) {
      prime[++cnt] = i;
      vis[i] = i;
    }
    for(int j = 1; j <= cnt; ++j) {
      if(i*prime[j] > n) break;
      vis[i*prime[j]] = prime[j];
      if(i%prime[j] == 0) break;
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  eular_sieve();
  int n; cin >> n;
  int i = 1;
  dp[0] = 1;
  for(; i <= cnt && prime[i] <= n; ++i) {
    for(int j = 0; j <= n; ++j) {
      if(j >= prime[i]) dp[j] += dp[j-prime[i]];
    }
  }
  cout << dp[n] << endl;
  return 0;
}