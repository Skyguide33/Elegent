//2025/10/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 10005
#define INF 10000000

namespace FastIO {
    const int SZ = 1 << 20;
    char inbuf[SZ], outbuf[SZ];
    int in_left = 0, in_right = 0;
    int out_right = 0;
    
    inline void load() {
        int len = fread(inbuf, 1, SZ, stdin);
        in_left = 0;
        in_right = len;
    }
    
    inline char getchar() {
        if (in_left >= in_right) load();
        if (in_left >= in_right) return EOF;
        return inbuf[in_left++];
    }
    
    inline int read() {
        int x = 0, f = 1;
        char ch = getchar();
        while (ch < '0' || ch > '9') {
            if (ch == '-') f = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9') {
            x = x * 10 + (ch - '0');
            ch = getchar();
        }
        return x * f;
    }
    
    inline void flush() {
        fwrite(outbuf, 1, out_right, stdout);
        out_right = 0;
    }
    
    inline void putchar(char ch) {
        outbuf[out_right++] = ch;
        if (out_right == SZ) flush();
    }
    
    inline void write(int x) {
        if (x < 0) {
            putchar('-');
            x = -x;
        }
        if (x > 9) write(x / 10);
        putchar(x % 10 + '0');
    }
    
    struct Flusher {
        ~Flusher() { flush(); }
    } flusher;
}

using namespace FastIO;

struct edge { int to, w, next; } e[N<<1];
int head[N];
int dep[N], dis[N], vis[N], siz[N], query[N], sub_rt[N], ans[N], cnt, max_siz, root, sub_n, p, m, n;

void addedge(int u, int v, int w) {
  e[++cnt] = {v, w, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, w, head[v]};
  head[v] = cnt;
}

bool cmp(int a, int b) {
  return dis[a] < dis[b];
}

void dfs_root(int u, int fa) {
  // cout << "dfs_root=" << u << endl;
  siz[u] = 1;
  int temp = 0;
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if(v != fa && !vis[v]) {
      dfs_root(v, u);
      siz[u] += siz[v];
      temp = max(temp, siz[v]);
    }
  }
  temp = max(temp, sub_n-siz[u]);
  if(temp < max_siz) {
    max_siz = temp;
    root = u;
  }
}

void dfs_dep(int u, int fa, int from) {
  dep[++p] = u;
  sub_rt[u] = from;
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to, w = e[i].w;
    if(v != fa && !vis[v]) {
      dis[v] = dis[u]+w;
      dfs_dep(v, u, from);
    }
  }
}

void dfs_num(int u) {
  // cout << "root=" << u << endl;
  dis[u] = 0;
  p = 0; 
  dep[++p] = u; 
  sub_rt[u] = u;
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to, w = e[i].w;
    if(!vis[v]) {
      dis[v] = dis[u]+w;
      dfs_dep(v, u, v);
    }
  }
  sort(dep+1, dep+p+1, cmp);
  // for(int i = 1; i <= p; ++i) cout << dis[dep[i]] << ' ';
  // cout << endl;
  for(int i = 1; i <= m; ++i) {
    if(ans[i]) continue;
    int l = 1, r = p;
    while(l < r) {
      if(dis[dep[l]]+dis[dep[r]] < query[i]) ++l;
      else if(dis[dep[l]]+dis[dep[r]] > query[i]) --r;
      else if(sub_rt[dep[l]] == sub_rt[dep[r]]) {
        if(sub_rt[dep[r]] == sub_rt[dep[r-1]]) --r;
        else ++l;
      } else {
        ans[i] = 1;
        // cout << "query=" << query[i] << endl;
        break;
      }
    }
  }
}

void dfs_ans(int u) {
  vis[u] = 1;
  dfs_num(u);
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if(!vis[v]) {
      sub_n = siz[v]; 
      root = 0;
      max_siz = INF; 
      dfs_root(v, 0); 
      dfs_ans(root);
    }
  }
}

int main() {
  n = read(), m = read();
  for(int i = 1; i < n; ++i) {
    int u = read(), v = read(), w = read();
    addedge(u, v, w); 
  }
  for(int i = 1; i <= m; ++i) {
    query[i] = read();
    if(!query[i]) ans[i] = 1;
  }
  sub_n = n; max_siz = INF; 
  dfs_root(1, 0);
  dfs_ans(root);
  for(int i = 1; i <= m; ++i) {
    if(ans[i]) printf("AYE\n");
    else printf("NAY\n");
  }
  return 0; 
}