//2025/8/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll MOD = 19930726;

char a[1000005], s[2000005];
int n, p[2000005];

void change() {
  int k = 0; s[k++] = '$', s[k++] = '#';
  for(int i = 0; i < n; ++i) {
    s[k++] = a[i]; s[k++] = '#';
  }
  s[k++] = '&';
  n = k;
}

void manacher() {
  int R = 0, C;
  for(int i = 1; i < n-1; ++i) {
    p[i] = (i < R? min(p[(C<<1)-i], p[C]+C-i): 1);
    while(s[i-p[i]] == s[i+p[i]]) ++p[i];
    if(p[i]+i > R) {
      R = p[i]+i;
      C = i;
    }
  }
}

ll fp(ll b, int p) {
  ll res = 1;
  while(p) {
    if(p&1) res = (res*b)%MOD;
    b = b*b%MOD;
    p >>= 1;
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll k; cin >> n >> k;
  cin >> a; change();
  manacher();
  map<int, ll> mp;
  for(int i = 1; i < n-1; ++i) {
    --p[i];
    if(p[i]&1) {
      if(!mp.count(p[i])) mp[p[i]] = 1;
      else ++mp[p[i]];
    }
  }
  ll ans = 1;
  auto idx = mp.end(); 
  ll maxn = (--idx)->first;
  while(!mp.empty()) {
    if(k == 0) break;
    ll sub = min(k, mp[maxn]);
    ans = ans*fp(maxn, sub)%MOD;
    k -= sub;
    mp[maxn] -= sub;
    if(maxn > 2) {
      ll t = maxn-2;
      if(!mp.count(t)) mp[t] = sub;
      else mp[t] += sub;
    }
    if(mp[maxn] == 0) {
      mp.erase(maxn);
      idx = mp.end(); 
      maxn = (--idx)->first;
    }
  }
  if(k == 0) cout << ans << endl;
  else cout << -1 << endl;
  return 0;
}