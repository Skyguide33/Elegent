//2026/4/30
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005], vis[100005];

void solve() {
  int n; cin >> n;
  int pos1 = -1, pos2 = -1;
  for(int i = 1; i <= 2*n; ++i){
    cin >> a[i];
    if(a[i] == 0) {
      if(pos1 == -1) pos1 = i;
      else pos2 = i;
    }
  }
  // cout << "p1 p2 " << pos1 << ' ' << pos2 << endl;

  fill(vis, vis+n, 0);
  for(int i = 0; i <= min(pos1-1, 2*n-pos1); ++i) {
    if(a[pos1-i] == a[pos1+i]) vis[a[pos1-i]] = 1;
    else break;
  }
  int ans1 = 0;
  for(int i = 0; i < n; ++i) {
    if(vis[i]) ++ans1;
    else break;
  }
  fill(vis, vis+n, 0);
  for(int i = 0; i <= min(pos2-1, 2*n-pos2); ++i) {
    // cout << "p-+ " << pos2-i << ' ' << pos2+i << endl;
    if(a[pos2-i] == a[pos2+i]) vis[a[pos2-i]] = 1;
    else break;
  }
  int ans2 = 0;
  for(int i = 0; i < n; ++i) {
    if(vis[i]) ++ans2;
    else break;
  }
  fill(vis, vis+n, 0);
  if((pos2-pos1)%2 == 0) {
    int pos = (pos1+pos2)/2;
    // cout << "pos1=" << pos << endl;
    for(int i = 0; i <= min(pos-1, 2*n-pos); ++i) {
      if(a[pos-i] == a[pos+i]) vis[a[pos-i]] = 1;
      else break;
    }
  } else {
    int pos = (pos1+pos2+1)/2;
    // cout << "pos2=" << pos << endl;
    for(int i = 0; i <= min(pos-2, 2*n-pos); ++i) {
      if(a[pos-i-1] == a[pos+i]) vis[a[pos+i]] = 1;
      else break;
    }
  }
  int ans3 = 0;
  for(int i = 0; i < n; ++i) {
    if(vis[i]) ++ans3;
    else break;
  }
  // cout << ans1 << ' ' << ans2 << ' ' << ans3 << endl;
  cout << max({ans1, ans2, ans3}) << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}