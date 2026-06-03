//2025/9/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 40005;

int vis[N], prime[N], phi[N], sum[N];

ll eular(ll n) {
  ll res = n;
  for(int i = 2; i*i <= n; ++i) {
    if(n%i == 0) {
      res = res/i*(i-1);
      while(n%i == 0) n /= i;
    }
  }
  if(n != 1) res = res/n*(n-1);
  return res;
}

void get_phi(int n) {
  phi[1] = 1;
  int cnt = 0;
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

void solve1() {
  int n; cin >> n;
  int ans = 0;
  if(n > 1) ans += 1;
  for(int i = 1; i < n; ++i) ans += 2*eular(i);
  cout << ans << endl;
}

void solve2() {
  int n; cin >> n;
  if(n == 1) {
    cout << 0 << endl;
    return;
  }
  get_phi(--n);
  sum[1] = 1;
  for(int i = 2; i <= n; ++i) sum[i] = sum[i-1]+phi[i];
  cout << 2*sum[n]+1 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  // solve1();
  solve2();
  return 0;
}