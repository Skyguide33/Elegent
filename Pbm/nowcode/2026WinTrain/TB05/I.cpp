//2026/2/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll n, m, h;
ll a[200005], p[200005], f[200005]; 
  
bool check(int k) {
  for(int i = 1; i <= n; ++i) a[i] = 0;
  for(int i = 1; i <= k; ++i) {
    a[p[i]+1] += -2;
    if(p[i]-f[i] >= 0) a[p[i]-f[i]+1] += 1;
    else {
      ll dep = f[i]-p[i]+1;
      a[1] += dep;
      a[2] -= dep-1;
    }
    if(p[i]+f[i]+1 <= n) a[p[i]+f[i]+1] += 1; 
  }
  for(int i = 2; i <= n; ++i) a[i] += a[i-1];
  for(int i = 2; i <= n; ++i) a[i] += a[i-1];
  for(int i = 1; i <= n; ++i) {
    if(a[i] > h) return 1;
  }
  return 0;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m >> h;
  for(int i = 1; i <= m; ++i) {
    cin >> p[i] >> f[i];
  }
  int l = 1, r = m+1;
  while(l < r) {
    int mid = (l+r)>>1;
    if(check(mid)) r = mid;
    else l = mid+1;
  }
  if(l == m+1) cout << "No" << endl;
  else cout << "Yes" << endl << l << endl;
  // check(m);
  // for(int i = 1; i <= n; ++i) {
  //   cout << a[i] << ' ';
  // }
  // cout << endl;
  return 0;
}