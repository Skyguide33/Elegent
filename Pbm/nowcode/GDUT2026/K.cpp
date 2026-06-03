//2026/3/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Node { 
  int son[26]; 
  vector<int> q;
} tr[100005]; 
int cnt;

struct Edge { int v, ch, nxt; } e[200005];
int head[100005], ecnt;

void addedge(int u, int v, int ch) {
  e[++ecnt] = {v, ch, head[u]};
  head[u] = ecnt;
}

int pos[100005];

void dfs1(int u) {
  // cout << "u=" << u << endl;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v, ch = e[i].ch;
    if(!tr[pos[u]].son[ch]) tr[pos[u]].son[ch] = ++cnt;
    pos[v] = tr[pos[u]].son[ch];
    tr[pos[v]].q.push_back(v);
    dfs1(v);
  } 
}

void dfs2(int u) {
  auto &q = tr[u].q;
  sort(q.begin(), q.end());
  for(int x: q) cout << x << ' ';
  for(int i = 0; i < 26; ++i) {
    if(tr[u].son[i]) dfs2(tr[u].son[i]);
  }
}

void solve() {
  int n; cin >> n;
  for(int i = 2; i <= n; ++i) {
    int x; cin >> x;
    char ch; cin >> ch;
    addedge(x, i, ch-'a');
  }
  tr[0].q.push_back(1);
  dfs1(1);
  dfs2(0);
  cout << endl;
  // cout << "cnt=" << cnt << ' ' << ecnt << endl;
  for(int i = 0; i <= cnt; ++i) {
    tr[i].q.clear();
    fill(tr[i].son, tr[i].son+26, 0);
  }
  fill(head+1, head+n+1, 0);
  ecnt = cnt = 0;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}