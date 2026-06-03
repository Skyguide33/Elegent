//2025/3/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 10505

struct Node {
  int son[26], fail;
  vector<int> id;
} t[N];
int cnt;

int ans[N], tme[N], indge[N];

inline void Insert(const string &s, int idx) { 
  int now = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    if(!t[now].son[ch]) t[now].son[ch] = ++cnt;
    now = t[now].son[ch];
  }
  t[now].id.push_back(idx);
}


inline void getFail() {
  queue<int> q;
  for(int i = 0; i < 26; ++i) 
    if(t[0].son[i]) q.push(t[0].son[i]);
  while(!q.empty()) {
    int now = q.front(); q.pop();
    for(int i = 0; i < 26; ++i) {
      if(t[now].son[i]) {
        int v = t[t[now].fail].son[i];
        t[t[now].son[i]].fail = v; 
        ++indge[v];
        q.push(t[now].son[i]);
      } else t[now].son[i] = t[t[now].fail].son[i];
    }
  }
}

inline void query(const string &s) {
  int now = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    now = t[now].son[ch];
    ++tme[now];
  }
}

inline void topo() {
  queue<int> q;
  for(int i = 1; i <= cnt; ++i)
    if(!indge[i]) q.push(i);
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int x: t[u].id) ans[x] += tme[u];
    int v = t[u].fail;
    tme[v] += tme[u];
    if(!--indge[v]) q.push(v);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; 
  while(cin >> n) {
    if(n == 0) break;
    fill(t, t+cnt+1, t[N-1]);
    fill(tme, tme+cnt+1, 0);
    fill(ans, ans+cnt+1, 0);
    vector<string> tt(n+1);
    cnt = 0;
    for(int i = 1; i <= n; ++i) Insert((cin >> tt[i], tt[i]), i);
    getFail();
    string s; cin >> s;
    query(s);
    topo();
    int maxn = 0;
    for(int i = 1; i <= n; ++i) maxn = max(maxn, ans[i]);
    cout << maxn << endl;
    for(int i = 1; i <= n; ++i) {
      if(ans[i] == maxn) cout << tt[i] << endl;
    }
  }
  return 0;
}