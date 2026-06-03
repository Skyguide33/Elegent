//2025/9/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll vis[100005], prime[100005], phi[100005], cnt;

void get_phi(ll n) {
  phi[1] = 1;
  for(int i = 2; i <= n; ++i) {
    if(!vis[i]) {
      vis[i] = i;
      prime[cnt++] = i;
      phi[i] = i-1;
    }
    for(int j = 0; j < cnt; ++j) {
      if(i*prime[j] > n) break;
      vis[i*prime[j]] = prime[j];
      if(i%prime[j] == 0) {
        phi[i*prime[j]] = phi[i]*prime[j];
        break;
      }
      phi[i*prime[j]] = phi[i]*phi[prime[j]];
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  get_phi(n);
  ll ans = 0;
  for(int i = 1; i <= n; ++i) phi[i] += phi[i-1];
  for(int i = 1; i <= n; ++i) ans += i*(2*phi[n/i]-1);
  cout << ans << endl;
  return 0;
}