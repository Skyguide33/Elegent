//2025/11/22 题解
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 8005

ll a[N];
int c[N], b1[N], b2[N];
bool vis[N];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i], c[i] = i;
  sort(c+1, c+n+1, [&](int x, int y) -> bool {
    if(a[x] == a[y]) return x < y;
    return a[x] < a[y];
  });
  int m; cin >> m;
  while(m--) {
    int l, r, k; cin >> l >> r >> k;
    int t1 = 0, t2 = 0;
    // 分离区间a至b1和b2
    for(int i = 1; i <= n; ++i) {
      if(c[i] < l || c[i] > r) b1[++t1] = c[i];
      else b2[++t2] = c[i];
    }
    ll mx = 0, len = t2; // len存储修改的区间长度
    for(int i = 1; i <= t2; ++i) {
      ll dt = a[b2[i+1]]-a[b2[i]]; // dt记录修改区间内顺序相邻的两个数值的差
      if(dt*i >= k || i == t2) {
        mx = a[b2[i]]+k/i;
        k %= i;
        len = i;
        break;
      }
      k -= dt*i; 
    }
    for(int i = 1; i <= len; ++i) a[b2[i]] = mx, vis[b2[i]] = 1;
    int tp = 0;
    for(int i = 1; k; ++i) {
      if(vis[i]) {
        ++a[i]; --k; tp = i;
      }
    }
    // 对b2数组重排序
    int ft = 0;
    for(int i = tp+1; i <= n; ++i) {
      if(vis[i]) b2[++ft] = i, vis[i] = 0;
    }
    for(int i = 1; i <= tp; ++i) {
      if(vis[i]) b2[++ft] = i, vis[i] = 0;
    }
    int fl = 0, fr = 0;
    for(int i = 1; i <= n; ++i) {
      if(fl >= t1) c[i] = b2[++fr];
      else if(fr >= t2) c[i] = b1[++fl];
      else if(a[b1[fl+1]] < a[b2[fr+1]] || (a[b1[fl+1]] == a[b2[fr+1]] && b1[fl+1] < b2[fr+1])) c[i] = b1[++fl];
      else c[i] = b2[++fr];
    }
  }
  for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
  cout << endl;
  return 0;
}