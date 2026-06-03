//2025/7/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

int a[N], n, k;

bool check(int mid) {
  int num = 0;
  for(int i = 1; i <= n; ++i) {
    num += a[i]/mid;
    if(num >= k) return 1;
  }
  return 0;
}

void solve() {
  cin >> n >> k;
  int l = 0, r = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    r = max(r, a[i]);
  }
  while(l < r) {
    int mid = l + (r-l+1) / 2;
    if(check(mid)) l = mid;
    else r = mid-1;
  }
  cout << r << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; //cin >> T;
  while(T--) solve();
  return 0;
}