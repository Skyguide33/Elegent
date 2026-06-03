//2025/8/27
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, q; cin >> n >> q;
  string s; cin >> s;
  while(q--) {
    string t; cin >> t;
    int a; cin >> a;
    int lent = t.length();
    ll cnt = 0, ans = 0;
    for(int x = 0; x < lent; ++x) {
      if(a+x-1 >= n) break;
      if(s[a+x-1] == t[x]) ++cnt;
      else {
        ans += cnt*(cnt+1)/2;
        cnt = 0;
      }
    }
    cout << ans+cnt*(cnt+1)/2 << endl;
  }
  return 0;
}