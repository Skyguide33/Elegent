//2025/11/6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005], s[100005], cnt_b[100005][30][2], s_n[100005];
// cnt_b[i][j] 第i个集合中第j位为1的元素的个数, s_n[i] 集合i的元素个数
 
int find_set(int x) {
  return (x == s[x]? x: s[x] = find_set(s[x]));
}
 
int pw[30];
 
int main() {
  cin.tie(0) -> sync_with_stdio(0);
  pw[0] = 1;
  for(int i = 1; i < 30; ++i) pw[i] = pw[i-1]<<1;
  int n, m, u, v, w; cin >> n >> m;
  for(int i = 1; i <= n; ++i) s[i] = i;
  memset(a, -1, sizeof(a));
  while(m--) {
    cin >> u >> v >> w;
    int x = find_set(u), y = find_set(v);
    if(x != y) s[x] = y;
    if(a[u] == -1 && a[v] == -1) {
      a[u] = 0; a[v] = w;
    } else if(a[u] == -1) {
      a[u] = a[v]^w;
    } else if(a[v] == -1) {
      a[v] = a[u]^w;
    } else if((a[u]^a[v]) != w) {
      cout << -1 << endl;
      return 0;
    }
  }
  ll ans = 0;
  for(int i = 1; i <= n; ++i) {
    if(a[i] >= 0) {
      int tt = a[i];
      for(int j = 0; j < 30; ++j) {
        if(tt&1) ++cnt_b[find_set(i)][j][1];
        else ++cnt_b[find_set(i)][j][0];
        tt >>= 1;
      }
    }
  }
  for(int i = 1; i <= n; ++i) {
    if(cnt_b[i][0][0] || cnt_b[i][0][1]) {
      for(int j = 0; j < 30; ++j) {
        // cout << "j=" << j << ' ' << cnt_b[i][j][0] << ' ' <<  cnt_b[i][j][1] << endl;
        ans += 1ll*min(cnt_b[i][j][0], cnt_b[i][j][1])*pw[j];
      }
    }
    
  }
  cout << ans << endl;
  return 0;
}