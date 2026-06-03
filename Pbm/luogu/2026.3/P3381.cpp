//2026/3/6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 5005

struct Edge { int v, w, c, nxt; } e[110005];
int head[N], ecnt;

inline void addedge(int u, int v, int w, int c) {
  e[++ecnt] = {v, w, c, head[u]};
  head[u] = ecnt;
}

inline void link(int u, int v, int w, int c) {
	addedge(u, v, w, c); addedge(v, u, 0, -c);
}

int n, s, t;
int mf[N], pre[N], d[N], revf[N];

bool spfa() {
  fill(d+1, d+n+1, INT_MAX); d[s] = 0;
  fill(mf+1, mf+n+1, 0); mf[s] = INT_MAX;
  vector<int> vis(n+1, 0);
  queue<int> q; q.push(s); 
  while(!q.empty()) {
    int u = q.front(); q.pop(); vis[u] = 0;
    for(int i = head[u]; i; i = e[i].nxt) {
      auto [v, w, c, _] = e[i];
      if(d[u]+c < d[v] && w) {
        d[v] = d[u]+c;
        mf[v] = min(mf[u], w);
        pre[v] = i;
        if(!vis[v]) {
          q.push(v);
          vis[v] = 1;
        }
      } 
    }
  }
  return mf[t] > 0;
}

pair<int, int> EK() {
  int flow = 0, cost = 0;
  while(spfa()) {
    for(int v = t; v != s;) {
      int i = pre[v];
      e[i].w -= mf[t];
      e[i^1].w += mf[t];
      v = e[i^1].v;
    }
    flow += mf[t], cost += mf[t]*d[t];
  }
  return {flow, cost};
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m; cin >> n >> m >> s >> t;
  ecnt = 1;
	int flow = 0, cost = 0;
  for(int i = 1; i <= m; ++i) {
    int u, v, w, c; cin >> u >> v >> w >> c;
		if(c >= 0) link(u, v, w, c);
		else {
			revf[u] -= w, revf[v] += w;
			cost += c*w;
			link(v, u, w, -c);
		}
  }
	int sbak = s, tbak = t;
	s = n+1, t = n+2;
	for(int i = 1; i <= n; ++i) {
		if(revf[i] > 0) link(s, i, revf[i], 0);
		else if(revf[i] < 0) link(i, t, -revf[i], 0);
	}
	link(tbak, sbak, INT_MAX, 0);
	n += 2;
  auto [A, B] = EK();
	flow += e[ecnt].w, cost += B;
	e[ecnt].w = e[ecnt^1].w = 0;
	s = sbak, t = tbak; 
	tie(A, B) = EK();
  cout << flow+A << ' ' << cost+B << endl;
  return 0;
}