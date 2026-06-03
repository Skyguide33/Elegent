//2025/9/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005], pos[100005], st[330], ed[330], sum[330], rev[330], block, t;

void init(int n) {
  block = sqrt(n);
  t = n/block;
  // cout << n << ' ' << block << ' ' << t << endl;
  if(n%t) ++t; 
  for(int i = 1; i <= n; ++i) {
    pos[i] = (i-1)/block+1;
  }
  for(int i = 1; i <= t; ++i) {
    st[i] = (i-1)*block+1;
    ed[i] = i*block;
  }
  ed[t] = n;
}

void change(int l, int r) {
  int p = pos[l], q = pos[r];
  if(p == q) {
    if(rev[p]) {
      for(int i = l; i <= r; ++i) {
        a[i] ^= 1;
        sum[p] += (a[i]? -1: 1);
      }
    } else {
      for(int i = l; i <= r; ++i) {
        a[i] ^= 1;
        sum[p] += (a[i]? 1: -1);
      }
    }
  } else {
    for(int i = p+1; i < q; ++i) {
      rev[i] ^= 1;
      sum[i] = block-sum[i];
    }
    if(rev[p]) {
      for(int i = l; i <= ed[p]; ++i) {
        a[i] ^= 1;
        sum[p] += (a[i]? -1: 1);
      }
    } else {
      for(int i = l; i <= ed[p]; ++i) {
        a[i] ^= 1;
        sum[p] += (a[i]? 1: -1);
      }
    }
    if(rev[q]) {
      for(int i = st[q]; i <= r; ++i) {
        a[i] ^= 1;
        sum[q] += (a[i]? -1: 1);
      }
    } else {
      for(int i = st[q]; i <= r; ++i) {
        a[i] ^= 1;
        sum[q] += (a[i]? 1: -1);
      }
    }
  }
}

int query(int l, int r) {
  int p = pos[l], q = pos[r];
  int res = 0;
  if(p == q) {
    if(rev[p]) for(int i = l; i <= r; ++i) res += 1-a[i];
    else for(int i = l; i <= r; ++i) res += a[i];
  } else {
    for(int i = p+1; i < q; ++i) res += sum[i];
    if(rev[p]) {
      for(int i = l; i <= ed[p]; ++i) res += 1-a[i];
    } else {
      for(int i = l; i <= ed[p]; ++i) res += a[i];
    } 
    if(rev[q]) {
      for(int i = st[q]; i <= r; ++i) res += 1-a[i];
    } else {
      for(int i = st[q]; i <= r; ++i) res += a[i];
    } 
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  init(n);
  while(m--) {
    int c, a, b; cin >> c >> a >> b;
    if(c == 0) change(a, b);
    else cout << query(a, b) << endl;
  }
  // for(int i = 1; i <= t; ++i) {
  //   cout << st[i] << ' ' << ed[i] << endl;
  // }
  return 0;
}