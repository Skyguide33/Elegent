//2026/4/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005], vis[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, tt; cin >> n;
  for(int i = 1; i <= n; ++i) {
    int k; cin >> k;
    if(k <= 1) {
      if(k == 1) cin >> tt;
    } else {
      for(int j = 1; j <= k; ++j) {
        cin >> tt;
        a[tt] = 1;
      }
    }
  }
  int q; cin >> q;
  bool flag = 1;
  while(q--) {
    cin >> tt;
    if(!a[tt] && !vis[tt]) {
      if(!flag) cout << ' ';
      cout << setw(5) << setfill('0') << tt;
      flag = 0;
      vis[tt] = 1;
    } 
  }
  if(flag) cout << "No one is handsome";
  cout << endl;
  return 0;
}
