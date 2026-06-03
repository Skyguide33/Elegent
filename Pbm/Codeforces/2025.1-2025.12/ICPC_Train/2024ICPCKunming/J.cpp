//2025/7/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int is_sorted(int* a, int len) {
  int disorder = 0;
  for(int i = 0; i < len; ++i) {
    if(a[i] != i+1) {
      if(disorder) {
        if(disorder == a[i]) continue;
        else return 0;
      }
    }
  }
  if(disorder) return 2;
  return 1;
}

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  if(s == "Alice") {

  } else {

  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}