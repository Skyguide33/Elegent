//2025/7/31
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
int cnt[500005];

ll f(ll P) {
  vector<ll> a;
  for(int i = 1; i <= P; ++i) a.push_back(i);
  bool ctn = 1;
  vector<ll> num;
  ll res, maxn;
  while(ctn) {
    res = 0, maxn = 0;
    //cout << "next_permutation:";
    for(ll& x: a) {
      //cout << x << ' ';
      if(x > maxn) {
        maxn = x;
        ++res;
      }
    }
    //cout << endl;
    num.push_back(res);
    ctn = next_permutation(a.begin(), a.end());
  }
  ll ans = 0;
  for(ll& x: num) {
    ans = (ans+x*x*x)%MOD;
    ++cnt[x];
  }
  for(int i = 1; i <= P; ++i) {
    if(cnt[i]) {
      cout << i << ": " << cnt[i] << endl; 
    }
  }
  cout << endl;
  return ans;
}


void solve() {
  int P; cin >> P;
  cout << f(P) << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}