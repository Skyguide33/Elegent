//2026/3/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 11000005

char s[N], s2[N<<1];
int p[N<<1], n2;

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
  cin >> s;
  change();
  manacher();
  int ans = 0;
  for(int i = 1; i < n2; ++i) ans = max(ans, p[i]);
  cout << ans-1 << endl;
  return 0;
}