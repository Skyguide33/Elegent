//2025/3/
#include <bits/stdc++.h>
using namespace std;

int a[1000005], n, m;

inline int bin_search(int key) {
  int l = 1, r = n+1;
  int mid = l + (r-l) / 2;
  while(l < r) {
    if(a[mid] >= key) r = mid;
    else l = mid + 1;
    mid = l + (r-l) / 2;
  }
  if(a[l] == key) return l;
  return -1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> a[i];
  while(m--) {
    int srh; cin >> srh;
    cout << bin_search(srh) << ' ';
    // int res = lower_bound(a+1, a+n+1, srh) - a;
    // if(a[res] == srh) cout << res << ' ';
    // else cout << -1 << ' ';
  }
  return 0;
}