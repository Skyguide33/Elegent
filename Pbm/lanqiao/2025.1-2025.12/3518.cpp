//2025/5/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct event{ ll a, b, c; } e[100005];

bool cmp1(event x, event y) { 
  return (x.a-x.b-x.c) > (y.a-y.b-y.c);
}
bool cmp2(event x, event y) { 
  return (x.b-x.a-x.c) > (y.b-y.a-y.c);
}
bool cmp3(event x, event y) { 
  return (x.c-x.a-x.b) > (y.c-y.a-y.b);
}

ll max_e[4], res;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n; cin >> n;
  for(ll i = 1; i <= n; ++i) cin >> e[i].a;
  for(ll i = 1; i <= n; ++i) cin >> e[i].b;
  for(ll i = 1; i <= n; ++i) cin >> e[i].c;
  sort(e+1, e+n+1, cmp1);
  ll a = e[1].a, other = e[1].b + e[1].c;
  for(ll i = 2; i <= n; ++i) {
    if(a > other) {
      ++max_e[1];
      a += e[i].a;
      other += e[i].b + e[i].c;
    } else break;
  }
  sort(e+1, e+n+1, cmp2);
  ll b = e[1].b; other = e[1].a + e[1].c;
  for(ll i = 2; i <= n; ++i) {
    if(b > other) {
      ++max_e[2];
      b += e[i].b;
      other += e[i].a + e[i].c;
    } else break;
  }
  sort(e+1, e+n+1, cmp3);
  ll c = e[1].c; other = e[1].a + e[1].b;
  for(ll i = 2; i <= n; ++i) {
    if(c > other) {
      ++max_e[3];
      c += e[i].c;
      other += e[i].a + e[i].b;
    } else break;
  }
  res = max(max_e[1], max(max_e[2], max_e[3]));
  if(res == 0) cout << -1 << endl;
  else cout << res << endl;
  return 0;
}