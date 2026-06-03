//2025/11/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll fa[60];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  fa[1] = 1;
  for(int i = 2; i < 60; ++i) fa[i] = fa[i-1]+fa[i-2];
  int m; cin >> m;
  while(m--) {
    ll a, b, t; cin >> a >> b;
    set<ll> st;
    do {
      st.insert(a);
      t = *(upper_bound(fa, fa+60, a-1)-1);
      a -= t;
    } while(t);
    do {
      if(st.count(b)) {
        cout << b << endl;
        break;
      }
      t = *(upper_bound(fa, fa+60, b-1)-1);
      b -= t;
    } while(t);
  }
  return 0;
}