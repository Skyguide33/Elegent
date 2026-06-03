//2025/11/19
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  vector<int> a;
  while(n) {
    a.push_back(n%10);
    n /= 10;
  }
  reverse(a.begin(), a.end());
  int j, k; cin >> j >> k;
  if(j > k) swap(j, k);
  int now = 1;
  while(now < j) next_permutation(a.begin(), a.end()), ++now;
  vector<int> b = a;
  while(now < k) next_permutation(a.begin(), a.end()), ++now;
  vector<int> c = a;
  int x = 0;
  for(int i = 0; i < b.size(); ++i) {
    if(b[i] == c[i]) ++x;
  }
  cout << x << 'A' << b.size()-x << 'B' << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}