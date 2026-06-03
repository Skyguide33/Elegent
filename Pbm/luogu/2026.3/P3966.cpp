//2025/3/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 1000005

struct Node {
  int son[27], fail;
  vector<int> id;
} trie[N];

int cnt, ans[N], tme[N], indge[N];

inline void Insert(const string &s, int idx) { 
  int now = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    if(!trie[now].son[ch]) trie[now].son[ch] = ++cnt;
    now = trie[now].son[ch];
  }
  trie[now].id.push_back(idx);
}

inline void getFail() {
  queue<int> q;
  for(int i = 0; i < 26; ++i) 
    if(trie[0].son[i]) q.push(trie[0].son[i]);
  while(!q.empty()) {
    int now = q.front(); q.pop();
    for(int i = 0; i < 26; ++i) {
      if(trie[now].son[i]) {
        int v = trie[trie[now].fail].son[i];
        trie[trie[now].son[i]].fail = v; 
        ++indge[v];
        q.push(trie[now].son[i]);
      } else trie[now].son[i] = trie[trie[now].fail].son[i];
    }
  }
}

inline void query(const string &s) {
  int now = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    now = trie[now].son[ch];
    ++tme[now];
  }
}

inline void topo() {
  queue<int> q;
  for(int i = 1; i <= cnt; ++i)
    if(!indge[i]) q.push(i);
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int x: trie[u].id) ans[x] += tme[u];
    int v = trie[u].fail;
    tme[v] += tme[u];
    if(!--indge[v]) q.push(v);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  string t, s;
  for(int i = 1; i <= n; ++i) {
    Insert((cin >> t, t), i);
    s += '{'+t;
  }
  getFail();
  query(s);
  topo();
  for(int i = 1; i <= n; ++i) cout << ans[i] << endl;
  return 0;
}