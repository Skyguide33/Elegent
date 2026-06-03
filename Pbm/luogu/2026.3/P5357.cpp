//2025/3/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 200005

int tr[N][26], fail[N], cnt, ans[N], tme[N], indge[N];
char s[2000005];
vector<int> id[N];

inline void Insert(int idx) { 
  int now = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    if(!tr[now][ch]) tr[now][ch] = ++cnt;
    now = tr[now][ch];
  }
  id[now].push_back(idx);
}

inline void getFail() {
  queue<int> q;
  for(int i = 0; i < 26; ++i) 
    if(tr[0][i]) q.push(tr[0][i]);
  while(!q.empty()) {
    int now = q.front(); q.pop();
    for(int i = 0; i < 26; ++i) {
      if(tr[now][i]) {
        int v = tr[fail[now]][i];
        fail[tr[now][i]] = v;
        ++indge[v];
        q.push(tr[now][i]);
      } else tr[now][i] = tr[fail[now]][i];
    }
  }
}

inline void query() {
  int now = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    now = tr[now][ch];
    ++tme[now];
  }
}

inline void topo() {
  queue<int> q;
  for(int i = 1; i <= cnt; ++i)
    if(!indge[i]) q.push(i);
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int x: id[u]) ans[x] += tme[u];
    int v = fail[u];
    tme[v] += tme[u];
    if(!--indge[v]) q.push(v);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) Insert((cin >> s, i));
  getFail();
  cin >> s;
  query();
  topo();
  for(int i = 1; i <= n; ++i) cout << ans[i] << endl;
  return 0;
}