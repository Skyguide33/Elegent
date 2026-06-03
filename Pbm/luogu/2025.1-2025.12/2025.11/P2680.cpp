//2025/11/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

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

struct Edge { int to, w, next; } e[600005];
int head[300005], cnt;

void addedge(int u, int v, int w) { 
  e[++cnt] = {v, w, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, w, head[v]};
  head[v] = cnt;
}

struct Dist { int x, y, lca, dis; } d[300005];

int fa[300005][20], dep[300005], s[300005], t[300005], p[300005], cnt_p, n, m;

int LCA(int x, int y) {
  if(dep[x] < dep[y]) swap(x, y);
  for(int i = 19; i >= 0; --i) {
    if(dep[x]-(1<<i) >= dep[y]) x = fa[x][i];
  }
  if(x == y) return x;
  for(int i = 19; i >= 0; --i) {
    if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  }
  return fa[x][0];
}

bool cmp(const Dist &a, const Dist &b) { return a.dis > b.dis; }

bool check(int k) {
  memset(t, 0, sizeof(t));
  int i = 1;
  for(; i <= m && d[i].dis > k; ++i) {
    ++t[d[i].x]; ++t[d[i].y]; t[d[i].lca] -= 2;
  }
  int cnt = i-1;
  for(int i = n; i >= 1; --i) t[fa[p[i]][0]] += t[p[i]];
  for(int i = 1; i <= n; ++i) {
    if(t[i] == cnt && s[i]-s[fa[i][0]] >= d[1].dis-k) return 1;
  }
  return 0;
} 

int main() {
  n = read(), m = read();
  int maxw = 0;
  for(int i = 1; i < n; ++i) {
    int a = read(), b = read(), t = read();
    addedge(a, b, t);
    maxw = max(maxw, t);
  }
  stack<int> st;
  st.push(1);
  while(!st.empty()) {
    int u = st.top(); st.pop();
    p[++cnt_p] = u;
    for(int i = 1; (1<<i) <= dep[u]; ++i) fa[u][i] = fa[fa[u][i-1]][i-1];
    for(int i = head[u]; i; i = e[i].next) {
      int v = e[i].to, w = e[i].w;
      if(v != fa[u][0]) {
        fa[v][0] = u;
        dep[v] = dep[u]+1;
        s[v] = s[u]+w;
        st.push(v);
      }
    }
  }
  for(int i = 1; i <= m; ++i) {
    d[i].x = read(), d[i].y = read();
    d[i].lca = LCA(d[i].x, d[i].y);
    d[i].dis = s[d[i].x]+s[d[i].y]-2*s[d[i].lca];
  }
  sort(d+1, d+m+1, cmp);
  int l = max(0, d[1].dis-maxw), r = d[1].dis;
  while(l < r) {
    int mid = (l+r)>>1;
    if(check(mid)) r = mid;
    else l = mid+1;
  }
  write(l);
  putchar('\n');
  return 0;
}