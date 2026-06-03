//2026/3/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 1000000000000000000ll

ll a[3][10005][26], sum[105][26], len[105], tail = 2;

ll query(int k, ll r, int c) {
  if(r == 0) return 0;
  if(k <= 2) return a[k][r][c];
  if(r <= len[k-1]) return query(k-1, r, c);
  return sum[k-1][c]+query(k-2, r-len[k-1], c);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string x, y; cin >> x >> y;
  len[1] = x.length(), len[2] = y.length();
  for(int i = 1; i <= len[1]; ++i) {
    for(int j = 0; j < 26; ++j) a[1][i][j] = a[1][i-1][j];
    ++a[1][i][x[i-1]-'a'];
  }
  for(int i = 0; i < 26; ++i) sum[1][i] = a[1][len[1]][i];
  for(int i = 1; i <= len[2]; ++i) {
    for(int j = 0; j < 26; ++j) a[2][i][j] = a[2][i-1][j];
    ++a[2][i][y[i-1]-'a'];
  }
  for(int i = 0; i < 26; ++i) sum[2][i] = a[2][len[2]][i];
  while(len[tail] <= N) {
    ++tail;
    len[tail] = len[tail-1]+len[tail-2];
    for(int i = 0; i < 26; ++i) {
      sum[tail][i] = sum[tail-1][i]+sum[tail-2][i];
    }
  }
  int q; cin >> q;
  while(q--) {
    ll l, r; cin >> l >> r;
    char c; cin >> c;
    cout << query(tail, r, c-'a')-query(tail, l-1, c-'a') << endl;
  }
  return 0;
}