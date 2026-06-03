//2025/11/21  
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int maxv[100005][2], h[1000005], v[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, T; cin >> n >> T;
  int maxh = 0;
  for(int i = 1; i <= n; ++i) cin >> h[i], maxh = max(maxh, h[i]);
  for(int i = 1; i <= n; ++i) {
    cin >> v[i];
    if(!maxv[h[i]][0]) maxv[h[i]][0] = v[i];
    else if(!maxv[h[i]][1]) {
      maxv[h[i]][1] = v[i];
      if(maxv[h[i]][1] > maxv[h[i]][0]) swap(maxv[h[i]][0], maxv[h[i]][1]);
    } else if(v[i] > maxv[h[i]][0]) maxv[h[i]][0] = v[i];
    else if(v[i] > maxv[h[i]][1]) maxv[h[i]][1] = v[i];
  }
  for(int i = 1; i <= 100000; ++i) {
    if(maxv[i][0] < maxv[i-1][0]) {
      maxv[i][1] = max(maxv[i][0], maxv[i-1][1]);
      maxv[i][0] = maxv[i-1][0];
    } else if(maxv[i][1] < maxv[i-1][0]) maxv[i][1] = maxv[i-1][0];
  }
  ll ans = 0;
  while(T--) {
    int x; cin >> x;
    ans += maxv[x-1][0]+maxv[x-1][1];
  }
  cout << ans << endl;
  return 0;
}