//2025/7/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6+5;

int a[N], n, m;

bool check(int mid) {
  int num = 0;
  for(int i = 1; i <= n; ++i) {
    num += max(a[i]-mid, 0);
    if(num >= m) return 1;
  }
  return 0;
}

void solve() {
  cin >> n >> m;
  int l = -1, r = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    r = max(r, a[i]);
  }
  while(l < r) {
    int mid = l + (r-l+1) / 2;
    if(check(mid)) l = mid;
    else r = mid - 1;
  }
  cout << l << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; //cin >> T;
  while(T--) solve();
  return 0;
}