//2026/3/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

tuple<int, int, int> a[505];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    auto &[x, y, id] = a[i];
    cin >> x >> y; id = i;
  }
  sort(a+1, a+n+1);
  int k = 3;
  cout << k << ' ' << n-k << endl;
  for(int i = 1; i <= k; ++i) {
    auto &[x, y, id] = a[i];
    cout << id << ' ';
  }
  cout << endl;
  for(int i = k+1; i <= n; ++i) {
    auto &[x, y, id] = a[i];
    cout << id << ' ';
  }
  cout << endl;
  return 0;
}