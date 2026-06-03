//2025/7/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool ok[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n, q; cin >> n >> q;
  string s; cin >> s;
  while(q--) {
    string t; ll a;  cin >> t >> a;
    ll lent = t.length();
    for(ll x = 0; x < lent; ++x) {
      if(s[a+x-1] == t[x]) ok[x] = 1;
      else ok[x] = 0;
    }
    ll ans = 0, cnt = 0;
    for(ll i = 0; i < lent; ++i) {
      if(ok[i] == 1) {
        ++cnt;
      } else {
        ans += (cnt+1)*cnt/2;
        cnt = 0;
      }
    }
    if(cnt) ans += (cnt+1)*cnt/2;
    cout << ans << endl;
  }
  return 0;
}