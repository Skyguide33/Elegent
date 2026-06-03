//2026/2/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int blkx[1000005], blky[1000005];
int blux[1000005], bluy[1000005], t[1000005];
int n, m, a, b; 

bool check(int k) {
  vector<vector<int>> e(n+1, vector<int>(m+1));
  for(int i = 1; i <= n; ++i) {
    
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m >> a >> b;
  int l = 0, r = max(n, m);
  for(int i = 1; i <= a; ++i) cin >> blkx[i] >> blky[i];
  for(int i = 1; i <= b; ++i) {
    cin >> blux[i] >> bluy[i] >> t[i];
    l = max(l, t[i]+1); r = max(r, t[i]+1);
  }
  while(l < r) {
    int mid = (l+r)>>1;
    if(check(mid)) r = mid;
    else l = mid+1;
  }
  cout << l << endl;
  return 0;
}