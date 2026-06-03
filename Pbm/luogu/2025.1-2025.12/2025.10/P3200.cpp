//2025/9/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'
#define tt(x) cout << "tt" << x << endl;
#define N 2000005

int prime[N], cnt[N], mp[N];
bool is_prime[N];

// 带模快速幂
ll fast_power(ll b, ll p, ll mod) {
  ll res = 1;
  while(p) {
    if(p&1) res = res*b%mod;
    b = (b*b)%mod;
    p >>= 1; 
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, p, pn = 0; cin >> n >> p;
  int t = n*2;
  for(int i = 2; i <= t; ++i) {
    if(!mp[i]) {
      prime[pn++] = i;
      mp[i] = i;
    }
    for(int j = 0; j < pn; ++j) {
      if(i*prime[j] > t) break;
      mp[i*prime[j]] = prime[j];
      if(i%prime[j] == 0) break;
    }
  }
  for(int i = 2; i <= n; ++i) cnt[i] = -1;
  for(int i = n+2; i <= t; ++i) cnt[i] = 1;
  for(int i = t; i > 1; --i) {
    if(mp[i] < i) {
      cnt[mp[i]] += cnt[i];
      cnt[i/mp[i]] += cnt[i];
    }
  }
  int ans = 1;
  for(int i = 2; i <= t; ++i) {
    if(mp[i] == i) {
      ans = (ll)ans*fast_power(i, cnt[i], p)%p;
    }
  }
  cout << ans << endl;
  return 0;
}