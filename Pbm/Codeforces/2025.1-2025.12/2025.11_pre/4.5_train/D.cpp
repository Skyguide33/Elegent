//2025/4/5
#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) cin >> a[i*m+j];
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        int srdmax = 0;
        if(i > 0) srdmax = max(srdmax, a[(i-1)*m+j]);
        if(i < n-1) srdmax = max(srdmax, a[(i+1)*m+j]);
        if(j > 0) srdmax = max(srdmax, a[i*m+j-1]);
        if(j < m-1) srdmax = max(srdmax, a[i*m+j+1]);
        if(a[i*m+j] > srdmax) a[i*m+j] = srdmax;
        cout << a[i*m+j] << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}