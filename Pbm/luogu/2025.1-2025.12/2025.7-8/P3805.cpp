//2025/8/27
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1.1e7+2;

int p[N<<1], n;
char a[N], s[N<<1];

void change() {
  n = strlen(a);
  int k = 0; s[k++] = '$'; s[k++] = '#';
  for(int i = 0; i < n; ++i) {
    s[k++] = a[i]; s[k++] = '#';
  }
  s[k++] = '&';
  n = k;
}

void manacher() {
  int R = 0, C;
  for(int i = 1; i < n-1; ++i) {
    if(i < R) p[i] = min(p[(C<<1)-i], C+p[C]-i);
    else p[i] = 1;
    while(s[i+p[i]] == s[i-p[i]]) ++p[i];
    if(p[i]+i > R) {
      R = p[i]+i;
      C = i;
    } 
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> a; change();
  manacher();
  int ans = 1;
  for(int i = 0; i < n-1; ++i) {
    ans = max(ans, p[i]);
  }
  cout << ans-1 << endl;
  return 0;
}