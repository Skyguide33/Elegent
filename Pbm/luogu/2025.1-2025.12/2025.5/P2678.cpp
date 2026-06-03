//2025/5/16
#include <bits/stdc++.h>
using namespace std;

int L, n, m, d[50005];

bool check(int mid){
  int rest = m, l = 0;
  bool flag = 0;
  for(int r = 1; r <= n; ++r) {
    if(d[r]-d[l] < mid) {
      if(rest == 0) return 0;
      else {
        --rest;
        if(r == n) flag = 1;
      }
    } else l = r;
  }
  if(rest == 0 && !flag && L-d[n] < mid) return 0;
  else return 1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> L >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> d[i]; 
  int l = 1, r = L;
  while(l < r) {
    // cout << "l=" << l << ", r=" << r << endl;
    int mid = l + (r-l+1)/2;
    if(check(mid)) l = mid;
    else r = mid-1;
  }
  cout << l << endl;
  return 0;
}