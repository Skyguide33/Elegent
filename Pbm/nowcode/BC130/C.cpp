//2026/3/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005], b[100005], c[100005], mx[100005], tail, mxv[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    ++c[a[i]]; ++c[b[i]];
  }
  int maxn = -1;
  for(int i = 1; i <= m; ++i) {
    if(c[i] > maxn) {
      maxn = c[i];
      mx[tail=1] = i;
    } else if(c[i] == maxn) mx[++tail] = i;
  }
  if(tail == 1) {
    int maxm = mx[1], cmaxn = -1;
    tail = 0;
    for(int i = 1; i <= m; ++i) {
      if(c[i] == maxn) continue;
      if(c[i] > cmaxn) {
        cmaxn = c[i];
        mx[tail=1] = i;
      } else if(c[i] == cmaxn) mx[++tail] = i;
    }
    for(int i = 1; i <= n; ++i) {
      if(a[i] == maxm) --c[b[i]];
      else if(b[i] == maxm) --c[a[i]];
    }
    int cmx = 0;
    cmaxn = -1;
    for(int i = 1; i <= tail; ++i) {
      if(c[mx[i]] > cmaxn) {
        cmaxn = c[mx[i]];
        cmx = mx[i];
      }
    } 
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
      if(a[i] == maxm || b[i] == maxm) ++ans;
      else if(a[i] == cmx || b[i] == cmx) ++ans;
    }
    cout << ans << endl;
  } else {
    set<int> st;
    for(int i = 1; i <= tail; ++i) st.insert(mx[i]);
    for(int i = 1; i <= n; ++i) {
      if(st.contains(a[i]) && st.contains(b[i])) continue;
      if(st.contains(a[i])) ++mxv[a[i]];
      else if(st.contains(b[i])) ++mxv[b[i]];
    }
    int maxm1 = 0;
    maxn = -1;
    for(int i = 1; i <= tail; ++i) {
      if(mxv[mx[i]] > maxn) {
        maxn = mxv[mx[i]];
        maxm1 = mx[i];
      }
    }
    for(int i = 1; i <= n; ++i) {
      if(a[i] == maxm1) --c[b[i]];
      else if(b[i] == maxm1) --c[a[i]];
    }
    int maxm2 = 0;
    maxn = -1;
    for(int i = 1; i <= tail; ++i) {
      if(mx[i] == maxm1) continue;
      if(c[mx[i]] > maxn) {
        maxn = c[mx[i]];
        maxm2 = mx[i];
      }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
      if(a[i] == maxm1 || b[i] == maxm1) ++ans;
      else if(a[i] == maxm2 || b[i] == maxm2) ++ans;
    }
    cout << ans << endl;
  }
  return 0;
}