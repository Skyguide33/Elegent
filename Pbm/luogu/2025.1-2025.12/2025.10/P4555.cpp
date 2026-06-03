//2025/10/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 100005

char s[N], ss[N<<1];
int n, p[N<<1], l[N<<1], r[N<<1];

void change() {
  int k = 0; ss[k++] = '$', ss[k++] = '#';
  for(int i = 0; i < n; ++i) ss[k++] = s[i], ss[k++] = '#';
  ss[k++] = '&';
  n = k;
}

void Manacher() {
  int R = 0, C;
  for(int i = 1; i < n-1; ++i) {
    if(i < R) p[i] = min(p[(C<<1)-i], R-i);
    else p[i] = 1;
    while(ss[i+p[i]] == ss[i-p[i]]) ++p[i];
    if(i+p[i] > R) {
      R = i+p[i];
      C = i;
    }
    l[i-p[i]+1] = max(l[i-p[i]+1], p[i]-1);
    r[i+p[i]-1] = max(r[i+p[i]-1], p[i]-1);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> s;
  n = strlen(s);
  change(); Manacher();
  for(int i = 1; i < n-1; ++i) l[i] = max(l[i], l[i-2]-2);
  for(int i = n-2; i >= 1; --i) r[i] = max(r[i], r[i+2]-2);
  int ans = 0;
  for(int i = 1; i < n; i += 2) {
    if(l[i] && r[i]) ans = max(ans, l[i]+r[i]);
  }
  cout << ans << endl;
  return 0;
}