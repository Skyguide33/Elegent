#include<bits/stdc++.h>
using namespace std;
int ans, n, m, s, t, now[1201], dis[1201], h[1201], idx, q[1201], qh, qt; // q 使用 (h,v] 部分
struct node {
	int nex, e, w;
} e[240001];
int mp[1201][1201];
inline void add(int u, int v, int w) {
	e[idx++]= {h[u], v, w}, h[u]=idx-1;
}
inline int bfs() {
	for(int i=1; i<=n; i++) dis[i]=1e9;
	q[0]=s, qh=-1, qt=0;
	dis[s]=0, now[s]=h[s];
	while(qh < qt) {
		int x=q[++qh];
		for(int i=h[x]; ~i; i=e[i].nex) {
			int v=e[i].e;
			if(e[i].w>0&&dis[v]==1e9) {
				q[++qt]=v, now[v]=h[v], dis[v]=dis[x]+1;
				if(v==t) return 1;
			}
		}
	}
	return 0;
}
inline int dfs(int x, int lim) {
	if(x==t) return lim;
	int flow, res=0;
	for(int i=now[x]; (~i) && lim>0; i=e[i].nex) {
		now[x]=i; // 当前弧优化
		int v=e[i].e;
		if(e[i].w>0 && (dis[v]==dis[x]+1)) {
			flow=dfs(v, min(lim, e[i].w));
			if(flow==0) dis[v]=1e9;
			e[i].w-=flow, e[i^1].w+=flow, res+=flow, lim-=flow;
		}
	}
	return res;
}
int main() {
	memset(h, -1, sizeof h);
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for(int i=1, u, v, w; i<=m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		mp[u][v] += w;
	}
	for(int b=28; b>=0; b-=4) {
		for(int u=1; u<=n; u++)
			for(int v=u+1; v<=n; v++)
				if((mp[u][v] > 0 || mp[v][u] > 0) && (mp[u][v] >= (1<<b) || mp[v][u] >= (1<<b)))
					add(u, v, mp[u][v]), add(v, u, mp[v][u]), mp[u][v]=0, mp[v][u]=0;
		while(bfs()) ans+=dfs(s, 1e9);
	}
	printf("%d", ans);
	return 0;
}
