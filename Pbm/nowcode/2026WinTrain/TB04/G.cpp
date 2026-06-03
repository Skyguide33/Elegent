//2026/2/10
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef __int128_t lll;

int a[10], maxg;
int b[2][10], idx;

ll make_num(int *arr=a) {
  ll res = 0;
  for(int i = 1; i <= 9; ++i) {
    int cnt = arr[i];
    while(cnt--) {
      res = res*10+i;
    }
  }
  return res;
}

ll f(ll x) {
  ll res = 1;
  while(x) {
    res *= x%10;
    x /= 10;
  }
  return res;
}

int g(ll x) {
  int res = 0;
  ll tt = f(x);
  while(tt != x) {
    x = tt;
    tt = f(x);
    ++res;
  }
  return res;
}

void dfs(int num, int cnt) {
  // cout << "num=" << num << ", cnt=" << cnt << endl;
  if(num == 9) {
    ll digit= make_num();
    int gg = g(digit);
    // cout << gg << endl;
    if(gg > maxg) {
      idx = 0;
      maxg = gg;
      for(int i = 1; i <= 9; ++i) b[idx][i] = a[i];
      ++idx;
    } else if(gg == maxg && idx < 2) {
      for(int i = 1; i <= 9; ++i) b[idx][i] = a[i];
      ++idx;
    }
    return;
  }
  int now = num+1;
  for(int i = 0; i <= 18-cnt; ++i) {
    a[now] = i;
    dfs(now, cnt+i);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  // dfs(0, 0);
  // cout << make_num(b[0]) << ' ' << g(make_num(b[0])) << endl;
  // cout << make_num(b[1]) << ' ' << g(make_num(b[1])) << endl;
  cout << "66667777799999999 666677777788888" << endl;
  return 0;
}