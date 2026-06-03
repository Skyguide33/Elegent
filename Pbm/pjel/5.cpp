//2025/11/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve1() {
  for(ll i = 2521;; ++i) {
    bool flag = 1;
    for(int j = 2; j <= 20; ++j) {
      if(i%j != 0) {
        flag = 0; break;
      }
    }
    if(flag) {
      cout << i << endl; 
      break;
    }
  }
}

int fast_power(int b, int p) {
  int res = 1;
  while(p) {
    if(p&1) res *= b;
    b *= b;
    p >>= 1;
  }
  return res;
}

int c[21], maxc[21];

void factor(int n) {
  for(int i = 1; i <= n; ++i) c[i] = 0;
  int tt = sqrt(n);
  for(int i = 2; i <= tt; ++i) {
    if(n%i == 0) {
      while(n%i == 0) n /= i, ++c[i];
    }
  }
  if(n > 1) c[n] = 1;
}

void solve2() {
  for(int i = 2; i <= 20; ++i) {
    factor(i); 
    for(int j = 2; j <= i; ++j) maxc[j] = max(maxc[j], c[j]);
  }
  ll ans = 1;
  for(int i = 2; i <= 20; ++i) {
    ans *= fast_power(i, maxc[i]);
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  solve2();
  return 0;
}

// 232792560