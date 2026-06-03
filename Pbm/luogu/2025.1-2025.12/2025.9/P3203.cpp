//2025/9/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'

int a[200005], step[200005], to[200005], pos[200005], st[450], ed[450], block, t, n;

void init() {
  block = sqrt(n);
  t = n/block;
  if(n%block) ++t;
  for(int i = 0; i < n; ++i) {
    pos[i] = i/block+1;
  }
  for(int i = 1; i <= t; ++i) {
    st[i] = (i-1)*block;
    ed[i] = i*block-1;
  }
  for(int i = n-1; i >= 0; --i) {
    int nt = i+a[i], cnt = 1;
    while(nt < n && pos[nt] == pos[i]) {
      nt += a[nt]; ++cnt; 
    }
    to[i] = nt;
    step[i] = cnt;
  }
}

void change(int j, int k) {
  int p = pos[j];
  a[j] = k;
  for(int i = ed[p]; i >= st[p]; --i) {
    int nt = i+a[i];
    if(nt <= ed[p]) {
      step[i] = step[nt]+1;
      to[i] = to[nt];
    } else {
      step[i] = 1;
      to[i] = nt;
    }
  }
}

int query(int j) {
  int res = 0;
  while(j < n) {
    res += step[j];
    j = to[j];
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> a[i];
  init();
  int m; cin >> m;
  while(m--) {
    int i, j; cin >> i >> j;
    if(i == 1) {
      cout << query(j) << endl;
    } else {
      int k; cin >> k;
      change(j, k);
    }
  }
  return 0;
}