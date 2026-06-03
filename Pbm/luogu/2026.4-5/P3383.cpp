//2026/5/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int prime[100000005], vis[100000005], cnt;

void eular_sieve(int n) {
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
  int n, q; cin >> n >> q;
  eular_sieve(n);
  while(q--) {
    int idx; cin >> idx;
    cout << prime[idx] << endl;
  }
  return 0;
}