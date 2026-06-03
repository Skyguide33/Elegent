//2026/3/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int z[20000005], p[20000005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string a, b; cin >> a >> b;
  int alen = a.length(), blen = b.length();
  z[0] = blen;
  for(int i = 1, l = -1, r = -1; i < blen; ++i) {
    if(i <= r) z[i] = min(z[i-l], r-i+1);
    while(b[z[i]] == b[i+z[i]]) ++z[i];
    if(i+z[i]-1 > r) l = i, r = i+z[i]-1;
  }
  ll ans1 = 0, ans2 = 0;
  for(int i = 0; i < blen; ++i) ans1 ^= 1ll*(i+1)*(z[i]+1);
  cout << ans1 << endl;
  for(int i = 0, l = -1, r = -1; i < alen; ++i) {
    if(i <= r) p[i] = min(z[i-l], r-i+1);
    while(p[i] < blen && i+p[i] < alen && 
      b[p[i]] == a[i+p[i]]) ++p[i];
    if(i+p[i]-1 > r) l = i, r = i+p[i]-1;
  }
  for(int i = 0; i < alen; ++i) ans2 ^= 1ll*(i+1)*(p[i]+1);
  cout << ans2 << endl;
  return 0;
}