//2026/2/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[262143];

void solve1() {
  int n; cin >> n;
  int len = 1<<n;
  int bt = 0;
  for(int i = 1; i < len; ++i) {
    a[i] |= a[i-1];
    if(i == (1<<bt)) {
      a[i] |= (1<<bt);
      ++bt;
    } else  a[i] ^= (a[i-(1<<(bt-1))]^a[i-(1<<(bt-1))-1]);
  }
  for(int i = 0; i < len; ++i) cout << a[i] << ' ';
  cout << endl;
}

void solve2() {
  int n; cin >> n;
  for(int i = 0; i < 1<<n; ++i) cout << (i^(i>>1)) << ' ';
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  solve2();
  return 0;
}