//2026/6/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, w, nxt; } e[2605];
int head[51], ecnt;

void addedge(int u, int v, int w) {
  e[++ecnt] = {v, w, head[u]};
  head[u] = ecnt;
}

char c[51][51];
int d1[51], d2[51], a[51][51], n;

bool spfa_max() {
  fill(d2+1, d2+n+1, 3);
  vector<int> vis(n+1, 1), cnt(n+1);
  queue<int> q;
  for(int i = 0; i <= n; ++i) q.push(i);
  d2[0] = 0;
  while(!q.empty()) {
    int u = q.front(); q.pop(); vis[u] = 0;
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].v, w = e[i].w;
      if(d2[v] > d2[u]+w) {
        d2[v] = d2[u]+w;
        cnt[v] = cnt[u]+1;
        if(cnt[v] > n) return 0;
        if(!vis[v]) vis[v] = 1, q.push(v);
      }
    }
  }
  return 1;
}

void spfa_min() {
  fill(d1+1, d1+n+1, 1);
  vector<int> vis(n+1, 1);
  queue<int> q;
  for(int i = 0; i <= n; ++i) q.push(i);
  d1[0] = 0;
  while(!q.empty()) {
    int u = q.front(); q.pop(); vis[u] = 0;
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].v, w = e[i].w;
      if(d1[v] < d1[u]+w) {
        d1[v] = d1[u]+w;
        if(!vis[v]) vis[v] = 1, q.push(v);
      }
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int A, B; cin >> n >> A >> B;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) cin >> c[i][j];
  }
  for(int ia = 1; ia <= 3; ++ia) {
    for(int ib = 1; ib <= 3; ++ib) {
      // cout << "A=" << ia << ' ' << "B=" << ib << endl;
      // 最大解
      fill(head, head+n+1, 0);
      ecnt = 0;
      addedge(0, A, ia);
      addedge(A, 0, -ia);
      addedge(0, B, ib);
      addedge(B, 0, -ib);
      for(int i = 1; i <= n; ++i) {
        addedge(0, i, 3);
        addedge(i, 0, -1);
      }
      for(int i = 1; i < n; ++i) {
        for(int j = i+1; j <= n; ++j) {
          if(c[i][j] == '+' || c[j][i] == '-') addedge(i, j, -1);
          else if(c[i][j] == '-' || c[j][i] == '+') addedge(j, i, -1);
          else if(c[i][j] == '=' || c[j][i] == '=') {
            addedge(i, j, 0);
            addedge(j, i, 0);
          }
        }
      }
      if(!spfa_max()) continue;

      // 最小解
      fill(head, head+n+1, 0);
      ecnt = 0;
      addedge(0, A, ia);
      addedge(A, 0, -ia);
      addedge(0, B, ib);
      addedge(B, 0, -ib);
      for(int i = 1; i <= n; ++i) {
        addedge(0, i, 1);
        addedge(i, 0, -3);
      }
      for(int i = 1; i < n; ++i) {
        for(int j = i+1; j <= n; ++j) {
          if(c[i][j] == '+' || c[j][i] == '-') addedge(j, i, 1);
          else if(c[i][j] == '-' || c[j][i] == '+') addedge(i, j, 1);
          else if(c[i][j] == '=' || c[j][i] == '=') {
            addedge(i, j, 0);
            addedge(j, i, 0);
          }
        }
      }
      spfa_min();
      // for(int i = 1; i <= n; ++i) {
      //   cout << format("{}=[{}, {}]", i, d1[i], d2[i]) << endl;
      // }
      int left = ia+ib;
      for(int i = 1; i < n; ++i) {
        if(i == A || i == B) continue;
        for(int j = i+1; j <= n; ++j) {
          if(j == A || j == B || a[i][j] == -1) continue;
          int minr = d1[i]+d1[j], maxr = d2[i]+d2[j];
          if(left > maxr) {
            if(a[i][j] == 0 || a[i][j] == 1) a[i][j] = 1;
            else a[i][j] = -1;
          } else if(left < minr) {
            if(a[i][j] == 0 || a[i][j] == 3) a[i][j] = 3;
            else a[i][j] = -1;
          } else if(left == minr && left == maxr) {
            if(a[i][j] == 0 || a[i][j] == 2) a[i][j] = 2;
            else a[i][j] = -1;
          } else a[i][j] = -1;
        }
      }
    }
  }
  int c1 = 0, c2 = 0, c3 = 0;
  for(int i = 1; i < n; ++i) {
    for(int j = i+1; j <= n; ++j) {
      if(a[i][j] == 1) ++c1;
      else if(a[i][j] == 2) ++c2;
      else if(a[i][j] == 3) ++c3;
    }
  }
  cout << c1 << ' ' << c2 << ' ' << c3 << endl;
  return 0;
}