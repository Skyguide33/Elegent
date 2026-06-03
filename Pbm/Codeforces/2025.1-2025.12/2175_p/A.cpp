//2025/12/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'


int a[105], c[1005];

void solve() {
  for(int i = 1; i <= 1000; ++i) c[i] = 0;
  int n; cin >> n;
  int num = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    if(!c[a[i]]++) ++num;
  }
  for(int i = n+1;; ++i) {
    if(!c[num]++) ++num;
    else break;
  }
  cout << num << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}