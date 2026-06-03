//2026/3/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005], b[100005], n, m;

bool check(int k) {
  int pos = lower_bound(a+1, a+n+1, k)-a-1;
  int rp = upper_bound(a+1, a+n+1, k)-a-1;
  int rst = m, cnt = 0;
  for(int i = pos+1; i <= n; ++i) {
    int p = a[i]/k;  
    if(rst >= p-1) {
      rst -= p-1;
      cnt += p;
    } else {
      cnt += rst+1+n-i;
      rst = 0;
      break;
    }
  }
  return pos < cnt;
}

void solve() {
  cin >> n >> m;
  
  cout << l << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}