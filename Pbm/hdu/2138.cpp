//2025/9/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll fast_pow(ll a, ll b, ll m) {
  a %= m; b %= m;
  ll res = 1;
  while(b) {
    if(b&1)  res = (res*a)%m;
    a = a*a%m;
    b >>= 1;
  }
  return res;
}

bool witness(ll a, ll n) {
  ll u = n-1;
  int t = 0;
  while(!u&1) u >>= 1, ++t;
  ll x1, x2;
  x1 = fast_pow(a, u, n);
  for(int i = 1; i <= t; ++i) {
    x2 = fast_pow(x1, 2, n);
    if(x2 == 1 && x1 != 1 && x1 != n-1) return 1;
    x1 = x2;
  }
  if(x1 != 1) return 1;
  return 0;
}

bool miller_rabin(ll n, int s) {
  if(n == 2) return 1;
  else if(n%2 == 0 || n < 2) return 0;
  for(int i = 0; i < s && i < n; ++i) {
    ll a = rand()%(n-1)+1;
    if(witness(a, n)) return 0;
  }
  return 1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m;
  while(cin >> m) {
    int cnt = 0;
    while(m--) {
      int n; cin >> n;
      int s = 50;
      cnt += miller_rabin(n, s);
    }
    cout << cnt << endl;
  }
  return 0;
}