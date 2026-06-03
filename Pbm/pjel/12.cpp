//2025/11/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int cnt_factor(int num) {
  int tt = sqrt(num), res = 0;
  for(int i = 1; i < tt; ++i) {
    if(num%i == 0) res += 2;
  }
  if(tt*tt == num) ++res;
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int num = 0;
  for(int i = 1; i <= 20000; ++i) {
    num += i;
    if(cnt_factor(num) > 500) {
      cout << num << endl; break;
    };
  }
  return 0;
}

// 76576500