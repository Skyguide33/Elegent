//2025/11/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int prime[2000005], vis[2000005];

int eular_sieve(int n) {
  int cnt = 0;
  for(int i = 2; i <= n; ++i) {
    if(!vis[i]) {
      prime[cnt++] = i;
      vis[i] = i;
    }
    for(int j = 0; j < cnt; ++j) {
      if(i*prime[j] > n) break;
      vis[i*prime[j]] = prime[j];
      if(i%prime[j] == 0) break;
    }
  }
  return cnt;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n = eular_sieve(2000000);
  ll sum = 0;
  for(int i = 0; i < n; ++i) sum += prime[i];
  cout << sum << endl;
  return 0;
}

// 142913828922