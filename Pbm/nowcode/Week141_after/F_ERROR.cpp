//2026/4/27
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

char s[200005], s2[400005];
int p[400005], n2;
int cnt2[400005], cnt3[400005];

void change() {
  s2[n2++] = '$'; s2[n2++] = '#';
  for(int i = 0; s[i]; ++i) s2[n2++] = s[i], s2[n2++] = '#';
  s2[n2] = '&';
}

void manacher() {
  for(int i = 1, C = 0, R = 0; i < n2; ++i) {
    if(i < R) p[i] = min(R-i, p[(C<<1)-i]);
    else p[i] = 1;
    while(s2[i-p[i]] == s2[i+p[i]]) ++p[i];
    if(i+p[i] > R) R = i+p[i], C = i;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, q; cin >> n >> q;
  cin >> s;
  change();
  manacher();
  cout << s2 << endl;
  for(int i = 1; i < n2; ++i) {
    cnt2[i] = cnt2[i-1];
    cnt3[i] = cnt3[i-1];
    if(i&1 && p[i] >= 3) ++cnt2[i];
    else if(!(i&1) && p[i] >= 4) ++cnt3[i];
  }
  for(int i = 1; i < n2; ++i) cout << p[i] << ' ';
  cout << endl;
  for(int i = 1; i < n2; ++i) cout << cnt2[i] << ' ';
  cout << endl;
  for(int i = 1; i < n2; ++i) cout << cnt3[i] << ' ';
  cout << endl;
  while(q--) {
    int l, r, x; cin >> l >> r >> x;
    if(x == 1) cout << r-l+1 << endl;
    else if(x == 2) {
      cout << cnt2[2*r]-cnt2[2*l] << endl;
    } else cout << cnt3[2*r-2]-cnt3[2*l] << endl;
  }
  return 0;
}