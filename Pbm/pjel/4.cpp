//2025/11/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool is_palin(int num) {
  vector<int> a;
  while(num) {
    a.push_back(num%10);
    num /= 10;
  }
  int len = a.size();
  for(int i = 0; i < len/2; ++i) {
    if(a[i] != a[len-1-i]) return 0;
  }
  return 1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int ans = 0, tt = 0;
  // int mul1 = 0, mul2 = 0;
  for(int i = 100; i <= 999; ++i) {
    for(int j = i; j <= 999; ++j) {
      tt = i*j;
      if(is_palin(tt) && tt > ans) {
        ans = tt;
        // mul1 = i, mul2 = j;
      }
    }
  }
  // cout << ans << ' ' << mul1 <<' ' << mul2 << endl;
  cout << ans << endl;
  return 0;
}

// 906609