//2026/5/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool is_prime(int x) {
  if(x == 1) return 0;
  for(int i = 2; i*i <= x; ++i) {
    if(x%i == 0) return 0;
  }
  return 1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int num = 0;
  set<int> st;
  for(ll i = 1; i <= 100000000; ++i) {
    bool flag = 1;
    ll cnt = 0, tt = i, pre = -1, now = -1;
    vector<int> tmp(10);
    while(tt) {
      now = tt%10;
      if(now == pre) {
        flag = 0;
        break;
      }
      cnt += now;
      ++tmp[now];
      pre = now;
      tt /= 10;
    }
    if(flag && is_prime(cnt)) {
      ++num;
      int tt = 0;
      for(int i = 0; i < 10; ++i) tt = tt*10+tmp[i];
      st.insert(tt);
    }
  }
  cout << num << endl;
  for(int x: st) cout << x << endl;
  cout << st.size() << endl;
  return 0;
}