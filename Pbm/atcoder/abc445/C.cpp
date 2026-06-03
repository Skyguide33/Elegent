//2026/2/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int s[500005], a[500005];

int find_set(int x) {
  return (x == s[x]? x: s[x] = find_set(s[x]));
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i], s[i] = i;
  for(int i = 1; i <= n; ++i) {
    int rx = find_set(i), ry = find_set(a[i]);
    s[rx] = ry;
  }
  for(int i = 1; i <= n; ++i) cout << find_set(i) << ' ';
  cout << endl;
  return 0;
}